#include "Application.h"
#include "Enemy_Barrel.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"

Enemy_Barrel::Enemy_Barrel(int x, int y, int HP) : Enemy(x, y, HP)
{

	fly.PushBack({ 198,853-9,20,22+9 });
	fly.PushBack({ 228,853-9,20,22+9 });
	fly.PushBack({ 258,853-9,20,22+9 });
	fly.PushBack({ 288,853-9,20,22+9 });

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

//	original_position.x = x;
//	original_position.y = y;
//	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

//	y_original = y;
//	collider = App->collision->AddCollider({ 0, 0, 20, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


}

void Enemy_Barrel::Move()
{
	dirx = position.x - App->player->position.x;
	diry = position.y - App->player->position.y;
	hyp = sqrt(dirx*dirx + diry*diry);
	angle = atan2(diry, dirx);
	angle = (angle * 360) / (2 * PI);
	angle += 180;

	if (angle > 337.5 && angle < 22.5) {
		Barrels_boy = &Barrelito7;
	}
	else if (angle > 22.5 && angle < 67.5) {
		Barrels_boy = &Barrelito4;
	}
	else if (angle > 67.5 && angle < 112.5) {
		Barrels_boy = &Barrelito1;
	}
	else if (angle > 112.5 && angle < 157.5) {
		Barrels_boy = &Barrelito3;
	}
	else if (angle > 157.5 && angle < 202.5) {
		Barrels_boy = &Barrelito8;
	}
	else if (angle > 202.5 && angle < 247.5) {
		Barrels_boy = &Barrelito6;
	}
	else if (angle > 247.5 && angle < 292.5) {
		Barrels_boy = &Barrelito2;
	}
	else {
		Barrels_boy = &Barrelito5;
	}
	/*position = original_position + path.GetCurrentPosition();*/
}
