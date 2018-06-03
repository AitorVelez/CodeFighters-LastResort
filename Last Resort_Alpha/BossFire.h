#ifndef __BOSS_FIRE_H__
#define __BOSS_FIRE_H__

#include "Enemy.h"

class BossFire : public Enemy
{
private:
	Animation middle; 
	Animation up; 
	Animation Moreup;
	Animation Down;
	Animation MoreDown;

	Animation Fire;
	int xx;
	int yy;
	int original_x;
	float wave = -1.0f;
	float FirePosX = 0; 
	bool going_up = true;
	int original_y = 0;
	uint fire = 0;
	uint recoill = 0;
	uint last = 0; 
	uint now = 0; 

public:

	BossFire(int x, int y, int HP);

	void Move();
};

#endif //__ENEMY_BOSS_H__
