#include "Enemy_Hunter_ZigZag.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleBackground2.h"

Enemy_Hunter_ZigZag::Enemy_Hunter_ZigZag(int x, int y, int HP) : Enemy (x,y,HP)
{
	up_anim.PushBack({ 392, 482, 40, 23 });
	up_anim.PushBack({ 442, 481, 40, 24 });
	up_anim.PushBack({ 490, 481, 40, 28 });
	up_anim.speed = 0.5f;
	up_anim.loop = true; 

	down_anim.PushBack({ 392, 510, 40, 23 });
	down_anim.PushBack({ 443, 511, 40, 22 });
	down_anim.PushBack({ 490, 511, 40, 24 });
	down_anim.speed = 0.5f;
	down_anim.loop = true; 

	forward.PushBack({ 287, 539, 50, 23 });
	forward.PushBack({ 345, 540, 45, 22 });
	forward.PushBack({ 398, 540, 43, 22});
	forward.speed = 0.5f;
	forward.loop = true; 

	up.PushBack({ 0.2f, -0.2f }, 20, &up_anim);
	up.PushBack({ -0.2f, -0.2f }, 20, &up_anim);
	up.loop = true; 

	down.PushBack({ 0.2f, -0.2f }, 20, &down_anim);
	down.PushBack({ -0.2f, -0.2f }, 20, &down_anim);
	down.loop = true;

	original_position.x = x; 
	original_position.y = y; 


	anim2ndLevel = &up_anim;
	if (App->player->position.y > position.y) player_lower = true;
	else player_higher = true;
}

void Enemy_Hunter_ZigZag::Move()
{

	if (player_higher)
	{
		
		position = original_position + up.GetCurrentPosition();

		if (position.y < App->player->position.y)
			position.x += 3; 
	}

	if (player_lower)
	{
		position = original_position + down.GetCurrentPosition();
	}
}
  

