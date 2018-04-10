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
#include "SDL/include/SDL_timer.h"

#define CameraScrollTime 1016
#define CameraWaitTime 4098                   // CHECK // 

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{
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

	DeepBackgroundLights.PushBack({ 0,0,240,74 });
	DeepBackgroundLights.PushBack({ 240,0,240,74 });
	DeepBackgroundLights.PushBack({ 480,0,240,74 });
	DeepBackgroundLights.PushBack({ 720,0,240,74 });
	DeepBackgroundLights.PushBack({ 480,0,240,74 });
	DeepBackgroundLights.PushBack({ 240,0,240,74 });
	DeepBackgroundLights.speed = 0.1f;

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
	lightNew.speed = 0.1235f;

	streetLights.PushBack({ 0,21,50,65 });
	streetLights.PushBack({ 51,21,50,65 });
	streetLights.PushBack({ 102,21,50,65 });
	streetLights.PushBack({ 153,21,50,65 });
	streetLights.PushBack({ 204,21,50,65 });
	streetLights.PushBack({ 153,21,50,65 });
	streetLights.PushBack({ 102,21,50,65 });
	streetLights.PushBack({ 51,21,50,65 });
	streetLights.speed = 0.02f;


	streetLights_2.PushBack({ 204,21,50,65 });
	streetLights_2.PushBack({ 153,21,50,65 });
	streetLights_2.PushBack({ 102,21,50,65 });
	streetLights_2.PushBack({ 51,21,50,65 });
	streetLights_2.PushBack({ 0,21,50,65 });
	streetLights_2.PushBack({ 51,21,50,65 });
	streetLights_2.PushBack({ 102,21,50,65 });
	streetLights_2.PushBack({ 153,21,50,65 });
	streetLights_2.speed = 0.02f; 

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

	backgroundLights.PushBack({ 0,595,284,144 });
	backgroundLights.PushBack({ 284,595,284,144 });
	backgroundLights.PushBack({ 568,595,284,144 });
	backgroundLights.PushBack({ 852,595,284,144 });
	backgroundLights.PushBack({ 1136,595,284,144 });
	backgroundLights.PushBack({ 1420,595,284,144 });
	backgroundLights.PushBack({ 1704,595,284,144 });
	backgroundLights.PushBack({ 1704,451,284,144 });
	backgroundLights.PushBack({ 1704,309,284,144 });
	backgroundLights.PushBack({ 0,748,284,144 });
	backgroundLights.PushBack({ 284,748,284,144 });
	backgroundLights.PushBack({ 568,748,284,144 });
	backgroundLights.PushBack({ 852,748,284,144 });
	backgroundLights.PushBack({ 1136,748,284,144 });
    backgroundLights.PushBack({ 1420,748,284,144 });
	backgroundLights.PushBack({ 1704,748,284,144 });
	backgroundLights.PushBack({ 1420,748,284,144 });
	backgroundLights.PushBack({ 1136,748,284,144 });
	backgroundLights.PushBack({ 852,748,284,144 });
	backgroundLights.PushBack({ 568,748,284,144 });
	backgroundLights.PushBack({ 284,748,284,144 });
	backgroundLights.PushBack({ 0,748,284,144 });
	backgroundLights.PushBack({ 1704,309,284,144 });
	backgroundLights.PushBack({ 1704,451,284,144 });
	backgroundLights.PushBack({ 1704,595,284,144 });
	backgroundLights.PushBack({ 1420,595,284,144 });
	backgroundLights.PushBack({ 1136,595,284,144 });
	backgroundLights.PushBack({ 852,595,284,144 });
	backgroundLights.PushBack({ 568,595,284,144 });
	backgroundLights.PushBack({ 284,595,284,144 });
	backgroundLights.speed = 0.4f;

	ships.PushBack({ 0,0,8,3 });
	ships.PushBack({ 15,0,8,4 });
	ships.PushBack({ 30,0,8,4 });
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

	//graphics = App->textures->Load("backgroundlvl1v2.png");
	graphics = App->textures->Load("assets/sprites/background_lvl1.png");
	graphics2 = App->textures->Load("assets/sprites/background_lvl1_extra.png");
	graphics3 = App->textures->Load("assets/sprites/StreetLights_lvl1.png");
	graphics4 = App->textures->Load("assets/sprites/tunnelLights.png");
	graphics5 = App->textures->Load("assets/sprites/backspaceship_lvl101.png");
	graphics6 = App->textures->Load("assets/sprites/DeepBackgroundLights.png");
<<<<<<< HEAD
	App->player->Enable();
=======

>>>>>>> 78eee38016e59a2e47b9361f2b0650f510743c3f

	mus = App->audio->LoadMus("assets/SFX/music.ogg");
	App->audio->PlayMus(mus);

	return ret;
}

