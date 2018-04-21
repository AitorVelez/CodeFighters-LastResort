#include "Globals.h"
#include "Application.h"
#include "ModuleStartingImage.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleBackground.h"
#include "ModuleStageClear.h"
#include "Application.h"
#include "ModulePlayer2.h"
#include "Animation.h"
#include "SDL\include\SDL_timer.h"

ModuleStartingImage::ModuleStartingImage()
{
	StImage.x = 0;
	StImage.y = 0;
	StImage.w = SCREEN_WIDTH;
	StImage.h = SCREEN_HEIGHT;

	
	currentTime = SDL_GetTicks();

	/*
	Press.PushBack({ 0,0,138,10 });
	Press.PushBack({ 0,13,138,10 });
	Press.PushBack({ 0,27,138,10 });
	Press.PushBack({ 0,41,138,10 });
	Press.PushBack({ 0,55,138,10 });
	Press.PushBack({ 0,69,138,10 });
	Press.PushBack({ 0,55,138,10 });
	Press.PushBack({ 0,41,138,10 });
	Press.PushBack({ 0,27,138,10 });
	Press.PushBack({ 0,13,138,10 });
	Press.speed = 0.5f;
	*/


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
	Title1.speed = 0.5f;
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
	Title2.speed = 0.5f;
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
		Title3.speed = 0.5f;
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
		Title4.speed = 0.5f;
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
		Title5.speed = 0.5f;
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
		Title6.speed = 0.5f;
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
		Title7.speed = 0.5f;
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
		Title8.speed = 0.5f;
		Title8.loop = false;
	
		Title9.PushBack({ 0,  0,304,224 });
		Title9.PushBack({ 304,0,304,224 });
		Title9.PushBack({ 608,0,304,224 });
		Title9.PushBack({ 0,  224,304,224 });
		Title9.PushBack({ 304,224,304,224 });
		Title9.PushBack({ 608,224,304,224 });
		Title9.PushBack({ 0,  448,304,224 });
		Title9.PushBack({ 304,448,304,224 });
		Title9.PushBack({ 608,448,304,224 });
		Title9.PushBack({ 0,  672,304,224 });
		Title9.PushBack({ 304,672,304,224 });
		Title9.PushBack({ 608,672,304,224 });
		Title9.speed = 0.5f;
		Title9.loop = false;
	
		Title10.PushBack({ 0,  0,304,224 });
		Title10.PushBack({ 304,0,304,224 });
		Title10.PushBack({ 608,0,304,224 });
		Title10.PushBack({ 0,  224,304,224 });
		Title10.PushBack({ 304,224,304,224 });
		Title10.PushBack({ 608,224,304,224 });
		Title10.PushBack({ 0,  448,304,224 });
		Title10.PushBack({ 304,448,304,224 });
		Title10.PushBack({ 608,448,304,224 });
		Title10.PushBack({ 0,  672,304,224 });
		Title10.PushBack({ 304,672,304,224 });
		Title10.PushBack({ 608,672,304,224 });
		Title10.speed = 0.5f;
		Title10.loop = false;

		Title11.PushBack({ 0,  0,304,224 });
		Title11.PushBack({ 304,0,304,224 });
		Title11.PushBack({ 608,0,304,224 });
		Title11.PushBack({ 0,  224,304,224 });
		Title11.PushBack({ 304,224,304,224 });
		Title11.PushBack({ 608,224,304,224 });
		Title11.PushBack({ 0,  448,304,224 });
		Title11.PushBack({ 304,448,304,224 });
		Title11.PushBack({ 608,448,304,224 });
		Title11.PushBack({ 0,  672,304,224 });
		Title11.PushBack({ 304,672,304,224 });
		Title11.PushBack({ 608,672,304,224 });
		Title11.speed = 0.5f;
		Title11.loop = false;
	
		Title12.PushBack({ 0,  0,304,224 });
		Title12.PushBack({ 304,0,304,224 });
		Title12.PushBack({ 608,0,304,224 });
		Title12.PushBack({ 0,  224,304,224 });
		Title12.PushBack({ 304,224,304,224 });
		Title12.PushBack({ 608,224,304,224 });
		Title12.PushBack({ 0,  448,304,224 });
		Title12.PushBack({ 304,448,304,224 });
		Title12.PushBack({ 608,448,304,224 });
		Title12.PushBack({ 0,  672,304,224 });
		Title12.PushBack({ 304,672,304,224 });
		Title12.PushBack({ 608,672,304,224 });
		Title12.speed = 0.5f;
		Title12.loop = false;

		Title13.PushBack({ 0,  0,304,224 });
		Title13.PushBack({ 304,0,304,224 });
		Title13.PushBack({ 608,0,304,224 });
		Title13.PushBack({ 0,  224,304,224 });
		Title13.PushBack({ 304,224,304,224 });
		Title13.PushBack({ 608,224,304,224 });
		Title13.PushBack({ 0,  448,304,224 });
		Title13.PushBack({ 304,448,304,224 });
		Title13.PushBack({ 608,448,304,224 });
		Title13.PushBack({ 0,  672,304,224 });
		Title13.PushBack({ 304,672,304,224 });
		Title13.PushBack({ 608,672,304,224 });
		Title13.speed = 0.5f;
		Title13.loop = false;
	
		Title14.PushBack({ 0,  0,304,224 });
		Title14.PushBack({ 304,0,304,224 });
		Title14.PushBack({ 608,0,304,224 });
		Title14.PushBack({ 0,  224,304,224 });
		Title14.PushBack({ 304,224,304,224 });
		Title14.PushBack({ 608,224,304,224 });
		Title14.PushBack({ 0,  448,304,224 });
		Title14.PushBack({ 304,448,304,224 });
		Title14.PushBack({ 608,448,304,224 });
		Title14.PushBack({ 0,  672,304,224 });
		Title14.PushBack({ 304,672,304,224 });
		Title14.PushBack({ 608,672,304,224 });
		Title14.speed = 0.5f;
		Title14.loop = false;
	

		Title15.PushBack({ 0,  0,304,224 });
		Title15.PushBack({ 304,0,304,224 });
		Title15.PushBack({ 608,0,304,224 });
		Title15.PushBack({ 0,  224,304,224 });
		Title15.PushBack({ 304,224,304,224 });
		Title15.PushBack({ 608,224,304,224 });
		Title15.PushBack({ 0,  448,304,224 });
		Title15.PushBack({ 304,448,304,224 });
		Title15.PushBack({ 608,448,304,224 });
		Title15.PushBack({ 0,  672,304,224 });
		Title15.PushBack({ 304,672,304,224 });
		Title15.PushBack({ 608,672,304,224 });
		Title15.speed = 0.5f;
		Title15.loop = false;
		
	
	
		Title16.PushBack({ 0,  0,304,224 });
		Title16.PushBack({ 304,0,304,224 });
		Title16.PushBack({ 608,0,304,224 });
		Title16.PushBack({ 0,  224,304,224 });
		Title16.PushBack({ 304,224,304,224 });
		Title16.PushBack({ 608,224,304,224 });
		Title16.PushBack({ 0,  448,304,224 });
		Title16.PushBack({ 304,448,304,224 });
		Title16.PushBack({ 608,448,304,224 });
		Title16.PushBack({ 0,  672,304,224 });
		Title16.PushBack({ 304,672,304,224 });
		Title16.PushBack({ 608,672,304,224 });
		Title16.speed = 0.5f;
		Title16.loop = false;
	
	
	
		Title17.PushBack({ 0,  0,304,224 });
		Title17.PushBack({ 304,0,304,224 });
		Title17.PushBack({ 608,0,304,224 });
		Title17.PushBack({ 0,  224,304,224 });
		Title17.PushBack({ 304,224,304,224 });
		Title17.PushBack({ 608,224,304,224 });
		Title17.PushBack({ 0,  448,304,224 });
		Title17.PushBack({ 304,448,304,224 });
		Title17.PushBack({ 608,448,304,224 });
		Title17.PushBack({ 0,  672,304,224 });
		Title17.PushBack({ 304,672,304,224 });
		Title17.speed = 0.5f;
		Title17.loop = false;
	
	
	
}

