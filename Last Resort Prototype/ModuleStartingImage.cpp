#include "Globals.h"
#include "Application.h"
#include "ModuleStartingImage.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleBackground.h"
#include "ModuleStageClear.h"
#include "Application.h"


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
	TexStImage = App->textures->Load("assets/StartingTitle.png");

	mus = App->audio->LoadMus("assets/01-NEO-GEO-LOGO-SONG.ogg");
	App->audio->PlayMus(mus);

	App->render->camera.x = 0;
	App->render->camera.y = 0;
	App->player->Disable(); 

	return ret;
}

// Load assets
bool ModuleStartingImage::CleanUp()
{
	LOG("Unloading Intro Scene");
	App->textures->Unload(TexStImage);
	App->audio->UnloadMus(mus);

	return true;
}

// Update: draw background
update_status ModuleStartingImage::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(TexStImage, 0, 0, &StImage);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		App->fade->FadeToBlack(App->startimage, App->background, 1.5f);
	}


	return UPDATE_CONTINUE;
}