bool ModuleBackground::CleanUp()
{
	LOG("Cleaning Up background");
	//Disable Other Modules
	App->player->Disable(); 

	//Free all loaded textures
	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);
	App->textures->Unload(graphics3);
	App->textures->Unload(graphics4);
	App->textures->Unload(graphics5);
	App->textures->Unload(graphics6);

	//Free all audio material
	App->audio->UnloadMus(mus); 
	return true;
}


void ModuleBackground::MoveUp()
{
	App->render->camera.y += 2.0000008f; 
	App->player->position.y -= 2.0000008f/2;
	App->player->relativeposition.y -= 2.0000008f/2;
}
 


void ModuleBackground::MoveDown()
{
	App->render->camera.y -= 1; 
	App->player->position.y += 1;
	App->player->relativeposition.y += 1;
}

void ModuleBackground::CameraScroll(){
	Uint32 now = SDL_GetTicks();
	int UntilFirstScrollTime = 3530;
	int cont = 0;

	if (now >= UntilFirstScrollTime) {
		if (cont >= 1) {                         // FORCE LOOP, STILL DOES NOT WORK // 
			now = UntilFirstScrollTime;
		}
		if (now >= UntilFirstScrollTime && now <= UntilFirstScrollTime + CameraScrollTime) {     // Camera scrolls down
			MoveDown();
		}
		if (now > UntilFirstScrollTime + CameraScrollTime + CameraWaitTime && now < UntilFirstScrollTime + CameraWaitTime + CameraScrollTime * 2) {     // Camera scrolls up
			MoveUp();
		}
		cont++;
	}
	if (now >= 15000 && now <= 15000 + CameraScrollTime + 100) {    // provisional scroll before tunnel, the starting point must be corrected
		MoveDown();
	}
}

void ModuleBackground::CameraScroll2(int since, int to, bool up)
{
	if (App->render->camera.x >= -to && App->render->camera.x <= -since)
	{
		if (up) MoveUp();
		if (!up) MoveDown(); 
	}
	
}

