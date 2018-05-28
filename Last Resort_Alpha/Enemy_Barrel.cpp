#include "Application.h"
#include "Enemy_Barrel.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"

Enemy_Barrel::Enemy_Barrel(int x, int y, int HP) : Enemy(x, y, HP)
{

	fly.PushBack({ 198,853,20,22 });
	fly.PushBack({ 228,853,20,22 });
	fly.PushBack({ 258,853,20,22 });
	fly.PushBack({ 288,853,20,22 });
	
	path.PushBack({ 0,0.1f }, 60, &fly);
	path.PushBack({ 0,-0.1f }, 60, &fly);

	fly.speed = 0.1;
	animation = &fly;

	original_position.x = x;
	original_position.y = y;
	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Barrel::Move()
{
	position = original_position + path.GetCurrentPosition();
}
