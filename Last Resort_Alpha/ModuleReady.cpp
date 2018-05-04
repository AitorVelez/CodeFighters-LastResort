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
#include "ModuleReady.h"
#include "ModuleStageClear.h"
#include "Application.h"
#include "ModulePlayer2.h"

ModuleReady::ModuleReady()
{
	ReadyImage.x = 0;
	ReadyImage.y = 0;
	ReadyImage.w = SCREEN_WIDTH;
	ReadyImage.h = SCREEN_HEIGHT;
}

ModuleReady::~ModuleReady()
{}

// Load assets
bool ModuleReady::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	TextReadyImage = App->textures->Load("assets/sprites/ReadyImage.png");

	App->render->camera.x = 0;
	App->render->camera.y = 0;
	App->player->Disable();
	App->player2->Disable();
	return ret;
}

// Load assets
bool ModuleReady::CleanUp()
{
	LOG("Unloading Intro Scene");
	App->textures->Unload(TextReadyImage);

	return true;
}

// Update: draw background
update_status ModuleReady::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(TextReadyImage, 0, 0, &ReadyImage);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		App->fade->FadeToBlack(App->Ready, App->background, 1.5f); 
	}

	return UPDATE_CONTINUE;
}