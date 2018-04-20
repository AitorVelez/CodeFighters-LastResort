#include "Application.h"
#include "SPower.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

SpeedPowerUp::SpeedPowerUp(int x, int y) : Powerup(x, y)
{


	PowChangeColor.PushBack({ 342,483,18,21 });

	PowChangeColor.speed = 0.05f;
	PowChangeColor.loop = true;
	animation = &PowChangeColor;


	collider = App->collision->AddCollider({ 0, 0, 18, 21 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->power);

}

void SpeedPowerUp::OnCollision(Collider *collider)
{

	App->player->speed = 3;

}