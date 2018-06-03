#include "Application.h"
#include "BossFire.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "SDL\include\SDL_timer.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"

BossFire::BossFire(int x, int y, int HP) : Enemy(x, y, HP)
{
	Sticker = "BossFire"; 
	hp = 1000; 

	FlameThrowerDistance.x = -20; 
	FlameThrowerDistance.y = 20;


	middle.PushBack({ 562,520,44 + 2,16 + 10 });
	up.PushBack({ 397,519,42,19 + 7 });
	Moreup.PushBack({ 336,518,41,24 +2 });
	Down.PushBack({ 455,524,42,18 + 9 });
	MoreDown.PushBack({ 510,521,40,22+9 });


	Fire.PushBack({ 48,490,7,5 });
	Fire.PushBack({ 61,487,11,9 });
	Fire.PushBack({ 77,483,15,13 });
	Fire.PushBack({ 99,481,19,17 });
	Fire.PushBack({ 124,478,26,24 });
	Fire.PushBack({ 152,471,35,30 });
	Fire.PushBack({ 191,468,37,34 });
	Fire.PushBack({ 233,464,40,39 });
	Fire.PushBack({ 47,525,46,42 });
	Fire.PushBack({ 96,520,54,49 });
	Fire.PushBack({ 153,515,58,53 });
	Fire.PushBack({ 214,511,60,58 });
    Fire.PushBack({ 44,583,62,62 });
	Fire.PushBack({ 107,583,59,57 });
	Fire.PushBack({ 167,584,60,58 });
	Fire.PushBack({ 227,584,62,58 });
	Fire.PushBack({ 43,654,60,58 });
	Fire.PushBack({ 110,657,64,61 });
	Fire.PushBack({ 177,657,62,58 });
	Fire.PushBack({ 35,730,62,58 });
	Fire.PushBack({ 103,731,64,57 });
	Fire.PushBack({ 174,733,60,58 });
	Fire.PushBack({ 246,730,64,58 });
	Fire.PushBack({ 40,815,63,58 });
	Fire.PushBack({ 106,820,64,48 });
	Fire.speed = 0.4f; 

	original_x = x;

	BossFireThrower = &middle; 
	
	original_y = y;
	collider = App->collision->AddCollider({ 0, 0, 44, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void BossFire::Move()
{
	position.x += 1; 
	int delay = 350; 
	int start = 9500; 

	now = SDL_GetTicks(); //BossFireAnim = &Fire;
	
	if (position.x == original_x) {
		last = SDL_GetTicks();
	}

	else if (now < last + 500) {
		BossFireThrower = &middle;
		xx = -30 + 5;
		yy = -10;

		
	}
	else if(now < last + 1000){
		BossFireThrower = &up;
		xx = -25 + 5;
		yy = -20;
		
	}
	else if (now < last + 1500) {
		BossFireThrower = &Moreup;
		xx = -23 +5 ;
		yy = -23;
		
	}
	else if (now < last + 2000) {
		BossFireThrower = &up;
		xx = -25 +5;
		yy = -20;
	}
	else if (now < last + 2500) {
		BossFireThrower = &middle;
		xx = -30 +5 ;
		yy = -10;
	}
	else if (now < last + 3000) {
		BossFireThrower = &Down;
		xx = -25 +5;
		yy = 10;
	}
	else if (now < last + 3500) {
		BossFireThrower = &MoreDown;
		xx = -23 +5 ;
		yy = 13;
	}
	else if (now < last + 4000) {
		BossFireThrower = &Down;
		xx = -25 +5 ;
		yy = 10;
	}
	else if (now < last + 4500) {
		BossFireThrower = &middle;
		xx = -30 +5;
		yy = -10;
	}

	else {
		if (now > last + 5000)
			last = SDL_GetTicks();
	}
	

	fire = SDL_GetTicks();

	if (fire > recoill + 300) {
		
		App->particles->AddParticle(App->particles->Fire, position.x + xx, position.y + yy, COLLIDER_ENEMY_SHOT);
		recoill = SDL_GetTicks();

	}




	if (App->enemies->BossFlameDespawn == true) {
		App->enemies->ForcedDeath(); 

	 }

}
