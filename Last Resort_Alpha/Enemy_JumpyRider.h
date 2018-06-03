#ifndef __ENEMY_JUMPYRIDER_H__
#define __ENEMY_JUMPYRIDER_H__

#include "Enemy.h"

class Enemy_JumpyRider : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;
	bool JumpySpawned = false; 
	float dirx; 
	float diry; 

public:

	Enemy_JumpyRider(int x, int y, int HP);
	uint now = 0; 
	uint last = 0; 

	void Move();
};

#endif // __ENEMY_RHINO_H__