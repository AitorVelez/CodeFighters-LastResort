#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 12

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleBackground;
class ModuleStartingImage;
class ModulePlayer;
class ModuleAudio;
class ModuleLvl2;
class ModuleFadeToBlack;
class ModuleStageClear;
class ModuleLoseImage;
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
	ModuleLoseImage* loseimage = nullptr;
	ModuleAudio* audio = nullptr; 
	ModuleFadeToBlack* fade=nullptr;
	ModuleLvl2* lvl2 = nullptr;

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