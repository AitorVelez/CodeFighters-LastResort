#ifndef _cars_H_
#define _cars_H_

#include "enemy.h"

class car : public Enemy{
private:

	Animation carA;
	Animation carB;
	Animation carC;

public:

	car(int x, int y);
	void Move();
};


#endif //!_cars_H_