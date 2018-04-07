#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"
#include "ModulePlayer.h"

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

	if(App->render->camera.x<=-100 && App->render->camera.x>=-250)
		MoveDown();

	if (App->render->camera.x <= -450 && App->render->camera.x >= -600)
		MoveUp();



	// Draw everything --------------------------------------
	App->render->Blit(graphics2, 0, 0, &crater, 0.f);
	App->render->Blit(graphics2, 0, 0, &building_2, 0.224f);
	App->render->Blit(graphics2, 0, 35, &building_1, 0.4f)	;
	App->render->Blit(graphics, 0, 0, &background, 0.75f); 

	return UPDATE_CONTINUE;
}