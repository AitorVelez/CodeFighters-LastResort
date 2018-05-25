#ifndef __ENEMY_HUNTER_H__
#define __ENEMY_HUNTER_H__

#include "Enemy.h"

class Enemy_Hunter : public Enemy
{
private:
	Animation fly;
	int y_original;
public:

	Enemy_Hunter(int x, int y, int HP);

	void Move();
};

#endif // __ENEMY_HUNTER_H__