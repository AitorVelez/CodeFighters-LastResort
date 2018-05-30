#ifndef __ENEMY_HUNTER_H__
#define __ENEMY_HUNTER_H__

#include "Enemy.h"

class Enemy_Hunter : public Enemy
{
private:
	Animation fly;
	Animation appear;
	int y_original;
	int speed = 0; 
	bool ArrivedLeft = false; 
	bool colliderAdded = false; 
public:

	Enemy_Hunter(int x, int y, int HP);
	void Appear();
	void Move();
};

#endif // __ENEMY_HUNTER_H__