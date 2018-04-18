#include "Globals.h"
#include "Application.h"
#include "ModuleStartingImage.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleBackground.h"
#include "ModuleStageClear.h"
#include "ModuleIntroNeoGeo.h"
#include "Application.h"
#include "ModulePlayer2.h"


ModuleStageClear::ModuleStageClear()
{
	StageImage.x = 0;
	StageImage.y = 0;
	StageImage.w = SCREEN_WIDTH;
	StageImage.h = SCREEN_HEIGHT;
}

ModuleStageClear::~ModuleStageClear()
{}

// Load assets
bool ModuleStageClear::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	TexStageImage = App->textures->Load("assets/sprites/Stage1Clear.png");

	ClearMus = App->audio->LoadMus("assets/SFX/stage_clear.ogg");
	App->audio->PlayMus(ClearMus);

	App->render->camera.x = 0;
	App->render->camera.y = 0;
	App->player->Disable();
	App->player2->Disable();
	return ret;
}

// Load assets
bool ModuleStageClear::CleanUp()
{
	LOG("Unloading Intro Scene");
	App->textures->Unload(TexStageImage);
	App->audio->UnloadMus(ClearMus);

	return true;
}

// Update: draw background
update_status ModuleStageClear::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(TexStageImage, 0, 0, &StageImage);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		if (App->fade->FadeToBlack(App->stageclear, App->introneogeo, 1.5f))
			App->audio->FadeMus(750);
	}

	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN)
	{
		if (App->fade->FadeToBlack(this, App->background, 1.5f))
			App->audio->FadeMus(750);
	}

	return UPDATE_CONTINUE;
}