#ifndef __ENEMY_METAL_BEE_H__
#define __ENEMY_METAL_BEE_H__

#include "Enemy.h"

class Enemy_Metal_Bee : public Enemy
{
private:

	int original_y = 0;
	int aniam;
	float dirx;
	float diry;
	float speed;
	int original_x = 0;
	Animation Right1;
	Animation Right2;
	Animation Right;
	Animation Left1;
	Animation Left2;
	Animation Left;
	Animation frontleft;
	Animation frontright;
	Animation backleft;
	Animation backright;
	Animation front;
	Animation Back;
	int hyp;

public:

	Enemy_Metal_Bee(int x, int y, int HP);

	void Move();
};

#endif // METAL_BEE_H__ #pragma once
