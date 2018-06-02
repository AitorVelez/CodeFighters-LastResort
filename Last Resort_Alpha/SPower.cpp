#include "Application.h"
#include "SPower.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"

SpeedPowerUp::SpeedPowerUp(int x, int y) : Powerup(x, y)
{


	PowChangeColor.PushBack({ 342,483,18,21 });
	PowChangeColor.loop = false;
	animation = &PowChangeColor;


	collider = App->collision->AddCollider({ 0, 0, 18, 21 }, COLLIDER_TYPE::COLLIDER_POWERUP_S, (Module*)App->power);

	type = SPEED_POWER; 
}

void SpeedPowerUp::OnCollision(Collider *collider)
{
}