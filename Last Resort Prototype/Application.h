#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

<<<<<<< HEAD
#define NUM_MODULES 9
=======
#define NUM_MODULES 12
>>>>>>> parent of 2490e7f... Module Particles included

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleBackground;
class ModuleStartingImage;
class ModulePlayer;
class ModuleAudio;
<<<<<<< HEAD
=======
class ModuleLvl2;
>>>>>>> parent of 2490e7f... Module Particles included
class ModuleFadeToBlack;
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
<<<<<<< HEAD
=======
	ModuleStageClear* stageclear = nullptr;
	ModuleLoseImage* loseimage = nullptr;
>>>>>>> parent of 2490e7f... Module Particles included
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