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
	bgpos = 0; 
	BackgroundLvl2 = App->textures->Load("assets/sprites/Background_2.png");
	rain = App->textures->Load("assets/sprites/MinimunRainTest.png");
	mus = App->audio->LoadMus("assets/SFX/level2.ogg");
	ForegroundLvl2 = App->textures->Load("assets/sprites/Foreground_2.png");
	hangar_texture = App->textures->Load("assets/sprites/hangar_body.png");
	hangar_2_texture = App->textures->Load("assets/sprites/Foreground_part_3.png");
	//App->audio->PlayMus(mus);

	if (LifeReset == false) {
		if (App->player->lives != 3) {
			App->player->lives = 3;
		}
	if (App->player2->lives != 3) {
		App->player2->lives = 3;
	}
	LifeReset = true; 
	}


	hangar_1 = App->collision->AddCollider({750,156,80,68}, COLLIDER_WALL);
	App->power->AddPowerup(POWERUP_TYPES::GPOWER, 2100, 100);

	App->power->AddPowerup(POWERUP_TYPES::HPOWER, 2400, 100);

	App->power->AddPowerup(POWERUP_TYPES::LPOWER, 2700, 100);

	App->power->AddPowerup(POWERUP_TYPES::LPOWER, 3000, 100);

	App->power->AddPowerup(POWERUP_TYPES::SPOWER, 2000, 100);

	App->enemies->AddEnemy(ENEMY_TYPES::JUMPYRIDER, 400, 150);
	App->enemies->AddEnemy(ENEMY_TYPES::JUMPYRIDER2, 400, 70);

	/*hangar_1 = App->collision->AddCollider({500,156,80,68}, COLLIDER_WALL);*/

	App->power->AddPowerup(POWERUP_TYPES::GPOWER, 255, 100);


	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, 375, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, 425, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, 425, 150);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, 475, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, 475, 170);


	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG, 755, 280);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG, 755, 260);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG, 755, 240);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG, 755, 220);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG, 755, 200);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG, 755, 180);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG, 755, 160); // salen si les cambias el numero
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG, 755, 140);


	//App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG_DOWN, 500, 35);


	App->enemies->AddEnemy(ENEMY_TYPES::JUMPY, 651, 120);
	
	App->enemies->AddEnemy(ENEMY_TYPES::JUMPY, 669, 90);

	//App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, 750, 120);
	//App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, 750, 90);
	//App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, 750, 150);
	//App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, 750, 70);
	//App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, 750, 170);

	
	
	App->enemies->AddEnemy(ENEMY_TYPES::METAL_BEE, 1050, 120);			//NO SPAWNEAN POR ALGO
	App->enemies->AddEnemy(ENEMY_TYPES::METAL_BEE, 1300, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::METAL_BEE, 1650, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::METAL_BEE, 1700, 120);

	App->enemies->AddEnemy(ENEMY_TYPES::JUMPY, 1050, 90);

	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, 1550, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, 1560, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, 1550, 110);


	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, 1950, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, 1960, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, 1950, 110);


	//App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1200, 140);
	//App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1225, 85);
	//App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1200, 170);
	//App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1225, 60);

	//App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1250, 140);
	//App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1275, 85);
	//App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1250, 170);
	//App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1275, 60);

	//App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1300, 140);
	//App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1325, 85);
	//App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1300, 170);
	//App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1325, 60);

	//App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1350, 140);
	//App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1375, 85);
	//App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1350, 170);
	//App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1375, 60);

	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1900, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1900, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1910, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1910, 130);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1920, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1920, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1930, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 1930, 130);


	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG, 2000, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG, 2000, 160);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG, 2000, 180);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG, 2000, 200);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG, 2000, 220);



	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG_DOWN, 2220, 20);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG_DOWN, 2220, 0);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG_DOWN, 2220, -20);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG_DOWN, 2220, -40);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG_DOWN, 2220, -60);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG_DOWN, 2220, -80);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG_DOWN, 2220, -10);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG_DOWN, 2220, -120);
	App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG_DOWN, 2220, -140);








	//App->enemies->AddEnemy(ENEMY_TYPES::HELLFIRE, 50, 50);
	//App->enemies->AddEnemy(ENEMY_TYPES::RED_LAMELLA, 50, 25); 
	//App->enemies->AddEnemy(ENEMY_TYPES::RED_LAMELLA, 550, 205);  


	//App->enemies->AddEnemy(ENEMY_TYPES::RED_LAMELLA, 905, 25);
	//App->enemies->AddEnemy(ENEMY_TYPES::RED_LAMELLA, 950, 205);

