#include "Application.h"
#include "Enemy_Tank.h"
#include "ModuleCollision.h"

Enemy_Tank::Enemy_Tank(int x, int y) : Enemy(x, y)
{
	tank.PushBack({ 16,857,157,64 });
	tank.PushBack({ 17,921,157,63 });
	animation = &tank;

	collider = App->collision->AddCollider({ 0, 0, 48, 48 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
}

void Enemy_Tank::Move()
{

}
