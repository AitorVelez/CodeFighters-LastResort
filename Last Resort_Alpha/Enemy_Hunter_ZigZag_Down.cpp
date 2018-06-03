#include "Enemy_Hunter_ZigZag_Down.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleBackground2.h"
#include "ModuleCollision.h"

Enemy_Hunter_ZigZag_Down::Enemy_Hunter_ZigZag_Down(int x, int y, int HP) : Enemy(x, y, HP)
{
	down_anim.PushBack({ 392, 508, 40, 22 });
	down_anim.PushBack({ 443, 509, 40, 22 });
	down_anim.PushBack({ 490, 511, 40, 24 });
	down_anim.speed = 0.25f;
	down_anim.loop = true;

	forward.PushBack({ 287, 539, 50, 23 });
	forward.PushBack({ 345, 539, 45, 22 });
	forward.PushBack({ 398, 539, 43, 22 });
	forward.speed = 0.25f;
	forward.loop = true;

	down.PushBack({ 0.4f, 0.4f }, 20, &down_anim);
	down.PushBack({ -0.4f, 0.4f }, 20, &down_anim);
	down.loop = true;

	original_position.x = x;
	original_position.y = y;


	anim2ndLevel = &down_anim;
	collider = App->collision->AddCollider({ 0,0, 40, 22 }, COLLIDER_ENEMY, (Module*)App->enemies);
}

void Enemy_Hunter_ZigZag_Down::Move()
{

	if (PlayerLower() && !attacking || position.y < 35)
	{
		position = original_position + down.GetCurrentPosition();
	}

	else {
		Attack();
		attacking = true;
	}
}

bool Enemy_Hunter_ZigZag_Down::PlayerLower()
{
	return App->player->position.y > position.y;
}

void Enemy_Hunter_ZigZag_Down::Attack()
{
	position.x -= 3;
	anim2ndLevel = &forward; 
}

