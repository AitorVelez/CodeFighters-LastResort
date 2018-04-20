#ifndef __ENEMY_TANK_H__
#define __ENEMY_TANK_H__

#include "Enemy.h"

class Enemy_Tank : public Enemy
{
private:
	Animation tank;
	Animation canon; 
	Animation canon2;
	Animation canonUp;
	Animation canon2Up;
	Animation canonUpLeft;
	Animation canon2UpLeft;
    Animation canonUpRight;
	Animation canon2UpRight;
	Animation canonUpMoreLeft;
	Animation canonUpMoreRight;
	Animation canonRight;
	Animation canon2Right;

	int original_y; 
	int original_x; 
public:

	Enemy_Tank(int x, int y);

	void Move();
	void Shoot(); 

};

#endif // __ENEMY_TANK_H__
