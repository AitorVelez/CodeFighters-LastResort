#ifndef __ENEMY_LAMELLA_H__
#define __ENEMY_LAMELLA_H__

#include "Enemy.h"

class Enemy_Lamella : public Enemy
{
private:

	int original_y = 0;
	int dirx; 
	int diry; 
	int speed = 3; 
	int original_x = 0; 
	Animation fly;

public:

	Enemy_Lamella(int x, int y);

	void Move();
};

#endif // __ENEMY_LAMELLA_H__