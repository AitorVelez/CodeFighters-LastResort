#include "Enemy_Hunter_ZigZag_Down.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleBackground2.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"

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
	collider = App->collision->AddCollider({ 0, 0, 32, 26 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
}

void Enemy_Hunter_ZigZag_Down::Move()
{
	if (chunk_played == false) {
		App->particles->AddParticle(App->particles->Hunter1, 0, 0);
		chunk_played = true;
	}

	if (PlayerLower() && !attacking || position.y < 60)
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

