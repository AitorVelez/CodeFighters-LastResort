#ifndef __ModuleBackground2_H__
#define __ModuleBackground2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Music;
struct Collider;

class ModuleBackground2 : public Module
{
public:
	ModuleBackground2();
	~ModuleBackground2();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * BackgroundLvl2 = nullptr;
	SDL_Texture * ForegroundLvl2 = nullptr;
	SDL_Texture * hangar_texture = nullptr;
	SDL_Texture * hangar_2_texture = nullptr;
	SDL_Texture * rain = nullptr;

	Mix_Music* mus = nullptr;

	SDL_Rect background2;
	SDL_Rect foreground2;
	SDL_Rect hangar_body;
	SDL_Rect hangar_2_body;

	Animation rain_anim;

	bool activ = false;
	bool scroll = true;
	int bgpos;
	float depth_1;


	int TopTurretPosY = 16; 
	int BottomTurretPosY = 175;
};

#endif

