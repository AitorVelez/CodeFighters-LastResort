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
#include "ModuleBall.h"
#include "Module.h"


Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = textures = new ModuleTextures();
	modules[4] = background = new ModuleBackground();
	modules[5] = enemies = new ModuleEnemies(); 
	modules[6] = player = new ModulePlayer();
	modules[7] = particles = new ModuleParticles();
	modules[8] = introneogeo = new ModuleIntroNeoGeo();
	modules[9] = startimage = new ModuleStartingImage();
	modules[10] = stageclear = new ModuleStageClear();
	modules[11] = loseimage = new ModuleLoseImage();
	modules[12] = audio = new ModuleAudio(); 
	modules[13] = collision = new ModuleCollision();
	modules[14] = fade = new ModuleFadeToBlack();
	modules[15] = ball = new ModuleBall(); 
	
}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	startimage->Disable();
	player->Disable();
	particles->Disable(); 
	background->Disable();
	stageclear->Disable();
	loseimage->Disable();
	collision->Disable();
	ball->Disable(); 
	enemies->Disable(); 


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