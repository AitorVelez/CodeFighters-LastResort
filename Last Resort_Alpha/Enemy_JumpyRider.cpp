#include "Application.h"
#include "Enemy_JumpyRider.h"
#include "ModuleCollision.h"

Enemy_JumpyRider::Enemy_JumpyRider(int x, int y, int HP) : Enemy(x, y, HP)
{
	fly.PushBack({ 257,295,48,41 });
	fly.PushBack({ 315,295,48,39 });
	fly.PushBack({ 373,290,48,40 });
	fly.PushBack({ 431,290,48,45 });
	fly.PushBack({ 257,340,48,47 });
	fly.PushBack({ 315,339,48,41 });
	fly.PushBack({ 373,339,48,41 });
	fly.PushBack({ 431,343,48,48 });
	fly.PushBack({ 257,386,48,41 });
	fly.PushBack({ 315,386,48,41 });
	fly.PushBack({ 373,386,48,39 });
	fly.PushBack({ 431,392,48,45 });
	fly.PushBack({ 431,445,48,40 });
	fly.speed = 0.25f;


	hp = original_hp = 6;
	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 48, 48 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_JumpyRider::Move()
{
	position.y = int(float(original_y) + (80.0f * sinf(wave)));
	position.x -= 0.5;
}
