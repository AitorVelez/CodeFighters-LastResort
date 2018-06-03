#include "Application.h"
#include "Enemy_Hunter.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModuleBackground2.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "SDL\include\SDL_timer.h"

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
	appear.speed = 0.154;
	appear.loop = false;

	anim2ndLevel = &appear;

	fly.PushBack({ 509,288,65,32 });
	fly.PushBack({ 509,256,65,32 });
	fly.PushBack({ 509,224,65,32 });
	fly.PushBack({ 509,192,65,32 });
	fly.PushBack({ 509,160,65,32 });
	fly.PushBack({ 509,128,65,32 });
	fly.PushBack({ 509,96,65,32 });
	fly.PushBack({ 509,64,65,32 });
	fly.PushBack({ 509,32,65,32 });
	fly.PushBack({ 509,0,32,32 });
	fly.loop = false;
	fly.speed = 0.2;

	y_original = y;

}

void Enemy_Hunter::Move()
{

	position.y = y_original + (App->render->camera.y / 3);
	if (chunk_played == false) {
		App->particles->AddParticle(App->particles->Hunter1, 0, 0);
		chunk_played = true;
	}
	
	if (appear.Finished())
	{	
		chunk_played = false;
		if (chunk_played == false) {
			App->particles->AddParticle(App->particles->Hunter2, 0, 0);
			chunk_played = true;
		}

		speed = 1;
		now = SDL_GetTicks();
		
		if (now > last + 2000) {
		speed = -2; 
		position.y = y_original -9 + (App->render->camera.y / 3);
		anim2ndLevel = &fly;
		
		if (colliderAdded == false) {
			collider = App->collision->AddCollider({ 0, 19, 32, 14 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
			colliderAdded = true; 

		}
		collider->SetPos(position.x, position.y);
		}
		
	}
	else {
		if (position.x < App->background2->bgpos + 20) {
			ArrivedLeft = true;
		}
		else {
			speed = -2; 
			
		}
		if (ArrivedLeft) {
			speed = 2;
			last = SDL_GetTicks();
		}
	}

		



	position.x  += speed;
}

void Enemy_Hunter::Appear()
{
	
}
