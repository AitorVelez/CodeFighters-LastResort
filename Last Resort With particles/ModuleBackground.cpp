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
	ships.speed = 0.01f;

	EnemyTest.PushBack({ 9,443,32,16 });
	EnemyTest.PushBack({ 9,459,32,15 });
	EnemyTest.PushBack({ 9,474,32,15 });
	EnemyTest.PushBack({ 9,490,32,15 });
	EnemyTest.speed = 0.2f;
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
	//graphics = App->textures->Load("backgroundlvl1v2.png");
	graphics = App->textures->Load("assets/sprites/background_lvl1.png");
	graphics2 = App->textures->Load("assets/sprites/background_lvl1_extra.png");
	graphics3 = App->textures->Load("assets/sprites/StreetLights_lvl1.png");
	graphics4 = App->textures->Load("assets/sprites/tunnelLights.png");
	graphics5 = App->textures->Load("assets/sprites/backspaceship_lvl101.png");
	graphics6 = App->textures->Load("assets/sprites/DeepBackgroundLights.png");
	graphics7 = App->textures->Load("assets/sprites/MidBackgroundLights.png");
	graphics8 = App->textures->Load("assets/sprites/MidBackgroundLightsExtra.png");
	graphics9 = App->textures->Load("assets/sprites/CommonEnemies1.png");
	

	App->player->Enable();

	mus = App->audio->LoadMus("assets/SFX/level_1.ogg");
	App->audio->PlayMus(mus);
	App->collision->Enable();

	return ret;
}

bool ModuleBackground::CleanUp()
{
	LOG("Cleaning Up background");
	//Disable Other Modules
	App->player->Disable(); 
	App->particles->Disable(); 
	//Free all loaded textures
	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);
	App->textures->Unload(graphics3);
	App->textures->Unload(graphics4);
	App->textures->Unload(graphics5);
	App->textures->Unload(graphics6);
	App->textures->Unload(graphics7);
	App->textures->Unload(graphics8);
	App->textures->Unload(graphics9);

	//Free all audio material
	App->audio->UnloadMus(mus); 

	//Free Collision

	App->collision->Disable();
	return true;
}


void ModuleBackground::MoveUp()
{
	App->render->camera.y += 3;
	App->player->position.y -= 1;
}
 

void ModuleBackground::MoveCameraUp()
{
	int intensity = 15; 
	App->render->camera.y += intensity;
	intensity += 10; 
}

void ModuleBackground::MoveDown()
{
	App->render->camera.y -= 3;
	App->player->position.y += 1;
}

void ModuleBackground::MoveCameraDown()
{
	int intensity = 15;
	App->render->camera.y -= intensity;
	intensity += 10;
}

void ModuleBackground::CameraOscillation(int since, int to, bool up)
{
	if (App->render->camera.x >= -to && App->render->camera.x <= -since)
	{
		if (up) MoveUp();
		if (!up) MoveDown(); 
	}
	
}

void ModuleBackground::CameraOscillationShake(int since, int to, bool up) {
	if (App->render->camera.x >= -to && App->render->camera.x <= -since)
	{
		if (up) MoveCameraUp();
		if (!up) MoveCameraDown();
	}
}

void ModuleBackground::RenderCrater()
{
	if (App->render->camera.x <= -7500 * SCREEN_SIZE)
		App->render->Blit(graphics2, 0, 0, &crater, 0.f);
}

void ModuleBackground::RenderBackgroundSpaceships()
{
	if (App->render->camera.x >= -4000 * SCREEN_SIZE) {
		posx += 2;
		App->render->Blit(graphics5, posx, 50, &ships.GetCurrentFrame(), 0);
		App->render->Blit(graphics5, posx - 50, 50, &ships.GetCurrentFrame(), 0);
		App->render->Blit(graphics5, posx - 100, 50, &ships.GetCurrentFrame(), 0);
		App->render->Blit(graphics5, posx - 300, 40, &ships.GetCurrentFrame(), 0);
		App->render->Blit(graphics5, posx - 350, 40, &ships.GetCurrentFrame(), 0);
		App->render->Blit(graphics5, posx - 400, 40, &ships.GetCurrentFrame(), 0);
		App->render->Blit(graphics5, posx - 650, 60, &ships.GetCurrentFrame(), 0);
		App->render->Blit(graphics5, posx - 700, 60, &ships.GetCurrentFrame(), 0);
		App->render->Blit(graphics5, posx - 750, 60, &ships.GetCurrentFrame(), 0);
	}
}

