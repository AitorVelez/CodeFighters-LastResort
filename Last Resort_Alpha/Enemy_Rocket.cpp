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
	position.x += 1;
	dirx = position.x - App->player->position.x;
	diry = position.y - App->player->position.y;
	//hyp = sqrt(dirx*dirx + diry*diry);

	
	angle = atan2(diry,dirx);

	angle = (angle * 360) / (2 * PI);
	angle += 180;
	queso = floor(angle / 22.5);
	
	/*LOG("CCC dx=%f dy=%f a=%f q=%f", dirx, diry, angle, queso);*/

	if (queso == 1) {
		SpiderTank = &se1;
		
	}
	else if (queso == 2) {
		SpiderTank = &se2;
	}
	else if (queso == 3) {
		SpiderTank = &se3;
	}
	else if (queso == 4) {
		SpiderTank = &Down;
	}
	else if (queso == 5) {
		SpiderTank = &sw1;
	}
	else if (queso == 6) {
		SpiderTank = &sw2;
	}
	else if (queso == 7) {
		SpiderTank = &sw3;
	}
	else if (queso == 8) {
		SpiderTank = &left;
	}
	else if (queso == 9) {
		SpiderTank = &nw3;
	}
	else if (queso == 10) {
		SpiderTank = &nw2;
	}
	else if (queso == 11) {
		SpiderTank = &nw1;
	}
	else if (queso == 12) {
		SpiderTank = &Up;
	}
	else if (queso == 13) {
		SpiderTank = &ne1;
	}
	else if (queso == 14) {
		SpiderTank = &ne2;
	}
	else if (queso == 15) {
		SpiderTank = &ne3;
	}
	else if (queso == 16) {
		SpiderTank = &Right;
	}


}
