#ifndef __ENEMY_HUNTER_ZIGZAG_H__
#define __ENEMY_HUNTER_ZIGZAG_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Hunter_ZigZag : public Enemy
{
private:
	Animation up_anim;
	Animation up_forw;
	Animation forward; 

	Path up;
	Path down;
	int speed = 0;

	bool attacking = false;
	fPoint original_position;
public:

	Enemy_Hunter_ZigZag(int x, int y, int HP);
	void Move();
	bool PlayerHigher(); 
	void Attack(); 
};

#endif // __ENEMY_HUNTER_ZIGZAG_H__