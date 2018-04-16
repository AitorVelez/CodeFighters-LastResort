#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 14

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleBackground;
class ModuleStartingImage;
class ModulePlayer;
class ModuleAudio;
class ModuleParticles;
class ModuleFadeToBlack;
class ModuleCollision;
class ModuleStageClear;
class ModuleLoseImage;
class ModuleIntroNeoGeo;
class Module;

class Application
{
public:

	Module * modules[NUM_MODULES] = { nullptr };
	ModuleWindow* window = nullptr;
	ModuleRender* render = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	ModuleBackground* background = nullptr;
	ModuleStartingImage* startimage = nullptr;
	ModulePlayer* player = nullptr;
	ModuleStageClear* stageclear = nullptr;
	ModuleParticles* particles = nullptr;
	ModuleLoseImage* loseimage = nullptr;
	ModuleIntroNeoGeo* introneogeo = nullptr;
	ModuleCollision* collision = nullptr;
	ModuleAudio* audio = nullptr; 
	ModuleFadeToBlack* fade=nullptr;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__