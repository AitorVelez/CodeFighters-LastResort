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
#include "ModuleUI.h"
#include "ModuleBackground2.h"

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
	TexStageImage = App->textures->Load("assets/sprites/Stage1Clear1.png");

	ClearMus = App->audio->LoadMus("assets/SFX/stage_clear_1.ogg");
	App->audio->PlayMus(ClearMus);
	App->UI->Enable();
	App->render->camera.x = 0;
	App->render->camera.y = 0;
	App->player->Disable();
	App->player2->Disable();
	App->background->Disable();
	App->UI->stgclr = true;
	return ret;
}

// Load assets
bool ModuleStageClear::CleanUp()
{
	LOG("Unloading Intro Scene");
	App->textures->Unload(TexStageImage);
	App->audio->UnloadMus(ClearMus);
	App->UI->Disable();
	App->UI->stgclr = false;
	App->UI->pl2 = false;

	return true;
}

// Update: draw background
update_status ModuleStageClear::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(TexStageImage, 0, 0, &StageImage);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN
		|| App->input->Controller_1[SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_A] == KEY_DOWN
		|| App->input->Controller_2[SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_A] == KEY_DOWN) {
		if (App->fade->FadeToBlack(App->stageclear, App->background2, 1.5f))
			App->player->lives = 3; 
		    App->player2->lives = 3;
				App->audio->FadeMus(750);
	}

	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN)
	{
			if (App->fade->FadeToBlack(this, App->background2, 1.5f))
				App->audio->FadeMus(750);
	}

	bool PlayerLifeReset = false;
	bool Player2LifeReset = false;

	if (PlayerLifeReset == false) {
		LOG("------------------------------------------------------------------- PLAYER 1 LIFES BEFORE LIVE RESET: %i", App->player->lives);
		if (App->player->lives != 3) {
			App->player->lives = 3; LOG("-----------------------------------------------------------------PLAYER 1 LIFES AFTER LIVE RESET: %i", App->player->lives);
		}
		PlayerLifeReset = true;
	}

	if (Player2LifeReset == false) {
		if (App->player2->lives != 3) {
			App->player2->lives = 3;
		}
		Player2LifeReset = true;
	}

	return UPDATE_CONTINUE;
}