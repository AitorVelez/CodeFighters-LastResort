#ifndef __POWERUP_H__
#define __POWERUP_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class Powerup
{
protected:
	Animation * animation = nullptr;

	Collider* collider = nullptr;

public:
	iPoint position;

public:
	Powerup(int x, int y);
	virtual ~Powerup();

	const Collider* GetCollider() const;

	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void OnCollision(Collider* collider);
};

#endif // __POWERUP_H__