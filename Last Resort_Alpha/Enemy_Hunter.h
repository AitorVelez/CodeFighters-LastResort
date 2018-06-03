#ifndef __ENEMY_HUNTER_H__
#define __ENEMY_HUNTER_H__

#include "Enemy.h"

class Enemy_Hunter : public Enemy
{
private:
	Animation fly;
	Animation appear;
	uint now = 0;
	uint last = 0;
	int y_original;
	int speed = 0; 
	bool ArrivedLeft = false; 
	bool colliderAdded = false; 
	bool chunk_played;
	bool chunk_played2;
public:

	Enemy_Hunter(int x, int y, int HP);
	void Appear();
	void Move();
};

#endif // __ENEMY_HUNTER_H__