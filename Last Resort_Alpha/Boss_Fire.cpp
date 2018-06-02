#include "Application.h"
#include "BossFire.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "SDL\include\SDL_timer.h"

BossFire::BossFire(int x, int y, int HP) : Enemy(x, y, HP)
{

	FlameThrowerDistance.x = -20; 
	FlameThrowerDistance.y = 20;


	middle.PushBack({ 564,530,44,16 });
	up.PushBack({ 397,526,42,19 });
	Moreup.PushBack({ 336,520,41,24 });
	Down.PushBack({ 455,533,42,18 });
	MoreDown.PushBack({ 510,530,40,22 });


	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
    Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });
	Fire.PushBack({ 0,0,0,0 });



	BossFireThrower = &middle; 
	
	original_y = y;
	collider = App->collision->AddCollider({ 0, 0, 128, 80 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void BossFire::Move()
{
	position.x += 1; 
	int delay = 350; 

	BossFireAnim = &Fire;


	now = SDL_GetTicks(); 


	if (now <= last + delay) {
		BossFireThrower = &middle;
	}
	else if (now > last + delay && now <= last + delay * 2) {
		BossFireThrower = &up;
	}
		
	else if (now > last + delay * 2 && now <= last + delay * 3) {
			BossFireThrower = &Moreup;
		}

	else if (now > last + delay * 3 && now <= last + delay * 4) {
		BossFireThrower = &up;
	}
	else if (now > last + delay * 4 && now <= last + delay * 5) {
		BossFireThrower = &middle;
	}
	else if (now > last + delay * 5 && now <= last + delay * 6) {
		BossFireThrower = &Down;
	}
	else if (now > last + delay * 6 && now <= last + delay * 7) {
		BossFireThrower = &MoreDown;
	}
	else if (now > last + delay * 7 && now <= last + delay * 8) {
		BossFireThrower = &Down;
	}
	else if (now > last + delay * 8 && now <= last + delay * 9) {
		BossFireThrower = &middle;
		last = now; 
	}

	 

}
