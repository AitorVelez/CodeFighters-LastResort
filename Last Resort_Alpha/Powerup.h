#ifndef __POWERUP_H__
#define __POWERUP_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

enum COLOR {
	NONE,
	ORANGE,
	BLUE
};

enum TYPES {
	NO_PTYPE,
	LASER_POWER,
	SPEED_POWER,
	HELL_POWER,
	GRENADER_POWER,
	ZPOWER,

};

class Powerup
{
protected:
	Animation * animation = nullptr;

	Collider* collider = nullptr;
	uint now; 
	uint last_time; 

public:
	iPoint position;
	COLOR color = NONE; 
	TYPES type = NO_PTYPE;

public:
	Powerup(int x, int y);
	virtual ~Powerup();

	const Collider* GetCollider() const;

	virtual void Draw(SDL_Texture* sprites);
	virtual void SwapColor();
	virtual void OnCollision(Collider* c1, Collider* c2);
};

#endif // __POWERUP_H__