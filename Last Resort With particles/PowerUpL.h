#ifndef __POWERUPL_H__
#define __POWERUPL_H__

#include "Enemy.h"

class LaserPowerUp : public Enemy
{
private:
	Animation ClrChangePow;

public:

	LaserPowerUp(int x, int y);

	
};

#endif // __POWERUPL_H__