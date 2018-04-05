#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{
	// Background
	background.x = 0;
	background.y = 0;
	background.w = 4233;
	background.h = 239;

	crater.x = 4232;
	crater.y = 0; 
	crater.w = 328;
	crater.h = 239;
}


ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("backgroundlvl1v2.png");
	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	int scroll_speed = 3; 

	if (scroll) {
		App->render->camera.x -= scroll_speed;
	}

	if (App->render->camera.x <= -5700 * SCREEN_SIZE)
		scroll = false; 

	// Draw everything --------------------------------------
		App->render->Blit(graphics, 0, 0, &crater, 0.0001f);
		App->render->Blit(graphics, 0, 0, &background, 0.75f); // sea and sky

	return UPDATE_CONTINUE;
}