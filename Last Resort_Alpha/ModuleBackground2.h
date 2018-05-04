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
	Mix_Music* mus = nullptr;

	SDL_Rect background2;

	bool activ = false;
	bool scroll = true;
	int bgpos;
	float depth_1;
};

#endif

