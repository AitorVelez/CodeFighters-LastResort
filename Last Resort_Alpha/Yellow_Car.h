#ifndef __Yellow_Car_H__
#define __Yellow_Car_H__

#include "Enemy.h"

class Yellow_Car : public Enemy
{
private:
	Animation goCarC;
	int original_y; 
public:

	Yellow_Car(int x, int y, int HP);

	void Move();
};

#endif // __Yellow_Car_H__