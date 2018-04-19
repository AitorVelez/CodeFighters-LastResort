#include "Application.h"
#include "Enemy_Tank.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleBackground.h"

Enemy_Tank::Enemy_Tank(int x, int y) : Enemy(x, y)
{
	Anim2Distance.x = 50; 
	Anim2Distance.y = -2; 
	Anim3Distance.x = 84;
	Anim3Distance.y = 4;
	tank.PushBack({ 16,857,157,64 });
	tank.PushBack({ 17,921,157,63 });
	tank.speed = 0.2f; 
	animation = &tank;
	canon.PushBack({ 178,779,28,10 });
	canon2.PushBack({ 205,831,15,6 });
	animation2 = &canon;
	animation3 = &canon2; 
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


void Enemy_Tank::Shoot() {
	//App->particles->AddParticle(App->particles->bullet, position.x + 31, position.y - 12, COLLIDER_PLAYER_SHOT);
}
