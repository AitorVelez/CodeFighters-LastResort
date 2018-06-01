#ifndef __ENEMY_ROCKET_H__
#define __ENEMY_ROCKET_H__

#include "Enemy.h"

class Enemy_Rocket : public Enemy
{
private:
	Animation left;
	Animation Right;
	Animation Up;
	Animation Down;
	Animation ne1;
	Animation ne2;
	Animation ne3;
	Animation se1;
	Animation se2;
	Animation se3;
	Animation sw1;
	Animation sw2;
	Animation sw3;
	Animation nw1;
	Animation nw2;
	Animation nw3;
	uint now = 0;
	uint last = 0;
	uint shot = 0;
	uint aim = 0;
	float angle;

	int original_y = 0;
	float dirx;
	float diry;
	float speed;
	int original_x = 0;
	int hyp;



public:

	Enemy_Rocket(int x, int y, int HP);

	void Move();
};

#endif // __ENEMY_ROCKET_H__
