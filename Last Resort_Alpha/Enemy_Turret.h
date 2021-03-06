#ifndef __ENEMY_TURRET_H__
#define __ENEMY_TURRET_H__

#include "Enemy.h"

class Enemy_Turret : public Enemy
{
private:
	Animation UpLeft;
	Animation UpLeft2;
	Animation UpLeft3;
	Animation UpLeft4;
	Animation Up;
	Animation UpRight;
	Animation UpRight2;
	Animation UpRight3;
	Animation UpRight4;

	Animation DownLeft;
	Animation DownLeft2;
	Animation DownLeft3;
	Animation DownLeft4;
	Animation Down;
	Animation DownRight;
	Animation DownRight2;
	Animation DownRight3;
	Animation DownRight4;

	int original_y;
	int original_x;
	float hyp;
	float dirx;
	float diry;
	bool aimed = false; 
    float BulletSpeed; 
	float proportion; 
	uint current_time = 0;
	uint last_time = 0;
public:

	Enemy_Turret(int x, int y, int HP);
	void Move();
	void Shoot();
};

#endif // __ENEMY_TURRET_H__

