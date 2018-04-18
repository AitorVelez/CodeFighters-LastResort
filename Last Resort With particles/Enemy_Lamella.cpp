#include "Application.h"
#include "Enemy_Lamella.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"


Enemy_Lamella::Enemy_Lamella(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 4,513,28,28 });
	fly.PushBack({ 34,512,32,32 });
	fly.PushBack({ 68,513,30,30 });
	fly.PushBack({ 100,513,29,29 });
	fly.PushBack({ 130,513,36,36 }); 
	fly.PushBack({ 168,184,32,32 });
	fly.PushBack({ 202,512,28,28 });
	fly.PushBack({ 1,551,32,32 });
	fly.PushBack({ 35,551,30,30 });
	fly.PushBack({ 66,550,28,27 });
	fly.PushBack({ 97,551,36,36 });
	fly.PushBack({ 135,551,32,32 });
    fly.PushBack({ 168,551,28,28 });
	fly.PushBack({ 198,551,32,32 });
	fly.PushBack({ 1,589,30,30 });
	fly.PushBack({ 33,589,28,27 });
	fly.PushBack({ 63,589,36,36 });
	fly.PushBack({ 100,589,32,32 });
	fly.PushBack({ 135,589,28,28 });
	fly.PushBack({ 165,589,32,32 });
	fly.PushBack({ 199,589,30,30 });
	fly.PushBack({ 1,627,28,27 });
	fly.PushBack({ 31,627,36,36 });
	fly.PushBack({ 69,627,32,32 });
	fly.PushBack({ 103,627,28,28 });
	fly.PushBack({ 133,627,32,32 });
	fly.PushBack({ 167,627,30,30 });
	fly.PushBack({ 199,627,28,29 }); 
	fly.PushBack({ 1,665,36,36 });
	fly.PushBack({ 38,667,32,30 });
	fly.PushBack({ 72,665,31,30 });
	fly.PushBack({ 106,665,32,32 });
	fly.PushBack({ 140,665,31,30 });


	fly.speed = 0.5f;

	animation = &fly;


	collider = App->collision->AddCollider({ 0, 0, 31, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}


void Enemy_Lamella::Move()
{
	/*dirx = App->player->position.x + position.x; 
	diry = App->player->position.y + position.y;*/
	position.x += /*dirx **/ speed; 
	//position.y += diry * speed;
}