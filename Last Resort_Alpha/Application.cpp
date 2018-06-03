#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleBackground.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollision.h"
#include "ModuleStageClear.h"
#include "ModuleParticles.h"
#include "ModuleIntroNeoGeo.h"
#include "ModuleStartingImage.h"
#include "ModuleCollision.h"
#include "ModuleLoseImage.h"
#include "Module.h"
#include "ModulePlayer2.h"
#include "ModulePowerUp.h"
#include "ModuleBall.h"
#include "ModuleBall_P2.h"
#include "ModuleFonts.h"
#include "ModuleUI.h"
#include "ModuleReady.h"
#include "ModuleBackground2.h"

Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = textures = new ModuleTextures();
	modules[4] = background = new ModuleBackground();
	modules[5] = background2 = new ModuleBackground2();
	modules[6] = enemies = new ModuleEnemies(); 
	modules[7] = player2 = new ModulePlayer2();
	modules[8] = particles = new ModuleParticles();
	modules[9] = introneogeo = new ModuleIntroNeoGeo();
	modules[10] = startimage = new ModuleStartingImage();
	modules[11] = stageclear = new ModuleStageClear();
	modules[12] = loseimage = new ModuleLoseImage();
	modules[13] = audio = new ModuleAudio(); 
	modules[14] = collision = new ModuleCollision();
	modules[15] = fade = new ModuleFadeToBlack();
	modules[16] = player = new ModulePlayer();
	modules[20] = power = new ModulePowerUp();		
	modules[18] = ball = new ModuleBall();
	modules[19] = ball_p2 = new ModuleBall_P2();
	modules[17] = UI = new ModuleUI();
	modules[21] = Fonts = new ModuleFonts();
	modules[22] = Ready = new ModuleReady();

}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	//introneogeo->Disable();
	startimage->Disable();
	player->Disable();
	player2->Disable();
	particles->Disable(); 
	background->Disable();
	stageclear->Disable();
	loseimage->Disable();
	collision->Disable();
    enemies->Disable();
	power->Disable();
	ball->Disable();
	ball_p2->Disable(); 
	Fonts->Disable();
	UI->Disable();
	Ready->Disable();
	background2->Disable(); 

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;


	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;
	
	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}