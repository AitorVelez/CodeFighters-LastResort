#include "Application.h"
#include "Enemy_Cockroach.h"
#include "ModuleCollision.h"

Enemy_Cockroach::Enemy_Cockroach(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 9,443,32,16 });
	fly.PushBack({ 9,459,32,15 });
	fly.PushBack({ 9,474,32,15 });
	fly.PushBack({ 9,490,32,15 });
	fly.speed = 0.2f;
	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Cockroach::Move()
{
	position.x -= 1;
}
