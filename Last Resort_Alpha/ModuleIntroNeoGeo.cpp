#include "Globals.h"
#include "Application.h"
#include "ModuleStartingImage.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleBackground.h"
#include "ModuleBackground2.h"
#include "ModuleStageClear.h"
#include "ModuleIntroNeoGeo.h"
#include "Application.h"
#include "SDL\include\SDL_timer.h"


ModuleIntroNeoGeo::ModuleIntroNeoGeo()
{
	NeoGeoImage.x = 0;
	NeoGeoImage.y = 0;
	NeoGeoImage.w = SCREEN_WIDTH;
	NeoGeoImage.h = SCREEN_HEIGHT;




	Title1.PushBack({ 0,  0,304,224 });
	Title1.PushBack({ 304,0,304,224 });
	Title1.PushBack({ 608,0,304,224 });
	Title1.PushBack({ 0,  224,304,224 });
	Title1.PushBack({ 304,224,304,224 });
	Title1.PushBack({ 608,224,304,224 });
	Title1.PushBack({ 0,  448,304,224 });
	Title1.PushBack({ 304,448,304,224 });
	Title1.PushBack({ 608,448,304,224 });
	Title1.PushBack({ 0,  672,304,224 });
	Title1.PushBack({ 304,672,304,224 });
	Title1.PushBack({ 608,672,304,224 });
	Title1.PushBack({ 708,200,304,224 });
	Title1.speed = 0.25f;
	Title1.loop = false;



	Title2.PushBack({ 0,  0,304,224 });
	Title2.PushBack({ 304,0,304,224 });
	Title2.PushBack({ 608,0,304,224 });
	Title2.PushBack({ 0,  224,304,224 });
	Title2.PushBack({ 304,224,304,224 });
	Title2.PushBack({ 608,224,304,224 });
	Title2.PushBack({ 0,  448,304,224 });
	Title2.PushBack({ 304,448,304,224 });
	Title2.PushBack({ 608,448,304,224 });
	Title2.PushBack({ 0,  672,304,224 });
	Title2.PushBack({ 304,672,304,224 });
	Title2.PushBack({ 608,672,304,224 });
	Title2.PushBack({ 164,809,304,224 });
	Title2.speed = 0.25f;
	Title2.loop = false;




	Title3.PushBack({ 0,  0,304,224 });
	Title3.PushBack({ 304,0,304,224 });
	Title3.PushBack({ 608,0,304,224 });
	Title3.PushBack({ 0,  224,304,224 });
	Title3.PushBack({ 304,224,304,224 });
	Title3.PushBack({ 608,224,304,224 });
	Title3.PushBack({ 0,  448,304,224 });
	Title3.PushBack({ 304,448,304,224 });
	Title3.PushBack({ 608,448,304,224 });
	Title3.PushBack({ 0,  672,304,224 });
	Title3.PushBack({ 304,672,304,224 });
	Title3.PushBack({ 608,672,304,224 });
	Title3.speed = 0.25f;
	Title3.loop = false;

	Title4.PushBack({ 0,  0,304,224 });
	Title4.PushBack({ 304,0,304,224 });
	Title4.PushBack({ 608,0,304,224 });
	Title4.PushBack({ 0,  224,304,224 });
	Title4.PushBack({ 304,224,304,224 });
	Title4.PushBack({ 608,224,304,224 });
	Title4.PushBack({ 0,  448,304,224 });
	Title4.PushBack({ 304,448,304,224 });
	Title4.PushBack({ 608,448,304,224 });
	Title4.PushBack({ 0,  672,304,224 });
	Title4.PushBack({ 304,672,304,224 });
	Title4.PushBack({ 608,672,304,224 });
	Title4.speed = 0.25f;
	Title4.loop = false;

	Title5.PushBack({ 0,  0,304,224 });
	Title5.PushBack({ 304,0,304,224 });
	Title5.PushBack({ 608,0,304,224 });
	Title5.PushBack({ 0,  224,304,224 });
	Title5.PushBack({ 304,224,304,224 });
	Title5.PushBack({ 608,224,304,224 });
	Title5.PushBack({ 0,  448,304,224 });
	Title5.PushBack({ 304,448,304,224 });
	Title5.PushBack({ 608,448,304,224 });
	Title5.PushBack({ 0,  672,304,224 });
	Title5.PushBack({ 304,672,304,224 });
	Title5.PushBack({ 608,672,304,224 });
	Title5.speed = 0.25f;
	Title5.loop = false;

	Title6.PushBack({ 0,  0,304,224 });
	Title6.PushBack({ 304,0,304,224 });
	Title6.PushBack({ 608,0,304,224 });
	Title6.PushBack({ 0,  224,304,224 });
	Title6.PushBack({ 304,224,304,224 });
	Title6.PushBack({ 608,224,304,224 });
	Title6.PushBack({ 0,  448,304,224 });
	Title6.PushBack({ 304,448,304,224 });
	Title6.PushBack({ 608,448,304,224 });
	Title6.PushBack({ 0,  672,304,224 });
	Title6.PushBack({ 304,672,304,224 });
	Title6.PushBack({ 608,672,304,224 });
	Title6.speed = 0.25f;
	Title6.loop = false;

	Title7.PushBack({ 0,  0,304,224 });
	Title7.PushBack({ 304,0,304,224 });
	Title7.PushBack({ 608,0,304,224 });
	Title7.PushBack({ 0,  224,304,224 });
	Title7.PushBack({ 304,224,304,224 });
	Title7.PushBack({ 608,224,304,224 });
	Title7.PushBack({ 0,  448,304,224 });
	Title7.PushBack({ 304,448,304,224 });
	Title7.PushBack({ 608,448,304,224 });
	Title7.PushBack({ 0,  672,304,224 });
	Title7.PushBack({ 304,672,304,224 });
	Title7.PushBack({ 608,672,304,224 });
	Title7.speed = 0.25f;
	Title7.loop = false;

	Title8.PushBack({ 0,  0,304,224 });
	Title8.PushBack({ 304,0,304,224 });
	Title8.PushBack({ 608,0,304,224 });
	Title8.PushBack({ 0,  224,304,224 });
	Title8.PushBack({ 304,224,304,224 });
	Title8.PushBack({ 608,224,304,224 });
	Title8.PushBack({ 0,  448,304,224 });
	Title8.PushBack({ 304,448,304,224 });
	Title8.PushBack({ 608,448,304,224 });
	Title8.PushBack({ 0,  672,304,224 });
	Title8.PushBack({ 304,672,304,224 });
	Title8.PushBack({ 608,672,304,224 });
	Title8.speed = 0.25f;
	Title8.loop = false;

	Title9.PushBack({ 0,  0,304,224 });
	Title9.PushBack({ 304,0,304,224 });
	Title9.speed = 0.25f;
	Title9.loop = false;
}

