#include "Application.h"
#include "Blue_Car.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"

Blue_Car::Blue_Car(int x, int y) : Enemy(x, y)
{

	goCarA.PushBack({ 253,512,21,11 });
	goCarA.PushBack({ 274,512,21,11 });
	goCarA.PushBack({ 295,512,21,11 });
	goCarA.PushBack({ 316,512,21,11 });
	goCarA.loop = true; 
	goCarA.speed = 0.1;
	animation = &goCarA;
	original_y = y; 

	collider = App->collision->AddCollider({ 0, 0, 18, 11 }, COLLIDER_TYPE::COLLIDER_CAR, (Module*)App->enemies);

}

void Blue_Car::Move()
{
	position.x += 2;
	position.y = original_y - (App->render->camera.y / 3);
}