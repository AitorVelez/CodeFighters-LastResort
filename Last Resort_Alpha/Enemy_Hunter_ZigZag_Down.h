#ifndef __ENEMY_HUNTER_ZIGZAG_DOWN_H__
#define __ENEMY_HUNTER_ZIGZAG_DOWN_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Hunter_ZigZag_Down : public Enemy
{
private:
	Animation down_anim;
	Animation down_forw;
	Animation forward;

	Path up;
	Path down;
	int speed = 0;

	bool attacking = false;
	fPoint original_position;
public:

	Enemy_Hunter_ZigZag_Down(int x, int y, int HP);
	void Move();
	bool PlayerLower();
	void Attack();
};

#endif // __ENEMY_HUNTER_ZIGZAG_H__