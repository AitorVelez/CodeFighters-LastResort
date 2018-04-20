#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;
struct Mix_Chunk;

class ModulePlayer2 : public Module
{
public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);


public:

	SDL_Texture* graphics = nullptr;
	Animation *current_animation;
	Animation idle;
	Animation up;
	Animation down;
	Animation forward;
	Animation backward;
	Animation playershowup;
	Animation playershowup2;
	Animation playershowup3;
	Animation re_up;
	Animation re_down;
	Animation death;
	iPoint position;
	fPoint relativeposition;
	Collider* PlayerCollider = nullptr;

	bool alive_p2 = true;
	bool death_played = false; // different than player one 
	bool god_mode = true;

	Mix_Chunk* chunk;

};

#endif

