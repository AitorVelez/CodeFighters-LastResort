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
#include "ModuleIntroNeoGeo.h"
#include "Application.h"


ModuleIntroNeoGeo::ModuleIntroNeoGeo()
{
	StImage.x = 0;
	StImage.y = 0;
	StImage.w = SCREEN_WIDTH;
	StImage.h = SCREEN_HEIGHT;
}

ModuleIntroNeoGeo::~ModuleIntroNeoGeo()
{}

// Load assets
bool ModuleIntroNeoGeo::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	TexNeoGeoImage = App->textures->Load("assets/sprites/Neogeo.png");

	mus = App->audio->LoadMus("assets/SFX/musicInit.ogg");
	App->audio->PlayMus(mus);

	App->render->camera.x = 0;
	App->render->camera.y = 0;
	App->player->Disable();

	return ret;
}

// Load assets
bool ModuleIntroNeoGeo::CleanUp()
{
	LOG("Unloading Intro Scene");
	App->textures->Unload(TexNeoGeoImage);
	App->audio->UnloadMus(mus);

	return true;
}

// Update: draw background
update_status ModuleIntroNeoGeo::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(TexNeoGeoImage, 0, 0, &StImage);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		if (App->fade->FadeToBlack(this, App->startimage, 1.5f))
			App->audio->FadeMus(750);
	}
	
	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN)
	{
		if (App->fade->FadeToBlack(this, App->background, 1.5f))
			App->audio->FadeMus(750);
	}


	return UPDATE_CONTINUE;
}