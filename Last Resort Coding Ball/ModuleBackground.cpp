#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleStageClear.h"
#include "ModuleStartingImage.h"
#include "ModuleLoseImage.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleBall.h"
#include "SDL/include/SDL_timer.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{
	// Parallax levels
	
	depth_1 = 0.4875;			// Original 0.224	(60%)
	depth_2 = 0.26;				// Original 0.4		(60%)
	depth_3 = 0.1456;			// Original 0.75	(60%)
		
	// Background
	background.x = 0;
	background.y = 0;
	background.w = 4408;
	background.h = 239;

	// Crater 
	crater.x = 0;
	crater.y = 0; 
	crater.w = 327;
	crater.h = 239;

	// 1st Level Building
	building_1.x = 0;
	building_1.y = 290;
	building_1.w = 1530;
	building_1.h = 163;

	building_2.x = 839;
	building_2.y = 0;
	building_2.w = 803; 
	building_2.h = 160; 

	DeepBackgroundLights.PushBack({ 0,0,240,94 });
	DeepBackgroundLights.PushBack({ 240,0,240,94 });
	DeepBackgroundLights.PushBack({ 480,0,240,94 });
	DeepBackgroundLights.PushBack({ 720,0,240,94 });
	DeepBackgroundLights.PushBack({ 0,94,240,92 });
	DeepBackgroundLights.PushBack({ 240,94,240,92 });
	DeepBackgroundLights.PushBack({ 480,94,240,92 });
	DeepBackgroundLights.PushBack({ 720,94,240,92 });
	DeepBackgroundLights.speed = 0.06f;

	DeepBackgroundLights2.PushBack({ 0,187,249,112 });
	DeepBackgroundLights2.PushBack({ 249,187,249,112 });
	DeepBackgroundLights2.PushBack({ 498,187,249,112 });
	DeepBackgroundLights2.PushBack({ 747,187,249,112 });
	DeepBackgroundLights2.PushBack({ 0,299,249,112 });
	DeepBackgroundLights2.PushBack({ 249,299,249,112 });
	DeepBackgroundLights2.PushBack({ 498,299,249,112 });
	DeepBackgroundLights2.PushBack({ 747,299,249,112 });
	DeepBackgroundLights2.speed = 0.1f;

	MidBackgroundLights.PushBack({ 0,0,275,125});
	MidBackgroundLights.PushBack({ 275,0,275,125 });
	MidBackgroundLights.PushBack({ 550,0,275,125 });
	MidBackgroundLights.PushBack({ 825,0,275,125 });
	MidBackgroundLights.PushBack({ 0,125,275,125 });
	MidBackgroundLights.PushBack({ 275,125,275,125 });
	MidBackgroundLights.PushBack({ 550,125,275,125 });
	MidBackgroundLights.PushBack({ 825,125,275,125 });
	MidBackgroundLights.speed = 0.05f;

	MidBackgroundLights2.PushBack({ 0,250,227,107});
	MidBackgroundLights2.PushBack({ 227,250,227,107 });
	MidBackgroundLights2.PushBack({ 454,250,227,107 });
	MidBackgroundLights2.PushBack({ 681,250,227,107 });
	MidBackgroundLights2.PushBack({ 0,357,227,107 });
	MidBackgroundLights2.PushBack({ 227,357,227,107 });
	MidBackgroundLights2.PushBack({ 454,357,227,107 });
	MidBackgroundLights2.PushBack({ 681,357,227,107 });
	MidBackgroundLights2.speed = 0.06f;

	MidBackgroundLights3.PushBack({ 0,0,17,120 });
	MidBackgroundLights3.PushBack({ 17,0,17,120 });
	MidBackgroundLights3.PushBack({ 34,0,17,120 });
	MidBackgroundLights3.PushBack({ 51,0,17,120 });
	MidBackgroundLights3.PushBack({ 68,0,17,120 });
	MidBackgroundLights3.speed = 0.07f;

	light.PushBack({ 327,0,67,79 });
	light.PushBack({ 388,0,67,79 });
	light.PushBack({ 449,0,67,79 });
	light.PushBack({ 510,0,67,70 });
	light.PushBack({ 571,0,67,70 });
	light.PushBack({ 510,0,67,70 });
	light.PushBack({ 449,0,67,79 });
	light.PushBack({ 388,0,67,79 });
	light.speed = 0.041f;

	lightNew.PushBack({ 327,79,67,113 });
	lightNew.PushBack({ 388,79,67,114 });
	lightNew.PushBack({ 449,79,67,117 });
	lightNew.PushBack({ 510,79,67,105 });
	lightNew.PushBack({ 571,79,67,105 });
	lightNew.PushBack({ 510,79,67,105 });
	lightNew.PushBack({ 449,79,67,117 });
	lightNew.PushBack({ 388,79,67,114 });
	lightNew.speed = 0.1231f;

	streetLights.PushBack({ 0,21,50,65 });
	streetLights.PushBack({ 51,21,50,65 });
	streetLights.PushBack({ 102,21,50,65 });
	streetLights.PushBack({ 153,21,50,65 });
	streetLights.PushBack({ 204,21,50,65 });
	streetLights.PushBack({ 153,21,50,65 });
	streetLights.PushBack({ 102,21,50,65 });
	streetLights.PushBack({ 51,21,50,65 });
	streetLights.speed = 0.015f;


	streetLights_2.PushBack({ 204,21,50,65 });
	streetLights_2.PushBack({ 153,21,50,65 });
	streetLights_2.PushBack({ 102,21,50,65 });
	streetLights_2.PushBack({ 51,21,50,65 });
	streetLights_2.PushBack({ 0,21,50,65 });
	streetLights_2.PushBack({ 51,21,50,65 });
	streetLights_2.PushBack({ 102,21,50,65 });
	streetLights_2.PushBack({ 153,21,50,65 });
	streetLights_2.speed = 0.015f; 

	lightFloor.PushBack({ 0,0,60,20 });
	lightFloor.PushBack({ 61,0,60,20 });
	lightFloor.PushBack({ 122,0,60,20 });
	lightFloor.PushBack({ 183,0,60,20 });
	lightFloor.PushBack({ 122,0,60,20 });
	lightFloor.PushBack({ 61,0,60,20 });
	lightFloor.speed = 0.02f;

	lightFloor_2.PushBack({ 183,0,60,20 });
	lightFloor_2.PushBack({ 122,0,60,20 });
	lightFloor_2.PushBack({ 61,0,60,20 });
	lightFloor_2.PushBack({ 0,0,60,20 });
	lightFloor_2.PushBack({ 61,0,60,20 });
	lightFloor_2.PushBack({ 122,0,60,20 });
	lightFloor_2.speed = 0.02f; 


	tunnelLights.PushBack({ 0,0,137,161});
	tunnelLights.PushBack({ 138,0,137,161 });
	tunnelLights.PushBack({ 276,0,137,161 });
	tunnelLights.PushBack({ 414,0,137,161 });
	tunnelLights.PushBack({ 276,0,137,161 });
	tunnelLights.PushBack({ 138,0,137,161 });
	tunnelLights.speed = 0.03f;


	tunnelLights_2.PushBack({ 414,0,137,161 });
	tunnelLights_2.PushBack({ 276,0,137,161 });
	tunnelLights_2.PushBack({ 138,0,137,161 });	
	tunnelLights_2.PushBack({ 0,0,137,161 });
	tunnelLights_2.PushBack({ 138,0,137,161 });
	tunnelLights_2.PushBack({ 276,0,137,161 });
	tunnelLights_2.speed = 0.025f;

	backgroundLights.PushBack({ 0,595,284,142 });
	backgroundLights.PushBack({ 0,595,284,142 });
	backgroundLights.PushBack({ 0,595,284,142 });
	backgroundLights.PushBack({ 284,595,284,142 });
	backgroundLights.PushBack({ 284,595,284,142 });
	backgroundLights.PushBack({ 284,595,284,142 });
	backgroundLights.PushBack({ 568,595,284,142 });
	backgroundLights.PushBack({ 568,595,284,142 });
	backgroundLights.PushBack({ 852,595,284,142 });
	backgroundLights.PushBack({ 852,595,284,142 });
	backgroundLights.PushBack({ 1136,595,284,142 });
	backgroundLights.PushBack({ 1420,595,284,142 });
	backgroundLights.PushBack({ 1704,595,284,142 });
	backgroundLights.PushBack({ 1704,451,284,142 });
	backgroundLights.PushBack({ 1704,309,284,142 });
	backgroundLights.PushBack({ 0,748,284,142 });
	backgroundLights.PushBack({ 284,748,284,142 });
	backgroundLights.PushBack({ 568,748,284,142 });
	backgroundLights.PushBack({ 568,748,284,142 });
	backgroundLights.PushBack({ 852,748,284,142 });
	backgroundLights.PushBack({ 852,748,284,142 });
	backgroundLights.PushBack({ 1136,748,284,142 });
	backgroundLights.PushBack({ 1136,748,284,142 });
	backgroundLights.PushBack({ 1136,748,284,142 });
    backgroundLights.PushBack({ 1420,748,284,142 });
	backgroundLights.PushBack({ 1420,748,284,142 });
	backgroundLights.PushBack({ 1420,748,284,142 });
	backgroundLights.PushBack({ 1704,748,284,142 });
	backgroundLights.PushBack({ 1420,748,284,142 }); 
	backgroundLights.PushBack({ 1420,748,284,142 });
	backgroundLights.PushBack({ 1420,748,284,142 });
	backgroundLights.PushBack({ 1136,748,284,142 });
	backgroundLights.PushBack({ 1136,748,284,142 });
	backgroundLights.PushBack({ 1136,748,284,142 });
	backgroundLights.PushBack({ 852,748,284,142 });
	backgroundLights.PushBack({ 852,748,284,142 });
	backgroundLights.PushBack({ 568,748,284,142 });
	backgroundLights.PushBack({ 568,748,284,142 });
	backgroundLights.PushBack({ 284,748,284,142 });
	backgroundLights.PushBack({ 0,748,284,142 });
	backgroundLights.PushBack({ 1704,309,284,142 });
	backgroundLights.PushBack({ 1704,451,284,142 });
	backgroundLights.PushBack({ 1704,595,284,142 });
	backgroundLights.PushBack({ 1420,595,284,142 });
	backgroundLights.PushBack({ 1136,595,284,142 });
	backgroundLights.PushBack({ 852,595,284,142 });
	backgroundLights.PushBack({ 852,595,284,142 });
	backgroundLights.PushBack({ 568,595,284,142 });
	backgroundLights.PushBack({ 568,595,284,142 });
	backgroundLights.PushBack({ 284,595,284,142 });
	backgroundLights.PushBack({ 284,595,284,142 });
	backgroundLights.PushBack({ 284,595,284,142 });
	backgroundLights.PushBack({ 0,595,284,142 });
	backgroundLights.PushBack({ 0,595,284,142 });
	backgroundLights.speed = 0.82f;

	
	ships.PushBack({ 0,0,8,3 });
	ships.PushBack({ 15,0,8,4 });
	ships.PushBack({ 30,0,8,4 });
	ships.PushBack({ 15,0,8,4 });
	ships.PushBack({ 0,0,8,3 });
	ships.speed = 0.01f;
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");

	bool ret = true;	

	App->player->Enable();
	App->particles->Enable(); 	
	App->collision->Enable();
	App->ball->Enable(); 

	//graphics = App->textures->Load("backgroundlvl1v2.png");
	BackgroundLvl1 = App->textures->Load("assets/sprites/background_lvl1.png");
	BackgroundLvl1_extra = App->textures->Load("assets/sprites/background_lvl1_extra.png");
	StreetLightsTex = App->textures->Load("assets/sprites/StreetLights_lvl1.png");
	TunnelLightsTex = App->textures->Load("assets/sprites/tunnelLights.png");
	BackgroundSpaceshipLvl1 = App->textures->Load("assets/sprites/backspaceship_lvl101.png");
	BackLights = App->textures->Load("assets/sprites/DeepBackgroundLights.png");
	BackLights2 = App->textures->Load("assets/sprites/MidBackgroundLights.png");
	BackLights3 = App->textures->Load("assets/sprites/MidBackgroundLightsExtra.png");
	CommonEnemies = App->textures->Load("assets/sprites/CommonEnemies1.png");
	
	//Enemies	
	App->enemies->AddEnemy(ENEMY_TYPES::COCKROACH, 300, 112);

	mus = App->audio->LoadMus("assets/SFX/level_1.ogg");
	App->audio->PlayMus(mus);
	background_spaceship_posx = -200;

	return ret;
}

