#ifndef _MODULEBALL_H__
#define _MODULEBALL_H__

#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "Animation.h"
#include "Application.h"

#define BALL_SIZE 30

struct SDL_Texture;
struct Collider;
struct Particle;

class ModuleBall : public Module {

public:

	ModuleBall();
	~ModuleBall();

	bool Start();
	void Ball_Input_Movement();
	void Ball_Input_Attack();
	void Ball_Launch();
	void Ball_Set_Angle();
	void Ball_Set_Position(); 
	update_status Update();
	bool CleanUp();
	//bool CleanUp();


	Animation N;
	Animation NNE;
	Animation NE;
	Animation NEE;
	Animation E;
	Animation SEE;
	Animation SE;
	Animation SSE;
	Animation S;
	Animation SSW;
	Animation SW;
	Animation SWW;
	Animation W;
	Animation NWW;
	Animation NW;
	Animation NNW;
	Animation flying;

	Animation* current_animation = nullptr;
	Animation test;
	Collider* ball_collider = nullptr;
public:
	bool go_back = false;
	bool in_place = false;
	bool ball_launched = false;
	bool ball_locked = false;
	int angle = 0;
	int angle_speed = 10;

	float angle_aiming = 0;
	float angle_aiming_speed = 11.25;


	uint charge = 0;
	iPoint ball_position;
	iPoint center_player;
	SDL_Texture* texture = nullptr;
};


#endif //_MODULEBALL_H__