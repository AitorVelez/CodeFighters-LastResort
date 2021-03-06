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
#include "ModuleStageClear.h"
#include "ModuleIntroNeoGeo.h"
#include "Application.h"
#include "SDL\include\SDL_timer.h"


ModuleIntroNeoGeo::ModuleIntroNeoGeo()
{
	StImage.x = 0;
	StImage.y = 0;
	StImage.w = SCREEN_WIDTH;
	StImage.h = SCREEN_HEIGHT;


	NeoGeo9.PushBack({ 304,0,304,224 });
	NeoGeo9.PushBack({ 0,  0,304,224 });
	NeoGeo9.speed = 0.25f;
	NeoGeo9.loop = false;

	NeoGeo8.PushBack({ 608,672,304,224 });
	NeoGeo8.PushBack({ 304,672,304,224 });
	NeoGeo8.PushBack({ 0,  672,304,224 });
	NeoGeo8.PushBack({ 608,448,304,224 });
	NeoGeo8.PushBack({ 304,448,304,224 });
	NeoGeo8.PushBack({ 0,  448,304,224 });
	NeoGeo8.PushBack({ 608,224,304,224 });
	NeoGeo8.PushBack({ 304,224,304,224 });
	NeoGeo8.PushBack({ 0,  224,304,224 });
	NeoGeo8.PushBack({ 608,0,304,224 });
	NeoGeo8.PushBack({ 304,0,304,224 });
	NeoGeo8.PushBack({ 0,  0,304,224 });
	NeoGeo8.speed = 0.25f;
	NeoGeo8.loop = false;

	NeoGeo7.PushBack({ 608,672,304,224 });
	NeoGeo7.PushBack({ 304,672,304,224 });
	NeoGeo7.PushBack({ 0,  672,304,224 });
	NeoGeo7.PushBack({ 608,448,304,224 });
	NeoGeo7.PushBack({ 304,448,304,224 });
	NeoGeo7.PushBack({ 0,  448,304,224 });
	NeoGeo7.PushBack({ 608,224,304,224 });
	NeoGeo7.PushBack({ 304,224,304,224 });
	NeoGeo7.PushBack({ 0,  224,304,224 });
	NeoGeo7.PushBack({ 608,0,304,224 });
	NeoGeo7.PushBack({ 304,0,304,224 });
	NeoGeo7.PushBack({ 0,  0,304,224 });
	NeoGeo7.speed = 0.25f;
	NeoGeo7.loop = false;


	NeoGeo6.PushBack({ 608,672,304,224 });
	NeoGeo6.PushBack({ 304,672,304,224 });
	NeoGeo6.PushBack({ 0,  672,304,224 });
	NeoGeo6.PushBack({ 608,448,304,224 });
	NeoGeo6.PushBack({ 304,448,304,224 });
	NeoGeo6.PushBack({ 0,  448,304,224 });
	NeoGeo6.PushBack({ 608,224,304,224 });
	NeoGeo6.PushBack({ 304,224,304,224 });
	NeoGeo6.PushBack({ 0,  224,304,224 });
	NeoGeo6.PushBack({ 608,0,304,224 });
	NeoGeo6.PushBack({ 304,0,304,224 });
	NeoGeo6.PushBack({ 0,  0,304,224 });
	NeoGeo6.speed = 0.25f;
	NeoGeo6.loop = false;


	NeoGeo5.PushBack({ 608,672,304,224 });
	NeoGeo5.PushBack({ 304,672,304,224 });
	NeoGeo5.PushBack({ 0,  672,304,224 });
	NeoGeo5.PushBack({ 608,448,304,224 });
	NeoGeo5.PushBack({ 304,448,304,224 });
	NeoGeo5.PushBack({ 0,  448,304,224 });
	NeoGeo5.PushBack({ 608,224,304,224 });
	NeoGeo5.PushBack({ 304,224,304,224 });
	NeoGeo5.PushBack({ 0,  224,304,224 });
	NeoGeo5.PushBack({ 608,0,304,224 });
	NeoGeo5.PushBack({ 304,0,304,224 });
	NeoGeo5.PushBack({ 0,  0,304,224 });
	NeoGeo5.speed = 0.25f;
	NeoGeo5.loop = false;


	NeoGeo4.PushBack({ 608,672,304,224 });
	NeoGeo4.PushBack({ 304,672,304,224 });
	NeoGeo4.PushBack({ 0,  672,304,224 });
	NeoGeo4.PushBack({ 608,448,304,224 });
	NeoGeo4.PushBack({ 304,448,304,224 });
	NeoGeo4.PushBack({ 0,  448,304,224 });
	NeoGeo4.PushBack({ 608,224,304,224 });
	NeoGeo4.PushBack({ 304,224,304,224 });
	NeoGeo4.PushBack({ 0,  224,304,224 });
	NeoGeo4.PushBack({ 608,0,304,224 });
	NeoGeo4.PushBack({ 304,0,304,224 });
	NeoGeo4.PushBack({ 0,  0,304,224 });
	NeoGeo4.speed = 0.25f;
	NeoGeo4.loop = false;


	NeoGeo3.PushBack({ 608,672,304,224 });
	NeoGeo3.PushBack({ 304,672,304,224 });
	NeoGeo3.PushBack({ 0,  672,304,224 });
	NeoGeo3.PushBack({ 608,448,304,224 });
	NeoGeo3.PushBack({ 304,448,304,224 });
	NeoGeo3.PushBack({ 0,  448,304,224 });
	NeoGeo3.PushBack({ 608,224,304,224 });
	NeoGeo3.PushBack({ 304,224,304,224 });
	NeoGeo3.PushBack({ 0,  224,304,224 });
	NeoGeo3.PushBack({ 608,0,304,224 });
	NeoGeo3.PushBack({ 304,0,304,224 });
	NeoGeo3.PushBack({ 0,  0,304,224 });
	NeoGeo3.speed = 0.25f;
	NeoGeo3.loop = false;


	NeoGeo2.PushBack({ 608,672,304,224 });
	NeoGeo2.PushBack({ 304,672,304,224 });
	NeoGeo2.PushBack({ 0,  672,304,224 });
	NeoGeo2.PushBack({ 608,448,304,224 });
	NeoGeo2.PushBack({ 304,448,304,224 });
	NeoGeo2.PushBack({ 0,  448,304,224 });
	NeoGeo2.PushBack({ 608,224,304,224 });
	NeoGeo2.PushBack({ 304,224,304,224 });
	NeoGeo2.PushBack({ 0,  224,304,224 });
	NeoGeo2.PushBack({ 608,0,304,224 });
	NeoGeo2.PushBack({ 304,0,304,224 });
	NeoGeo2.PushBack({ 0,  0,304,224 });
	NeoGeo2.speed = 0.25f;
	NeoGeo2.loop = false;


	NeoGeo1.PushBack({ 608,672,304,224 });
	NeoGeo1.PushBack({ 304,672,304,224 });
	NeoGeo1.PushBack({ 0,  672,304,224 });
	NeoGeo1.PushBack({ 608,448,304,224 });
	NeoGeo1.PushBack({ 304,448,304,224 });
	NeoGeo1.PushBack({ 0,  448,304,224 });
	NeoGeo1.PushBack({ 608,224,304,224 });
	NeoGeo1.PushBack({ 304,224,304,224 });
	NeoGeo1.PushBack({ 0,  224,304,224 });
	NeoGeo1.PushBack({ 608,0,304,224 });
	NeoGeo1.PushBack({ 304,0,304,224 });
	NeoGeo1.PushBack({ 0,  0,304,224 });
	NeoGeo1.speed = 0.25f;
	NeoGeo1.loop = false;


}

