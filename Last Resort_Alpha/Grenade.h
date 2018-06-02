#ifndef __GRENADE__
#define __GRENADE__

#include "Enemy.h"

class Grenade : public Enemy
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

	Grenade(int x, int y, int HP);

	void Move();
};

#endif // __GRENADE__
