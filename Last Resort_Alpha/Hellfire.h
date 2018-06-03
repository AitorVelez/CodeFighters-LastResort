#ifndef __HELLFIRE__
#define __HELLFIRE__

#include "Enemy.h"

class Hellfire : public Enemy
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

	Hellfire(int x, int y, int HP);

	void Move();
};

#endif // __HELLFIRE__