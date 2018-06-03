#include "Application.h"
#include "Enemy_Turret.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL_timer.h"
#include "ModuleCollision.h"
#include "ModulePlayer2.h"
#include "ModuleParticles.h"
#define TurretWidth 16

Enemy_Turret::Enemy_Turret(int x, int y, int HP) : Enemy(x, y, HP)
{
	hp = 20;
	original_hp = 1;
	collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	if (original_y < 100) {
		anim2ndLevel = &UpLeft;
	}
	else {
		anim2ndLevel = &DownLeft;
	}
	UpLeft.PushBack({ 296, 159, 16, 12}); 
	UpLeft2.PushBack({ 316, 159, 16, 12 });
	UpLeft3.PushBack({ 333, 160, 16, 14 });
	UpLeft4.PushBack({ 355, 160, 15, 15 });
	Up.PushBack({ 374, 160, 16, 16 });
	UpRight.PushBack({ 394, 160, 15, 15 });
	UpRight2.PushBack({ 411, 160, 16, 14 });
	UpRight3.PushBack({ 431, 161, 16, 12 });
	UpRight4.PushBack({ 449, 162, 16, 12 });

	DownLeft.PushBack({ 305, 193, 16, 12 });
	DownLeft2.PushBack({ 322, 194, 16, 12 });
	DownLeft3.PushBack({ 341, 193, 16, 14 });
	DownLeft4.PushBack({ 360, 192, 15, 15 });
	Down.PushBack({ 378, 190, 16, 16 });
	DownRight.PushBack({ 398, 191, 15, 15 });
	DownRight2.PushBack({ 416, 193, 16, 14 });
	DownRight3.PushBack({ 435, 194, 16, 12 });
	DownRight4.PushBack({ 453, 193, 16, 12 });

	original_y = y;
	original_x = x;
}

void Enemy_Turret::Move()
{
	//position.x += 1.0f; // stay as foreground

	if (original_y < 100) {                        // TOP TURRETS
		if (App->player->position.y < position.y + 25) {                                  // above superior limit 
			if (App->player->position.x < position.x + TurretWidth/2) {
				anim2ndLevel = &UpLeft; // &UpLeft;
			}
			else {
				anim2ndLevel = &UpRight4;
			}
		}
		else {
			if (App->player->position.x > position.x - SCREEN_WIDTH && App->player->position.x < position.x - 160) {
				anim2ndLevel = &UpLeft2;
			}
			else if (App->player->position.x >= position.x - 160 && App->player->position.x < position.x - 53) {
				anim2ndLevel = &UpLeft3;
			}
			else if (App->player->position.x >= position.x - 53 && App->player->position.x < position.x - 24) {
				anim2ndLevel = &UpLeft4;
			}
			else if (App->player->position.x >= position.x - 24 && App->player->position.x <= TurretWidth + position.x + 24) {
				anim2ndLevel = &Up;
			}
			else if (App->player->position.x >= TurretWidth + position.x + 24 && App->player->position.x < TurretWidth + position.x + 53) {
				anim2ndLevel = &UpRight;
			}
			else if (App->player->position.x >= TurretWidth + position.x + 53 && App->player->position.x < TurretWidth + position.x + 160) {
				anim2ndLevel = &UpRight2;
			}
			else if (App->player->position.x >= TurretWidth + position.x + 160 && App->player->position.x < TurretWidth + SCREEN_WIDTH) {
				anim2ndLevel = &UpRight3;
			}

		}
	}
	else {         // BOTTOM TURRETS
		if (App->player->position.y > position.y) {                                  // above superior limit 
			if (App->player->position.x < position.x + TurretWidth * 2) {
				anim2ndLevel = &DownLeft;
			}
			else {
				anim2ndLevel = &DownRight4;
			}
		}
		else {
			if (App->player->position.x > position.x - SCREEN_WIDTH && App->player->position.x < position.x - 160) {
				anim2ndLevel = &DownLeft2;
			}
			else if (App->player->position.x >= position.x - 160 && App->player->position.x < position.x - 53) {
				anim2ndLevel = &DownLeft3;
			}
			else if (App->player->position.x >= position.x - 53 && App->player->position.x < position.x - 24) {
				anim2ndLevel = &DownLeft4;
			}
			else if (App->player->position.x >= position.x - 24 && App->player->position.x <= TurretWidth + position.x + 24) {
				anim2ndLevel = &Down;
			}
			else if (App->player->position.x >= TurretWidth + position.x + 24 && App->player->position.x < TurretWidth + position.x + 53) {
				anim2ndLevel = &DownRight;
			}
			else if (App->player->position.x >= TurretWidth + position.x + 53 && App->player->position.x < TurretWidth + position.x + 160) {
				anim2ndLevel = &DownRight2;
			}
			else if (App->player->position.x >= TurretWidth + position.x + 160 && App->player->position.x < TurretWidth + SCREEN_WIDTH) {
				anim2ndLevel = &DownRight3;
			}

		}

	}
}

void Enemy_Turret::Shoot()
{

	BulletSpeed = 1.5f; 
	dirx = App->player->position.x - position.x;
	diry = App->player->position.y - position.y;
	
	proportion = dirx / diry; 

	

	App->particles->TurretShot.speed.x = (dirx / sqrt((pow(dirx, 2)) + (pow(diry, 2)))) * 1.4;
	App->particles->TurretShot.speed.y = (diry / sqrt((pow(dirx, 2)) + (pow(diry, 2)))) * 1.4;

	current_time = SDL_GetTicks();
	if (current_time > last_time + 800) {
			App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);	
		last_time = current_time;
	}
	
}