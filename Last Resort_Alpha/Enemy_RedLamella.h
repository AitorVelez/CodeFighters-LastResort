#ifndef __ENEMY_REDLAMELLA_H__
#define __ENEMY_REDLAMELLA_H__

#include "Enemy.h"

class Enemy_RedLamella : public Enemy
{
private:

	int original_y = 0;
	float dirx;
	float diry;
	float dir2x; 
	float dir2y; 

	float speed;
	int original_x = 0;
	Animation Right; 
	Animation Left;
	Animation Center;
	float hyp;
	float hyp2; 
	char* target; 
	bool asigned = false; 
public:

	Enemy_RedLamella(int x, int y, int HP);

	void Move();
};

#endif // __ENEMY_REDLAMELLA 