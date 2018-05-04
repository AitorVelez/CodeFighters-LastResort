#include "Globals.h"
#include "Application.h"
#include "ModuleStartingImage.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleBackground.h"
#include "ModuleStageClear.h"
#include "ModuleLvl2.h"
#include "ModuleAudio.h"
#include "ModuleIntroNeoGeo.h"
#include "Application.h"



ModuleLvl2::ModuleLvl2()
{
	Lvl2Image.x = 0;
	Lvl2Image.y = 0;
	Lvl2Image.w = SCREEN_WIDTH;
	Lvl2Image.h = SCREEN_HEIGHT;
}

ModuleLvl2::~ModuleLvl2()
{}

// Load assets
bool ModuleLvl2::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	TexLvl2Image = App->textures->Load("assets/sprites/Background_2.png");
	App->render->camera.x = 0;
	App->render->camera.y = 0;
	//App->player->Enable();
	return ret;
}

// Load assets
bool ModuleLvl2::CleanUp()
{
	LOG("Unloading Intro Scene");
	App->textures->Unload(TexLvl2Image);

	return true;
}

// Update: draw background
update_status ModuleLvl2::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(TexLvl2Image, 0, 0, &Lvl2Image);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		App->fade->FadeToBlack(App->lvl2, App->introneogeo, 1.5f);
	}


	return UPDATE_CONTINUE;
}