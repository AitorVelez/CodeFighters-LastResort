#ifndef __SPOWER_H__
#define __SPOWER_H__

#include "Powerup.h"

class SpeedPowerUp : public Powerup
{
private:
	Animation PowChangeColor;

public:

	SpeedPowerUp(int x, int y);
	virtual void OnCollision(Collider* collider);

};

#endif // __SPOWER_H__