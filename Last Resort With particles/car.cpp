#include "Application.h"
#include "car.h"
#include "ModuleCollision.h"

car::car(int x, int y) : Enemy(x, y)
{

	goCar.PushBack({ 253,512,21,11 });
	goCar.PushBack({ 274,512,21,11 });
	goCar.PushBack({ 295,512,21,11 });
	goCar.PushBack({ 316,512,21,11 });

	goCar.speed = 0.1;
	animation = &goCar;


	collider = App->collision->AddCollider({ 0, 0, 18, 11 }, COLLIDER_TYPE::COLLIDER_CAR, (Module*)App->enemies);

}

void car::Move()
{
	position.x += 1.2;
}