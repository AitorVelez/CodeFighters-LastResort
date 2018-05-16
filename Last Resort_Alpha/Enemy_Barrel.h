#ifndef __ENEMY_BARREL_H__
#define __ENEMY_BARREL_H__

#include "Enemy.h"

class Enemy_Barrel : public Enemy
{
private:
	Animation fly;
	int y_original;
public:

	Enemy_Barrel(int x, int y, int HP);

	void Move();
};

#endif //__ENEMY_BARREL_H__