bool ModuleBackground::CleanUp()
{
	LOG("Cleaning Up background");
	//Disable Other Modules
	App->player->Disable(); 
	App->particles->Disable(); 
	App->ball->Disable();

	//Free all loaded textures
	App->textures->Unload(BackgroundLvl1);
	App->textures->Unload(BackgroundLvl1_extra);
	App->textures->Unload(StreetLightsTex);
	App->textures->Unload(TunnelLightsTex);
	App->textures->Unload(BackgroundSpaceshipLvl1);
	App->textures->Unload(BackLights);
	App->textures->Unload(BackLights2);
	App->textures->Unload(BackLights3);
	App->textures->Unload(CommonEnemies);

	//Free all audio material
	App->audio->UnloadMus(mus); 

	//Free Collision

	App->collision->Disable();
	return true;
}


void ModuleBackground::CameraUpDown()
{
	int  scrolltime = 190; int waittime = 443;
	CameraOscillation(100, 190, false);
	CameraOscillation(190 + waittime, 190 + waittime + scrolltime, true);
	CameraOscillation(190 + waittime * 2 + scrolltime, 190 + waittime * 2 + scrolltime * 2, false);
	CameraOscillation(190 + waittime * 3 + scrolltime * 2, 190 + waittime * 3 + scrolltime * 3, true);
	CameraOscillation(190 + waittime * 4 + scrolltime * 3, 190 + waittime * 4 + scrolltime * 4, false);
	CameraOscillation(190 + waittime * 5 + scrolltime * 4, 190 + waittime * 5 + scrolltime * 5, true);
	CameraOscillation(190 + waittime * 6 + scrolltime * 5, 190 + waittime * 6 + scrolltime * 6, false);
	CameraOscillation(190 + waittime * 7 + scrolltime * 6, 190 + waittime * 7 + scrolltime * 7, true);
	CameraOscillation(190 + waittime * 8 + scrolltime * 7, 190 + waittime * 8 + scrolltime * 8, false);
	CameraOscillation(190 + waittime * 9 + scrolltime * 8, 190 + waittime * 9 + scrolltime * 9, true);
	CameraOscillation(190 + waittime * 10 + scrolltime * 9, 190 + waittime * 10 + scrolltime * 10, false);
	CameraOscillation(190 + waittime * 11 + scrolltime * 10, 190 + waittime * 11 + scrolltime * 11, true);
	CameraOscillation(190 + waittime * 12 + scrolltime * 11, 190 + waittime * 12 + scrolltime * 11 + 100, false);
}

