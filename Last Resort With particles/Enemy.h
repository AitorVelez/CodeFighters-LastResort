#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"
#define MAX_ANIM 10
struct SDL_Texture;
struct Collider;

class Enemy
{
protected:
	Animation* animation = nullptr;
	Animation* animation2 = nullptr;
	Animation* animation3 = nullptr;
	/*Animation* animation4 = nullptr;
	Animation* animation5 = nullptr;*/
	Collider* collider = nullptr;
	float parallax = 1.f; 

public:
	fPoint position; 
	iPoint Anim2Distance;
	iPoint Anim3Distance;
	iPoint Anim4Distance;
	iPoint Anim5Distance;
public:
	Enemy(float x, float y, int HP);
	virtual ~Enemy();

	const Collider* GetCollider() const;

	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void OnCollision(Collider* collider);
	virtual void Shoot(); 
  /*  virtual void ShootStraightPlayerDirX(int PlayerPosX, int EnemyPosX, int SpeedX);
	int StoredShotDirX; 
	virtual void ShootStraightPlayerDirY(int PlayerPosY, int EnemyPosY, int SpeedY);
	int StoredShotDirY;*/
};

#endif // __ENEMY_H__