#include "Application.h"
#include "Yellow_Car.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"

Yellow_Car::Yellow_Car(int x, int y, int HP) : Enemy(x, y, HP)
{

	goCarC.PushBack({ 291,547,21,11 });
	goCarC.PushBack({ 312,547,21,11 });
	goCarC.PushBack({ 333,547,21,11 });
	goCarC.PushBack({ 354,547,21,11 });
	goCarC.loop = true;

	goCarC.speed = 0.1;
	animation = &goCarC;

	collider = App->collision->AddCollider({ 0, 0, 18, 11 }, COLLIDER_TYPE::COLLIDER_CAR, (Module*)App->enemies);

}

void Yellow_Car::Move()
{
	position.x += 1.5;
}