void ModuleBackground::MoveUp()
{
	App->render->camera.y += 3;
	App->player->position.y -= 1;
	downscroll = false; 
}

void ModuleBackground::MoveDown()
{
	App->render->camera.y -= 3;
	App->player->position.y += 1;
	downscroll = true; 
}
void ModuleBackground::CameraOscillation(int since, int to, bool up)
{
	if (App->render->camera.x >= -to && App->render->camera.x <= -since)
	{
		if (up) MoveUp();
		if (!up) MoveDown(); 
	}
	
}

void ModuleBackground::RenderCrater()
{
	if (App->render->camera.x <= -7500 * SCREEN_SIZE)
		App->render->Blit(BackgroundLvl1_extra, craterx, cratery, &crater, 0);
}

void ModuleBackground::RenderBackgroundSpaceships()
{
	if (App->render->camera.x >= -4000 * SCREEN_SIZE) {
		background_spaceship_posx += 1.46;
		
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx, 90 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 50, 100 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 50, 140 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 100, 90 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 170, 60 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 210, 60 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 230, 140 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 250, 60 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 290, 60 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 330, 60 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 370, 140 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 410, 140 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 450, 140 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 490, 140 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 530, 140 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 540, 120 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 590, 70 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 590, 140 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 640, 140 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 640, 90 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 660, 70 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 680, 80 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 740, 70 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 780, 70 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 820, 70 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 860, 70 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 900, 70 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 740, 130 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 780, 130 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 820, 130 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 860, 130 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 900, 130 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 1600, 60 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 1640, 80 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 1680, 100 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 1720, 120 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 1740, 130 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 1780, 130 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 1820, 130 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 1860, 130 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 1900, 130 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3000, 80 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3040, 50 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3040, 75 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3040, 100 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3090, 60 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3090, 75 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3090, 90 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3140, 60 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3140, 90 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3340, 120 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3380, 100 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3420, 80 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3460, 60 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3480, 50 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3520, 50 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3560, 50 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3600, 50 - 10, &ships.GetCurrentFrame(), depth_2);
		App->render->Blit(BackgroundSpaceshipLvl1, background_spaceship_posx - 3640, 50 - 10, &ships.GetCurrentFrame(), depth_2);
	}
}

