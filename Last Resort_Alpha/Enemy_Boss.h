#ifndef __ENEMY_BOSS_H__
#define __ENEMY_BOSS_H__

#include "Enemy.h"

class Enemy_Boss : public Enemy
{
private:
	Animation AnimMove;
	
	Animation FireSpot; 
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	bool FireThrowerSpawned = false; 
public:

	Enemy_Boss(int x, int y, int HP);

	void Move();
};

#endif //__ENEMY_BOSS_H__