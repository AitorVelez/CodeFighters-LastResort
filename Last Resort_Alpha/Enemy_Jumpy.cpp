#include "Application.h"
#include "Enemy_Jumpy.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"


Enemy_Jumpy::Enemy_Jumpy(int x, int y, int HP) : Enemy(x, y, HP)
{

	fly.PushBack({ 272,448,30,26 });
	fly.PushBack({ 314,448,32,26 });
	fly.PushBack({ 358,448,32,26 });


	animation = &fly;

	original_y = y;
	collider = App->collision->AddCollider({ 0, 0, 32, 26 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Jumpy::Move()
{
	if (going_up)
	{
		if (wave > 5.0f)
			going_up = false;
		else
			wave += 0.1f;
	}
	else
	{
		if (wave < -5.0f)
			going_up = true;
		else
			wave -= 0.1f;
	}

	position.y = int(float(original_y) + (10.0f * sinf(wave)));
	position.x -= 2;
}
