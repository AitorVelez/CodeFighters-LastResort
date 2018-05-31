#ifndef __ENEMY_ROCKET_H__
#define __ENEMY_ROCKET_H__

#include "Enemy.h"

class Enemy_Rocket : public Enemy
{
private:
	
public:

	Enemy_Rocket(int x, int y, int HP);

	void Move();
};

#endif // __ENEMY_ROCKET_H__
