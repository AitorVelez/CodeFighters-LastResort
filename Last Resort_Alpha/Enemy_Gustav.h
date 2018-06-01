#ifndef __ENEMY_GUSTAV_H__
#define __ENEMY_GUSTAV_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Gustav : public Enemy
{
private:
	Animation up_anim;

	
	Path up;
	Path down;
	int speed = 0;

	bool player_higher = false;
	bool player_lower = false;

	fPoint original_position;
public:

	Enemy_Gustav(int x, int y, int HP);
	void Move();
};

#endif // __ENEMY_GUSTAV_H__
