#include "Application.h"
#include "GPower.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleBall.h"

GrenadePowerUp::GrenadePowerUp(int x, int y) : Powerup(x, y)
{
	//L powerup sprites

	PowChangeColor.PushBack({ 108,488,31,16 });
	PowChangeColor.PushBack({ 146,488,31,16 });
	PowChangeColor.speed = 0.05f;
	PowChangeColor.loop = true;
	animation = &PowChangeColor;


	collider = App->collision->AddCollider({ 0, 0, 18, 21 }, COLLIDER_TYPE::COLLIDER_POWERUP_G, (Module*)App->power);

}


void GrenadePowerUp::OnCollision(Collider *collider)
{

}