#include "Application.h"
#include "Enemy_Boss.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleInput.h"
#include "SDL\include\SDL_timer.h"
#include "ModuleBackground.h"
#include "ModuleRender.h"

#define BOSSHEIGHT 80 

Enemy_Boss::Enemy_Boss(int x, int y, int HP) : Enemy(x, y, HP)
{
	hp = 5000; 
	App->enemies->BOSSHASSPAWNED = true; 

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

	FireSpotMove.PushBack({ 38, 61, 128, 81 });

	BossAnim = &AnimMove; 
	original_x = x;
	original_y = y;
	collider = App->collision->AddCollider({ 0, 0, 128, 80 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Boss::Move()
{

	int speed = 0; 
	if (position.x > App->render->camera.x + 200) {
		speed = 0; 
	}
	else {
		speed = 1; 
	}
	
	position.x += speed; 
	if (original_x == position.x) {
		last = SDL_GetTicks();
	}

	if (IsFiringGreen == true) {
		if (goingup == false) {
			position.y += 0.5f;
			if (position.y > SCREEN_HEIGHT - BOSSHEIGHT - 50) {
				goingup = true;
			}
		}
		else {
			position.y -= 0.5f;
			if (position.y < 30) {
				goingup = false;
			}
		}
	}

	//int ShotCounter = 0; 
	GreenShotTimer = SDL_GetTicks(); 
	if (GreenShotTimer > GreenLast + 1000) {
		//if (ShotCounter < 3) {
			if (IsFiringGreen == true) {
				App->particles->AddParticle(App->particles->PreBossGreenShot, position.x - 20, position.y + 12, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->PreBossGreenShot3, position.x + 5, position.y + 6, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->BossGreenShot, position.x - 15, position.y + 12, COLLIDER_ENEMY_SHOT);

				App->particles->AddParticle(App->particles->PreBossGreenShot, position.x - 35, position.y + 66, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->PreBossGreenShot3, position.x - 10, position.y + 60, COLLIDER_ENEMY_SHOT);
				App->particles->AddParticle(App->particles->BossGreenShot, position.x - 30, position.y + 66, COLLIDER_ENEMY_SHOT);

				GreenLast = GreenShotTimer;
				//ShotCounter++;
			}
		//}
	}
	
	
	/*if (FireThrowerSpawned == false) {
		if (position.x < App->player->position.x + 180) {	
			FireSpotSpawned = true; 
		}
	}*/

	now = SDL_GetTicks(); 
	int delay = 500;
	int firsttime = 9000;
	int time = 15000;

	//if (FireSpotSpawned == true) {
	if (now > last + firsttime + delay && flag == false) {
		flag = true;
		App->enemies->AddEnemy(ENEMY_TYPES::BOSSFIRE, position.x - 20, position.y + 25);
		
		FireThrowerSpawned = true;    LOG("DANGER: FIRETHROWER HAS SPAWNED ------------------------------");
		FireSpotSpawned = false; 
	}
	//}

	//now = SDL_GetTicks();
	
	if (FireThrowerSpawned == false) {
		if (now < last + firsttime) {
			BossAnim = &AnimMove;                // move
			IsFiringGreen = true; 
		}
		else if (now >= last + firsttime && now <= last + firsttime + delay) {
			BossAnim = &FireSpot;                                                // spawn flame thrower 
			IsFiringGreen = false; 
		}
	}
	else {
	    if (now >= last + firsttime + delay && now < last + time) {
		    BossAnim = &FireSpotMove;                                           // move with flame thrower 
			IsFiringGreen = false;
	    }
	    else if (now >= last + time && now < last + time + delay) {
		     App->enemies->BossFlameDespawn = true;
	   	     BossAnim = &FireSpotDespawn;                                      // despawn flame thrower 
			 IsFiringGreen = false;
			 
       	}
	    else if (now >= last + time + delay) {
		    BossAnim = &AnimMove; 
			App->enemies->BossFlameDespawn = false;// move
			IsFiringGreen = true;
			FireThrowerSpawned = false;
			last = SDL_GetTicks();
			flag = false;


	    }

	}
	
	

}
