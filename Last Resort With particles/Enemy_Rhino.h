#ifndef __ENEMY_RHINO_H__
#define __ENEMY_RHINO_H__

#include "Enemy.h"

class Enemy_Rhino : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;

public:

	Enemy_Rhino(int x, int y);

	void Move();
};

#endif // __ENEMY_RHINO_H__