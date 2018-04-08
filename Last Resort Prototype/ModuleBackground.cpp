#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleStartingImage.h"
#include "SDL/include/SDL_timer.h"

#define CameraScrollTime 1016
#define CameraWaitTime 4098                   // CHECK // 

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA
int a = 171, b = -20;

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

	light.PushBack({ 327,0,32,70 });
	light.PushBack({ 365,0,24,71 });
	light.PushBack({ 394,0,5,70 });
	light.PushBack({ 403,0,25,77 });
	light.PushBack({ 427,0,31,79 });
	light.PushBack({ 403,0,25,77 });
	light.PushBack({ 394,0,5,70 });
	light.PushBack({ 365,0,24,71 });
	light.speed = 0.1f;

	backgroundLights.PushBack({ 0,595,284,144 });
	backgroundLights.PushBack({ 284,595,243,144 });
	backgroundLights.PushBack({ 527,595,197,144 });
	backgroundLights.PushBack({ 724,595,162,144 });
	backgroundLights.PushBack({ 886,595,130,144 });
	backgroundLights.PushBack({ 1016,595,104,144 });
	backgroundLights.PushBack({ 1120,595,76,144 });
	backgroundLights.PushBack({ 1196,595,50,144 });
	/*backgroundLights.PushBack({ ,,50,144 });
	backgroundLights.PushBack({ ,,76,144 });
	backgroundLights.PushBack({ ,,104,144 });
	backgroundLights.PushBack({ ,,130,144 });
	backgroundLights.PushBack({ ,,162,144 });
	backgroundLights.PushBack({ ,,197,144 });
	backgroundLights.PushBack({ ,,243,144 });
	backgroundLights.PushBack({ ,,284,144 });*/
	backgroundLights.speed = 0.12f;

}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");


	bool ret = true;
	//graphics = App->textures->Load("backgroundlvl1v2.png");
	graphics = App->textures->Load("background_lvl1.png");
	graphics2 = App->textures->Load("background_lvl1_extra.png");
	
	/*if (App->input->keyboard[SDL_SCANCODE_SPACE]) {
		App->fade->FadeToBlack(App->background, App->startimage, 5.0f);
	}*/

	Mix_Music* mus = App->audio->LoadMus("music.ogg");
	App->audio->PlayMus(mus);
	return ret;
}


void ModuleBackground::MoveUp()
{
	App->render->camera.y += 1; 
}

void ModuleBackground::MoveDown()
{
	App->render->camera.y -= 1; 
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
	Uint32 now = SDL_GetTicks();
	int UntilFirstScrollTime = 3530; 
	
	if (now >= UntilFirstScrollTime) {
		if (now > UntilFirstScrollTime && now < UntilFirstScrollTime + CameraScrollTime) {     // Camera scrolls down
			MoveDown();
		}
		if (now > UntilFirstScrollTime + CameraScrollTime + CameraWaitTime && now < UntilFirstScrollTime + CameraWaitTime + CameraScrollTime * 2) {     // Camera scrolls up
			MoveUp();
		}
		now = 0;
		UntilFirstScrollTime = 0;
	}

	// Draw everything --------------------------------------
	
	App->render->Blit(graphics2, 0, 0, &crater, 0.f);
	App->render->Blit(graphics2, 0, 0, &building_2, 0.224f);
	App->render->Blit(graphics2, a, b, &light.GetCurrentFrame(), 0.4f);
	App->render->Blit(graphics2, 450, 0, &backgroundLights.GetCurrentFrame(), 0.4f);
	App->render->Blit(graphics2, 0, 35, &building_1, 0.4f)	;
	App->render->Blit(graphics, 0, 0, &background, 0.75f); 

	return UPDATE_CONTINUE;
}
