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
#include "ModuleLoseImage.h"
#include "ModuleStageClear.h"
#include "Application.h"


ModuleLoseImage::ModuleLoseImage()
{
	LoseImage.x = 0;
	LoseImage.y = 0;
	LoseImage.w = SCREEN_WIDTH;
	LoseImage.h = SCREEN_HEIGHT;
}

ModuleLoseImage::~ModuleLoseImage()
{}

// Load assets
bool ModuleLoseImage::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	TexLoseImage = App->textures->Load("assets/sprites/GameOver.png");

	LoseMus = App->audio->LoadMus("assets/SFX/game_over.ogg");
	App->audio->PlayMus(LoseMus);

	App->render->camera.x = 0;
	App->render->camera.y = 0;
	App->player->Disable();

	return ret;
}

// Load assets
bool ModuleLoseImage::CleanUp()
{
	LOG("Unloading Intro Scene");
	App->textures->Unload(TexLoseImage);
	App->audio->UnloadMus(LoseMus);

	return true;
}

// Update: draw background
update_status ModuleLoseImage::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(TexLoseImage, 0, 0, &LoseImage);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		if (App->fade->FadeToBlack(App->loseimage, App->startimage, 1.5f))
			App->audio->FadeMus(750);
	}

	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN)
	{
		if (App->fade->FadeToBlack(this, App->background, 1.5f))
			App->audio->FadeMus(750);
	}


	return UPDATE_CONTINUE;
}