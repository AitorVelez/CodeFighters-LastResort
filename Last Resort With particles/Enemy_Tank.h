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
	Animation *AnimationBigCanon; 
	Animation *AnimationSmallCanon;

	int original_y; 
	int original_x; 
	int BigBulletDirx; 
	int BigBulletDiry;
	int speed; 
	int SmallBulletDirx;
	int SmallBulletDiry;

	uint current_time = 0;
	uint last_time = 0;
public:

	Enemy_Tank(int x, int y);

	void Move();
	void Shoot();
};

#endif // __ENEMY_TANK_H__
