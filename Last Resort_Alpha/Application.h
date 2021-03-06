#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 23

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleBackground;
class ModuleStartingImage;
class ModuleEnemies; 
class ModulePlayer2;
class ModuleAudio;
class ModuleParticles;
class ModuleFadeToBlack;
class ModuleCollision;
class ModuleStageClear;
class ModuleLoseImage;
class ModuleIntroNeoGeo;
class Module;
class ModulePlayer;
class ModulePowerUp;
class ModuleUI;
class ModuleBall; 
class ModuleBall_P2;  
class ModuleFonts;
class ModuleReady;
class ModuleBackground2; 

class Application
{
public:

	Module * modules[NUM_MODULES] = { nullptr };
	ModuleWindow* window = nullptr;
	ModuleRender* render = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	ModuleBackground* background = nullptr;
	ModuleBackground2* background2 = nullptr;
	ModuleStartingImage* startimage = nullptr;
	ModuleEnemies* enemies = nullptr; 
	ModulePlayer2* player2 = nullptr;
	ModuleStageClear* stageclear = nullptr;
	ModuleParticles* particles = nullptr;
	ModuleLoseImage* loseimage = nullptr;
	ModuleIntroNeoGeo* introneogeo = nullptr;
	ModuleCollision* collision = nullptr;
	ModuleAudio* audio = nullptr; 
	ModuleFadeToBlack* fade=nullptr;
	ModulePlayer* player = nullptr;
	ModulePowerUp* power = nullptr;
	ModuleBall* ball = nullptr;
	ModuleBall_P2* ball_p2 = nullptr; 
	ModuleUI* UI = nullptr;
	ModuleFonts* Fonts = nullptr;
	ModuleReady* Ready = nullptr;
	
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