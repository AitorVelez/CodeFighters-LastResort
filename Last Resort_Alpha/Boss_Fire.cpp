#include "Application.h"
#include "BossFire.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"


BossFire::BossFire(int x, int y, int HP) : Enemy(x, y, HP)
{

	FlameThrowerDistance.x = -20; 
	FlameThrowerDistance.y = 20;


	middle.PushBack({ 564,530,44,16 });
	up.PushBack({ 397,526,42,19 });
	Moreup.PushBack({ 336,520,41,24 });
	Down.PushBack({ 455,533,42,18 });
	MoreDown.PushBack({ 510,530,40,22 });

	BossFireThrower = &middle; 
	
	original_y = y;
	collider = App->collision->AddCollider({ 0, 0, 128, 80 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void BossFire::Move()
{
	position.x += 1; 



}