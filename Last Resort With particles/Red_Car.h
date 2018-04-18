#ifndef __RED_CAR_H__
#define __RED_CAR_H__

#include "Enemy.h"

class Red_Car : public Enemy
{
private:
	Animation goCarB;

public:

	Red_Car(int x, int y);

	void Move();
};

#endif // __RED_CAR_H__