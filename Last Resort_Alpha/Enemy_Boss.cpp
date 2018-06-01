#include "Application.h"
#include "Enemy_Boss.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"


Enemy_Boss::Enemy_Boss(int x, int y, int HP) : Enemy(x, y, HP)
{

	//BossAnim.PushBack({ 0,62,128,81 });
//	BossAnim.PushBack({ 133,62,128,80 });



	//animation = &BossAnim;

	original_y = y;
	collider = App->collision->AddCollider({ 0, 0, 128, 80 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Boss::Move()
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
