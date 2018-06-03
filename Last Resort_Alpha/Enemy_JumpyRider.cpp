#include "Application.h"
#include "Enemy_JumpyRider.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "SDL\include\SDL_timer.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "SDL\include\SDL_timer.h"

Enemy_JumpyRider::Enemy_JumpyRider(int x, int y, int HP) : Enemy(x, y, HP)
{
	fly.PushBack({ 257,295,48,41 });
	fly.PushBack({ 315,295,48,39 });
	fly.PushBack({ 373,290,48,40 });
	fly.PushBack({ 431,290,48,45 });
	fly.PushBack({ 257,340,48,47 });
	fly.PushBack({ 315,339,48,41 });
	fly.PushBack({ 373,339,48,41 });
	fly.PushBack({ 431,343,48,48 });
	fly.PushBack({ 257,386,48,41 });
	fly.PushBack({ 315,386,48,41 });
	fly.PushBack({ 373,386,48,39 });
	fly.PushBack({ 431,392,48,45 });
	fly.PushBack({ 431,445,48,40 });
	fly.speed = 0.25f;


	hp = original_hp = 6;
	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 48, 48 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_JumpyRider::Move()
{
	
	position.x +=1;
	
	dirx = App->player->position.x - position.x;
	diry = App->player->position.y - position.y;

	App->particles->Bossgreen.speed.x = (dirx / sqrt((pow(dirx, 2)) + (pow(diry, 2))));
	App->particles->Bossgreen.speed.y = (diry / sqrt((pow(dirx, 2)) + (pow(diry, 2))));

	now = SDL_GetTicks(); 
	if (now > last + 2000) {
		App->particles->AddParticle(App->particles->Bossgreen, position.x, position.y, COLLIDER_ENEMY_SHOT);
	}
	last = now; 
	
	

}
