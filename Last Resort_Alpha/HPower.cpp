#include "Application.h"
#include "HPower.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleBall.h"

HellfirePowerUp::HellfirePowerUp(int x, int y) : Powerup(x, y)
{
	//L powerup sprites

	PowChangeColor.PushBack({ 184,488,31,16 });
	PowChangeColor.PushBack({ 222,488,31,16 });
	PowChangeColor.speed = 0.05f;
	PowChangeColor.loop = true;
	animation = &PowChangeColor;


	collider = App->collision->AddCollider({ 0, 0, 18, 21 }, COLLIDER_TYPE::COLLIDER_POWERUP_L, (Module*)App->power);

}


void HellfirePowerUp::OnCollision(Collider *collider)
{

}