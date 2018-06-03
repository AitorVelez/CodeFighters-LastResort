#ifndef __HELLFIRE2__
#define __HELLFIRE2__

#include "Enemy.h"

class Hellfire2 : public Enemy
{
private:
	Animation Launch;

	int original_y;
	float dirx;
	float proxim;
	float proximx;
	float proximy;
	float diry;
	bool flag = false;;
	int time = 0;
	uint now;
	uint shhot;
	bool thr = true;
	int original_x;
	float hyp;
public:

	Hellfire2(int x, int y, int HP);

	void Move();
};

#endif // __HELLFIRE2__