#include "Application.h"
#include "Red_Car.h"
#include "ModuleCollision.h"

Red_Car::Red_Car(int x, int y) : Enemy(x, y)
{

	goCarB.PushBack({ 313,666,21,11 });
	goCarB.PushBack({ 334,666,21,11 });
	goCarB.PushBack({ 355,666,21,11 });
	goCarB.PushBack({ 256,681,21,11 });

	goCarB.speed = 0.1;
	animation = &goCarB;

	carDeathB.PushBack({ 278,680,21,18 });
	carDeathB.PushBack({ 299,680,20,18 });
	carDeathB.PushBack({ 318,680,21,18 });
	carDeathB.PushBack({ 339,680,21,18 });
	carDeathB.PushBack({ 359,680,21,18 });
	carDeathB.PushBack({ 256,699,27,13 });
	carDeathB.PushBack({ 283,699,28,13 });
	carDeathB.PushBack({ 314,699,35,13 });

	collider = App->collision->AddCollider({ 0, 0, 18, 11 }, COLLIDER_TYPE::COLLIDER_CAR, (Module*)App->enemies);

}

void Red_Car::Move()
{
	position.x += 2;
}