#include "Application.h"
#include "Red_Car.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"

Red_Car::Red_Car(int x, int y) : Enemy(x, y)
{

	goCarB.PushBack({ 313,666,21,11 });
	goCarB.PushBack({ 334,666,21,11 });
	goCarB.PushBack({ 355,666,21,11 });
	goCarB.PushBack({ 256,681,21,11 });

	goCarB.speed = 0.1;
	animation = &goCarB;
	original_y = y; 
	collider = App->collision->AddCollider({ 0, 0, 18, 11 }, COLLIDER_TYPE::COLLIDER_CAR, (Module*)App->enemies);

}

void Red_Car::Move()
{
	position.x += 2;
	position.y = original_y - (App->render->camera.y / 3);
}