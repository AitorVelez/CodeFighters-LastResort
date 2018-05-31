#include "Application.h"
#include "Enemy_Rocket.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "SDL\include\SDL_timer.h"

Enemy_Rocket::Enemy_Rocket(int x, int y, int HP) : Enemy(x, y, HP)
{

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Rocket::Move()
{
	
}
