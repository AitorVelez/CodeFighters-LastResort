#include "Application.h"
#include "Blue_Car.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"

Blue_Car::Blue_Car(int x, int y, int HP) : Enemy(x, y, HP)
{

	goCarA.PushBack({ 253,512,21,11 });
	goCarA.PushBack({ 274,512,21,11 });
	goCarA.PushBack({ 295,512,21,11 });
	goCarA.PushBack({ 316,512,21,11 });
	goCarA.loop = true; 

	goCarA.speed = 0.1;
	animation = &goCarA;

	is_a_car = 1; 
	collider = App->collision->AddCollider({ 0, 0, 18, 11 }, COLLIDER_TYPE::COLLIDER_CAR, (Module*)App->enemies);

}

void Blue_Car::Move()
{
	position.x += 2;
}