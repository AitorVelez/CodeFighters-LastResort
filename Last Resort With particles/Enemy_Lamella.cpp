#include "Application.h"
#include "Enemy_Lamella.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
Enemy_Lamella::Enemy_Lamella(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 140,665,31,30 });



	fly.speed = 0.05f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 31, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}


void Enemy_Lamella::Move()
{
	dirx = App->player->position.x - position.x; 
	diry = App->player->position.y - position.y;
	position.x += dirx * speed; 
	position.y += diry * speed;
}