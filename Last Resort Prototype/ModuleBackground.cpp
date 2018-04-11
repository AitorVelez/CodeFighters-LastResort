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

	light.PushBack({ 327,0,67,79 });
	light.PushBack({ 388,0,67,79 });
	light.PushBack({ 449,0,67,79 });
	light.PushBack({ 510,0,67,70 });
	light.PushBack({ 571,0,67,70 });
	light.PushBack({ 510,0,67,70 });
	light.PushBack({ 449,0,67,79 });
	light.PushBack({ 388,0,67,79 });
	light.speed = 0.05f;

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
	backgroundLights.speed = 0.3f;


}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");


	bool ret = true;
	//graphics = App->textures->Load("backgroundlvl1v2.png");
	graphics = App->textures->Load("assets/background_lvl1.png");
	graphics2 = App->textures->Load("assets/background_lvl1_extra.png");
	
	App->player->Enable();

	Mix_Music* mus = App->audio->LoadMus("assets/music.ogg");
	App->audio->PlayMus(mus);
	return ret;
}

bool ModuleBackground::CleanUp()
{
	LOG("Cleaning Up background");

	return true;
}


void ModuleBackground::MoveUp()
{
	App->render->camera.y += 2.0000008f; 
}

void ModuleBackground::MoveDown()
{
	App->render->camera.y -= 1; 
}

<<<<<<< HEAD


void ModuleBackground::CameraOscillation(int since, int to, bool up)
{
	if (App->render->camera.x >= -to && App->render->camera.x <= -since)
	{
		if (up) {//MoveUp();
			App->render->camera.y += 3;
			App->player->position.y -= 1;
			App->player->relativeposition.y -= 1;          // camera MUST move 3 times more than player
		}
		if (!up) {// MoveDown(); 
			App->render->camera.y -= 3;
			App->player->position.y += 1;                       
			App->player->relativeposition.y += 1;                    // camera MUST move 3 times more than player
		}
=======
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
>>>>>>> 5b5389acf371d08341ead698e92ba03dc6c1d5fa
	}
	if (now >= 15000 && now <= 15000 + CameraScrollTime + 100) {    // provisional scroll before tunnel, the starting point must be corrected
		MoveDown();
	}
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
<<<<<<< HEAD

	CameraOscillation(100, 150 , false);
	CameraOscillation(600, 970, true);
	CameraOscillation(1400, 1770, false);
	CameraOscillation(2100, 2470, true);
	CameraOscillation(2900, 3270, false);
	CameraOscillation(3800, 4170, true);
	CameraOscillation(4600, 4970, false);
	CameraOscillation(5200, 5380, true);
=======
	CameraScroll();
>>>>>>> 5b5389acf371d08341ead698e92ba03dc6c1d5fa


	 // fInal shake   



	// Draw everything --------------------------------------
	
	App->render->Blit(graphics2, 0, 0, &crater, 0.f);
	App->render->Blit(graphics2, 0, 0, &building_2, 0.224f);
	App->render->Blit(graphics2, 172, -20, &light.GetCurrentFrame(), 0.4f);
	
	if (flip == 0) {
		App->render->Blit(graphics2, 450, -10, &backgroundLights.GetCurrentFrame(), 0.4f);
		lights1++;
		if (lights1 == 1) {
			flip = 1;
		}
	}
	else if (flip == 1) {
		lights1--;
		if (lights1 == 0)
			flip = 0;
	}

	App->render->Blit(graphics2, 0, 35, &building_1, 0.4f)	;
	App->render->Blit(graphics, 0, 0, &background, 0.75f); 


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
<<<<<<< HEAD
		App->fade->FadeToBlack(App->background, App->startimage, 1.5f);
=======
		App->fade->FadeToBlack(App->background, App->stageclear, 1.5f);
>>>>>>> parent of 1fc184f... Added direct lose by pressing L

	return UPDATE_CONTINUE;
}
