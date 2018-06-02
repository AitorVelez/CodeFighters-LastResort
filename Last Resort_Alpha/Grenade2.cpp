#include "Application.h"
#include "Grenade2.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "Path.h"

#include "SDL\include\SDL_timer.h"
#include "ModulePlayer2.h"

Grenade2::Grenade2(int x, int y, int HP) : Enemy(x, y, HP)
{
	shot.PushBack({ 165,69,16,6 });
	shot.PushBack({ 182,66,15,10 });
	shot.PushBack({ 199,64,10,15 });


	shot2.PushBack({ 165,69,16,6 });
	shot2.PushBack({ 364,124,15,10 });
	shot2.PushBack({ 364,139,10,15 });
	shot.loop = false;
	shot.speed = 0.2f;
	shot2.loop = false;
	shot2.speed = 0.2f;
	alliedgrenade = 2;
	Bullets = &shot2;
	original_x = x;
	original_y = y;
	collider = App->collision->AddCollider({ 0, 0, 14, 14 }, COLLIDER_TYPE::COLLIDER_PLAYER2_SHOT, (Module*)App->enemies);

}

void Grenade2::Move()
{
	float speed = 2.1;
	now = SDL_GetTicks();

	if (thr) {
		thr = false;
		shhot = SDL_GetTicks();
	}

	if (original_y > App->player2->position.y && position.y == original_y) {
		flag = true;
		Bullets = &shot;

	}
	if (flag) {
		if (shhot + 600 > now) {
			position.x += speed*1.1;
			position.y += speed*0.8;
		}
		else if (shhot + 600 < now && shhot + 900 > now) {
			position.x += speed*0.9;
			position.y += speed*1.1;
		}
		else {
			position.x += speed*0.9;
			position.y += speed*1.4;
		}

	}

	else {
		
		if (shhot + 600 > now) {
			position.x += speed*1.1;
			position.y -= speed*0.8;
		}
		else if (shhot + 600 < now && shhot + 900 > now) {
			position.x += speed*0.9;
			position.y -= speed*1.1;
		}
		else {
			position.x += speed*0.9;
			position.y -= speed*1.4;
		}
	}



}