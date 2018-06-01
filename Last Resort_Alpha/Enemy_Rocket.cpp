#include "Application.h"
#include "Enemy_Rocket.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL_timer.h"
#include <math.h>
#include "ModuleParticles.h"

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
	
	int initial_speed = 1;
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
