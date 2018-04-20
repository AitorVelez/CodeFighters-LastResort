#ifndef __ENEMY_COCKROACH_H__
#define __ENEMY_COCKROACH_H__

#include "Enemy.h"

class Enemy_Cockroach : public Enemy
{
private:
	Animation fly;
	int y_original;
public:

	Enemy_Cockroach(int x, int y);

	void Move();
};

#endif // __ENEMY_COCKROACH_H__