void ModuleBackground::RenderDiscoLights()
{
	App->render->Blit(graphics2, 171, -19, &light.GetCurrentFrame(), 0.4f);
	App->render->Blit(graphics2, 683, -19, &light.GetCurrentFrame(), 0.4f);
	App->render->Blit(graphics2, 752, -22, &lightNew.GetCurrentFrame(), 0.4f);
	App->render->Blit(graphics2, 827, -35, &light.GetCurrentFrame(), 0.4f);
	App->render->Blit(graphics5, 100, 50, &ships.GetCurrentFrame(), -1.f); // example of the backship

	if (!render_light) {
		App->render->Blit(graphics2, 300, -10, &backgroundLights.GetCurrentFrame(), 0.4f);
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

	App->render->Blit(graphics3, 39, 136, &streetLights.GetCurrentFrame(), 0.75f);

	App->render->Blit(graphics3, 103, 136, &streetLights.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 167, 136, &streetLights_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 231, 136, &streetLights_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 295, 136, &streetLights.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 359, 136, &streetLights.GetCurrentFrame(), 0.75f);

	App->render->Blit(graphics3, 423, 136, &streetLights_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 487, 136, &streetLights.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 551, 136, &streetLights_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 615, 136, &streetLights.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 679, 136, &streetLights_2.GetCurrentFrame(), 0.75f);

	App->render->Blit(graphics3, 743, 136, &streetLights_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 807, 136, &streetLights.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 871, 136, &streetLights_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 935, 136, &streetLights_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 999, 136, &streetLights.GetCurrentFrame(), 0.75f);

	App->render->Blit(graphics3, 1063, 136, &streetLights_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 1127, 136, &streetLights.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 1191, 136, &streetLights.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 1255, 136, &streetLights_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 1319, 136, &streetLights.GetCurrentFrame(), 0.75f);

	App->render->Blit(graphics3, 1383, 136, &streetLights_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 1447, 136, &streetLights_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 1511, 136, &streetLights.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 1575, 136, &streetLights_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 1639, 136, &streetLights.GetCurrentFrame(), 0.75f);

	App->render->Blit(graphics3, 1703, 136, &streetLights_2.GetCurrentFrame(), 0.75f);

	//	BOTTOM PART
	
	// 1 2 2 1 1 
	// 2 1 2 1 2 
	// 2 1 2 2 1 (+128)

	App->render->Blit(graphics3, 121, 217, &lightFloor.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 249, 217, &lightFloor_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 377, 217, &lightFloor_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 505, 217, &lightFloor.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 633, 217, &lightFloor.GetCurrentFrame(), 0.75f);

	App->render->Blit(graphics3, 761, 217, &lightFloor_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 889, 217, &lightFloor.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 1017, 217, &lightFloor_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 1145, 217, &lightFloor.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 1273, 217, &lightFloor_2.GetCurrentFrame(), 0.75f);

	App->render->Blit(graphics3, 1401, 217, &lightFloor_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 1529, 217, &lightFloor.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics3, 1657, 217, &lightFloor_2.GetCurrentFrame(), 0.75f);
}

void ModuleBackground::RenderTunnelLights()
{
	App->render->Blit(graphics4, 2051, 0, &tunnelLights.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics4, 2308, 0, &tunnelLights_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics4, 2565, 0, &tunnelLights.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics4, 2822, 0, &tunnelLights_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics4, 3079, 0, &tunnelLights.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics4, 3336, 0, &tunnelLights_2.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics4, 3593, 0, &tunnelLights.GetCurrentFrame(), 0.75f);
	App->render->Blit(graphics4, 3850, 0, &tunnelLights_2.GetCurrentFrame(), 0.75f);
}



// Update: draw background
update_status ModuleBackground::Update()
{
	int scroll_speed = 3; 

	// Camera Movement Conditions
	if (scroll) {
		App->render->camera.x -= scroll_speed;
	}

	if (App->render->camera.x <= -6000 * SCREEN_SIZE)
		scroll = false; 

			// Up and down Conditions 
	//CameraScroll();

	CameraScroll2(100, 250, false);
	CameraScroll2(400, 475, true);
	CameraScroll2(700, 850, false);

	// Draw everything --------------------------------------
	if(App->render->camera.x<=-4800*SCREEN_SIZE)	
		App->render->Blit(graphics2, 0, 0, &crater, 0.f);		

	App->render->Blit(graphics2, 0, 0, &building_2, 0.224f);
	App->render->Blit(graphics6, 0, 0, &DeepBackgroundLights.GetCurrentFrame(), 0.75f);             // DEPTH 1

	RenderDiscoLights(); 
	
	App->render->Blit(graphics2, 0, 35, &building_1, 0.4f)	;										// DEPTH 2

	App->render->Blit(graphics, 0, 0, &background, 0.75f);											// DEPTH 3

	App->render->Blit(graphics3, 121, 217, &lightFloor.GetCurrentFrame(), 0.75f);

	RenderStreetLights(); 
	RenderTunnelLights();
	// Fade to black
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
		App->fade->FadeToBlack(App->background, App->stageclear, 1.5f);

	return UPDATE_CONTINUE;
}
