#include "Application.h"
#include "Enemy_Boss.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"


Enemy_Boss::Enemy_Boss(int x, int y, int HP) : Enemy(x, y, HP)
{

	AnimMove.PushBack({ 19,936,128,80 });
	AnimMove.PushBack({ 152,936,128,81 });
	AnimMove.PushBack({ 285,936,128,81 });
	AnimMove.PushBack({ 418,936,128,80 });
	AnimMove.PushBack({ 19,1028,128,80 });
	AnimMove.PushBack({ 152,1027,128,81 });
	AnimMove.PushBack({ 285,1028,128,81 });
	AnimMove.PushBack({ 418,1028,128,81 });
	AnimMove.PushBack({ 24,1118,128,81 });
	AnimMove.PushBack({ 152,1118,128,80 });
	AnimMove.PushBack({ 285,1118,128,80 });
	AnimMove.PushBack({ 418,1118,128,79 });
	AnimMove.PushBack({ 19,1222,128,80 });
	AnimMove.PushBack({ 152,1221,128,81 });
	AnimMove.PushBack({ 285,1221,128,81 });
	AnimMove.PushBack({ 418,1221,128,81 });
	AnimMove.speed = 0.15f;



	BossAnim = &AnimMove; 
	original_y = y;
	collider = App->collision->AddCollider({ 0, 0, 128, 80 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Boss::Move()
{
/*	
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
	*/

	

	position.x += 1; 

}