ModuleIntroNeoGeo::~ModuleIntroNeoGeo()
{}

// Load assets
bool ModuleIntroNeoGeo::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	TexNeoGeoImage = App->textures->Load("assets/sprites/Neogeo.png");
	/*NeoGeoTex1 = App->textures->Load("assets/sprites/NeoGeoTitle/Neo_Geo_Title_1.png");
	NeoGeoTex2 = App->textures->Load("assets/sprites/NeoGeoTitle/Neo_Geo_Title_2.png");
	NeoGeoTex3 = App->textures->Load("assets/sprites/NeoGeoTitle/Neo_Geo_Title_3.png");
	NeoGeoTex4 = App->textures->Load("assets/sprites/NeoGeoTitle/Neo_Geo_Title_4.png");
	NeoGeoTex5 = App->textures->Load("assets/sprites/NeoGeoTitle/Neo_Geo_Title_5.png");
	NeoGeoTex6 = App->textures->Load("assets/sprites/NeoGeoTitle/Neo_Geo_Title_6.png");
	NeoGeoTex7 = App->textures->Load("assets/sprites/NeoGeoTitle/Neo_Geo_Title_7.png");
	NeoGeoTex8 = App->textures->Load("assets/sprites/NeoGeoTitle/Neo_Geo_Title_8.png");
	NeoGeoTex9 = App->textures->Load("assets/sprites/NeoGeoTitle/Neo_Geo_Title_9.png");
	
	*/
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
	/*App->textures->Unload(NeoGeoTex1);
	App->textures->Unload(NeoGeoTex2);
	App->textures->Unload(NeoGeoTex3);
	App->textures->Unload(NeoGeoTex4);
	App->textures->Unload(NeoGeoTex5);
	App->textures->Unload(NeoGeoTex6);
	App->textures->Unload(NeoGeoTex7);
	App->textures->Unload(NeoGeoTex8);
	App->textures->Unload(NeoGeoTex9);*/
	App->audio->UnloadMus(mus);

	return true;
}

