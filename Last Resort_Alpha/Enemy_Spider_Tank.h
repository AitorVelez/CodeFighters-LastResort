#ifndef __ENEMY_SPIDER_TANK_H__
#define __ENEMY_SPIDER_TANK_H__

#include "Enemy.h"

class Enemy_Spider_Tank : public Enemy
{
private:


	Animation Upright;
	Animation Upleft;
	Animation Downright;
	Animation Downleft;
	bool topleft = false;
	float speed;
	int original_y = 0;
	int original_x = 0;
	

public:

	Enemy_Spider_Tank(int x, int y, int HP);

	void Move();
};

#endif
