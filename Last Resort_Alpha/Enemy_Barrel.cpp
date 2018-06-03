#include "Application.h"
#include "Enemy_Barrel.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "SDL\include\SDL_timer.h"
#include "ModuleParticles.h"

Enemy_Barrel::Enemy_Barrel(int x, int y, int HP) : Enemy(x, y, HP)
{
	hp = 4;

	fly.PushBack({ 198,853-9,20,22+9 });
	fly.PushBack({ 228,853-9,20,22+9 });
	fly.PushBack({ 258,853-9,20,22+9 });
	fly.PushBack({ 288,853-9,20,22+9 });

	Barrelito1.PushBack({ 11,166,9,11 });
	Barrelito2.PushBack({ 23,167,10,12 });
	Barrelito3.PushBack({ 36,166,12,12 });
	Barrelito4.PushBack({ 52,167,12,11 });
	Barrelito5.PushBack({ 65,167,10,12 });
	Barrelito6.PushBack({ 79,166,14,13 });
	Barrelito7.PushBack({ 98,167,13,10 });
	Barrelito8.PushBack({ 113,168,13,10 });

	Barrelitoup.PushBack({ 65,160,10,12 + 6 });
	Barrelitoup.PushBack({ 65,161,10,12 + 5 });
	Barrelitoup.PushBack({ 65,162,10,12 + 4 });
	Barrelitoup.PushBack({ 65,163,10,12 + 3 });
	Barrelitoup.PushBack({ 65,164,10,12 + 2 });
	Barrelitoup.PushBack({ 65,165,10,12 + 1 });
	Barrelitoup.PushBack({ 65,166,10,12 });
	Barrelitoup.speed = 0.5f;
	Barrelitoup.loop = false;

	Barrelitodown.PushBack({ 65,166,10,12 });
	Barrelitodown.PushBack({ 65,165,10,12 + 1 });
	Barrelitodown.PushBack({ 65,163,10,12 + 3 });
	Barrelitodown.PushBack({ 65,162,10,12 + 4 });
	Barrelitodown.PushBack({ 65,161,10,12 + 5 });
	Barrelitodown.PushBack({ 65,158,10,12 + 6 });
	Barrelitodown.speed = 0.5f;
	Barrelitodown.loop = false;





	path.PushBack({ 0,0.1f }, 60, &fly);
	path.PushBack({ 0,-0.1f }, 60, &fly);

	fly.speed = 0.1;
	

//	original_position.x = x;
//	original_position.y = y;
	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

//	y_original = y;
//	collider = App->collision->AddCollider({ 0, 0, 20, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


}

