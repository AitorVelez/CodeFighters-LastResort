#include "Application.h"
#include "Enemy_Tank.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleBackground.h"
#include "ModuleParticles.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "SDL\include\SDL_timer.h"
#include "Enemy.h"
#define TANKWIDTH 157
#define TANKHEIGHT 64
Enemy_Tank::Enemy_Tank(int x, int y, int HP) : Enemy(x, y, HP)
{
	HP = 5; 
	RelPosx = SCREEN_WIDTH; 
	RelPosy = SCREEN_HEIGHT - TANKHEIGHT;

	Anim2Distance.x = 52; 
	Anim2Distance.y = -4; 
	Anim3Distance.x = 86;
	Anim3Distance.y = 2;

/*	Anim4Distance.x = 52;             // RIGHT AND LEFT (BIG) 
	Anim4Distance.y = -1;              
	Anim5Distance.x = 86;             // RIGHT AND LEFT (SMALL)
	Anim5Distance.y = 0; */

	tank.PushBack({ 16,857,157,64 }); 
	tank.PushBack({ 17,921,157,63 });
	tank.speed = 0.2f; 
	animation = &tank;

	canon.PushBack({ 178,779,28,10 });
	animation2 = &canon;                            // LEFT BIG 
	canon2.PushBack({ 205,831,15,6 });
    animation3 = &canon2;                           // LEFT SMALL


	collider = App->collision->AddCollider({ 0, 0, 157, 64 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_y = y;
	original_x = x; 


	canonUp.PushBack({ 218,731,26,14 });
	canon2Up.PushBack({ 212,805,13,9 });
	canonUpLeft.PushBack({ 244,731,26,14 });
	canon2UpLeft.PushBack({ 186,805,13,9 });
	canonUpRight.PushBack({ 192,731,26,14 });
	canon2UpRight.PushBack({ 225,805,13,9 });
    canonUpMoreLeft.PushBack({ 179,762,26,13 });           // 
	canonUpMoreRight.PushBack({ 240,776,26,13 });
	canonRight.PushBack({ 206,779,29,10 });
	canon2Right.PushBack({ 221,831,14,6 });
}

void Enemy_Tank::Move()
{

	if (App->background->bgpos < original_x + SCREEN_WIDTH) {           // IT SHOULD APPEAR WITH THE SAME SPEED AS BG DEPTH 1 
		position.x += 0.4875f; 
		RelPosx -= 0.5125f;
	}
	else if (App->background->bgpos >= original_x + SCREEN_WIDTH && App->background->bgpos <= original_x + SCREEN_WIDTH*2) {
		position.x += 1.5f;
		RelPosx += 0.5f;
	}
	else if(App->background->bgpos > original_x + SCREEN_WIDTH*2 && App->background->bgpos < 8350) {      // STAY
		position.x += 1; 
		ReadyToShoot = true; 
	}
	else if (App->background->bgpos >= 8350) {
		position.x += 0.4875f;
		//RelPosx += 0.4875f;
	}


	


	                                                                  // ONLY FOR PLAYER 1

	if (App->player2->IsEnabled() == false && App->player->IsEnabled() == true) {
		if (App->player->position.x <= position.x + TANKWIDTH / 2 - 3 * CHARACTER_WIDTH / 2 - 70 && App->player->position.y >= SCREEN_HEIGHT - TANKHEIGHT) {              // LEFT BOTTOM
			animation2 = &canon;
			animation3 = &canon2;
		}

		if (App->player->position.x >= 0 && App->player->position.y < SCREEN_HEIGHT - TANKHEIGHT && App->player->position.x <= position.x + TANKWIDTH / 2 - 3 * CHARACTER_WIDTH / 2 -70 ) {
			animation2 = &canonUpMoreLeft;
			animation3 = &canon2UpLeft;
		}

		if (App->player->position.x > position.x + TANKWIDTH / 2 - 3 * CHARACTER_WIDTH -70 / 2 && App->player->position.x <= position.x + TANKWIDTH / 2 - CHARACTER_WIDTH / 2 - 40) {
			animation2 = &canonUpLeft;
			animation3 = &canon2UpLeft;
		}

		if (App->player->position.x > position.x + TANKWIDTH / 2 - CHARACTER_WIDTH - 20/ 2 && App->player->position.x <= position.x + TANKWIDTH / 2 + CHARACTER_WIDTH / 2) { // UP
			animation2 = &canonUp;
			animation3 = &canon2Up;
		}
		if (App->player->position.x > position.x + TANKWIDTH / 2 + CHARACTER_WIDTH / 2 && App->player->position.x <= position.x + TANKWIDTH / 2 + 3 * CHARACTER_WIDTH / 2) {
			animation2 = &canonUpRight;
			animation3 = &canon2UpRight;
		}
		if (App->player->position.x > position.x + TANKWIDTH / 2 + 3 * CHARACTER_WIDTH / 2 && App->player->position.y <= SCREEN_HEIGHT - TANKHEIGHT) {
			animation2 = &canonUpMoreRight;
			animation3 = &canon2UpRight;
		}
		if (App->player->position.x > position.x + TANKWIDTH && App->player->position.y >= SCREEN_HEIGHT - TANKHEIGHT) {       // RIGHT BOTTOM
			animation2 = &canonRight;
			animation3 = &canon2Right;
		}
	}                                                                
	
																	// ONLY FOR PLAYER 2

	if (App->player2->IsEnabled() == true && App->player->IsEnabled() == false) {
		if (App->player2->position.x <= position.x + TANKWIDTH / 2 - 3 * CHARACTER_WIDTH / 2 - 70 && App->player2->position.y >= SCREEN_HEIGHT - TANKHEIGHT) {              // LEFT BOTTOM
			animation2 = &canon;
			animation3 = &canon2;
		}

		if (App->player2->position.x >= 0 && App->player2->position.y < SCREEN_HEIGHT - TANKHEIGHT && App->player2->position.x <= position.x + TANKWIDTH / 2 - 3 * CHARACTER_WIDTH / 2 - 70) {
			animation2 = &canonUpMoreLeft;
			animation3 = &canon2UpLeft;
		}

		if (App->player2->position.x > position.x + TANKWIDTH / 2 - 3 * CHARACTER_WIDTH - 70 / 2 && App->player2->position.x <= position.x + TANKWIDTH / 2 - CHARACTER_WIDTH / 2 - 40) {
			animation2 = &canonUpLeft;
			animation3 = &canon2UpLeft;
		}

		if (App->player2->position.x > position.x + TANKWIDTH / 2 - CHARACTER_WIDTH - 20 / 2 && App->player2->position.x <= position.x + TANKWIDTH / 2 + CHARACTER_WIDTH / 2) { // UP
			animation2 = &canonUp;
			animation3 = &canon2Up;
		}
		if (App->player2->position.x > position.x + TANKWIDTH / 2 + CHARACTER_WIDTH / 2 && App->player2->position.x <= position.x + TANKWIDTH / 2 + 3 * CHARACTER_WIDTH / 2) {
			animation2 = &canonUpRight;
			animation3 = &canon2UpRight;
		}
		if (App->player2->position.x > position.x + TANKWIDTH / 2 + 3 * CHARACTER_WIDTH / 2 && App->player2->position.y <= SCREEN_HEIGHT - TANKHEIGHT) {
			animation2 = &canonUpMoreRight;
			animation3 = &canon2UpRight;
		}
		if (App->player2->position.x > position.x + TANKWIDTH && App->player2->position.y >= SCREEN_HEIGHT - TANKHEIGHT) {       // RIGHT BOTTOM
			animation2 = &canonRight;
			animation3 = &canon2Right;
		}
	}

	                                                                              
																			// Two player 




	if(App->player->IsEnabled() ==true && App->player2->IsEnabled() == true) {   // BIG CANON FOLLOWS PLAYER 1
		if (App->player->position.x <= position.x + TANKWIDTH / 2 - 3 * CHARACTER_WIDTH / 2 - 70 && App->player->position.y >= SCREEN_HEIGHT - TANKHEIGHT) {              // LEFT BOTTOM
			animation2 = &canon;
		}

		if (App->player->position.x >= 0 && App->player->position.y < SCREEN_HEIGHT - TANKHEIGHT && App->player->position.x <= position.x + TANKWIDTH / 2 - 3 * CHARACTER_WIDTH / 2 - 70) {
			animation2 = &canonUpMoreLeft;
		}

		if (App->player->position.x > position.x + TANKWIDTH / 2 - 3 * CHARACTER_WIDTH - 70 / 2 && App->player->position.x <= position.x + TANKWIDTH / 2 - CHARACTER_WIDTH / 2 - 40) {
			animation2 = &canonUpLeft;
		}

		if (App->player->position.x > position.x + TANKWIDTH / 2 - CHARACTER_WIDTH - 20 / 2 && App->player->position.x <= position.x + TANKWIDTH / 2 + CHARACTER_WIDTH / 2) { // UP
			animation2 = &canonUp;
		}
		if (App->player->position.x > position.x + TANKWIDTH / 2 + CHARACTER_WIDTH / 2 && App->player->position.x <= position.x + TANKWIDTH / 2 + 3 * CHARACTER_WIDTH / 2) {
			animation2 = &canonUpRight;
		}
		if (App->player->position.x > position.x + TANKWIDTH / 2 + 3 * CHARACTER_WIDTH / 2 && App->player->position.y <= SCREEN_HEIGHT - TANKHEIGHT) {
			animation2 = &canonUpMoreRight;
		}
		if (App->player->position.x > position.x + TANKWIDTH && App->player->position.y >= SCREEN_HEIGHT - TANKHEIGHT) {       // RIGHT BOTTOM
			animation2 = &canonRight;
		}

		                                                       // SMALL CANON FOLLOWS PLAYER 2
		if (App->player2->position.x <= position.x + TANKWIDTH / 2 - 3 * CHARACTER_WIDTH / 2 - 70 && App->player2->position.y >= SCREEN_HEIGHT - TANKHEIGHT) {              // LEFT BOTTOM
			animation3 = &canon2;
		}

		if (App->player2->position.x >= 0 && App->player2->position.y < SCREEN_HEIGHT - TANKHEIGHT && App->player2->position.x <= position.x + TANKWIDTH / 2 - 3 * CHARACTER_WIDTH / 2 - 70) {
			animation3 = &canon2UpLeft;
		}

		if (App->player2->position.x > position.x + TANKWIDTH / 2 - 3 * CHARACTER_WIDTH - 70 / 2 && App->player2->position.x <= position.x + TANKWIDTH / 2 - CHARACTER_WIDTH / 2 - 40) {
			animation3 = &canon2UpLeft;
		}

		if (App->player2->position.x > position.x + TANKWIDTH / 2 - CHARACTER_WIDTH - 20 / 2 && App->player2->position.x <= position.x + TANKWIDTH / 2 + CHARACTER_WIDTH / 2) { // UP
			animation3 = &canon2Up;
		}
		if (App->player2->position.x > position.x + TANKWIDTH / 2 + CHARACTER_WIDTH / 2 && App->player2->position.x <= position.x + TANKWIDTH / 2 + 3 * CHARACTER_WIDTH / 2) {
			animation3 = &canon2UpRight;
		}
		if (App->player2->position.x > position.x + TANKWIDTH / 2 + 3 * CHARACTER_WIDTH / 2 && App->player2->position.y <= SCREEN_HEIGHT - TANKHEIGHT) {
			animation3 = &canon2UpRight;
		}
		if (App->player2->position.x > position.x + TANKWIDTH && App->player2->position.y >= SCREEN_HEIGHT - TANKHEIGHT) {       // RIGHT BOTTOM
			animation3 = &canon2Right;
		}
	}
	
}


void Enemy_Tank::Shoot() {                     // two player
	
	if (ReadyToShoot == true) {
		if (App->player->IsEnabled() == true && App->player2->IsEnabled() == true) {
			BigBulletDirx = (App->player->relativeposition.x + CHARACTER_WIDTH * 4) - (RelPosx + Anim2Distance.x);
			BigBulletDiry = (App->player->relativeposition.y) - (RelPosy + Anim2Distance.y);
			SmallBulletDirx = (App->player2->relativeposition.x + CHARACTER_WIDTH * 4) - (RelPosx + Anim3Distance.x);
			SmallBulletDiry = (App->player2->relativeposition.y) - (RelPosy + Anim3Distance.y);

			App->particles->BigTankShot.speed.x = 0.01*BigBulletDirx;
			App->particles->BigTankShot.speed.y = 0.01*BigBulletDiry;
			App->particles->SmallTankShot.speed.x = 0.01*SmallBulletDirx;
			App->particles->SmallTankShot.speed.y = 0.01*SmallBulletDiry;

			current_time = SDL_GetTicks();

			if (current_time > last_time + 1000) {
				App->particles->AddParticle(App->particles->BigTankShot, position.x + Anim2Distance.x, position.y + Anim2Distance.y, COLLIDER_ENEMY_SHOT);
				last_time = current_time;
			}
			current_time2 = SDL_GetTicks();

			if (current_time2 > last_time2 + 1000) {
				App->particles->AddParticle(App->particles->SmallTankShot, position.x + Anim3Distance.x, position.y + Anim3Distance.y, COLLIDER_ENEMY_SHOT);
				last_time2 = current_time2;
			}
		}


		// PLAYER ONE ALIVE



		if (App->player->IsEnabled() == true && App->player2->IsEnabled() == false) {
			BigBulletDirx = (App->player->relativeposition.x + CHARACTER_WIDTH * 4) - (RelPosx + Anim2Distance.x);
			BigBulletDiry = (App->player->relativeposition.y) - (RelPosy + Anim2Distance.y); 

			SmallBulletDirx = (App->player->relativeposition.x + CHARACTER_WIDTH * 4) - (RelPosx + Anim3Distance.x);
			SmallBulletDiry = (App->player->relativeposition.y) - (RelPosy + Anim3Distance.y);

			App->particles->BigTankShot.speed.x = 0.01*BigBulletDirx;
			App->particles->BigTankShot.speed.y = 0.01*BigBulletDiry;
			App->particles->SmallTankShot.speed.x = 0.01*SmallBulletDirx;
			App->particles->SmallTankShot.speed.y = 0.01*SmallBulletDiry;

			current_time = SDL_GetTicks();

			if (current_time > last_time + 1000) {
				App->particles->AddParticle(App->particles->BigTankShot, position.x + Anim2Distance.x, position.y + Anim2Distance.y, COLLIDER_ENEMY_SHOT);
				last_time = current_time;
			}
			current_time2 = SDL_GetTicks();

			if (current_time2 > last_time2 + 1000) {
				App->particles->AddParticle(App->particles->SmallTankShot, position.x + Anim3Distance.x, position.y + Anim3Distance.y, COLLIDER_ENEMY_SHOT);
				last_time2 = current_time2;
			}
		}




		// PLAYER 2 ALIVE


		if (App->player2->IsEnabled() == true && App->player->IsEnabled() == false) {
			BigBulletDirx = (App->player2->relativeposition.x + CHARACTER_WIDTH * 4) - (RelPosx + Anim2Distance.x);
			BigBulletDiry = (App->player2->relativeposition.y) - (RelPosy + Anim2Distance.y);
			SmallBulletDirx = (App->player2->relativeposition.x + CHARACTER_WIDTH * 4) - (RelPosx + Anim3Distance.x);
			SmallBulletDiry = (App->player2->relativeposition.y) - (RelPosy + Anim3Distance.y);

			App->particles->BigTankShot.speed.x = 0.01*BigBulletDirx;
			App->particles->BigTankShot.speed.y = 0.01*BigBulletDiry;
			App->particles->SmallTankShot.speed.x = 0.01*SmallBulletDirx;
			App->particles->SmallTankShot.speed.y = 0.01*SmallBulletDiry;

			current_time = SDL_GetTicks();

			if (current_time > last_time + 1000) {
				App->particles->AddParticle(App->particles->BigTankShot, position.x + Anim2Distance.x, position.y + Anim2Distance.y, COLLIDER_ENEMY_SHOT);
				last_time = current_time;
			}
			current_time2 = SDL_GetTicks();

			if (current_time2 > last_time2 + 1000) {
				App->particles->AddParticle(App->particles->SmallTankShot, position.x + Anim3Distance.x, position.y + Anim3Distance.y, COLLIDER_ENEMY_SHOT);
				last_time2 = current_time2;
			}
		}
	}









}