/*
	App->enemies->AddEnemy(ENEMY_TYPES::RED_LAMELLA, 605, 195);
	App->enemies->AddEnemy(ENEMY_TYPES::RED_LAMELLA, 635, 195);
	App->enemies->AddEnemy(ENEMY_TYPES::RED_LAMELLA, 655, 195);

	


	App->enemies->AddEnemy(ENEMY_TYPES::RED_LAMELLA, 1505, 195);*/

	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 2725, TopTurretPosY + 36);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 2765, TopTurretPosY + 36);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 2805, TopTurretPosY + 36);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 2860, TopTurretPosY + 3);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 2900, TopTurretPosY + 3);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 2940, TopTurretPosY + 3);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 2980, TopTurretPosY + 3);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3020, TopTurretPosY + 3);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3060, TopTurretPosY+3);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3100, TopTurretPosY+3);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3140, TopTurretPosY+3);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3180, TopTurretPosY+3);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3220, TopTurretPosY+3);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3260, TopTurretPosY+3);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3280, TopTurretPosY + 36);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3320, TopTurretPosY + 36);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3360, TopTurretPosY +36);


	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 2725, BottomTurretPosY-31);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 2755, BottomTurretPosY-31);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 2805, BottomTurretPosY-31);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 2860, BottomTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 2900, BottomTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 2940, BottomTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 2980, BottomTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3020, BottomTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3060, BottomTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3100, BottomTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3140, BottomTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3180, BottomTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3220, BottomTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3260, BottomTurretPosY);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3275, BottomTurretPosY-31);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3315, BottomTurretPosY-31);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, 3355, BottomTurretPosY-31);


	// App->enemies->AddEnemy(ENEMY_TYPES::BARREL, 660, TopTurretPosY);

	//App->enemies->AddEnemy(ENEMY_TYPES::JUMPY, 700, 100);
	//App->enemies->AddEnemy(ENEMY_TYPES::RED_LAMELLA, 205, 195);





	//App->enemies->AddEnemy(ENEMY_TYPES::ROCKET, 200, 100);






	//App->enemies->AddEnemy(ENEMY_TYPES::SPIDER_TANK, 200, 20);

	////App->enemies->AddEnemy(ENEMY_TYPES::ROCKET, 200, 100);




	//App->enemies->AddEnemy(ENEMY_TYPES::BOSS, 300, 20);
	////App->enemies->AddEnemy(ENEMY_TYPES::BOSSFIRE, 200, 40);


	




	App->collision->AddCollider({ 750,156,80,68 }, COLLIDER_WALL);
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
	App->collision->AddCollider({ 3368,0,736,19 }, COLLIDER_WALL);				//larg dalt
	App->collision->AddCollider({ 3691,17,65,34 }, COLLIDER_WALL);				//petit dalt
	App->collision->AddCollider({ 4104,140,100,100 }, COLLIDER_WALL);			//cuadrat baix
	App->collision->AddCollider({ 4104,0,96,68 }, COLLIDER_WALL);				//cuadrat dalt
	App->collision->AddCollider({ 4200,187,130,37 }, COLLIDER_WALL);			//llarg baix
	App->collision->AddCollider({ 4200,0,130,19 }, COLLIDER_WALL);				//larg dalt

	App->collision->AddCollider({ 4330,172,65,52 }, COLLIDER_WALL);				//petit baix
	App->collision->AddCollider({ 4843,172,65,52 }, COLLIDER_WALL);				//petit baix
	App->collision->AddCollider({ 4330,0,65,34 }, COLLIDER_WALL);				//petit dalt

	App->collision->AddCollider({ 4395,187,192,37 }, COLLIDER_WALL);			//llarg baix
	App->collision->AddCollider({ 4395,0,192,19 }, COLLIDER_WALL);				//larg dalt

	App->collision->AddCollider({ 4587,172,65,52 }, COLLIDER_WALL);				//petit baix
	App->collision->AddCollider({ 5356,172,65,52 }, COLLIDER_WALL);				//petit baix
	App->collision->AddCollider({ 4587,0,65,19 }, COLLIDER_WALL);				//estret dalt

	App->collision->AddCollider({ 4652,187,192,37 }, COLLIDER_WALL);			//llarg baix
	App->collision->AddCollider({ 4652,0,192,19 }, COLLIDER_WALL);				//larg dalt


	App->collision->AddCollider({ 4844,187,65,52 }, COLLIDER_WALL);				//petit baix
	App->collision->AddCollider({ 5865,172,65,52 }, COLLIDER_WALL);				//petit baix
	App->collision->AddCollider({ 6385,172,65,52 }, COLLIDER_WALL);				//petit baix
	App->collision->AddCollider({ 4844,0,65,34 }, COLLIDER_WALL);				//petit dalt

	App->collision->AddCollider({ 4909,187,192,37 }, COLLIDER_WALL);			//llarg baix
	App->collision->AddCollider({ 4909,0,192,19 }, COLLIDER_WALL);				//larg dalt


	App->collision->AddCollider({ 5101,172,65,52 }, COLLIDER_WALL);				//petit baix
	App->collision->AddCollider({ 5101,0,65,19 }, COLLIDER_WALL);				//estret dalt

	App->collision->AddCollider({ 5166,187,192,37 }, COLLIDER_WALL);			//llarg baix
	App->collision->AddCollider({ 5166,0,192,19 }, COLLIDER_WALL);				//larg dalt


	App->collision->AddCollider({ 5358,187,65,52 }, COLLIDER_WALL);				//petit baix
	App->collision->AddCollider({ 5358,0,65,34 }, COLLIDER_WALL);				//petit dalt

	App->collision->AddCollider({ 5423,187,192,37 }, COLLIDER_WALL);			//llarg baix
	App->collision->AddCollider({ 5423,0,192,19 }, COLLIDER_WALL);				//larg dalt

	App->collision->AddCollider({ 5615,172,65,52 }, COLLIDER_WALL);				//petit baix
	App->collision->AddCollider({ 5615,0,65,19 }, COLLIDER_WALL);				//estret dalt

	App->collision->AddCollider({ 5680,187,192,37 }, COLLIDER_WALL);			//llarg baix
	App->collision->AddCollider({ 5680,0,192,19 }, COLLIDER_WALL);				//larg dalt


	App->collision->AddCollider({ 5872,187,65,52 }, COLLIDER_WALL);				//petit baix
	App->collision->AddCollider({ 5872,0,65,34 }, COLLIDER_WALL);				//petit dalt

	App->collision->AddCollider({ 5937,187,192,37 }, COLLIDER_WALL);			//llarg baix
	App->collision->AddCollider({ 5937,0,192,19 }, COLLIDER_WALL);				//larg dalt

	App->collision->AddCollider({ 6129,172,65,52 }, COLLIDER_WALL);				//petit baix
	App->collision->AddCollider({ 6129,0,65,19 }, COLLIDER_WALL);				//estret dalt

	App->collision->AddCollider({ 6194,187,192,37 }, COLLIDER_WALL);			//llarg baix
	App->collision->AddCollider({ 6194,0,192,19 }, COLLIDER_WALL);				//larg dalt

	App->collision->AddCollider({ 6386,187,65,52 }, COLLIDER_WALL);				//petit baix
	App->collision->AddCollider({ 6386,0,65,34 }, COLLIDER_WALL);				//petit dalt

	App->collision->AddCollider({ 6451,187,192,37 }, COLLIDER_WALL);			//llarg baix
	App->collision->AddCollider({ 6451,0,192,19 }, COLLIDER_WALL);				//larg dalt

	App->collision->AddCollider({ 6643,172,65,52 }, COLLIDER_WALL);				//petit baix
	App->collision->AddCollider({ 6643,0,65,19 }, COLLIDER_WALL);				//estret dalt

	App->collision->AddCollider({ 6708,187,192,37 }, COLLIDER_WALL);			//llarg baix
	App->collision->AddCollider({ 6708,0,192,19 }, COLLIDER_WALL);				//larg dalt


	App->collision->AddCollider({ 6900,187,65,52 }, COLLIDER_WALL);				//petit baix
	App->collision->AddCollider({ 6900,0,65,34 }, COLLIDER_WALL);				//petit dalt

	App->collision->AddCollider({ 6965,187,192,37 }, COLLIDER_WALL);			//llarg baix
	App->collision->AddCollider({ 6965,0,192,19 }, COLLIDER_WALL);				//larg dalt

	App->collision->AddCollider({ 7157,172,65,52 }, COLLIDER_WALL);				//petit baix
	App->collision->AddCollider({ 7157,0,65,19 }, COLLIDER_WALL);				//estret dalt

	App->collision->AddCollider({ 7222,187,192,37 }, COLLIDER_WALL);			//llarg baix
	App->collision->AddCollider({ 7222,0,192,19 }, COLLIDER_WALL);				//larg dalt



	





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
	App->render->Blit(BackgroundLvl2, 0, 0, &background2, 0.1f);						
		
	
		// Rain
	for(int cont = 0; cont <= background2.w * 3; cont+=240)
	App->render->Blit(rain, cont, 0, &rain_anim.GetCurrentFrame(), 1.0f);

		// Foreground
	App->render->Blit(ForegroundLvl2, 2700, 0, &foreground2, 1.0f);
		// Hangars 

	/*App->render->Blit(hangar_texture, 1000, 156, &hangar_body,1.0f);
	App->render->Blit(hangar_2_texture, 300, 0, &hangar_2_body, 1.0f);*/

	App->render->Blit(hangar_texture, 750, 156, &hangar_body, 1.0f);
	App->render->Blit(hangar_texture, 2000, 156, &hangar_body, 1.0f);
	App->render->Blit(hangar_2_texture, 2200, 0, &hangar_2_body, 1.0f);
	App->render->Blit(hangar_texture, 2400, 156, &hangar_body, 1.0f);



		
	

	// Fade to black
	if (App->input->keyboard[SDL_SCANCODE_T] == KEY_STATE::KEY_DOWN) {
		App->player->god_mode = true;
		App->player2->god_mode = true;
		if (App->fade->FadeToBlack(App->background2, App->stageclear, 1.5f))
			App->player2->TwoPlayers = false; 
			App->audio->FadeMus(750);
	}

	if (App->input->keyboard[SDL_SCANCODE_Y] == KEY_STATE::KEY_DOWN) {
		App->player->god_mode = true;
		App->player2->god_mode = true;
		if (App->fade->FadeToBlack(App->background2, App->loseimage, 1.5f))
			App->audio->FadeMus(750);
	}
	if (App->input->keyboard[SDL_SCANCODE_4] == KEY_STATE::KEY_DOWN
		|| App->input->Controller_2[SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_START] == KEY_DOWN) {
		App->player2->Enable();
		App->player2->TwoPlayers = true;
	}


	if (App->player2->TwoPlayers == false) {         // When player 1 is active and dies, ready appears
		if (activ == false) {
			if (App->player->alive_p1 == false) {
				LOG("PLAYER 1 LIVES: %i", App->player->lives);
				if (App->player->lives == 0) {
					
					App->fade->FadeToBlack((Module*)App->background2, (Module*)App->loseimage, 2.5f);
					
				}
				else {
					App->fade->FadeToBlack((Module*)App->background2, (Module*)App->Ready, 1.5f);
				}
			}
		}
	 }
	
	
	else {       // when both players active, they can respawn 
		if (activ == false) {
			LOG("PLAYER 1 LIVES: %i    Player 2 lives: %i, ready to loseimage?????", App->player->lives, App->player2->lives);
		//	if (App->player2->alive_p2 == false && App->player2->alive_p2 == false) {
				if (App->player->lives == 0 && App->player2->lives == 0) {
					App->fade->FadeToBlack((Module*)App->background2, (Module*)App->loseimage, 2.5f);
					App->player2->TwoPlayers = false;
				}
			//}
		}
	}
	


	if (App->render->camera.x == 9000 * SCREEN_SIZE) {
		App->fade->FadeToBlack((Module*)App->background2, (Module*)App->stageclear, 2.5f);
	}



	if (App->input->keyboard[SDL_SCANCODE_KP_1] == KEY_DOWN)
		App->enemies->AddEnemy(ENEMY_TYPES::TURRET, App->render->camera.x + 300, BottomTurretPosY);

	if (App->input->keyboard[SDL_SCANCODE_KP_2] == KEY_DOWN)
		App->enemies->AddEnemy(ENEMY_TYPES::BARREL, App->render->camera.x + 300, 100);

	if (App->input->keyboard[SDL_SCANCODE_KP_3] == KEY_DOWN)
		App->enemies->AddEnemy(ENEMY_TYPES::RED_LAMELLA, App->render->camera.x + 300, 100);

	if (App->input->keyboard[SDL_SCANCODE_KP_4] == KEY_DOWN)
		App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG_DOWN, App->render->camera.x + 300, 0);

	if (App->input->keyboard[SDL_SCANCODE_KP_5] == KEY_DOWN)
		App->enemies->AddEnemy(ENEMY_TYPES::COCKROACH, App->render->camera.x + 300, 100);

	if (App->input->keyboard[SDL_SCANCODE_KP_6] == KEY_DOWN)
		App->enemies->AddEnemy(ENEMY_TYPES::RHINO, App->render->camera.x + 300, 100);

	if (App->input->keyboard[SDL_SCANCODE_KP_7] == KEY_DOWN)
		App->enemies->AddEnemy(ENEMY_TYPES::HUNTER_ZIGZAG, App->render->camera.x + 300, 200);

	if (App->input->keyboard[SDL_SCANCODE_KP_8] == KEY_DOWN)
		App->power->AddPowerup(POWERUP_TYPES::SPOWER, App->render->camera.x + 300, 100);

	if (App->input->keyboard[SDL_SCANCODE_KP_9] == KEY_DOWN)
		App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, App->render->camera.x + 300, 100);

	if (App->input->keyboard[SDL_SCANCODE_KP_9] == KEY_DOWN)
		App->enemies->AddEnemy(ENEMY_TYPES::HUNTER, App->render->camera.x + 300, 100);

	if (App->input->keyboard[SDL_SCANCODE_O] == KEY_DOWN)
		App->enemies->AddEnemy(ENEMY_TYPES::BOSS, App->render->camera.x + 220, SCREEN_HEIGHT/2 - 80);

	if (App->input->keyboard[SDL_SCANCODE_G] == KEY_DOWN)
		App->power->AddPowerup(POWERUP_TYPES::GPOWER, App->render->camera.x + 300, 100);
	
	if (App->input->keyboard[SDL_SCANCODE_X] == KEY_DOWN)
		App->power->AddPowerup(POWERUP_TYPES::LPOWER, App->render->camera.x + 300, 100);

	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_DOWN)
		App->enemies->AddEnemy(ENEMY_TYPES::GUSTAV, App->render->camera.x + 300, 100);

	if (App->input->keyboard[SDL_SCANCODE_U] == KEY_DOWN)
		App->enemies->AddEnemy(ENEMY_TYPES::SPIDER_TANK, App->render->camera.x + 300, 100);

	return UPDATE_CONTINUE;
}
