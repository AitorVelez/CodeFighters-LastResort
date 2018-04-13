#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;
struct Mix_Chunk;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp(); 
	void RenderStartingAnim(); 
public:

	SDL_Texture* graphics = nullptr;
	Animation idle;
	Animation up;
	Animation down; 
	Animation forward;
	Animation backward;
	Animation playershowup; 
	fPoint position;
	fPoint relativeposition;

	Mix_Chunk* chunk;

};

#endif
