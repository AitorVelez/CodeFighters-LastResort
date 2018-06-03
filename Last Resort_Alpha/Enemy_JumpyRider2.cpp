#include "Application.h"
#include "Enemy_JumpyRider2.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"

Enemy_JumpyRider2::Enemy_JumpyRider2(int x, int y, int HP) : Enemy(x, y, HP)
{
	fly.PushBack({ 9,247,48,41 });
	fly.PushBack({ 67,247,48,39 });
	fly.PushBack({ 125,248,48,40 });
	fly.PushBack({ 183,243,48,45 });
	fly.PushBack({ 9,203,48,47 });
	fly.PushBack({ 67,203,48,41 });
	fly.PushBack({ 125,203,48,41 });
	fly.PushBack({ 183,194,48,48 });
	fly.PushBack({ 9,156,48,41 });
	fly.PushBack({ 67,156,48,41 });
	fly.PushBack({ 125,156,48,39 });
	fly.PushBack({ 183,146,48,45 });
	fly.PushBack({ 267,193,48,40 });
	fly.speed = 0.25f;


	hp = original_hp = 6;
	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 48, 48 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_JumpyRider2::Move()
{

	int speed;
	if (position.x > App->render->camera.x + 200) {
		speed = 0;

	}
	else {
		speed = 1;
	}
	position.x += speed;
}
