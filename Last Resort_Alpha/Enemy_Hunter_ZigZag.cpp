#include "Enemy_Hunter_ZigZag.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleBackground2.h"

Enemy_Hunter_ZigZag::Enemy_Hunter_ZigZag(int x, int y, int HP) : Enemy (x,y,HP)
{
	
}

void Enemy_Hunter_ZigZag::Move()
{
	if (App->player->position.y > position.y) player_lower = true; 
	else player_higher = true; 

}

void Enemy_Hunter_ZigZag::Attack()
{
}

