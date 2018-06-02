#ifndef __GRENADE2__
#define __GRENADE2__

#include "Enemy.h"

class Grenade2 : public Enemy
{
private:
	Animation shot;
	Animation shot2;
	Path path;
	int original_y;
	bool flag = false;;
	int time = 0;
	uint now;
	uint shhot;
	bool thr = true;
	int original_x;
public:

	Grenade2(int x, int y, int HP);

	void Move();
};

#endif // __GRENADE__