#include "Application.h"
#include "Enemy_Spider_Tank.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL_timer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"


Enemy_Spider_Tank::Enemy_Spider_Tank(int x, int y, int HP) : Enemy(x, y, HP)
{
	
	Downleft.PushBack({7,6,61,47});
	Downleft.PushBack({ 71,6,61,48 });
	Downleft.PushBack({ 135,7,61,48 });
	Downleft.speed = 0.15f;


	Downright.PushBack({ 7,58,61,48 });
	Downright.PushBack({ 71,57,61,48 });
	Downright.PushBack({ 135,56,61,48 });
	Downright.speed = 0.15f;

	Upleft.PushBack({ 7,111,61,47 });
	Upleft.PushBack({ 71,110,61,48 });
	Upleft.PushBack({ 135,109,61,48 });
	Upleft.speed = 0.15f;


	Upright.PushBack({ 7,161,61,47 });
	Upright.PushBack({ 71,162,61,48 });
	Upright.PushBack({ 135,163,61,48 });
	Upright.speed = 0.15f;


	collider = App->collision->AddCollider({ 0, 0, 31, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}


void Enemy_Spider_Tank::Move()
{
	speed = 2;
	if (position.x > original_x + 1000) {
		position.x += speed * 0;
	}
	else {
		if (now > lastshot + 7000 || shotting) {
			position.x += speed * 0;
			lastshot = SDL_GetTicks();
			if (recoil + 700  > lastshot) {
				shotting = true;
			}
			else {
				shotting = false;
			}


		}
		else {
			recoil = SDL_GetTicks();
			now = SDL_GetTicks();
			if (original_y > 78) // abajo
			{
				SpiderTank = &Downright;
				/*if (position.x < original_x - 150 || topleft == true) {
				position.x += speed;
				topleft = true;
				if (position.x == original_x - 200)
				topleft = false;
				}
				else if (((position.x <= original_x) || (position.x > original_x)) && topleft == false) {
				position.x -= speed;

				}*/


				if (position.x > App->render->camera.x + 80 && topleft == true) {
					position.x -= (speed / 2);
				}
				else /*if (position.x <= App->render->camera.x + 80 )*/ {
					position.x += speed;
					topleft = false;
					if (position.x > App->render->camera.x + 400) {
						topleft = true;
					}
				}
				/*else if(){

				}*/
			}
			if (original_y < 78) // arriba
			{
				/*position.x -= speed;*/
				SpiderTank = &Upright;
				/*if (position.x < original_x - 150 || topleft == true) {
				position.x += speed;
				topleft = true;
				if (position.x == original_x - 500)
				topleft = false;
				}
				else if (((position.x <= original_x) || (position.x > original_x)) && topleft == false) {
				position.x -= speed;

				}*/
				if (position.x > App->render->camera.x + 80 && topleft == true) {
					position.x -= (speed / 2);
				}
				else /*if (position.x <= App->render->camera.x + 80 )*/ {
					position.x += speed;
					topleft = false;
					if (position.x > App->render->camera.x + 400) {
						topleft = true;
					}
				}

			}
		}

	}
	
	
}