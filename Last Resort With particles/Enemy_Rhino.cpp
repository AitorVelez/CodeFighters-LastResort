#include "Application.h"
#include "Enemy_Rhino.h"
#include "ModuleCollision.h"

Enemy_Rhino::Enemy_Rhino(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 9,290,48,46 });
	fly.PushBack({ 57,290,48,46 });
	fly.PushBack({ 105,290,48,46 });
	fly.PushBack({ 153,290,48,47 });
	fly.PushBack({ 201,290,48,47 });
	fly.PushBack({ 9  ,337,48,47 });
	fly.PushBack({ 57 ,337,48,47 });
	fly.PushBack({ 105,337,48,48 });
	fly.PushBack({ 153,337,48,48 });
	fly.PushBack({ 201 ,337,48,48 });
	fly.PushBack({ 9,385,48,48 });
	fly.PushBack({ 57,385,48,48 });
	fly.PushBack({ 105,385,50,47 });
	fly.PushBack({ 155,385,48,49 });


	fly.speed = 0.05f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 48, 48 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_Rhino::Move()
{
	if (going_up)
	{
		if (wave > 1.0f)
			going_up = false;
		else
			wave += 0.05f;
	}
	else
	{
		if (wave < -1.0f)
			going_up = true;
		else
			wave -= 0.05f;
	}

	position.y = int(float(original_y) + (80.0f * sinf(wave)));
	position.x -= 0.5;
}
