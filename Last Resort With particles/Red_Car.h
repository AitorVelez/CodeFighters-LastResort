#ifndef __Red_Car_H__
#define __Red_Car_H__

#include "Enemy.h"

class Red_Car : public Enemy
{
private:
	Animation goCarB;
	int original_y; 
public:

	Red_Car(int x, int y);

	void Move();
};

#endif // __Red_Car_H__