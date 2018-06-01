#ifndef __ENEMY_BARREL_H__
#define __ENEMY_BARREL_H__

#include "Enemy.h"

class Enemy_Barrel : public Enemy
{
private:
	Animation fly;
	fPoint original_position;
	Path path;
public:

	Enemy_Barrel(int x, int y, int HP);

	void Move();
};

#endif //__ENEMY_BARREL_H__