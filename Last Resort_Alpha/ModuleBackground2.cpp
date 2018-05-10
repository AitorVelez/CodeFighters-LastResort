#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground2.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleStageClear.h"
#include "ModuleStartingImage.h"
#include "ModuleLoseImage.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "PowerUp.h"
#include "SDL/include/SDL_timer.h"
#include "ModulePlayer2.h"
#include "ModulePowerUp.h"
#include "ModuleUI.h"
#include "ModuleFonts.h"
#include "ModuleBall.h"
#include "ModuleBackground.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground2::ModuleBackground2()
{
	// Parallax levels
	depth_1 = 0.4875;

								// Background
	background2.x = 0;
	background2.y = 0;
	background2.w = 3896;
	background2.h = 224;

	foreground2.x = 0;
	foreground2.y = 0;
	foreground2.w = 4825;
	foreground2.h = 224;

	extra_foreground.x = 0;
	extra_foreground.y = 0;
	extra_foreground.w = 80;
	extra_foreground.h = 68;

	Rainlvl2.PushBack({ 0,0,32,32 });
	Rainlvl2.PushBack({ 32,0,32,32 });
	Rainlvl2.PushBack({ 64,0,32,32 });
	Rainlvl2.PushBack({ 86,0,32,32 });
	Rainlvl2.PushBack({ 118,0,32,32 });
	Rainlvl2.PushBack({ 150,0,32,32 });
	Rainlvl2.PushBack({ 182,0,32,32 });
	Rainlvl2.PushBack({ 214,0,32,32 });
	Rainlvl2.speed = 0.1f;

}

ModuleBackground2::~ModuleBackground2()
{}

// Load assets
bool ModuleBackground2::Start()
{
	LOG("Loading background assets");

	bool ret = true;
	App->background->BgLevel2Active = true; 
	App->particles->Enable();
	App->player->Enable();
	App->collision->Enable();
	App->background->Disable();
	App->power->Enable();
	App->UI->Enable();
	App->Fonts->Enable();
	App->enemies->Enable();
	
	BackgroundLvl2 = App->textures->Load("assets/sprites/Background_2.png");
	Rain = App->textures->Load("assets/sprites/MinimunRainTest.png");
	mus = App->audio->LoadMus("assets/SFX/level2.ogg");
	ForegroundLvl2 = App->textures->Load("assets/sprites/Foreground_2.png");
	Extra_ForegroundLvl2 = App->textures->Load("assets/sprites/ForegroundExtra.png");
	App->audio->PlayMus(mus);


	App->enemies->AddEnemy(ENEMY_TYPES::RED_LAMELLA, 205, 195);

	activ = false;
	App->UI->ready = true;

	return ret;
}

bool ModuleBackground2::CleanUp()
{
	LOG("Cleaning Up background");
	//Disable Other Modules
	App->particles->Disable();
	App->player->Disable();
	App->player2->Disable();
	App->collision->Disable();
	App->enemies->Disable();
	App->Fonts->Disable();
	App->UI->Disable();
	App->power->Disable();

	App->UI->ready = false;
	//Free all loaded textures
	App->textures->Unload(BackgroundLvl2);
	App->textures->Unload(Rain);
	App->textures->Unload(ForegroundLvl2);
	App->textures->Unload(Extra_ForegroundLvl2);
	//Free all audio material
	App->audio->UnloadMus(mus);

	//Free Collision



	return true;
}



// Update: draw background
update_status ModuleBackground2::Update()
{
	
	int scroll_speed = 1;

	// Camera Movement Conditions
	

	if (scroll) {
		App->render->camera.x += scroll_speed;
		bgpos += 1;
	}

	if (App->render->camera.x >= 9100 * SCREEN_SIZE)
		scroll = false;



	// Draw everything --------------------------------------
	int separation = 32; 
	App->render->Blit(BackgroundLvl2, 0, 0, &background2, depth_1);
	App->render->Blit(ForegroundLvl2, 1000, 0, &foreground2, depth_1);
	App->render->Blit(Extra_ForegroundLvl2, 300, 156, &extra_foreground, depth_1);
	App->render->Blit(Rain, 0, 50, &Rainlvl2.GetCurrentFrame(), depth_1);



	// Fade to black
	if (App->input->keyboard[SDL_SCANCODE_T] == KEY_STATE::KEY_DOWN) {
		App->player->god_mode = true;
		App->player2->god_mode = true;
		if (App->fade->FadeToBlack(App->background2, App->stageclear, 1.5f))
			App->audio->FadeMus(750);
	}

	if (App->input->keyboard[SDL_SCANCODE_Y] == KEY_STATE::KEY_DOWN) {
		App->player->god_mode = true;
		App->player2->god_mode = true;
		if (App->fade->FadeToBlack(App->background2, App->loseimage, 1.5f))
			App->audio->FadeMus(750);
	}
	if (App->input->keyboard[SDL_SCANCODE_2] == KEY_STATE::KEY_DOWN)
		App->player2->Enable();


	if (activ == false) {
		if (App->player->alive_p1 == false) {
			if (App->player->lives == 0) {
				App->fade->FadeToBlack((Module*)App->background2, (Module*)App->loseimage, 2.5f);
			}
			else {
				App->fade->FadeToBlack((Module*)App->background2, (Module*)App->Ready, 0.0f);
				if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
					App->fade->FadeToBlack((Module*)App->Ready, (Module*)App->background2, 0.0f);
				}
			}
		}
		/*
		if (App->player->alive_p1 == false && App->player2->alive_p2 == false && App->player->lives == 0 && App->player2->lives == 0) {
		App->fade->FadeToBlack((Module*)App->background, (Module*)App->loseimage, 2.5f);
		}*/
	}



	if (App->render->camera.x == 9000 * SCREEN_SIZE) {
		App->fade->FadeToBlack((Module*)App->background2, (Module*)App->stageclear, 2.5f);
	}



	return UPDATE_CONTINUE;
}
