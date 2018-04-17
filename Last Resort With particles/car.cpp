#include "Application.h"
#include "car.h"
#include "ModuleCollision.h"

car::car(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 256,512,18,11 });
	fly.PushBack({ 274,512,22,11 });
	fly.PushBack({ 294,512,21,11 });
	fly.PushBack({ 316,512,21,11 });

	fly.speed = 0.1;
	animation = &fly;


	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_CAR, (Module*)App->enemies);

}

void car::Move()
{
	position.x += 0.5;
}