#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleBackground.h"
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


Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = textures = new ModuleTextures();
	modules[4] = background = new ModuleBackground();
	modules[5] = player = new ModulePlayer();
	modules[6] = particles = new ModuleParticles();
	modules[7] = introneogeo = new ModuleIntroNeoGeo();
	modules[8] = startimage = new ModuleStartingImage();
	modules[9] = stageclear = new ModuleStageClear();
	modules[10] = loseimage = new ModuleLoseImage();
	modules[11] = audio = new ModuleAudio(); 
	modules[12] = collision = new ModuleCollision();
	modules[13] = fade = new ModuleFadeToBlack();

	
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