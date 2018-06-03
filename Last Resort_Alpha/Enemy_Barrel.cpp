#include "Application.h"
#include "Enemy_Barrel.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"

Enemy_Barrel::Enemy_Barrel(int x, int y, int HP) : Enemy(x, y, HP)
{

	fly.PushBack({ 198,853,20,22 });
	fly.PushBack({ 228,853,20,22 });
	fly.PushBack({ 258,853,20,22 });
	fly.PushBack({ 288,853,20,22 });

	Barrelito1.PushBack({ 11,166,9,11 });
	Barrelito2.PushBack({ 23,167,10,12 });
	Barrelito3.PushBack({ 36,166,12,12 });
	Barrelito4.PushBack({ 52,167,12,11 });
	Barrelito5.PushBack({ 65,167,10,12 });
	Barrelito6.PushBack({ 79,166,14,13 });
	Barrelito7.PushBack({ 98,167,13,10 });
	Barrelito8.PushBack({ 113,168,13,10 });
	
	path.PushBack({ 0,0.1f }, 60, &fly);
	path.PushBack({ 0,-0.1f }, 60, &fly);

	fly.speed = 0.1;
	animation = &fly;

//<<<<<<< HEAD
//	original_position.x = x;
//	original_position.y = y;
//	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
//=======
//	y_original = y;
//	collider = App->collision->AddCollider({ 0, 0, 20, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
//>>>>>>> 82cccd5d6330562b847dc3ac284b8affe88d94fd

}

void Enemy_Barrel::Move()
{

	 


	/*position = original_position + path.GetCurrentPosition();*/
}