ModuleStartingImage::~ModuleStartingImage()
{}

// Load assets
bool ModuleStartingImage::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	//TexStImage = App->textures->Load("assets/sprites/StartingTitle2.png");

	TitleTex1 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_1.png");
	TitleTex2 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_2.png");
	TitleTex3 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_3.png");
	TitleTex4 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_4.png");
	TitleTex5 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_5.png");
	TitleTex6 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_6.png");
	TitleTex7 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_7.png");
	TitleTex8 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_8.png");
	TitleTex9 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_9.png");
	TitleTex10 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_10.png");
	TitleTex11 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_11.png");
	TitleTex12 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_12.png");
	TitleTex13 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_13.png");
	TitleTex14 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_14.png");
	TitleTex15 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_15.png");
	TitleTex16 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_16.png");
	TitleTex17 = App->textures->Load("assets/sprites/LastResortTitle/Last_Resort_Title_17.png");

	mus = App->audio->LoadMus("assets/SFX/last_resort_tittle.ogg");
	App->audio->PlayMus(mus);
	Starts = App->textures->Load("assets/sprites/Start.png");

	App->render->camera.x = 0;
	App->render->camera.y = 0;
	App->player->Disable(); 
	App->player2->Disable();
	return ret;
}

// Load assets
bool ModuleStartingImage::CleanUp()
{
	LOG("Unloading Intro Scene");
	App->textures->Unload(TexStImage);
	App->textures->Unload(TitleTex1);
	App->textures->Unload(TitleTex2);
	App->textures->Unload(TitleTex3);
	App->textures->Unload(TitleTex4);
	App->textures->Unload(TitleTex5);
	App->textures->Unload(TitleTex6);
	App->textures->Unload(TitleTex7);
	App->textures->Unload(TitleTex8);
	App->textures->Unload(TitleTex9);
	App->textures->Unload(TitleTex10);
	App->textures->Unload(TitleTex11);
	App->textures->Unload(TitleTex12);
	App->textures->Unload(TitleTex13);
	App->textures->Unload(TitleTex14);
	App->textures->Unload(TitleTex15);
	App->textures->Unload(TitleTex16);
	App->textures->Unload(TitleTex17);

	App->textures->Unload(Starts);
	App->audio->UnloadMus(mus);

	return true;
}

