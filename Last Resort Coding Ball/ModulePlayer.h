#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

enum PLAYER_DIRECTION {
	GOING_DOWN,
	GOING_LEFT, 
	GOING_RIGHT,
	GOING_UP,
	GOING_UP_LEFT,
	GOING_UP_RIGHT,
	GOING_DOWN_LEFT,
	GOING_DOWN_RIGHT,
};

struct SDL_Texture;
struct Collider;
struct Mix_Chunk;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();  
	void OnCollision(Collider* c1, Collider* c2);

	/*void SwitchToDown(Animation*);     // switch animation functions, they should recieve the "idle" animation
	void SwitchToUp(Animation*);*/
public:

	SDL_Texture* graphics = nullptr;
	Animation *current_animation;
	Animation idle;
	Animation up;
	Animation down; 
	Animation playershowup; 
	Animation playershowup2;
	Animation playershowup3;
	Animation re_up;
	Animation re_down;
	Animation death;
	iPoint position;
	fPoint relativeposition;
	Collider *PlayerCollider = nullptr;
	
	PLAYER_DIRECTION player_direction; 
	bool alive = true; 
	bool death_played = false;

	Mix_Chunk* chunk;

};

#endif
