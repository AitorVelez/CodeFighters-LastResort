#include "Application.h"
#include "PowerUpL.h"
#include "ModuleCollision.h"

LaserPowerUp::LaserPowerUp(int x, int y) : Enemy(x, y)
{
	ClrChangePow.PushBack({ 260,488,31,16 });
	ClrChangePow.PushBack({ 298,488,31,16 });
	ClrChangePow.speed = 0.05f;
	ClrChangePow.loop = true;
	animation = &ClrChangePow;


	collider = App->collision->AddCollider({ 0, 0, 31, 16 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->enemies);

}