// Update: draw background
update_status ModuleStartingImage::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(TexStImage, 0, 0, &StImage);
	//App->render->Blit(Starts, 130, 170, &Press.GetCurrentFrame(), 0, false);


	if(currentTime>lastTime+200)
	App->render->Blit(TitleTex1, 0, 0, &Title1.GetCurrentFrame(), 1, false);

	if (Title1.Finished() && Title2.Finished() != true);
	App->render->Blit(TitleTex2, 0, 0, &Title2.GetCurrentFrame(), 1, false);
	
	if (Title2.Finished() && Title3.Finished() != true)
	App->render->Blit(TitleTex3, 0, 0, &Title3.GetCurrentFrame(), 1, false);
	
	if (Title3.Finished() && Title4.Finished() != true)
	App->render->Blit(TitleTex4, 0, 0, &Title4.GetCurrentFrame(), 1, false);
	
	if (Title4.Finished() && Title5.Finished() != true)
	App->render->Blit(TitleTex5, 0, 0, &Title5.GetCurrentFrame(), 1, false);
	
	if (Title5.Finished() && Title6.Finished() != true)
	App->render->Blit(TitleTex6, 0, 0, &Title6.GetCurrentFrame(), 1, false);
	
	if (Title6.Finished() && Title7.Finished() != true)
	App->render->Blit(TitleTex7, 0, 0, &Title7.GetCurrentFrame(), 1, false);
	
	if (Title7.Finished() && Title8.Finished() != true)
	App->render->Blit(TitleTex8, 0, 0, &Title8.GetCurrentFrame(), 1, false);
	
	if (Title8.Finished() && Title9.Finished() != true)
	App->render->Blit(TitleTex9, 0, 0, &Title9.GetCurrentFrame(), 1, false);
	
	if (Title9.Finished() && Title10.Finished() != true)
	App->render->Blit(TitleTex10, 0, 0, &Title10.GetCurrentFrame(), 1, false);
	
	if (Title10.Finished() && Title11.Finished() != true)
	App->render->Blit(TitleTex11, 0, 0, &Title11.GetCurrentFrame(), 1, false);
	
	if (Title11.Finished() && Title12.Finished() != true)
	App->render->Blit(TitleTex12, 0, 0, &Title12.GetCurrentFrame(), 1, false);

	if (Title12.Finished() && Title13.Finished() != true)
	App->render->Blit(TitleTex13, 0, 0, &Title13.GetCurrentFrame(), 1, false);
	
	if (Title13.Finished() && Title14.Finished() != true)
	App->render->Blit(TitleTex14, 0, 0, &Title14.GetCurrentFrame(), 1, false);
	
	if (Title14.Finished() && Title15.Finished() != true)
	App->render->Blit(TitleTex15, 0, 0, &Title15.GetCurrentFrame(), 1, false);
	
	if (Title15.Finished() && Title16.Finished() != true)
	App->render->Blit(TitleTex16, 0, 0, &Title16.GetCurrentFrame(), 1, false);
	
	if (Title16.Finished() && Title17.Finished() != true)
	App->render->Blit(TitleTex16, 0, 0, &Title17.GetCurrentFrame(), 1, false);



	if (currentTime > lastTime + 15000) {
		if (App->fade->FadeToBlack(App->startimage, App->background, 1.5f))
			App->audio->FadeMus(750);
	}



	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		if (App->fade->FadeToBlack(App->startimage, App->background, 1.5f))
			App->audio->FadeMus(750);
	}

	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN)
	{
		if (App->fade->FadeToBlack(this, App->background, 1.5f))
			App->audio->FadeMus(750);
	}


	return UPDATE_CONTINUE;
}