void ModuleBackground::RenderEnemyTest() 
{
	App->render->Blit(graphics9,250, 50, &EnemyTest.GetCurrentFrame(), 0);
}

void ModuleBackground::RenderDeepBuildingLights()
{
	//TOP - BOT (+62 Y)

	App->render->Blit(graphics6, 312, -10, &DeepBackgroundLights2.GetCurrentFrame(), depth_3);
	App->render->Blit(graphics6, 56, -10, &DeepBackgroundLights.GetCurrentFrame(), depth_3);
	App->render->Blit(graphics6, 857, -10, &DeepBackgroundLights2.GetCurrentFrame(), depth_3);
	App->render->Blit(graphics6, 568, -10, &DeepBackgroundLights.GetCurrentFrame(), depth_3);

}

void ModuleBackground::RenderBuildingLights()
{
	App->render->Blit(graphics7, 32, 52, &MidBackgroundLights.GetCurrentFrame(), depth_2);
	App->render->Blit(graphics7, 544, 52, &MidBackgroundLights.GetCurrentFrame(), depth_2);
	App->render->Blit(graphics7, 305, 70, &MidBackgroundLights2.GetCurrentFrame(), depth_2);
	App->render->Blit(graphics7, 817, 70, &MidBackgroundLights2.GetCurrentFrame(), depth_2);
	App->render->Blit(graphics8, 328, 34, &MidBackgroundLights3.GetCurrentFrame(), depth_2);
}

