#ifndef __ModuleBackground_H__
#define __ModuleBackground_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleBackground : public Module
{
public:
	ModuleBackground();
	~ModuleBackground();

	bool Start();
	update_status Update();

public:
	
	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr; 
	SDL_Rect background;
	SDL_Rect crater;
	SDL_Rect building_1; 
	bool scroll = true; 
};

#endif