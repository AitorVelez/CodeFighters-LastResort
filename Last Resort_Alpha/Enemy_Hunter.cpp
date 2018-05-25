#include "Application.h"
#include "Enemy_Hunter.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModuleBackground2.h"

Enemy_Hunter::Enemy_Hunter(int x, int y, int HP) : Enemy(x, y, HP)
{
	appear.PushBack({ 192,559,32,15 });
	appear.PushBack({ 160,559,32,15 });
	appear.PushBack({ 128,559,32,15 });
	appear.PushBack({ 96,559,32,15 });
	appear.PushBack({ 64,559,32,15 });
	appear.PushBack({ 32,559,32,15 });
	appear.PushBack({ 0,559,32,15 });
	appear.PushBack({ 256,544,32,15 });
	appear.PushBack({ 224,544,32,15 });
	appear.PushBack({ 192,544,32,15 });
	appear.PushBack({ 160,544,32,15 });
	appear.PushBack({ 128,544,32,15 });
	appear.PushBack({ 96,544,32,15 });
	appear.PushBack({ 64,544,32,15 });
	appear.PushBack({ 32,544,32,15 });
	appear.PushBack({ 0,544,32,15 });
	appear.PushBack({ 256,529,32,15 });
	appear.PushBack({ 224,529,32,15 });
	appear.PushBack({ 192,529,32,15 });
	appear.PushBack({ 160,529,32,15 });
	appear.PushBack({ 128,529,32,15 });
	appear.PushBack({ 96,529,32,15 });
	appear.PushBack({ 64,529,32,15 });
	appear.PushBack({ 32,529,32,15 });
	appear.PushBack({ 0,529,32,15 });
	appear.PushBack({ 256,514,32,15 });
	appear.PushBack({ 224,514,32,15 });
	appear.PushBack({ 192,514,32,15 });
	appear.PushBack({ 160,514,32,15 });
	appear.PushBack({ 128,514,32,15 });
	appear.PushBack({ 96,514,32,15 });
	appear.PushBack({ 64,514,32,15 });
	appear.PushBack({ 32,514,32,15 });
	appear.PushBack({ 0,514,32,15 });
	appear.speed = 0.2;

	anim2ndLevel = &appear;

	fly.PushBack({ 509,0,65,32 });
	fly.PushBack({ 509,32,65,32 });
	fly.PushBack({ 509,64,65,32 });
	fly.PushBack({ 509,96,65,32 });
	fly.PushBack({ 509,128,65,32 });
	fly.PushBack({ 509,160,65,32 });
	fly.PushBack({ 509,192,65,32 });
	fly.PushBack({ 509,224,65,32 });
	fly.PushBack({ 509,256,65,32 });
	fly.PushBack({ 509,256,32,32 });
	fly.PushBack({ 509,256,32,32 });
	fly.PushBack({ 509,256,32,32 });
	fly.PushBack({ 509,256,32,32 });
	fly.PushBack({ 509,256,32,32 });
	fly.PushBack({ 509,256,32,32 });
	fly.PushBack({ 509,256,32,32 });
	fly.PushBack({ 509,256,32,32 });
	fly.loop = false;
	fly.speed = 0.2;

	y_original = y;

}

void Enemy_Hunter::Move()
{

	position.y = y_original + (App->render->camera.y / 3);

	if (appear.Finished())
	{
		speed = -3; 
		anim2ndLevel = &fly;
		
		collider = App->collision->AddCollider({ 0, 19, 32, 14 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	}
	else {
		if (position.x < App->background2->bgpos) {
			ArrivedLeft = true;
		}
		else {
			speed = -3; 
		}
		if (ArrivedLeft) {
			speed = 3;
		}
	}

		



	position.x += speed;
}

void Enemy_Hunter::Appear()
{
	
}
