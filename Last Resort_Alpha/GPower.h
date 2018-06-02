#ifndef __POWERUPG_H__
#define __POWERUPG_H__

#include "Powerup.h"

class GrenadePowerUp : public Powerup
{
private:
	Animation PowChangeColor;

public:

	GrenadePowerUp(int x, int y);

	virtual void OnCollision(Collider* collider);
};

#endif // __POWERUPG_H__