void Enemy_Barrel::Move()
{
	int axis;
	dirx = position.x - App->player->position.x;
	diry = position.y - App->player->position.y;
	hyp = sqrt(dirx*dirx + diry*diry);
	angle = atan2(diry, dirx);
	angle = (angle * 360) / (2 * PI);
	angle += 180;
	
	
	now = SDL_GetTicks();

	if (now > up + 3000) {
		Barrels_boy = &Barrelitoup;
	
		
		if (Barrelitoup.Finished()) {
			if (flag) {
				stay = SDL_GetTicks();
				flag = false;
			}
			
			if (angle > 337.5 && angle < 22.5) {
				Barrels_boy = &Barrelito7;
				if (pum == false) {
					pum = true;
					App->particles->TurretShot.speed.x = 1.5f;
					App->particles->TurretShot.speed.y = 0;
					App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);
				
				}
			}
			else if (angle > 22.5 && angle < 67.5) {
				Barrels_boy = &Barrelito5;
				if (pum == false) {
					pum = true;
					App->particles->TurretShot.speed.x = 1;
					App->particles->TurretShot.speed.y = 1;
					App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);
				
				}
			}
			else if (angle > 67.5 && angle < 112.5) {
				Barrels_boy = &Barrelito2;
				if (pum == false) {
					pum = true;
					App->particles->TurretShot.speed.x = 0;
					App->particles->TurretShot.speed.y = 1.5f;
					App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);
				

				}
			}
			else if (angle > 112.5 && angle < 157.5) {
				Barrels_boy = &Barrelito6;
				if (pum == false) {
					pum = true;
					App->particles->TurretShot.speed.x = -1;
					App->particles->TurretShot.speed.y = 1;
					App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);
				

				}
			}
			else if (angle > 157.5 && angle < 202.5) {
				Barrels_boy = &Barrelito8;
				if (pum == false) {
					pum = true;
					App->particles->TurretShot.speed.x = -1.5;
					App->particles->TurretShot.speed.y = 0;
					App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);
				

				}
			}
			else if (angle > 202.5 && angle < 247.5) {
				Barrels_boy = &Barrelito3;
				if (pum == false) {
					pum = true;
					App->particles->TurretShot.speed.x = -1;
					App->particles->TurretShot.speed.y = -1;
					App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);
				

				}
			}
			else if (angle > 247.5 && angle < 292.5) {
				Barrels_boy = &Barrelito1;
				if (pum == false) {
					pum = true;
					App->particles->TurretShot.speed.x = 0;
					App->particles->TurretShot.speed.y = -1.5;
					App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);
				

				}
			}
			else {
				Barrels_boy = &Barrelito4;
				if (pum == false) {
					pum = true;
					App->particles->TurretShot.speed.x = 1;
					App->particles->TurretShot.speed.y = -1;
					App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);
				
				}
			}
				
			if (now > stay + 2000) {
				Barrels_boy = &Barrelitodown;
				if (Barrelitodown.Finished()) {
					up = SDL_GetTicks();
					pum = false;
				}
			}
		}
	}


	if (App->player->alive_p1 == false & App->player2->alive_p2 == true) {
		
		dirx1 = position.x - App->player2->position.x;
		diry1 = position.y - App->player2->position.y;
		hyp1 = sqrt(dirx1*dirx1 + diry1*diry1);
		angle1 = atan2(diry1, dirx1);
		angle1 = (angle1 * 360) / (2 * PI);
		angle1 += 180;


		now = SDL_GetTicks();

		if (now > up + 3000) {
			Barrels_boy = &Barrelitoup;


			if (Barrelitoup.Finished()) {
				if (flag) {
					stay = SDL_GetTicks();
					flag = false;
				}

				if (angle1 > 337.5 && angle1 < 22.5) {
					Barrels_boy = &Barrelito7;
					if (pum == false) {
						pum = true;
						App->particles->TurretShot.speed.x = 1.5f;
						App->particles->TurretShot.speed.y = 0;
						App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);

					}
				}
				else if (angle1 > 22.5 && angle1 < 67.5) {
					Barrels_boy = &Barrelito5;
					if (pum == false) {
						pum = true;
						App->particles->TurretShot.speed.x = 1;
						App->particles->TurretShot.speed.y = 1;
						App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);

					}
				}
				else if (angle1 > 67.5 && angle1 < 112.5) {
					Barrels_boy = &Barrelito2;
					if (pum == false) {
						pum = true;
						App->particles->TurretShot.speed.x = 0;
						App->particles->TurretShot.speed.y = 1.5f;
						App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);


					}
				}
				else if (angle1 > 112.5 && angle1 < 157.5) {
					Barrels_boy = &Barrelito6;
					if (pum == false) {
						pum = true;
						App->particles->TurretShot.speed.x = -1;
						App->particles->TurretShot.speed.y = 1;
						App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);


					}
				}
				else if (angle1 > 157.5 && angle1 < 202.5) {
					Barrels_boy = &Barrelito8;
					if (pum == false) {
						pum = true;
						App->particles->TurretShot.speed.x = -1.5;
						App->particles->TurretShot.speed.y = 0;
						App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);


					}
				}
				else if (angle1 > 202.5 && angle1 < 247.5) {
					Barrels_boy = &Barrelito3;
					if (pum == false) {
						pum = true;
						App->particles->TurretShot.speed.x = -1;
						App->particles->TurretShot.speed.y = -1;
						App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);


					}
				}
				else if (angle1 > 247.5 && angle1 < 292.5) {
					Barrels_boy = &Barrelito1;
					if (pum == false) {
						pum = true;
						App->particles->TurretShot.speed.x = 0;
						App->particles->TurretShot.speed.y = -1.5;
						App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);


					}
				}
				else {
					Barrels_boy = &Barrelito4;
					if (pum == false) {
						pum = true;
						App->particles->TurretShot.speed.x = 1;
						App->particles->TurretShot.speed.y = -1;
						App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);

					}
				}

				if (now > stay + 2000) {
					Barrels_boy = &Barrelitodown;
					if (Barrelitodown.Finished()) {
						up = SDL_GetTicks();
						pum = false;
					}
				}
			}
		}
	}
	else {
		dirx = position.x - App->player->position.x;
		diry = position.y - App->player->position.y;
		hyp = sqrt(dirx*dirx + diry*diry);
		angle = atan2(diry, dirx);
		angle = (angle * 360) / (2 * PI);
		angle += 180;


		now = SDL_GetTicks();

		if (now > up + 3000) {
			Barrels_boy = &Barrelitoup;


			if (Barrelitoup.Finished()) {
				if (flag) {
					stay = SDL_GetTicks();
					flag = false;
				}

				if (angle > 337.5 && angle < 22.5) {
					Barrels_boy = &Barrelito7;
					if (pum == false) {
						pum = true;
						App->particles->TurretShot.speed.x = 1.5f;
						App->particles->TurretShot.speed.y = 0;
						App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);

					}
				}
				else if (angle > 22.5 && angle < 67.5) {
					Barrels_boy = &Barrelito5;
					if (pum == false) {
						pum = true;
						App->particles->TurretShot.speed.x = 1;
						App->particles->TurretShot.speed.y = 1;
						App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);

					}
				}
				else if (angle > 67.5 && angle < 112.5) {
					Barrels_boy = &Barrelito2;
					if (pum == false) {
						pum = true;
						App->particles->TurretShot.speed.x = 0;
						App->particles->TurretShot.speed.y = 1.5f;
						App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);


					}
				}
				else if (angle > 112.5 && angle < 157.5) {
					Barrels_boy = &Barrelito6;
					if (pum == false) {
						pum = true;
						App->particles->TurretShot.speed.x = -1;
						App->particles->TurretShot.speed.y = 1;
						App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);


					}
				}
				else if (angle > 157.5 && angle < 202.5) {
					Barrels_boy = &Barrelito8;
					if (pum == false) {
						pum = true;
						App->particles->TurretShot.speed.x = -1.5;
						App->particles->TurretShot.speed.y = 0;
						App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);


					}
				}
				else if (angle > 202.5 && angle < 247.5) {
					Barrels_boy = &Barrelito3;
					if (pum == false) {
						pum = true;
						App->particles->TurretShot.speed.x = -1;
						App->particles->TurretShot.speed.y = -1;
						App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);


					}
				}
				else if (angle > 247.5 && angle < 292.5) {
					Barrels_boy = &Barrelito1;
					if (pum == false) {
						pum = true;
						App->particles->TurretShot.speed.x = 0;
						App->particles->TurretShot.speed.y = -1.5;
						App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);


					}
				}
				else {
					Barrels_boy = &Barrelito4;
					if (pum == false) {
						pum = true;
						App->particles->TurretShot.speed.x = 1;
						App->particles->TurretShot.speed.y = -1;
						App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_ENEMY_SHOT);

					}
				}

				if (now > stay + 2000) {
					Barrels_boy = &Barrelitodown;
					if (Barrelitodown.Finished()) {
						up = SDL_GetTicks();
						pum = false;
					}
				}
			}
		}
	}
	
	
	animation = &fly;
	/*position = original_position + path.GetCurrentPosition();*/
}
