#ifndef __ENEMY_JUMPY_H__
#define __ENEMY_JUMPY_H__

#include "Enemy.h"

class Enemy_Jumpy : public Enemy
{
private:
	Animation fly;
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
public:

	Enemy_Jumpy(int x, int y, int HP);

	void Move();
};

#endif //__ENEMY_JUMPY_H__