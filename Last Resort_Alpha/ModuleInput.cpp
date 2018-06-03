#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput() : Module()
{
	for (uint i = 0; i < MAX_KEYS; ++i)
		keyboard[i] = KEY_IDLE;

	for (uint i = 0; i < SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_MAX; ++i)
		Controller_1[i] = KEY_IDLE;

	for (uint i = 0; i < SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_MAX; ++i)
		Controller_2[i] = KEY_IDLE;

	uint i = 0;
	button_array[i] = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_A; ++i;
	button_array[i] = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_B; ++i;
	button_array[i] = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_BACK; ++i;
	button_array[i] = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_DOWN; ++i;
	button_array[i] = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_LEFT; ++i;
	button_array[i] = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_RIGHT; ++i;
	button_array[i] = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_UP; ++i;
	button_array[i] = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_GUIDE; ++i;
	button_array[i] = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_LEFTSHOULDER; ++i;
	button_array[i] = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_LEFTSTICK; ++i;
	button_array[i] = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_RIGHTSHOULDER; ++i;
	button_array[i] = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_RIGHTSTICK; ++i;
	button_array[i] = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_START; ++i;
	button_array[i] = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_X; ++i;
	button_array[i] = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_Y; ++i;
}

// Destructor
ModuleInput::~ModuleInput()
{
}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;

	SDL_Init(SDL_INIT_GAMECONTROLLER);

	if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_PumpEvents();
	
	const Uint8* keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; i < MAX_KEYS; ++i)
	{
		if (keys[i] == 1)
		{
			if (keyboard[i] == KEY_IDLE)
				keyboard[i] = KEY_DOWN;
			else
				keyboard[i] = KEY_REPEAT;
		}
		else
		{
			if (keyboard[i] == KEY_REPEAT || keyboard[i] == KEY_DOWN)
				keyboard[i] = KEY_UP;
			else
				keyboard[i] = KEY_IDLE;
		}
	}

	for (int i = 0; i < SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_MAX; ++i)	
	{
		if (SDL_GameControllerGetButton(controller[0].controller, button_array[i]))
		{
			if (Controller_1[i] == KEY_IDLE)
				Controller_1[i] = KEY_DOWN;

			else
				Controller_1[i] = KEY_REPEAT;
		}
		else
		{
			if (Controller_1[i] == KEY_REPEAT || Controller_1[i] == KEY_DOWN)
				Controller_1[i] = KEY_UP;

			else
				Controller_1[i] = KEY_IDLE;
		}
	}


	for (int i = 0; i < SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_MAX; ++i)
	{
		if (SDL_GameControllerGetButton(controller[1].controller, button_array[i]))
		{
			if (Controller_2[i] == KEY_IDLE)
				Controller_2[i] = KEY_DOWN;

			else
				Controller_2[i] = KEY_REPEAT;
		}
		else
		{
			if (Controller_2[i] == KEY_REPEAT || Controller_2[i] == KEY_DOWN)
				Controller_2[i] = KEY_UP;

			else
				Controller_2[i] = KEY_IDLE;
		}
	}


	SDL_PollEvent(&e);

	if (e.type == SDL_CONTROLLERDEVICEADDED)
	{
		for (int i = 0; i < MAX_CONTROLLERS; i++)
		{
			if (controller[i].controller == nullptr && controller[i].joyId == -1)
			{
				controller[i].controller = SDL_GameControllerOpen(i);
				SDL_Joystick* j = SDL_GameControllerGetJoystick(controller[i].controller);
				controller[i].joyId = SDL_JoystickInstanceID(j);
				break;
			}
		}
	}

	if (e.type == SDL_CONTROLLERDEVICEREMOVED)
	{
		for (int i = 0; i < MAX_CONTROLLERS; ++i)
		{
			if (controller[i].joyId == e.cdevice.which)
			{
				SDL_GameControllerClose(controller[i].controller);
				controller[i].controller = nullptr;
				controller[i].joyId = -1;

				LOG("Disconnected gamepad index: %d", i)
					break;
			}
		}
	}

	if (e.type == SDL_QUIT) {
		return update_status::UPDATE_STOP;
	}

	if (keyboard[SDL_SCANCODE_ESCAPE])
		return update_status::UPDATE_STOP;

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}