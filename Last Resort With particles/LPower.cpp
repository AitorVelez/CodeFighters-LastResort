#include "Application.h"
#include "Lpower.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"

LaserPowerUp::LaserPowerUp(int x, int y) : Powerup(x, y)
{
	/*PowChangeColor.PushBack({ 260,488,31,16 });
	PowChangeColor.PushBack({ 298,488,31,16 });
	*/
	
	PowChangeColor.PushBack({ 342,483,18,21 });
//	PowChangeColor.PushBack({ 428,297,31,16 });
	
	PowChangeColor.speed = 0.05f;
	PowChangeColor.loop = true;
	animation = &PowChangeColor;


	collider = App->collision->AddCollider({ 0, 0, 18, 21 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->power);

}

void LaserPowerUp::OnCollision(Collider *collider)
{

	App->player->speed = 3;

}