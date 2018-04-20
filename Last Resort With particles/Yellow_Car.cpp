#include "Application.h"
#include "Yellow_Car.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"

Yellow_Car::Yellow_Car(int x, int y) : Enemy(x, y)
{

	goCarC.PushBack({ 291,547,21,11 });
	goCarC.PushBack({ 312,547,21,11 });
	goCarC.PushBack({ 333,547,21,11 });
	goCarC.PushBack({ 354,547,21,11 });

	goCarC.speed = 0.1;
	animation = &goCarC;
	original_y = y; 

	collider = App->collision->AddCollider({ 0, 0, 18, 11 }, COLLIDER_TYPE::COLLIDER_CAR, (Module*)App->enemies);

}

void Yellow_Car::Move()
{
	position.x += 2;
	position.y = original_y - (App->render->camera.y / 3);
}