void ModuleBackground::RenderDiscoLights()
{
	App->render->Blit(graphics2, 171, -19, &light.GetCurrentFrame(), depth_2);
	App->render->Blit(graphics2, 683, -19, &light.GetCurrentFrame(), depth_2);
	App->render->Blit(graphics2, 752, -22, &lightNew.GetCurrentFrame(), depth_2);
	App->render->Blit(graphics2, 827, -35, &light.GetCurrentFrame(), depth_2);

	if (!render_light) {
		App->render->Blit(graphics2, 250, -10, &backgroundLights.GetCurrentFrame(), depth_3);
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

	App->render->Blit(graphics3, 39, 136, &streetLights.GetCurrentFrame(), depth_1);

	App->render->Blit(graphics3, 103, 136, &streetLights.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 167, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 231, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 295, 136, &streetLights.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 359, 136, &streetLights.GetCurrentFrame(), depth_1);

	App->render->Blit(graphics3, 423, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 487, 136, &streetLights.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 551, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 615, 136, &streetLights.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 679, 136, &streetLights_2.GetCurrentFrame(), depth_1);

	App->render->Blit(graphics3, 743, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 807, 136, &streetLights.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 871, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 935, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 999, 136, &streetLights.GetCurrentFrame(), depth_1);

	App->render->Blit(graphics3, 1063, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 1127, 136, &streetLights.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 1191, 136, &streetLights.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 1255, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 1319, 136, &streetLights.GetCurrentFrame(), depth_1);

	App->render->Blit(graphics3, 1383, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 1447, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 1511, 136, &streetLights.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 1575, 136, &streetLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 1639, 136, &streetLights.GetCurrentFrame(), depth_1);

	App->render->Blit(graphics3, 1703, 136, &streetLights_2.GetCurrentFrame(), depth_1);

	//	BOTTOM PART
	
	// 1 2 2 1 1 
	// 2 1 2 1 2 
	// 2 1 2 2 1 (+128)

	App->render->Blit(graphics3, 121, 217, &lightFloor.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 249, 217, &lightFloor_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 377, 217, &lightFloor_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 505, 217, &lightFloor.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 633, 217, &lightFloor.GetCurrentFrame(), depth_1);

	App->render->Blit(graphics3, 761, 217, &lightFloor_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 889, 217, &lightFloor.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 1017, 217, &lightFloor_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 1145, 217, &lightFloor.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 1273, 217, &lightFloor_2.GetCurrentFrame(), depth_1);

	App->render->Blit(graphics3, 1401, 217, &lightFloor_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 1529, 217, &lightFloor.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics3, 1657, 217, &lightFloor_2.GetCurrentFrame(), depth_1);
}

void ModuleBackground::RenderTunnelLights()
{
	App->render->Blit(graphics4, 2051, 0, &tunnelLights.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics4, 2308, 0, &tunnelLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics4, 2565, 0, &tunnelLights.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics4, 2822, 0, &tunnelLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics4, 3079, 0, &tunnelLights.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics4, 3336, 0, &tunnelLights_2.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics4, 3593, 0, &tunnelLights.GetCurrentFrame(), depth_1);
	App->render->Blit(graphics4, 3850, 0, &tunnelLights_2.GetCurrentFrame(), depth_1);
}


// Update: draw background
update_status ModuleBackground::Update()
{
    int scroll_speed = 3; 

	// Camera Movement Conditions
	if (scroll) {
		App->render->camera.x -= scroll_speed;
	}

	if (App->render->camera.x <= -9100 * SCREEN_SIZE)
		scroll = false; 

			// Up and down Conditions 
	int  scrolltime = 190; int waittime = 443; 
	CameraOscillation(100, 190, false);
	CameraOscillation(190+ waittime, 190 + waittime + scrolltime, true);
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
	CameraOscillation(190 + waittime * 12 + scrolltime * 11, 190 + waittime * 12 + scrolltime *11 + 100, false);

	                     // End shake 
	
	/*int  scrolltime2 = 10; int start = 9100 * SCREEN_SIZE;
	
	CameraOscillationShake(start + scrolltime2, start + scrolltime2 * 2, true);
	CameraOscillationShake(start + scrolltime2 * 2, start + scrolltime2 * 3, false);
	CameraOscillationShake(start + scrolltime2 * 3, start + scrolltime2 * 4, true);
	CameraOscillationShake(start + scrolltime2 * 4, start + scrolltime2 * 5, false);
	CameraOscillationShake(start + scrolltime2 * 5, start + scrolltime2 * 6, true);
	CameraOscillationShake(start + scrolltime2 * 6, start + scrolltime2 * 7, false);
	CameraOscillationShake(start + scrolltime2 * 7, start + scrolltime2 * 8, true);
	CameraOscillationShake(start + scrolltime2 * 8, start + scrolltime2 * 9, false);
	CameraOscillationShake(start + scrolltime2 * 9, start + scrolltime2 * 10, true);
	CameraOscillationShake(start + scrolltime2 * 10, start + scrolltime2 * 11, false);
	CameraOscillationShake(start + scrolltime2 * 11, start + scrolltime2 * 12, true);
	CameraOscillationShake(start + scrolltime2 * 12, start + scrolltime2 * 13, false);
	CameraOscillationShake(start + scrolltime2 * 13, start + scrolltime2 * 14, true);
	CameraOscillationShake(start + scrolltime2 * 14, start + scrolltime2 * 15, false);
	CameraOscillationShake(start + scrolltime2 * 15, start + scrolltime2 * 16, true);
	CameraOscillationShake(start + scrolltime2 * 16, start + scrolltime2 * 17, false);
	CameraOscillationShake(start + scrolltime2 * 17, start + scrolltime2 * 18, true);
	CameraOscillationShake(start + scrolltime2 * 18, start + scrolltime2 * 19, false);
	CameraOscillationShake(start + scrolltime2 * 19, start + scrolltime2 * 20, true);
	CameraOscillationShake(start + scrolltime2 * 20, start + scrolltime2 * 21, false);
	CameraOscillationShake(start + scrolltime2 * 21, start + scrolltime2 * 22, true);
	CameraOscillationShake(start + scrolltime2 * 22, start + scrolltime2 * 23, false);
	CameraOscillationShake(start + scrolltime2 * 23, start + scrolltime2 * 24, true);
	CameraOscillationShake(start + scrolltime2 * 24, start + scrolltime2 * 25, false);
	CameraOscillationShake(start + scrolltime2 * 25, start + scrolltime2 * 26, true);
	CameraOscillationShake(start + scrolltime2 * 26, start + scrolltime2 * 27, false);
	CameraOscillationShake(start + scrolltime2 * 27, start + scrolltime2 * 28, true);
	CameraOscillationShake(start + scrolltime2 * 28, start + scrolltime2 * 29, false);
	CameraOscillationShake(start + scrolltime2 * 29, start + scrolltime2 * 30, true);
	CameraOscillationShake(start + scrolltime2 * 30, start + scrolltime2 * 31, false);
	CameraOscillationShake(start + scrolltime2 * 31, start + scrolltime2 * 32, true);
	CameraOscillationShake(start + scrolltime2 * 32, start + scrolltime2 * 33, false);
	CameraOscillationShake(start + scrolltime2 * 33, start + scrolltime2 * 34, true);
	CameraOscillationShake(start + scrolltime2 * 34, start + scrolltime2 * 35, false);
	CameraOscillationShake(start + scrolltime2 * 35, start + scrolltime2 * 36, true);
	CameraOscillationShake(start + scrolltime2 * 36, start + scrolltime2 * 37, false);
	CameraOscillationShake(start + scrolltime2 * 37, start + scrolltime2 * 38, true);
	CameraOscillationShake(start + scrolltime2 * 38, start + scrolltime2 * 39, false);
	CameraOscillationShake(start + scrolltime2 * 39, start + scrolltime2 * 40, true);
	CameraOscillationShake(start + scrolltime2 * 40, start + scrolltime2 * 41, false);
	CameraOscillationShake(start + scrolltime2 * 41, start + scrolltime2 * 42, true);
	CameraOscillationShake(start + scrolltime2 * 42, start + scrolltime2 * 43, false);
	CameraOscillationShake(start + scrolltime2 * 43, start + scrolltime2 * 44, true);
	CameraOscillationShake(start + scrolltime2 * 44, start + scrolltime2 * 45, false);
	CameraOscillationShake(start + scrolltime2 * 45, start + scrolltime2 * 46, true);
	CameraOscillationShake(start + scrolltime2 * 46, start + scrolltime2 * 47, false);
	CameraOscillationShake(start + scrolltime2 * 47, start + scrolltime2 * 48, true);
	CameraOscillationShake(start + scrolltime2 * 48, start + scrolltime2 * 49, false);
	CameraOscillationShake(start + scrolltime2 * 49, start + scrolltime2 * 50, true);
	CameraOscillationShake(start + scrolltime2 * 50, start + scrolltime2 * 51, false);
	CameraOscillationShake(start + scrolltime2 * 51, start + scrolltime2 * 52, true);
	CameraOscillationShake(start + scrolltime2 * 52, start + scrolltime2 * 53, false);
	CameraOscillationShake(start + scrolltime2 * 53, start + scrolltime2 * 54, true);
	CameraOscillationShake(start + scrolltime2 * 54, start + scrolltime2 * 55, false);
	CameraOscillationShake(start + scrolltime2 * 55, start + scrolltime2 * 56, true);
	CameraOscillationShake(start + scrolltime2 * 56, start + scrolltime2 * 57, false);
	CameraOscillationShake(start + scrolltime2 * 57, start + scrolltime2 * 58, true);
	CameraOscillationShake(start + scrolltime2 * 58, start + scrolltime2 * 59, false);
	CameraOscillationShake(start + scrolltime2 * 59, start + scrolltime2 * 60, true);
	CameraOscillationShake(start + scrolltime2 * 60, start + scrolltime2 * 61, false);
	CameraOscillationShake(start + scrolltime2 * 61, start + scrolltime2 * 62, true);
	CameraOscillationShake(start + scrolltime2 * 62, start + scrolltime2 * 63, false);
	CameraOscillationShake(start + scrolltime2 * 63, start + scrolltime2 * 64, true);
	CameraOscillationShake(start + scrolltime2 * 64, start + scrolltime2 * 65, false);
	CameraOscillationShake(start + scrolltime2 * 65, start + scrolltime2 * 66, true);
	CameraOscillationShake(start + scrolltime2 * 66, start + scrolltime2 * 67, false);
	CameraOscillationShake(start + scrolltime2 * 67, start + scrolltime2 * 68, true);
	CameraOscillationShake(start + scrolltime2 * 68, start + scrolltime2 * 69, false);
	CameraOscillationShake(start + scrolltime2 * 69, start + scrolltime2 * 70, true);
	CameraOscillationShake(start + scrolltime2 * 70, start + scrolltime2 * 71, false);
	CameraOscillationShake(start + scrolltime2 * 71, start + scrolltime2 * 72, true);
	CameraOscillationShake(start + scrolltime2 * 72, start + scrolltime2 * 73, false);
	CameraOscillationShake(start + scrolltime2 * 73, start + scrolltime2 * 74, true);
	CameraOscillationShake(start + scrolltime2 * 74, start + scrolltime2 * 75, false);
	CameraOscillationShake(start + scrolltime2 * 75, start + scrolltime2 * 76, true);
	CameraOscillationShake(start + scrolltime2 * 76, start + scrolltime2 * 77, false);
	CameraOscillationShake(start + scrolltime2 * 77, start + scrolltime2 * 78, true);
	CameraOscillationShake(start + scrolltime2 * 78, start + scrolltime2 * 79, false);
	CameraOscillationShake(start + scrolltime2 * 79, start + scrolltime2 * 80, true);
	CameraOscillationShake(start + scrolltime2 * 80, start + scrolltime2 * 81, false);
	CameraOscillationShake(start + scrolltime2 * 81, start + scrolltime2 * 82, true);
	CameraOscillationShake(start + scrolltime2 * 82, start + scrolltime2 * 83, false);
	CameraOscillationShake(start + scrolltime2 * 83, start + scrolltime2 * 84, true);
	CameraOscillationShake(start + scrolltime2 * 84, start + scrolltime2 * 85, false);
	CameraOscillationShake(start + scrolltime2 * 85, start + scrolltime2 * 86, true);
	CameraOscillationShake(start + scrolltime2 * 86, start + scrolltime2 * 87, false);
	CameraOscillationShake(start + scrolltime2 * 87, start + scrolltime2 * 88, true);
	CameraOscillationShake(start + scrolltime2 * 88, start + scrolltime2 * 89, false);
	CameraOscillationShake(start + scrolltime2 * 89, start + scrolltime2 * 90, true);
	CameraOscillationShake(start + scrolltime2 * 90, start + scrolltime2 * 91, false);
	CameraOscillationShake(start + scrolltime2 * 91, start + scrolltime2 * 92, true);
	CameraOscillationShake(start + scrolltime2 * 92, start + scrolltime2 * 93, false);
	CameraOscillationShake(start + scrolltime2 * 93, start + scrolltime2 * 94, true);
	CameraOscillationShake(start + scrolltime2 * 94, start + scrolltime2 * 95, false);
	CameraOscillationShake(start + scrolltime2 * 95, start + scrolltime2 * 96, true);
	CameraOscillationShake(start + scrolltime2 * 96, start + scrolltime2 * 97, false);
	CameraOscillationShake(start + scrolltime2 * 97, start + scrolltime2 * 98, true);
	CameraOscillationShake(start + scrolltime2 * 98, start + scrolltime2 * 99, false);
	CameraOscillationShake(start + scrolltime2 * 99, start + scrolltime2 * 100, true);
	CameraOscillationShake(start + scrolltime2 * 100, start + scrolltime2 * 101, false);
	CameraOscillationShake(start + scrolltime2 * 101, start + scrolltime2 * 102, true);
	CameraOscillationShake(start + scrolltime2 * 102, start + scrolltime2 * 103, false);
	CameraOscillationShake(start + scrolltime2 * 103, start + scrolltime2 * 104, true);
	CameraOscillationShake(start + scrolltime2 * 104, start + scrolltime2 * 105, false);
	CameraOscillationShake(start + scrolltime2 * 105, start + scrolltime2 * 106, true);
	CameraOscillationShake(start + scrolltime2 * 106, start + scrolltime2 * 107, false);
	CameraOscillationShake(start + scrolltime2 * 107, start + scrolltime2 * 108, true);
	CameraOscillationShake(start + scrolltime2 * 108, start + scrolltime2 * 109, false);
	CameraOscillationShake(start + scrolltime2 * 109, start + scrolltime2 * 110, true);
	CameraOscillationShake(start + scrolltime2 * 110, start + scrolltime2 * 111, false);
	CameraOscillationShake(start + scrolltime2 * 111, start + scrolltime2 * 112, true);
	CameraOscillationShake(start + scrolltime2 * 112, start + scrolltime2 * 113, false);
	CameraOscillationShake(start + scrolltime2 * 113, start + scrolltime2 * 114, true);
	CameraOscillationShake(start + scrolltime2 * 114, start + scrolltime2 * 115, false);
	CameraOscillationShake(start + scrolltime2 * 115, start + scrolltime2 * 116, true);
	CameraOscillationShake(start + scrolltime2 * 116, start + scrolltime2 * 117, false);
	CameraOscillationShake(start + scrolltime2 * 117, start + scrolltime2 * 118, true);
	CameraOscillationShake(start + scrolltime2 * 118, start + scrolltime2 * 119, false);
	CameraOscillationShake(start + scrolltime2 * 119, start + scrolltime2 * 120, true);
	CameraOscillationShake(start + scrolltime2 * 120, start + scrolltime2 * 121, false);
	CameraOscillationShake(start + scrolltime2 * 121, start + scrolltime2 * 122, true);
	CameraOscillationShake(start + scrolltime2 * 122, start + scrolltime2 * 123, false);
	CameraOscillationShake(start + scrolltime2 * 123, start + scrolltime2 * 124, true);
	CameraOscillationShake(start + scrolltime2 * 124, start + scrolltime2 * 125, false);
	CameraOscillationShake(start + scrolltime2 * 125, start + scrolltime2 * 126, true);
	CameraOscillationShake(start + scrolltime2 * 126, start + scrolltime2 * 127, false);
	CameraOscillationShake(start + scrolltime2 * 127, start + scrolltime2 * 128, true);
	CameraOscillationShake(start + scrolltime2 * 128, start + scrolltime2 * 129, false);
	CameraOscillationShake(start + scrolltime2 * 129, start + scrolltime2 * 130, true);
	CameraOscillationShake(start + scrolltime2 * 130, start + scrolltime2 * 131, false);
	CameraOscillationShake(start + scrolltime2 * 131, start + scrolltime2 * 132, true);
	CameraOscillationShake(start + scrolltime2 * 132, start + scrolltime2 * 133, false);
	CameraOscillationShake(start + scrolltime2 * 133, start + scrolltime2 * 134, true);
	CameraOscillationShake(start + scrolltime2 * 134, start + scrolltime2 * 135, false);
	CameraOscillationShake(start + scrolltime2 * 135, start + scrolltime2 * 136, true);
	CameraOscillationShake(start + scrolltime2 * 136, start + scrolltime2 * 137, false);
	CameraOscillationShake(start + scrolltime2 * 137, start + scrolltime2 * 138, true);
	CameraOscillationShake(start + scrolltime2 * 138, start + scrolltime2 * 139, false);
	CameraOscillationShake(start + scrolltime2 * 139, start + scrolltime2 * 140, true);
	CameraOscillationShake(start + scrolltime2 * 140, start + scrolltime2 * 141, false);
	CameraOscillationShake(start + scrolltime2 * 141, start + scrolltime2 * 142, true);
	CameraOscillationShake(start + scrolltime2 * 142, start + scrolltime2 * 143, false);
	CameraOscillationShake(start + scrolltime2 * 143, start + scrolltime2 * 144, true);
	CameraOscillationShake(start + scrolltime2 * 144, start + scrolltime2 * 145, false);
	CameraOscillationShake(start + scrolltime2 * 145, start + scrolltime2 * 146, true);
	CameraOscillationShake(start + scrolltime2 * 146, start + scrolltime2 * 147, false);
	CameraOscillationShake(start + scrolltime2 * 147, start + scrolltime2 * 148, true);
	CameraOscillationShake(start + scrolltime2 * 148, start + scrolltime2 * 149, false);
	CameraOscillationShake(start + scrolltime2 * 149, start + scrolltime2 * 150, true);
	CameraOscillationShake(start + scrolltime2 * 150, start + scrolltime2 * 151, false);
	CameraOscillationShake(start + scrolltime2 * 151, start + scrolltime2 * 152, true);
	CameraOscillationShake(start + scrolltime2 * 152, start + scrolltime2 * 153, false);
	CameraOscillationShake(start + scrolltime2 * 153, start + scrolltime2 * 154, true);
	CameraOscillationShake(start + scrolltime2 * 154, start + scrolltime2 * 155, false);
	CameraOscillationShake(start + scrolltime2 * 155, start + scrolltime2 * 156, true);
	CameraOscillationShake(start + scrolltime2 * 156, start + scrolltime2 * 157, false);
	CameraOscillationShake(start + scrolltime2 * 157, start + scrolltime2 * 158, true);
	CameraOscillationShake(start + scrolltime2 * 158, start + scrolltime2 * 159, false);
	CameraOscillationShake(start + scrolltime2 * 159, start + scrolltime2 * 160, true);
	CameraOscillationShake(start + scrolltime2 * 160, start + scrolltime2 * 161, false);
	CameraOscillationShake(start + scrolltime2 * 161, start + scrolltime2 * 162, true);
	CameraOscillationShake(start + scrolltime2 * 162, start + scrolltime2 * 163, false);
	CameraOscillationShake(start + scrolltime2 * 163, start + scrolltime2 * 164, true);
	CameraOscillationShake(start + scrolltime2 * 164, start + scrolltime2 * 165, false);
	CameraOscillationShake(start + scrolltime2 * 165, start + scrolltime2 * 166, true);
	CameraOscillationShake(start + scrolltime2 * 166, start + scrolltime2 * 167, false);
	CameraOscillationShake(start + scrolltime2 * 167, start + scrolltime2 * 168, true);
	CameraOscillationShake(start + scrolltime2 * 168, start + scrolltime2 * 169, false);
	CameraOscillationShake(start + scrolltime2 * 169, start + scrolltime2 * 170, true);
	CameraOscillationShake(start + scrolltime2 * 170, start + scrolltime2 * 171, false);
	CameraOscillationShake(start + scrolltime2 * 171, start + scrolltime2 * 172, true);
	CameraOscillationShake(start + scrolltime2 * 172, start + scrolltime2 * 173, false);
	CameraOscillationShake(start + scrolltime2 * 173, start + scrolltime2 * 174, true);
	CameraOscillationShake(start + scrolltime2 * 174, start + scrolltime2 * 175, false);
	CameraOscillationShake(start + scrolltime2 * 175, start + scrolltime2 * 176, true);
	CameraOscillationShake(start + scrolltime2 * 176, start + scrolltime2 * 177, false);
	CameraOscillationShake(start + scrolltime2 * 177, start + scrolltime2 * 178, true);
	CameraOscillationShake(start + scrolltime2 * 178, start + scrolltime2 * 179, false);
	CameraOscillationShake(start + scrolltime2 * 179, start + scrolltime2 * 180, true);
	CameraOscillationShake(start + scrolltime2 * 180, start + scrolltime2 * 181, false);*/   // Crater doesn't move 

	// Draw everything --------------------------------------
	
	RenderCrater();
	App->render->Blit(graphics2, 0, -5, &building_2, depth_3);										// DEPTH 3
	
	
	RenderDeepBuildingLights();
	RenderDiscoLights(); 
	RenderBackgroundSpaceships(); 
	
	

	App->render->Blit(graphics2, 0, 35, &building_1, depth_2);										// DEPTH 2
	
	RenderBuildingLights();

	App->render->Blit(graphics, 0, 0, &background, depth_1);										// DEPTH 1
	RenderEnemyTest();
	RenderStreetLights(); 
	RenderTunnelLights();
	
	


	// Fade to black
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
		if(App->fade->FadeToBlack(App->background, App->stageclear, 1.5f))
			App->audio->FadeMus(750);

	if (App->input->keyboard[SDL_SCANCODE_L] == 1) 
		if (App->fade->FadeToBlack(App->background, App->loseimage, 1.5f))
			App->audio->FadeMus(750);
	

	return UPDATE_CONTINUE;
}
