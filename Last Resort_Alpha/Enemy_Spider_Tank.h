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
	uint now = 0;
	uint lastshot = 0;
	uint recoil = 2000;
	bool shotting = false;
	bool shotting2 = true;

	bool topleft = true;
	float speed;
	int original_y = 0;
	int original_x = 0;
	

public:

	Enemy_Spider_Tank(int x, int y, int HP);

	void Move();
};

#endif
