#include "Application.h"
#include "Enemy_Rocket.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL_timer.h"
#include <math.h>
#include "ModuleParticles.h"
#include "ModulePlayer2.h"

Enemy_Rocket::Enemy_Rocket(int x, int y, int HP) : Enemy(x, y, HP)
{
	Up.PushBack({211,191,10,14});
	Down.PushBack({ 211,241,10,14 });
	Right.PushBack({ 271,217,14,10 });
	left.PushBack({190,218,14,10});
	ne1.PushBack({ 224,191,11,13 });
	ne2.PushBack({ 239,191,13,13 });
	ne3.PushBack({ 256,191,13,11 });
	se1.PushBack({ 256,244,13,11 });
	se2.PushBack({239,242,13,13});
	se3.PushBack({ 224,242,11,13 });
	sw3.PushBack({ 209,210,13,11 });
	sw2.PushBack({ 226,208,13,13 });
	sw1.PushBack({ 243,208,11,13 });
	nw3.PushBack({ 209,225,13,11 });
	nw2.PushBack({ 226,225,13,13 });
	nw1.PushBack({ 243,225,11,13 });

	SpiderTank = &nw1;
	original_x = x;
	original_y = y;

	collider = App->collision->AddCollider({ 0, 0, 13, 11 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void Enemy_Rocket::Move()
{
	float queso;
	float queso2;
	
	int initial_speed = 1;

	if ((App->player2->alive_p2 == true) && (App->player->alive_p1 == false)) {

		dirx1 = position.x - App->player2->position.x;
		diry1 = position.y - App->player2->position.y;
		hyp1 = sqrt(dirx1*dirx1 + diry1*diry1);
		angle1 = atan2(diry1, dirx1);

		angle1 = (angle1 * 360) / (2 * PI);
		angle1 += 180;
		queso2 = floor(angle1 / 22.5);
		speed = 2;

		dirx1 /= hyp1;
		diry1 /= hyp1;

		now = SDL_GetTicks();
		if (position.y == original_y) {
			shot = SDL_GetTicks();
		}
		if (original_y < 78) // arriba
		{
			aim = SDL_GetTicks();
			if (aim < shot + 1000) {
				position.y += 1;
			}

			else {
				position.x -= dirx1 * speed * 1.6f;
				position.y -= diry1 * speed * 1.6f;
			}

		}
		if (original_y > 78) // abajo
		{
			aim = SDL_GetTicks();
			if (aim < shot + 1000) {
				position.y -= 1;
			}

			else {
				position.x -= dirx1 * speed * 1.6f;
				position.y -= diry1 * speed * 1.6f;
			}
		}


		/*LOG("CCC dx=%f dy=%f a=%f q=%f", dirx, diry, angle, queso);*/

		if (queso2 == 1) {
			SpiderTank = &se1;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x - 14, position.y - 10);
			}

		}
		else if (queso2 == 2) {
			SpiderTank = &se2;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x - 12, position.y - 12);
			}

		}
		else if (queso2 == 3) {
			SpiderTank = &se3;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x - 11, position.y - 15);
			}
		}
		else if (queso2 == 4) {
			SpiderTank = &Down;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x - 4, position.y - 16);
			}
		}
		else if (queso2 == 5) {
			SpiderTank = &sw1;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x + 5, position.y - 15);
			}
		}
		else if (queso2 == 6) {
			SpiderTank = &sw2;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x + 9, position.y - 12);
			}
		}
		else if (queso2 == 7) {
			SpiderTank = &sw3;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x + 11, position.y - 10);
			}
		}
		else if (queso2 == 8) {
			SpiderTank = &left;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x + 14, position.y - 3);
			}
		}
		else if (queso2 == 9) {
			SpiderTank = &nw3;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x + 11, position.y + 4);
			}
		}
		else if (queso2 == 10) {
			SpiderTank = &nw2;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x + 8, position.y + 9);
			}
		}
		else if (queso2 == 11) {
			SpiderTank = &nw1;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x + 4, position.y + 11);
			}
		}
		else if (queso2 == 12) {
			SpiderTank = &Up;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x - 4, position.y + 15);
			}
		}
		else if (queso2 == 13) {
			SpiderTank = &ne1;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x - 10, position.y + 12);
			}
		}
		else if (queso2 == 14) {
			SpiderTank = &ne2;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x - 13, position.y + 10);
			}
		}
		else if (queso2 == 15) {
			SpiderTank = &ne3;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x - 14, position.y + 6);
			}
		}
		else if (queso2 > 15) {
			SpiderTank = &Right;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x - 14, position.y + 6);

			}
		}
		else {
			SpiderTank = &Right;
			if (now > last + 200) {
				last = SDL_GetTicks();
				App->particles->AddParticle(App->particles->MisileSpidy, position.x - 19, position.y + -3);
			}
		}
	}


	dirx = position.x - App->player->position.x;
	diry = position.y - App->player->position.y;
	hyp = sqrt(dirx*dirx + diry*diry);
	angle = atan2(diry,dirx);

	angle = (angle * 360) / (2 * PI);
	angle += 180;
	queso = floor(angle / 22.5);
	speed = 2;

	dirx /= hyp;
	diry /= hyp;

	now = SDL_GetTicks();
	if (position.y == original_y) {
		shot = SDL_GetTicks();
	}
	if (original_y < 78) // arriba
	{
		aim = SDL_GetTicks();
		if (aim < shot + 1000) {
			position.y += 1;
		}

		else {
			position.x -= dirx * speed * 1.6f;
			position.y -= diry * speed * 1.6f;
		}

	}
	if (original_y > 78) // abajo
	{
		aim = SDL_GetTicks();
		if (aim < shot + 1000) {
			position.y -= 1;
		}

		else {
			position.x -= dirx * speed * 1.6f;
			position.y -= diry * speed * 1.6f;
		}
	}

	
	/*LOG("CCC dx=%f dy=%f a=%f q=%f", dirx, diry, angle, queso);*/

	if (queso == 1) {
		SpiderTank = &se1;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x - 14, position.y - 10);
		}
		
	}
	else if (queso == 2) {
		SpiderTank = &se2;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x - 12, position.y -12);
		}

	}
	else if (queso == 3) {
		SpiderTank = &se3;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x - 11, position.y - 15);
		}
	}
	else if (queso == 4) {
		SpiderTank = &Down;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x - 4, position.y - 16);
		}
	}
	else if (queso == 5) {
		SpiderTank = &sw1;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x + 5, position.y - 15);
		}
	}
	else if (queso == 6) {
		SpiderTank = &sw2;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x + 9, position.y - 12);
		}
	}
	else if (queso == 7) {
		SpiderTank = &sw3;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x + 11, position.y - 10);
		}
	}
	else if (queso == 8) {
		SpiderTank = &left;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x + 14, position.y - 3);
		}
	}
	else if (queso == 9) {
		SpiderTank = &nw3;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x + 11, position.y + 4);
		}
	}
	else if (queso == 10) {
		SpiderTank = &nw2;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x + 8, position.y + 9);
		}
	}
	else if (queso == 11) {
		SpiderTank = &nw1;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x + 4, position.y + 11);
		}
	}
	else if (queso == 12) {
		SpiderTank = &Up;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x -4, position.y + 15);
		}
	}
	else if (queso == 13) {
		SpiderTank = &ne1;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x - 10, position.y + 12);
		}
	}
	else if (queso == 14) {
		SpiderTank = &ne2;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x - 13, position.y + 10);
		}
	}
	else if (queso == 15) {
		SpiderTank = &ne3;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x - 14, position.y + 6);
		}
	}
	else if (queso > 15) {
		SpiderTank = &Right;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x - 14, position.y + 6);

		}
	}
	else {
		SpiderTank = &Right;
		if (now > last + 200) {
			last = SDL_GetTicks();
			App->particles->AddParticle(App->particles->MisileSpidy, position.x - 19, position.y + -3);
		}
	}


	


}
