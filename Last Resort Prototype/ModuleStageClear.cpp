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
#include "ModuleLvl2.h"
#include "Application.h"



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

	ClearMus = App->audio->LoadMus("assets/SFX/musicStageClear.ogg");
	App->audio->PlayMus(ClearMus);

	App->render->camera.x = 0;
	App->render->camera.y = 0;
	App->player->Disable();

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
		App->fade->FadeToBlack(App->stageclear, App->lvl2, 1.5f);
	}


	return UPDATE_CONTINUE;
}