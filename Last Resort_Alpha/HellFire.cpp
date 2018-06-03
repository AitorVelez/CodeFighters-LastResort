#include "Application.h"
#include "Grenade.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "Path.h"
#include "SDL\include\SDL_timer.h"
#include "ModulePlayer.h"
#include "Hellfire.h"
#include "ModuleEnemies.h"

Hellfire::Hellfire(int x, int y, int HP) : Enemy(x, y, HP)
{
	Launch.PushBack({ 330,49,14,6 });

	Bullets = &Launch;
	original_x = x;
	original_y = y;
	collider = App->collision->AddCollider({ 0, 0, 14, 6 }, COLLIDER_TYPE::COLLIDER_PLAYER_SHOT, (Module*)App->enemies);

}

void Hellfire::Move()
{
	uint i = 0;
	now = SDL_GetTicks();

	if (position.x == original_x) {
		shhot = SDL_GetTicks();
		position.x -= 1.5f;
		position.y -= 1.5f;

	}
	else if (shhot + 500 > now) {
		position.x -= 0.5f;
		position.y -= 0.3f;
	}
	else {
		position.x += 5.5;
		

		//dirx = App->enemies->nearbyenemyx(position.x, position.y);
		//diry = App->enemies->nearbyenemyy(position.x, position.y);

		LOG("%f", dirx);
		LOG("%f", diry);





	}
}