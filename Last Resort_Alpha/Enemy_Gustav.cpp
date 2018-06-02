#include "Enemy_Gustav.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleBackground2.h"

Enemy_Gustav::Enemy_Gustav(int x, int y, int HP) : Enemy(x, y, HP)
{
	body.PushBack({ 0,93,18,18 });
	body.PushBack({ 18,93,18,18 });
	body.PushBack({ 36,93,18,18 });
	body.PushBack({ 54,93,18,18 });
	body.PushBack({ 62,93,18,18 });
	body.PushBack({ 80,93,18,18 });
	body.PushBack({ 98,93,18,18 });
	body.PushBack({ 0,111,18,18 });
	body.PushBack({ 18,111,18,18 });
	body.PushBack({ 36,111,18,18 });
	body.PushBack({ 54,111,18,18 });
	body.PushBack({ 62,111,18,18 });
	body.speed = 0.4f;
	body.loop = true;

	anim2ndLevel = &body;
}

void Enemy_Gustav::Move()
{
	speed = 4; 

	vec_x = App->player->position.x - position.x; 
	vec_y = App->player->position.y - position.y; 

	track.x = (vec_x / sqrt(pow(vec_x, 2) + pow(vec_y, 2))) * speed;
	track.y = (vec_y / sqrt(pow(vec_x, 2) + pow(vec_y, 2))) * speed;

	position = position + track; 
}
