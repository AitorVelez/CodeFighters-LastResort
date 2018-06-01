#include "Application.h"
#include "Enemy_RedLamella.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL_timer.h"
#include "ModulePlayer2.h"
#include "ModuleRender.h"

Enemy_RedLamella::Enemy_RedLamella(int x, int y, int HP) : Enemy(x, y, HP)
{
	original_hp = 11;
	Right.PushBack({ 325, 0, 30, 29}); 
	Right.PushBack({ 355, 0, 31, 30});
	Right.PushBack({ 386, 0, 31, 31});
	Right.speed = 0.4f;
	Right.loop = true;

	Left.PushBack({ 325, 31, 31, 31});
	Left.PushBack({ 357, 31, 31, 30});
	Left.PushBack({ 387, 31, 30, 29});
	Left.speed = 0.4f;
	Left.loop = true;

	anim2ndLevel = &Left; 

    Center.PushBack({ 417, 0, 25, 30 });


	collider = App->collision->AddCollider({ 0, 0, 31, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}


void Enemy_RedLamella::Move()
{
	speed = 1.2f;


	dir2x = App->player2->position.x - position.x;
	dir2y = App->player2->relativeposition.y - position.y;
	hyp2 = sqrt(dir2x*dir2x + dir2y * dir2y);


	dirx = App->player->position.x - position.x;
	diry = App->player->relativeposition.y - position.y;
	hyp = sqrt(dirx*dirx + diry * diry);

	if (position.x < App->render->camera.x + SCREEN_WIDTH) {
		if (asigned == false) {
			if (hyp < hyp2) {
				target = "player1";
				asigned = true;
			}
			else {
				target = "player2";
				asigned = true;
			}
		}
	}

	if ((target == "player1")) {
		if (App->player->position.x < position.x) {
			anim2ndLevel = &Left;
		}
		else if (App->player->position.x == position.x) {
			anim2ndLevel = &Center;
		}
		else if (App->player->position.x > position.x) {
			anim2ndLevel = &Right;
		}


		dirx /= hyp;
		diry /= hyp;

		if (dirx < 0) {
			dirx /= 2.4f;
		}
		if (dirx > 0) {
			dirx *= 1.2f;
		}
		/*if (diry < 0) {
			diry *= 1.05f;
		}*/

		position.x += dirx * speed * 1.6f;
		position.y += diry * speed;
	}
	else if (target == "player2") {
		if (App->player2->position.x < position.x) {
			anim2ndLevel = &Left;
		}
		else if (App->player2->position.x == position.x) {
			anim2ndLevel = &Center;
		}
		else if (App->player2->position.x > position.x) {
			anim2ndLevel = &Right;
		}


		dir2x /= hyp2;
		dir2y /= hyp2;

		if (dir2x < 0) {
			dir2x /= 2.4f;
		}
		if (dir2x > 0) {
			dir2x *= 1.2f;
		}
		/*if (diry < 0) {
		diry *= 1.05f;
		}*/

		position.x += dir2x * speed * 1.6f;
		position.y += dir2y * speed;
	}
}