ModuleIntroNeoGeo::~ModuleIntroNeoGeo()
{}

// Load assets
bool ModuleIntroNeoGeo::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	TexNeoGeoImage = App->textures->Load("assets/sprites/NeogeoImage.png");
	
	
	NeoGeoTex1 = App->textures->Load("assets/sprites/NeoGeoTitleGood/Neo_Geo_Title_Good1.png");
	NeoGeoTex2 = App->textures->Load("assets/sprites/NeoGeoTitleGood/Neo_Geo_Title_Good2.png");
	NeoGeoTex3 = App->textures->Load("assets/sprites/NeoGeoTitleGood/Neo_Geo_Title_Good3.png");
	NeoGeoTex4 = App->textures->Load("assets/sprites/NeoGeoTitleGood/Neo_Geo_Title_Good4.png");
	NeoGeoTex5 = App->textures->Load("assets/sprites/NeoGeoTitleGood/Neo_Geo_Title_Good5.png");
	NeoGeoTex6 = App->textures->Load("assets/sprites/NeoGeoTitleGood/Neo_Geo_Title_Good6.png");
	NeoGeoTex7 = App->textures->Load("assets/sprites/NeoGeoTitleGood/Neo_Geo_Title_Good7.png");
	NeoGeoTex8 = App->textures->Load("assets/sprites/NeoGeoTitleGood/Neo_Geo_Title_Good8.png");
	NeoGeoTex9 = App->textures->Load("assets/sprites/NeoGeoTitleGood/Neo_Geo_Title_Good9.png");

	
	
	mus = App->audio->LoadMus("assets/SFX/musicInit1.ogg");
	App->audio->PlayMus(mus);

	App->render->camera.x = 0;
	App->render->camera.y = 0;
	App->player->Disable();
	App->player2->Disable();
	return ret;
}

