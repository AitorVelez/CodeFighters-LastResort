#include "Application.h"
#include "Enemy_Tank.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleBackground.h"
Enemy_Tank::Enemy_Tank(int x, int y) : Enemy(x, y)
{
	tank.PushBack({ 16,857,157,64 });
	tank.PushBack({ 17,921,157,63 });
	tank.speed = 0.2f; 
	animation = &tank;

	collider = App->collision->AddCollider({ 0, 0, 157, 64 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
}

void Enemy_Tank::Move()
{
	bool arrived = false; 
	if (App->background->bgpos >= position.x) {
		position.x += 1;
		arrived = true;
	}
	/*if (position.x >= App->background->bgpos + SCREEN_WIDTH && arrived == true) {
		position.x += 2;
	}*/
}
