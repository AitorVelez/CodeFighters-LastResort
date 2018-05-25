#include "Application.h"
#include "Enemy_Hunter.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"

Enemy_Hunter::Enemy_Hunter(int x, int y, int HP) : Enemy(x, y, HP)
{

	fly.PushBack({ 0,0,65,32 });
	fly.PushBack({ 0,32,65,32 });
	fly.PushBack({ 0,64,65,32 });
	fly.PushBack({ 0,96,65,32 });
	fly.PushBack({ 0,128,65,32 });
	fly.PushBack({ 0,160,65,32 });
	fly.PushBack({ 0,192,65,32 });
	fly.PushBack({ 0,224,65,32 });
	fly.PushBack({ 0,256,65,32 });
	fly.PushBack({ 0,256,32,32 });
	fly.PushBack({ 0,256,32,32 });
	fly.PushBack({ 0,256,32,32 });
	fly.PushBack({ 0,256,32,32 });
	fly.PushBack({ 0,256,32,32 });
	fly.PushBack({ 0,256,32,32 });
	fly.PushBack({ 0,256,32,32 });
	fly.PushBack({ 0,256,32,32 });

	fly.speed = 0.2;
	animation = &fly;

	y_original = y;
	collider = App->collision->AddCollider({ 0, 0, 32, 14 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Hunter::Move()
{
	position.x -= 3;
	position.y = y_original + (App->render->camera.y / 3);
}