void ModuleBackground::RenderDeepBuildingLights()
{
	//TOP - BOT (+62 Y)

	App->render->Blit(BackLights, 312, -10, &DeepBackgroundLights2.GetCurrentFrame(), depth_3);
	App->render->Blit(BackLights, 56, -10, &DeepBackgroundLights.GetCurrentFrame(), depth_3);
	App->render->Blit(BackLights, 857, -10, &DeepBackgroundLights2.GetCurrentFrame(), depth_3);
	App->render->Blit(BackLights, 568, -10, &DeepBackgroundLights.GetCurrentFrame(), depth_3);

}

void ModuleBackground::RenderBuildingLights()
{
	App->render->Blit(BackLights2, 32, 52, &MidBackgroundLights.GetCurrentFrame(), depth_2);
	App->render->Blit(BackLights2, 544, 52, &MidBackgroundLights.GetCurrentFrame(), depth_2);
	App->render->Blit(BackLights2, 305, 70, &MidBackgroundLights2.GetCurrentFrame(), depth_2);
	App->render->Blit(BackLights2, 817, 70, &MidBackgroundLights2.GetCurrentFrame(), depth_2);
	App->render->Blit(BackLights3, 328, 34, &MidBackgroundLights3.GetCurrentFrame(), depth_2);
}

