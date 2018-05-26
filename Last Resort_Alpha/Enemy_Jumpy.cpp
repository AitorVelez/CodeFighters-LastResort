#include "Application.h"
#include "Enemy_Jumpy.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"

Enemy_Jumpy::Enemy_Jumpy(int x, int y, int HP) : Enemy(x, y, HP)
{

	fly.PushBack({ 272,448,30,26 });
	fly.PushBack({ 314,448,32,26 });
	fly.PushBack({ 358,448,32,26 });

	fly.speed = 0.1;
	animation = &fly;

	y_original = y;
	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Jumpy::Move()
{
	position.x -= 2;
	position.y = y_original + (App->render->camera.y / 3);
}
