#include "Application.h"
#include "Enemy_Turret.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL_timer.h"
#include "ModuleCollision.h"
#include "ModulePlayer2.h"

Enemy_Turret::Enemy_Turret(int x, int y, int HP) : Enemy(x, y, HP)
{
	original_hp = 1;
	collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	anim2ndLevel = &UpLeft;

	UpLeft.PushBack({ 0, 0, 0, 0}); 
	UpLeft2.PushBack({ 0, 0, 0, 0 });
	UpLeft3.PushBack({ 0, 0, 0, 0 });
	UpLeft4.PushBack({ 0, 0, 0, 0 });
	Up.PushBack({ 0, 0, 0, 0 });
	UpRight.PushBack({ 0, 0, 0, 0 });
	UpRight2.PushBack({ 0, 0, 0, 0 });
	UpRight3.PushBack({ 0, 0, 0, 0 });
	UpRight4.PushBack({ 0, 0, 0, 0 });

	DownLeft.PushBack({ 0, 0, 0, 0 });
	DownLeft2.PushBack({ 0, 0, 0, 0 });
	DownLeft3.PushBack({ 0, 0, 0, 0 });
	DownLeft4.PushBack({ 0, 0, 0, 0 });
	Down.PushBack({ 0, 0, 0, 0 });
	DownRight.PushBack({ 0, 0, 0, 0 });
	DownRight2.PushBack({ 0, 0, 0, 0 });
	DownRight3.PushBack({ 0, 0, 0, 0 });
	DownRight4.PushBack({ 0, 0, 0, 0 });

	original_y = y;
	original_x = x;
}


void Enemy_Turret::Shoot()
{

}