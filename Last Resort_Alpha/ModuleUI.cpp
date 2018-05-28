#include "ModuleUI.h"
#include "Globals.h"
#include "ModuleFonts.h"
#include "ModuleTextures.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleBackground.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
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

	Punit2.PushBack({ 0,17,96,8 });
	Punit2.speed = 0;

	Pl2.PushBack({ 0,0,40,16 });
	Pl2.speed = 0;


}

ModuleUI::~ModuleUI()
{}

bool ModuleUI::Start(){
	LOG("Loading UI");

	font_score = App->Fonts->Load("assets/sprites/chars2.png", "0123456789A", 1);
	P22 = App->textures->Load("assets/sprites/Player2.png");
	P2 = App->textures->Load("assets/sprites/Player2ready.png");
	UIS = App->textures->Load("assets/sprites/UIsprite1.png");


	return true;
}

bool ModuleUI::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(P2);
	App->textures->Unload(P22);
	App->textures->Unload(UIS);
	App->Fonts->UnLoad(font_score);
	

	return true;
}


update_status ModuleUI::Update()
{
	
	char score[10];
	char score2[10];
	char coins[10];
	App->player->score_p1;
	int a, b;
	b = App->player2->score_p2 + 1000;
	a = App->player->score_p1 + 1000;
	sprintf_s(score2, "%d", App->player2->score_p2);
	sprintf_s(score, "%d", App->player->score_p1);
	sprintf_s(coins, "%d", coin);

	if (ready == true || stgclr == true) {
		App->render->Blit(UIS, 0, 0, &UIstable, 0, false);
		App->Fonts->BlitText(280, 216, 0, coins);
	}
	if (ready)
		App->Fonts->BlitText(45, 15, 0, score);

	if (ready == true && App->background->activ == false)
		App->render->Blit(P2, 210, 20, &Player2.GetCurrentFrame(), 0, false);
	if ((ready == true && App->background->activ == true) || (stgclr == true && pl2 == true)) {
		App->render->Blit(P22, 260, 15, &Pl2.GetCurrentFrame(), 0, false);
		
		App->render->Blit(P22, 200, 208, &Punit2.GetCurrentFrame(), 0, false);

	}
	if (ready == true && App->background->activ == true)
		App->Fonts->BlitText(240, 15, 0, score2);


	if (stgclr == true && pl2 == true) {
		sprintf_s(score2, "%d", b);
		App->Fonts->BlitText(240, 15, 0, score2);

	}

	if (stgclr) {
		sprintf_s(score, "%d", a);
		App->Fonts->BlitText(45, 15, 0, score);
		App->Fonts->BlitText(160, 88, 0, "1000");
	}
	
	if ((App->player->lives == 0 && App->player2->lives == 0) && lflag == true) {
		if (coin >> 0) {
			coin -= 1;
			lflag = false;
		}
		else lflag = false;

	}

	if (App->player->lives == 0 && lflag == true) {
		if (coin >> 0) {
			coin -= 1;
			lflag = false;
		}
		else lflag = false;
		

	}

	if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN) {
		App->UI->coin += 1;
	}
	return UPDATE_CONTINUE;
}