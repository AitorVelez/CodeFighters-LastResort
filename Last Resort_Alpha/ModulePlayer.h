#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"




struct SDL_Texture;
struct Collider;
struct Mix_Chunk;

enum BULLET_STATE
{
	BULLET_NO_TYPE=1,
	LASER1,
	LASER2,
	GRENADE1,
	HELLFIRE1,
};

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
	Animation *current_animation = nullptr;
	Animation idle;
	Animation up;
	Animation down; 
	Animation playershowup; 
	Animation playershowup2;
	Animation playershowup3;
	Animation re_up;
	Animation re_down;
	Animation death;
	Animation WaterUp;
	Animation WaterDown;
	Animation Water;
	Animation re_WaterUp;
	Animation re_WaterDown;
	Animation none; 
	iPoint position;
	fPoint relativeposition;
	Collider *PlayerCollider = nullptr;
	BULLET_STATE bullet_state=BULLET_NO_TYPE;

	int score_p1 = 0;	
	bool alive_p1 = true; 
	bool death_played = false;
	bool god_mode = false; 
	int speed = 2;
	int lives = 3; 
	bool SwitchToBg2 = false; 
	uint now = 0; 
	uint last = 1000;
	uint current_time = 0;
	uint last_time = 0; 
};

#endif
