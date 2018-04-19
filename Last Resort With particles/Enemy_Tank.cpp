#include "Application.h"
#include "Enemy_Tank.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleBackground.h"
#include "ModuleParticles.h"
#include "ModuleInput.h"

Enemy_Tank::Enemy_Tank(int x, int y) : Enemy(x, y)
{
	Anim2Distance.x = 50; 
	Anim2Distance.y = -2; 
	Anim3Distance.x = 84;
	Anim3Distance.y = 4;
	tank.PushBack({ 16,857,157,64 });
	tank.PushBack({ 17,921,157,63 });
	tank.speed = 0.2f; 
	animation = &tank;
	canon.PushBack({ 178,779,28,10 });
	canon2.PushBack({ 205,831,15,6 });
	animation2 = &canon;
	animation3 = &canon2; 
	collider = App->collision->AddCollider({ 0, 0, 157, 64 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
}

void Enemy_Tank::Move()
{
	 /*
	int cont = 0; 
	if (cont == 0) {
		if (App->background->bgpos >= position.x) {
			cont++; 
			RelToBg = App->background->bgpos; 
		}
	}
	else {
		if (RelToBg <= position.x && position.x <= RelToBg + SCREEN_WIDTH) {
			position.x += 2; 
		}
	}*/
	if (App->background->bgpos >= position.x) {
		position.x += 1;
	}
}


void Enemy_Tank::Shoot() {
	//if (App->background->bgpos >= position.x) {

	if (App->input->keyboard[SDL_SCANCODE_U] == KEY_STATE::KEY_DOWN) {
		App->particles->AddParticle(App->particles->BigTankShot, position.x + Anim2Distance.x, position.y + Anim2Distance.y, COLLIDER_ENEMY_SHOT);
	}
	//}
}
