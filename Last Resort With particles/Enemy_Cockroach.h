#ifndef __ENEMY_COCKROACH_H__
#define __ENEMY_COCKROACH_H__

#include "Enemy.h"

class Enemy_Cockroach : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;

public:

	Enemy_Cockroach(int x, int y);

	void Move();
};

#endif // __ENEMY_COCKROACH_H__