// Load assets
bool ModuleIntroNeoGeo::CleanUp()
{
	LOG("Unloading Intro Scene");
	//App->textures->Unload(TexNeoGeoImage);
	App->textures->Unload(NeoGeoTex1);
	App->textures->Unload(NeoGeoTex2);
	App->textures->Unload(NeoGeoTex3);
	App->textures->Unload(NeoGeoTex4);
	App->textures->Unload(NeoGeoTex5);
	App->textures->Unload(NeoGeoTex6);
	App->textures->Unload(NeoGeoTex7);
	App->textures->Unload(NeoGeoTex8);
	App->textures->Unload(NeoGeoTex9);
	App->textures->Unload(TexNeoGeoImage);
	
	App->audio->UnloadMus(mus);

	return true;
}

// Update: draw background
update_status ModuleIntroNeoGeo::Update()
{
	
	
	App->render->Blit(NeoGeoTex1, 0, 0, &Title1.GetCurrentFrame(), 1, false);

	if (Title1.Finished() && Title2.Finished() != true);
	App->render->Blit(NeoGeoTex2, 0, 0, &Title2.GetCurrentFrame(), 1, false);

	if (Title2.Finished() && Title3.Finished() != true)
		App->render->Blit(NeoGeoTex3, 0, 0, &Title3.GetCurrentFrame(), 1, false);

	if (Title3.Finished() && Title4.Finished() != true)
		App->render->Blit(NeoGeoTex4, 0, 0, &Title4.GetCurrentFrame(), 1, false);

	if (Title4.Finished() && Title5.Finished() != true)
		App->render->Blit(NeoGeoTex5, 0, 0, &Title5.GetCurrentFrame(), 1, false);

	if (Title5.Finished() && Title6.Finished() != true)
		App->render->Blit(NeoGeoTex6, 0, 0, &Title6.GetCurrentFrame(), 1, false);

	if (Title6.Finished() && Title7.Finished() != true)
		App->render->Blit(NeoGeoTex7, 0, 0, &Title7.GetCurrentFrame(), 1, false);

	if (Title7.Finished() && Title8.Finished() != true)
		App->render->Blit(NeoGeoTex8, 0, 0, &Title8.GetCurrentFrame(), 1, false);

	if (Title8.Finished() && Title9.Finished() != true)
		App->render->Blit(NeoGeoTex9, 0, 0, &Title9.GetCurrentFrame(), 1, false);
	
	if (Title9.Finished())
		App->render->Blit(TexNeoGeoImage, 0, 0, &NeoGeoImage);
	



	// Draw everything --------------------------------------	
	//App->render->Blit(TexNeoGeoImage, 0, 0, &StImage);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1
		|| App->input->Controller_1[SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_A] == KEY_DOWN
		|| App->input->Controller_2[SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_A] == KEY_DOWN) {
		if (App->fade->FadeToBlack(this, App->startimage, 1.5f))
			App->audio->FadeMus(750);
	}
	
	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN)
	{
		if (App->fade->FadeToBlack(this, App->background2, 1.5f))
			App->audio->FadeMus(750);
	}


	return UPDATE_CONTINUE;
}