#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"
#include "Path.h"
#define MAX_ANIM 15 // 10
struct SDL_Texture;
struct Collider;

class Enemy
{
protected:
	Animation* animation = nullptr;
	Animation* animation2 = nullptr;
	Animation* animation3 = nullptr;
	Animation* anim2ndLevel= nullptr;   // Use in case of enemy level 2 
	Animation* SpiderTank = nullptr; 
	Animation* BossAnim = nullptr;
	Animation* BossFire = nullptr; 
	Animation* BossFireThrower = nullptr;
	Collider* collider = nullptr;
	uint is_a_car = 0; 
public:
	uint hp = 1;
	uint original_hp = 1;
	fPoint position; 
	iPoint Anim2Distance;
	iPoint Anim3Distance;
	iPoint Anim4Distance;
	iPoint Anim5Distance;


	fPoint FlameThrowerDistance; 
public:
	Enemy(float x, float y, int HP);
	virtual ~Enemy();

	const Collider* GetCollider() const;

	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void Draw2(SDL_Texture* sprites2);
	virtual void Draw3(SDL_Texture* sprites3);
	virtual void Draw4(SDL_Texture* sprites4);

	virtual void OnCollision(Collider* collider);
	virtual void Shoot(); 
};

#endif // __ENEMY_H__