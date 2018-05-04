#ifndef __POWERUPL_H__
#define __POWERUPL_H__

#include "Powerup.h"

class LaserPowerUp : public Powerup
{
private:
	Animation PowChangeColor;

public:

	LaserPowerUp(int x, int y);

	virtual void OnCollision(Collider* collider);
};

#endif // __POWERUPL_H__