void ModuleBackground::RenderDiscoLights()
{
	App->render->Blit(BackgroundLvl1_extra, 171, -19, &light.GetCurrentFrame(), depth_2);
	App->render->Blit(BackgroundLvl1_extra, 683, -19, &light.GetCurrentFrame(), depth_2);
	App->render->Blit(BackgroundLvl1_extra, 752, -22, &lightNew.GetCurrentFrame(), depth_2);
	App->render->Blit(BackgroundLvl1_extra, 827, -35, &light.GetCurrentFrame(), depth_2);

	if (!render_light) {
		App->render->Blit(BackgroundLvl1_extra, 250, -10, &backgroundLights.GetCurrentFrame(), depth_3);
		render_light = true;
	}
	else render_light = false;
}

void ModuleBackground::RenderStreetLights()
{	
	// 1
	// 1 2 2 1 1 
	// 2 1 2 1 2 
	// 2 1 2 2 1 
	// 2 1 1 2 1 
	// 2 2 1 2 1 
	// 2 1 don't delete yet (+64)

	App->render->Blit(StreetLightsTex, 39, 136, &streetLights.GetCurrentFrame(), depth_1);

	App->render->Blit(StreetLightsTex, 103, 136, &streetLights.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 167, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 231, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 295, 136, &streetLights.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 359, 136, &streetLights.GetCurrentFrame(), depth_1);

	App->render->Blit(StreetLightsTex, 423, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 487, 136, &streetLights.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 551, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 615, 136, &streetLights.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 679, 136, &streetLights_2.GetCurrentFrame(), depth_1);

	App->render->Blit(StreetLightsTex, 743, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 807, 136, &streetLights.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 871, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 935, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 999, 136, &streetLights.GetCurrentFrame(), depth_1);

	App->render->Blit(StreetLightsTex, 1063, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 1127, 136, &streetLights.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 1191, 136, &streetLights.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 1255, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 1319, 136, &streetLights.GetCurrentFrame(), depth_1);

	App->render->Blit(StreetLightsTex, 1383, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 1447, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 1511, 136, &streetLights.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 1575, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 1639, 136, &streetLights.GetCurrentFrame(), depth_1);

	App->render->Blit(StreetLightsTex, 1703, 136, &streetLights_2.GetCurrentFrame(), depth_1);

	//	BOTTOM PART
	
	// 1 2 2 1 1 
	// 2 1 2 1 2 
	// 2 1 2 2 1 (+128)

	App->render->Blit(StreetLightsTex, 121, 217, &lightFloor.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 249, 217, &lightFloor_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 377, 217, &lightFloor_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 505, 217, &lightFloor.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 633, 217, &lightFloor.GetCurrentFrame(), depth_1);

	App->render->Blit(StreetLightsTex, 761, 217, &lightFloor_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 889, 217, &lightFloor.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 1017, 217, &lightFloor_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 1145, 217, &lightFloor.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 1273, 217, &lightFloor_2.GetCurrentFrame(), depth_1);

	App->render->Blit(StreetLightsTex, 1401, 217, &lightFloor_2.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 1529, 217, &lightFloor.GetCurrentFrame(), depth_1);
	App->render->Blit(StreetLightsTex, 1657, 217, &lightFloor_2.GetCurrentFrame(), depth_1);
}


