#include "Globals.h"
#include "Application.h"
#include "ModuleStartingImage.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleBackground.h"
#include "Application.h"
#include "Module.h"


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
	TexStImage = App->textures->Load("StartingTitle.png");

	App->player->Disable(); 

	return ret;
}

// Load assets
bool ModuleStartingImage::CleanUp()
{
	// TODO 5: Remove all memory leaks
	// App->textures(graphics)->Disable();
	LOG("Unloading honda stage");

	return true;
}

// Update: draw background
update_status ModuleStartingImage::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(TexStImage, 0, 0, &StImage);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		App->fade->FadeToBlack(App->background, App->startimage, 1.0f);
	}


	return UPDATE_CONTINUE;
}