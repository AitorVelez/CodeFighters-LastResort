#include "Application.h"
#include "Enemy_Boss.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleInput.h"
#include "SDL\include\SDL_timer.h"


Enemy_Boss::Enemy_Boss(int x, int y, int HP) : Enemy(x, y, HP)
{
	hp = 5000; 

	AnimMove.PushBack({ 19,936,128,80 });
	AnimMove.PushBack({ 152,936,128,81 });
	AnimMove.PushBack({ 285,936,128,81 });
	AnimMove.PushBack({ 418,936,128,80 });
	AnimMove.PushBack({ 19,1028,128,80 });
	AnimMove.PushBack({ 152,1027,128,81 });
	AnimMove.PushBack({ 285,1028,128,81 });
	AnimMove.PushBack({ 418,1028,128,81 });
	AnimMove.PushBack({ 24,1118,128,81 });
	AnimMove.PushBack({ 152,1118,128,80 });
	AnimMove.PushBack({ 285,1118,128,80 });
	AnimMove.PushBack({ 418,1118,128,79 });
	AnimMove.PushBack({ 19,1222,128,80 });
	AnimMove.PushBack({ 152,1221,128,81 });
	AnimMove.PushBack({ 285,1221,128,81 });
	AnimMove.PushBack({ 418,1221,128,81 });
	AnimMove.speed = 0.15f;


	FireSpot.PushBack({ 531, 813, 119, 81 });
	FireSpot.PushBack({ 369, 812, 121, 81 });
	FireSpot.PushBack({ 524, 709, 123, 81 });
	FireSpot.PushBack({ 369, 709, 126, 80 });
	FireSpot.PushBack({ 521, 604, 129, 80 });
	FireSpot.PushBack({ 363, 603, 137, 80 });
	FireSpot.speed = 0.1f; 

	FireSpotDespawn.PushBack({ 363, 603, 137, 80 });
	FireSpotDespawn.PushBack({ 521, 604, 129, 80 });
	FireSpotDespawn.PushBack({ 369, 709, 126, 80 });
	FireSpotDespawn.PushBack({ 524, 709, 123, 81 });
	FireSpotDespawn.PushBack({ 369, 812, 121, 81 });
	FireSpotDespawn.PushBack({ 531, 813, 119, 81 });
	FireSpotDespawn.speed = 0.1f;

	FireSpotMove.PushBack({ 38, 70, 128, 81 });

	BossAnim = &AnimMove; 
	original_y = y;
	collider = App->collision->AddCollider({ 0, 0, 128, 80 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Boss::Move()
{
/*	
	if (going_up)
	{
		if (wave > 5.0f)
			going_up = false;
		else
			wave += 0.1f;
	}
	else
	{
		if (wave < -5.0f)
			going_up = true;
		else
			wave -= 0.1f;
	}

	position.y = int(float(original_y) + (10.0f * sinf(wave)));
	position.x -= 2;
	*/

	

	position.x += 1; 

	GreenShotTimer = SDL_GetTicks(); 
	if (GreenShotTimer > GreenLast + 1000) {
		App->particles->AddParticle(App->particles->PreBossGreenShot, position.x - 20, position.y + 12, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->PreBossGreenShot3, position.x + 5, position.y + 6, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->BossGreenShot, position.x - 15, position.y + 12, COLLIDER_ENEMY_SHOT); 

			App->particles->AddParticle(App->particles->PreBossGreenShot, position.x -35, position.y + 61, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->PreBossGreenShot3, position.x -10, position.y + 55, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->BossGreenShot, position.x -30 , position.y + 61, COLLIDER_ENEMY_SHOT);

			GreenLast = GreenShotTimer; 
	}
	
	
	if (FireThrowerSpawned == false) {
		if (position.x < App->player->position.x + 180) {	
			FireSpotSpawned = true; 
		}
	}
	if (FireSpotSpawned == true) {
		BossAnim = &FireSpot;
		now = SDL_GetTicks();
		if (now > last + 2100) {
			App->enemies->AddEnemy(ENEMY_TYPES::BOSSFIRE, position.x - 20, position.y + 20);
			FireThrowerSpawned = true;    LOG("DANGER: FIRETHROWER HAS SPAWNED ------------------------------");
			FireSpotSpawned = false; 
		}
	}

	//now = SDL_GetTicks();
	int delay = 500; 
	if (FireThrowerSpawned == true) {
		if (now < last + 5000) {
			BossAnim = &FireSpotMove;
		}
		else if (now > last + 5000 && now < last + 5000 + delay) {
			App->enemies->BossFlameDespawn = true; 
			BossAnim = &FireSpotDespawn;
		}
		else if (now >= last + 5000 + delay) {
			BossAnim = &AnimMove; 
		}
	}
		
	

}
