#ifndef __ENEMY_TANK_H__
#define __ENEMY_TANK_H__

#include "Enemy.h"

class Enemy_Tank : public Enemy
{
private:
	Animation tank;
	Animation canon; 
	Animation canon2;
	int original_y; 
	int original_x; 
public:

	Enemy_Tank(int x, int y);

	void Move();
	void Shoot(); 

	int RelToBg; 
};

#endif // __ENEMY_TANK_H__
