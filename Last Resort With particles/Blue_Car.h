#ifndef __Blue_Car_H__
#define __Blue_Car_H__

#include "Enemy.h"

class Blue_Car : public Enemy
{
private:
	Animation goCarA;
	int original_y; 

public:

	Blue_Car(int x, int y);

	void Move();
};

#endif // __Blue_Car_H__