#ifndef __BLUE_CAR_H__
#define __BLUE_CAR_H__

#include "Enemy.h"

class Blue_Car : public Enemy
{
private:
	Animation goCarA;

public:

	Blue_Car(int x, int y);

	void Move();
};

#endif // __BLUE_CAR_H__