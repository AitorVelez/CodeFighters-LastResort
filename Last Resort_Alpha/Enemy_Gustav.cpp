#include "Enemy_Gustav.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleBackground2.h"

Enemy_Gustav::Enemy_Gustav(int x, int y, int HP) : Enemy(x, y, HP)
{

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
