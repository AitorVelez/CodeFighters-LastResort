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
	Animation* BossFireAnim = nullptr; 
	Animation* BossFireThrower = nullptr;
	Animation* Bullets = nullptr;
	Animation* Barrels_boy = nullptr;
	Collider* collider = nullptr;
	uint is_a_car = 0; 
	uint alliedgrenade;
public:
	uint hp = 1;

	char* Sticker = nullptr; 


	uint original_hp = 1;
	fPoint position; 
	iPoint Anim2Distance;
	iPoint Anim3Distance;
	iPoint Anim4Distance;
	iPoint Anim5Distance;
	fPoint FireFakePos; 
	bool AsignedFirePos = false; 

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
	virtual void Draw5(SDL_Texture* sprites5);
	virtual void Draw6(SDL_Texture* sprites6);
	virtual void Draw7(SDL_Texture* sprites7);

	virtual void OnCollision(Collider* collider);
	virtual void Shoot(); 
};

#endif // __ENEMY_H__