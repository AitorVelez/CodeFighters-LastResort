#ifndef __POWERUPH_H__
#define __POWERUPH_H__

#include "Powerup.h"

class HellfirePowerUp : public Powerup
{
private:
	Animation PowChangeColor;

public:

	HellfirePowerUp(int x, int y);

	virtual void OnCollision(Collider* collider);
};

#endif // __POWERUPH_H__
