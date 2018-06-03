#include "Enemy_Hunter_ZigZag.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleBackground2.h"
#include "ModuleCollision.h"

Enemy_Hunter_ZigZag::Enemy_Hunter_ZigZag(int x, int y, int HP) : Enemy (x,y,HP)
{
	up_anim.PushBack({ 392, 482, 40, 23 });
	up_anim.PushBack({ 442, 481, 40, 24 });
	up_anim.PushBack({ 490, 481, 40, 28 });
	up_anim.speed = 0.25f;
	up_anim.loop = true; 

	/*down_anim.PushBack({ 392, 510, 40, 23 });
	down_anim.PushBack({ 443, 511, 40, 22 });
	down_anim.PushBack({ 490, 511, 40, 24 });
	down_anim.speed = 0.5f;
	down_anim.loop = true; */

	forward.PushBack({ 287, 539, 50, 23 });
	forward.PushBack({ 345, 540, 45, 22 });
	forward.PushBack({ 398, 540, 43, 22});
	forward.speed = 0.25f;
	forward.loop = true; 

	up.PushBack({ 0.4f, -0.4f }, 20, &up_anim);
	up.PushBack({ -0.4f, -0.4f }, 20, &up_anim);
	up.loop = true; 

	//down.PushBack({ 0.2f, -0.2f }, 20, &down_anim);
	//down.PushBack({ -0.2f, -0.2f }, 20, &down_anim);
	//down.loop = true;

	original_position.x = x; 
	original_position.y = y; 


	anim2ndLevel = &up_anim;	
	collider = App->collision->AddCollider({ 0,0, 40, 22 }, COLLIDER_ENEMY, (Module*)App->enemies);
}

void Enemy_Hunter_ZigZag::Move()
{

	if (PlayerHigher() && !attacking || position.y > 130)
	{
		position = original_position + up.GetCurrentPosition();
	}

	else {
		Attack();
		attacking = true; 
	}
}
  
bool Enemy_Hunter_ZigZag::PlayerHigher()
{
	return App->player->position.y < position.y + 20;
}

void Enemy_Hunter_ZigZag::Attack()
{
	position.x -= 3; 
	anim2ndLevel = &forward;
}

