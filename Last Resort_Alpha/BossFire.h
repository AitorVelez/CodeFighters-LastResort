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

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	uint last = 0; 
	uint now = 0; 
public:

	BossFire(int x, int y, int HP);

	void Move();
};

#endif //__ENEMY_BOSS_H__
