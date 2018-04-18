#include "Application.h"
#include "Blue_Car.h"
#include "ModuleCollision.h"

Blue_Car::Blue_Car(int x, int y) : Enemy(x, y)
{

	goCarA.PushBack({ 253,512,21,11 });
	goCarA.PushBack({ 274,512,21,11 });
	goCarA.PushBack({ 295,512,21,11 });
	goCarA.PushBack({ 316,512,21,11 });

	goCarA.speed = 0.1;
	animation = &goCarA;


	collider = App->collision->AddCollider({ 0, 0, 18, 11 }, COLLIDER_TYPE::COLLIDER_BLUE_CAR, (Module*)App->enemies);

}

void Blue_Car::Move()
{
	position.x += 2;
}