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

	hangar_body.x = 0;
	hangar_body.y = 0;
	hangar_body.w = 80;
	hangar_body.h = 68;

	hangar_2_body.x = 0;
	hangar_2_body.y = 0;
	hangar_2_body.w = 80;
	hangar_2_body.h = 35;

	/*rain_anim.PushBack({ 0,0,32,32 });
	rain_anim.PushBack({ 32,0,32,32 });
	rain_anim.PushBack({ 64,0,32,32 });
	rain_anim.PushBack({ 86,0,32,32 });
	rain_anim.PushBack({ 118,0,32,32 });
	rain_anim.PushBack({ 150,0,32,32 });
	rain_anim.PushBack({ 182,0,32,32 });
	rain_anim.PushBack({ 214,0,32,32 });*/

	
	rain_anim.PushBack({ 720, 192, 240,192 });
	rain_anim.PushBack({ 480, 192, 240,192 });	
	rain_anim.PushBack({ 240, 192, 240,192 });	
	rain_anim.PushBack({ 0, 192, 240,192 });	
	rain_anim.PushBack({ 720, 0, 240,192 });
	rain_anim.PushBack({ 480, 0, 240,192 });
	rain_anim.PushBack({ 240, 0, 240,192 });
	rain_anim.PushBack({ 0, 0, 240,192 });
	rain_anim.speed = 0.007f;
	rain_anim.loop = true; 

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
	rain = App->textures->Load("assets/sprites/MinimunRainTest.png");
	mus = App->audio->LoadMus("assets/SFX/level2.ogg");
	ForegroundLvl2 = App->textures->Load("assets/sprites/Foreground_2.png");
	hangar_texture = App->textures->Load("assets/sprites/hangar_body.png");
	hangar_2_texture = App->textures->Load("assets/sprites/Foreground_part_3.png");
	//App->audio->PlayMus(mus);



	App->power->AddPowerup(POWERUP_TYPES::LPOWER, 205, 100);
	App->power->AddPowerup(POWERUP_TYPES::LPOWER, 255, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::RED_LAMELLA, 205, 195);
	App->enemies->AddEnemy(ENEMY_TYPES::RED_LAMELLA, 805, 195);
	App->enemies->AddEnemy(ENEMY_TYPES::RED_LAMELLA, 1505, 195);
	
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3060, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3100, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3140, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3180, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3220, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3260, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3300, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3340, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3380, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3420, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3460, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3480, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3520, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3560, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3600, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3640, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3680, TopTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 660, TopTurretPosY);
	

	App->collision->AddCollider({500,156,80,68}, COLLIDER_WALL);
	App->collision->AddCollider({ 2000,156,80,68 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2200,0,80,35 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2400,156,80,68 }, COLLIDER_WALL);
	

	//COLLIDERS GRANS

	App->collision->AddCollider({ 2700,156,160,68 }, COLLIDER_WALL);			//baix
	App->collision->AddCollider({ 2700,0,160,51 }, COLLIDER_WALL);				//dalt
	App->collision->AddCollider({ 2860,187,419,37 }, COLLIDER_WALL);			//llarg baix
	App->collision->AddCollider({ 2860,0,415,19 }, COLLIDER_WALL);				//llarg dalt	
	App->collision->AddCollider({ 3272,140,100,100 }, COLLIDER_WALL);			//cuadrat baix
	App->collision->AddCollider({ 3272,0,96,68 }, COLLIDER_WALL);				//cuadrat dalt
	
	App->collision->AddCollider({ 3368,187,736,37 }, COLLIDER_WALL);			//llarg baix
	App->collision->AddCollider({ 3368,0,736,19 }, COLLIDER_WALL);				//larg baix
	App->collision->AddCollider({ 4104,140,100,100 }, COLLIDER_WALL);			//cuadrat baix
	App->collision->AddCollider({ 4104,0,96,68 }, COLLIDER_WALL);				//cuadrat dalt
	App->collision->AddCollider({ 3368,187,130,37 }, COLLIDER_WALL);			//llarg baix
	App->collision->AddCollider({ 3368,0,130,19 }, COLLIDER_WALL);				//larg baix



	activ = false;
	App->UI->ready = true;

	mus = App->audio->LoadMus("assets/SFX/level_2.ogg");
	App->audio->PlayMus(mus);

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
	App->textures->Unload(rain);
	App->textures->Unload(ForegroundLvl2);
	App->textures->Unload(hangar_texture);
	App->textures->Unload(hangar_2_texture);
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


		// Background  
	App->render->Blit(BackgroundLvl2, 0, 0, &background2, 0.416);						
		
	
		// Rain
	for(int cont = 0; cont <= background2.w * 3; cont+=240)
	App->render->Blit(rain, cont, 0, &rain_anim.GetCurrentFrame(), 1.f);

		// Foreground
	App->render->Blit(ForegroundLvl2, 2700, 0, &foreground2, 1.0f);

		// Hangars 

	/*App->render->Blit(hangar_texture, 1000, 156, &hangar_body, 1.0f);
	App->render->Blit(hangar_2_texture, 300, 0, &hangar_2_body, 1.0f);*/

	App->render->Blit(hangar_texture, 500, 156, &hangar_body, 1.0f);
	App->render->Blit(hangar_texture, 2000, 156, &hangar_body, 1.0f);
	App->render->Blit(hangar_2_texture, 2200, 0, &hangar_2_body, 1.0f);
	App->render->Blit(hangar_texture, 2400, 156, &hangar_body, 1.0f);


		
	






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


	if (App->player->IsEnabled() == true && App->player2->IsEnabled() == false) {         // When player 1 is active and dies, ready appears
		if (activ == false) {
			if (App->player->alive_p1 == false) {
				if (App->player->lives == 0) {
					App->fade->FadeToBlack((Module*)App->background2, (Module*)App->loseimage, 2.5f);
				}
				else {
					App->fade->FadeToBlack((Module*)App->background2, (Module*)App->Ready, 1.5f);
				}
			}
		}
	 }
	
	
	else if (App->player->IsEnabled() == true && App->player2->IsEnabled() == true) {       // when both players active, they can respawn 
		if (activ == false) {
			if (App->player2->alive_p2 == false) {
				if (App->player->lives == 0 && App->player2->lives == 0) {
					App->fade->FadeToBlack((Module*)App->background2, (Module*)App->loseimage, 2.5f);
				}
			}
		}
	}
	


	if (App->render->camera.x == 9000 * SCREEN_SIZE) {
		App->fade->FadeToBlack((Module*)App->background2, (Module*)App->stageclear, 2.5f);
	}



	return UPDATE_CONTINUE;
}
