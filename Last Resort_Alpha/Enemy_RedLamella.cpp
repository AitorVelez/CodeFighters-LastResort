#include "Application.h"
#include "Enemy_RedLamella.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL_timer.h"
#include "ModulePlayer2.h"

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
	// if()
	speed = 1.2f;

	if (App->player->position.x < position.x) {
		anim2ndLevel = &Left;
	}
	else if (App->player->position.x == position.x) {
		anim2ndLevel = &Center; 
	}
	else if (App->player->position.x > position.x) {
		anim2ndLevel = &Right;
	}


	dirx = App->player->position.x - position.x;
	diry = App->player->relativeposition.y - position.y;
	hyp = sqrt(dirx*dirx + diry * diry);

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