#ifndef __ENEMY_LAMELLA_H__
#define __ENEMY_LAMELLA_H__

#include "Enemy.h"

class Enemy_Lamella : public Enemy
{
private:

	int original_y = 0;
	float dirx; 
    float diry; 
	float speed; 
	int original_x = 0; 
	Animation fly;
	Animation Moving; 
	int hyp; 
	bool aimed = false;
	uint last_time = 0; 
	uint current_time = 0;

public:

	Enemy_Lamella(int x, int y, int HP);

	void Move();
};

#endif // __ENEMY_LAMELLA_H__