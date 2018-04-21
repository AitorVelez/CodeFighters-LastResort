#include "ModuleUI.h"
#include "Globals.h"
#include "ModuleFonts.h"
#include "ModuleTextures.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleBackground.h"
#include <string.h>
#include <sstream>


ModuleUI::ModuleUI()

{

	UIstable.x = 0;
	UIstable.y = 0;
	UIstable.w = SCREEN_WIDTH;
	UIstable.h = SCREEN_HEIGHT;


	Player2.PushBack({ 0,0,95,15 });
	Player2.PushBack({ 90,90,95,15 });
	Player2.speed = 0.02;


}

ModuleUI::~ModuleUI()
{}

bool ModuleUI::Start(){
	LOG("Loading UI");

	font_score = App->Fonts->Load("assets/sprites/chars2.png", "0123456789A", 1);

	P2 = App->textures->Load("assets/sprites/Player2ready.png");
	UIS = App->textures->Load("assets/sprites/UIsprite1.png");


	return true;
}

bool ModuleUI::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(P2);
	App->textures->Unload(UIS);
	App->Fonts->UnLoad(font_score);
	

	return true;
}


update_status ModuleUI::Update()
{
	/*Tenemos la variable "App->Player->score_p1" que es un int, y tenemos la variable "score"
	que es un char* necesitamos transformar ese int en un char* o algo asi para que se pueda printear*/
	App->player->score_p1;


	if (ready == true) {
		App->render->Blit(UIS, 0, 0, &UIstable, 0, false);
		App->Fonts->BlitText(45, 15, 0, score);
	}
	if (ready == true && App->background->activ == false)
		App->render->Blit(P2, 210, 20, &Player2.GetCurrentFrame(), 0, false);

	return UPDATE_CONTINUE;
}