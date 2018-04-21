#include "Application.h"
#include "Lpower.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

LaserPowerUp::LaserPowerUp(int x, int y) : Powerup(x, y)
{
	//L powerup sprites

	PowChangeColor.PushBack({ 260,488,31,16 });
	PowChangeColor.PushBack({ 298,488,31,16 });
	PowChangeColor.speed = 0.05f;
	PowChangeColor.loop = true;
	animation = &PowChangeColor;


	collider = App->collision->AddCollider({ 0, 0, 18, 21 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->power);

}

void LaserPowerUp::OnCollision(Collider *collider)
{

	if (App->player->bullet_state == BULLET_NO_TYPE) {
		App->player->bullet_state=LASER1;
	}

	if (App->player->bullet_state == LASER1) {
		App->player->bullet_state = LASER2;
	}
	

	//si state laser 1 laser 2 
	//laser 2 no fot re
}