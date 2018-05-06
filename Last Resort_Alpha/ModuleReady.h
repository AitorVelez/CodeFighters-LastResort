#ifndef __MODULEREADY_H__
#define __MODULEREADY_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleReady : public Module
{
public:
	ModuleReady();
	~ModuleReady();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * TextReadyImage = nullptr;
	SDL_Rect ReadyImage;
	uint last_time = 0;
	uint current_time = 0;
};

#endif // __MODULEREADY_H__