void ModuleBackground::RenderTunnelLights()
{
	App->render->Blit(TunnelLightsTex, 2051, 0, &tunnelLights.GetCurrentFrame(), depth_1);
	App->render->Blit(TunnelLightsTex, 2308, 0, &tunnelLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(TunnelLightsTex, 2565, 0, &tunnelLights.GetCurrentFrame(), depth_1);
	App->render->Blit(TunnelLightsTex, 2822, 0, &tunnelLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(TunnelLightsTex, 3079, 0, &tunnelLights.GetCurrentFrame(), depth_1);
	App->render->Blit(TunnelLightsTex, 3336, 0, &tunnelLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(TunnelLightsTex, 3593, 0, &tunnelLights.GetCurrentFrame(), depth_1);
	App->render->Blit(TunnelLightsTex, 3850, 0, &tunnelLights_2.GetCurrentFrame(), depth_1);
}

// Update: draw background
update_status ModuleBackground::Update()
{
    int scroll_speed = 3; 

	// Camera Movement Conditions
	falscamara -= scroll_speed;

	if (scroll) {
		App->render->camera.x -= scroll_speed;
	}

	if (App->render->camera.x <= -9100 * SCREEN_SIZE)
		scroll = false; 

	// Up and down Conditions 
	CameraUpDown();

	// Draw everything --------------------------------------
	
	RenderCrater();
	App->render->Blit(BackgroundLvl1_extra, 0, -5, &building_2, depth_3);										// DEPTH 3
	
	
	RenderDeepBuildingLights();
	RenderDiscoLights(); 
	RenderBackgroundSpaceships(); 
	
	
	App->render->Blit(BackgroundLvl1_extra, 0, 35, &building_1, depth_2);										// DEPTH 2
	

	RenderBuildingLights();


	App->render->Blit(BackgroundLvl1, 0, 0, &background, depth_1);										// DEPTH 1
	

	RenderStreetLights(); 
	RenderTunnelLights();
	

	// Fade to black
	if (App->input->keyboard[SDL_SCANCODE_F2] == 1)
		if(App->fade->FadeToBlack(App->background, App->stageclear, 1.5f))
			App->audio->FadeMus(750);

	if (App->input->keyboard[SDL_SCANCODE_F3] == 1) 
		if (App->fade->FadeToBlack(App->background, App->loseimage, 1.5f))
			App->audio->FadeMus(750);

	return UPDATE_CONTINUE;
}