// Update: draw background
update_status ModuleIntroNeoGeo::Update()
{
	/*
	App->render->Blit(NeoGeoTex9, 0, 0, &NeoGeo1.GetCurrentFrame(), 1, false);

	if (NeoGeo9.Finished() && NeoGeo8.Finished() != true);
	App->render->Blit(NeoGeoTex8, 0, 0, &NeoGeo8.GetCurrentFrame(), 1, false);
	
	if (NeoGeo8.Finished() && NeoGeo7.Finished() != true);
	App->render->Blit(NeoGeoTex7, 0, 0, &NeoGeo7.GetCurrentFrame(), 1, false);

	if (NeoGeo7.Finished() && NeoGeo6.Finished() != true);
	App->render->Blit(NeoGeoTex6, 0, 0, &NeoGeo6.GetCurrentFrame(), 1, false);

	if (NeoGeo6.Finished() && NeoGeo5.Finished() != true);
	App->render->Blit(NeoGeoTex5, 0, 0, &NeoGeo5.GetCurrentFrame(), 1, false);

	if (NeoGeo5.Finished() && NeoGeo4.Finished() != true);
	App->render->Blit(NeoGeoTex4, 0, 0, &NeoGeo4.GetCurrentFrame(), 1, false);

	if (NeoGeo4.Finished() && NeoGeo3.Finished() != true);
	App->render->Blit(NeoGeoTex3, 0, 0, &NeoGeo3.GetCurrentFrame(), 1, false);

	if (NeoGeo3.Finished() && NeoGeo2.Finished() != true);
	App->render->Blit(NeoGeoTex2, 0, 0, &NeoGeo2.GetCurrentFrame(), 1, false);

	if (NeoGeo2.Finished() && NeoGeo1.Finished() != true);
	App->render->Blit(NeoGeoTex1, 0, 0, &NeoGeo1.GetCurrentFrame(), 1, false);*/

	

	



	// Draw everything --------------------------------------	
	App->render->Blit(TexNeoGeoImage, 0, 0, &StImage);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		if (App->fade->FadeToBlack(this, App->startimage, 1.5f))
			App->audio->FadeMus(750);
	}
	
	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN)
	{
		if (App->fade->FadeToBlack(this, App->background, 1.5f))
			App->audio->FadeMus(750);
	}


	return UPDATE_CONTINUE;
}