#include "Application.h"
#include "Lpower.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleBall.h"

LaserPowerUp::LaserPowerUp(int x, int y) : Powerup(x, y)
{
	//L powerup sprites

	PowChangeColor.PushBack({ 260,488,31,16 });
	PowChangeColor.PushBack({ 298,488,31,16 });
	PowChangeColor.speed = 0.05f;
	PowChangeColor.loop = true;
	animation = &PowChangeColor;


	collider = App->collision->AddCollider({ 0, 0, 18, 21 }, COLLIDER_TYPE::COLLIDER_POWERUP_L, (Module*)App->power);

}


void LaserPowerUp::OnCollision(Collider *collider)
{
	
}