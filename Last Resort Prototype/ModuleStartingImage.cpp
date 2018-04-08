#include "Globals.h"
#include "Application.h"
#include "ModuleStartingImage.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleBackground.h"


// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleStartingImage::ModuleStartingImage()
{
	StImage.x = 0;
	StImage.y = 0;
	StImage.w = SCREEN_WIDTH;
	StImage.h = SCREEN_HEIGHT;
}

ModuleStartingImage::~ModuleStartingImage()
{}

// Load assets
bool ModuleStartingImage::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("StartingTitle.png");

	// TODO 1: Enable (and properly disable) the player module
	App->textures->Enable();

	return ret;
}

// Load assets
bool ModuleStartingImage::CleanUp()
{
	// TODO 5: Remove all memory leaks
//	App->textures(graphics)->Disable();
	LOG("Unloading honda stage");

	return true;
}

// Update: draw background
update_status ModuleStartingImage::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 160, &StImage);


	// TODO 2: make so pressing SPACE the KEN stage is loaded



	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		App->fade->FadeToBlack(App->startimage, App->background, 5.0f);

	}


	return UPDATE_CONTINUE;
}