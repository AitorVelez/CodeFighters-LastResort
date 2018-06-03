#ifndef __ENEMY_BOSS_H__
#define __ENEMY_BOSS_H__

#include "Enemy.h"

class Enemy_Boss : public Enemy
{
private:
	Animation AnimMove; 
	Animation FireSpot; 
	Animation FireSpotMove; 
	Animation FireSpotDespawn;

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	bool FireThrowerSpawned = false; 
	bool FireSpotSpawned = true; 
	uint now = 0; 
	uint last = 0; 
	uint GreenShotTimer = 0; 
	uint GreenLast = 0; 
	bool IsFiringGreen = false; 
public:

	Enemy_Boss(int x, int y, int HP);

	void Move();
};

#endif //__ENEMY_BOSS_H__