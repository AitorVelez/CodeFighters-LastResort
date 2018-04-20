#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class Enemy
{
protected:
	Animation* animation = nullptr;
	Animation* animation2 = nullptr;
	Animation* animation3 = nullptr;
	Animation* animation4 = nullptr;
	Animation* animation5 = nullptr;
	Animation* animation6 = nullptr;
	Animation* animation7 = nullptr;
	Animation* animation8 = nullptr;
	Animation* animation9 = nullptr;
	Animation* animation10= nullptr;
	Animation* animation11= nullptr;
	Animation* animation12= nullptr;
	Animation* animation13 = nullptr;
	Collider* collider = nullptr;

public:
	fPoint position; 
	iPoint Anim2Distance;
	iPoint Anim3Distance;
public:
	Enemy(float x, float y);
	virtual ~Enemy();

	const Collider* GetCollider() const;

	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void OnCollision(Collider* collider);
};

#endif // __ENEMY_H__