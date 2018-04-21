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
#include "ModulePlayer2.h"

ModuleStartingImage::ModuleStartingImage()
{
	StImage.x = 0;
	StImage.y = 0;
	StImage.w = SCREEN_WIDTH;
	StImage.h = SCREEN_HEIGHT;

	Press.PushBack({ 0,0,138,10 });
	Press.PushBack({ 0,13,138,10 });
	Press.PushBack({ 0,27,138,10 });
	Press.PushBack({ 0,41,138,10 });
	Press.PushBack({ 0,55,138,10 });
	Press.PushBack({ 0,69,138,10 });
	Press.PushBack({ 0,55,138,10 });
	Press.PushBack({ 0,41,138,10 });
	Press.PushBack({ 0,27,138,10 });
	Press.PushBack({ 0,13,138,10 });
	Press.speed = 0.09;
}

ModuleStartingImage::~ModuleStartingImage()
{}

// Load assets
bool ModuleStartingImage::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	TexStImage = App->textures->Load("assets/sprites/StartingTitle2.png");

	mus = App->audio->LoadMus("assets/SFX/last_resort_tittle.ogg");
	App->audio->PlayMus(mus);
	Starts = App->textures->Load("assets/sprites/Start.png");

	App->render->camera.x = 0;
	App->render->camera.y = 0;
	App->player->Disable(); 
	App->player2->Disable();
	return ret;
}

// Load assets
bool ModuleStartingImage::CleanUp()
{
	LOG("Unloading Intro Scene");
	App->textures->Unload(TexStImage);
	App->textures->Unload(Starts);
	App->audio->UnloadMus(mus);

	return true;
}

// Update: draw background
update_status ModuleStartingImage::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(TexStImage, 0, 0, &StImage);
	App->render->Blit(Starts, 130, 170, &Press.GetCurrentFrame(), 0, false);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		if (App->fade->FadeToBlack(App->startimage, App->background, 1.5f))
			App->audio->FadeMus(750);
	}

	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN)
	{
		if (App->fade->FadeToBlack(this, App->background, 1.5f))
			App->audio->FadeMus(750);
	}


	return UPDATE_CONTINUE;
}