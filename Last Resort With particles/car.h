#ifndef __CAR_H__
#define __CAR_H__

#include "Enemy.h"

class car : public Enemy
{
private:
	Animation goCar;

public:

	car(int x, int y);

	void Move();
};

#endif // __CAR_H__