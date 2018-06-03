#include "Application.h"
#include "BossFire.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "SDL\include\SDL_timer.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"

BossFire::BossFire(int x, int y, int HP) : Enemy(x, y, HP)
{
	Sticker = "BossFire"; 
	hp = 1000; 

	FlameThrowerDistance.x = -20; 
	FlameThrowerDistance.y = 20;


	middle.PushBack({ 564,530,44,16 });
	up.PushBack({ 397,526,42,19 });
	Moreup.PushBack({ 336,520,41,24 });
	Down.PushBack({ 455,533,42,18 });
	MoreDown.PushBack({ 510,530,40,22 });


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



	BossFireThrower = &middle; 
	
	original_y = y;
	collider = App->collision->AddCollider({ 0, 0, 44, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void BossFire::Move()
{
	position.x += 1; 
	int delay = 350; 
	int start = 9500; 

		//BossFireAnim = &Fire;
	


	now = SDL_GetTicks(); 


	if (now <= last + start + delay) {
		BossFireThrower = &middle;
	}
	else if (now > last + start + delay && now <= last + start + delay * 2) {
		BossFireThrower = &up;
	}
		
	else if (now > last + start + delay * 2 && now <= last + start + delay * 3) {
			BossFireThrower = &Moreup;
		}

	else if (now > last + start + delay * 3 && now <= last + start + delay * 4) {
		BossFireThrower = &up;
	}
	else if (now > last + start  + delay * 4 && now <= last + start + delay * 5) {
		BossFireThrower = &middle;
	}
	else if (now > last + start + delay * 5 && now <= last + start + delay * 6) {
		BossFireThrower = &Down;
	}
	else if (now > last + start + delay * 6 && now <= last + start + delay * 7) {
		BossFireThrower = &MoreDown;
	}
	else if (now > last + start + delay * 7 && now <= last + start + delay * 8) {
		BossFireThrower = &Down;
	}
	else if (now > last + start + delay * 8 && now <= last + start + delay * 9) {
		BossFireThrower = &middle;
		last = now - start - delay; 
	}
	




	if (App->enemies->BossFlameDespawn == true) {
		App->enemies->ForcedDeath(); 
	 }

}
