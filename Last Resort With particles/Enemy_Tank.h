#ifndef __ENEMY_TANK_H__
#define __ENEMY_TANK_H__

#include "Enemy.h"

class Enemy_Tank : public Enemy
{
private:
	Animation tank;

public:

	Enemy_Tank(int x, int y);

	void Move();
};

#endif // __ENEMY_TANK_H__
