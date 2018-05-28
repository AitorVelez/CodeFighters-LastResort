#include "Application.h"
#include "Enemy_Metal_Bee.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL_timer.h"

Enemy_Metal_Bee::Enemy_Metal_Bee(int x, int y, int HP) : Enemy(x, y, HP)
{
	original_hp = 11;

	// De frente -->derecha;
	Right1.PushBack({ 141,98,41,46 });
	Right1.PushBack({ 184,98,41,46 });
	Right1.PushBack({ 415,2,37,46 });
	Right1.PushBack({ 308,98,39,46 });
	Right1.PushBack({ 349,98,42,45 });
	Right1.PushBack({ 394,98,42,45 });
	Right1.speed = 0.15;

	// De espaldas --> Derecha x2
	Right2.PushBack({ 80,50,40,46 });
	Right2.PushBack({ 123,50,40,46 });
	Right2.PushBack({ 3,50,37,46 });
	Right2.PushBack({ 42,50,37,46 });
	Right2.PushBack({ 454,2,44,45 });
	Right2.PushBack({ 360,50,43,45 });
	Right2.speed = 0.15;

	// De frente --> izquierda
	Left1.PushBack({ 279,2,41,46 });
	Left1.PushBack({ 322,2,41,46 });
	Left1.PushBack({ 199,2,37,46 });
	Left1.PushBack({ 238,2,37,46 });
	Left1.PushBack({ 3,98,42,45 });
	Left1.PushBack({ 47,98,42,45 });
	Left1.speed = 0.15;

	// De espaldas --> izquierda
	Left2.PushBack({ 405,50,40,46 });
	Left2.PushBack({ 266,98,40,46 });
	Left2.PushBack({ 437,98,37,46 });
	Left2.PushBack({ 227,98,37,46 });
	Left2.PushBack({ 153,2,44,45 });
	Left2.PushBack({ 265,50,43,45 });
	Left2.speed = 0.15;

	// De izquierda a derecha por detr�s
	backleft.PushBack({ 265,50,43,45 });
	backleft.PushBack({ 153,2,44,45 });
	backleft.PushBack({ 227,98,37,46 });
	backleft.PushBack({ 437,98,37,46 });
	backleft.PushBack({ 266,98,40,46 });
	backleft.PushBack({ 405,50,40,46 });
	backleft.PushBack({ 165,50,48,45 });
	backleft.PushBack({ 215,50,48,45 });
	backleft.PushBack({ 80,50,40,46 });
	backleft.PushBack({ 123,50,40,46 });
	backleft.PushBack({ 3,50,37,46 });
	backleft.PushBack({ 42,50,37,46 });
	backleft.PushBack({ 454,2,44,45 });
	backleft.PushBack({ 360,50,43,45 });

	frontleft.speed = 0.14;
	backleft.speed = 0.14;
	// De derecha izquierda por detr�s
	backright.PushBack({ 360,50,43,45 });
	backright.PushBack({ 454,2,44,45 });
	backright.PushBack({ 42,50,37,46 });
	backright.PushBack({ 3,50,37,46 });
	backright.PushBack({ 123,50,40,46 });
	backright.PushBack({ 80,50,40,46 });
	backright.PushBack({ 215,50,48,45 });
	backright.PushBack({ 165,50,48,45 });
	backright.PushBack({ 405,50,40,46 });
	backright.PushBack({ 266,98,40,46 });
	backright.PushBack({ 437,98,37,46 });
	backright.PushBack({ 227,98,37,46 });
	backright.PushBack({ 153,2,44,45 });
	backright.PushBack({ 265,50,43,45 });

	frontright.speed = 0.14;
	backright.speed = 0.14;
	// De izquierda a derecha de frente


	frontleft.PushBack({ 47,98,42,45 });
	frontleft.PushBack({ 3,98,42,45 });
	frontleft.PushBack({ 238,2,37,46 });
	frontleft.PushBack({ 199,2,37,46 });
	frontleft.PushBack({ 322,2,41,46 });
	frontleft.PushBack({ 279,2,41,46 });
	frontleft.PushBack({ 365,2,48,46 });
	frontleft.PushBack({ 91,98,48,46 });
	frontleft.PushBack({ 141,98,41,46 });
	frontleft.PushBack({ 184,98,41,46 });
	frontleft.PushBack({ 415,2,37,46 });
	frontleft.PushBack({ 308,98,39,46 });
	frontleft.PushBack({ 349,98,42,45 });
	frontleft.PushBack({ 394,98,42,45 });

	// De derecha a izquierda de frente

	frontright.PushBack({ 394,98,42,45 });
	frontright.PushBack({ 349,98,42,45 });
	frontright.PushBack({ 308,98,39,46 });
	frontright.PushBack({ 415,2,37,46 });
	frontright.PushBack({ 184,98,41,46 });
	frontright.PushBack({ 141,98,41,46 });
	frontright.PushBack({ 365,2,48,46 });
	frontright.PushBack({ 91,98,48,46 });
	frontright.PushBack({ 279,2,41,46 });
	frontright.PushBack({ 322,2,41,46 });
	frontright.PushBack({ 199,2,37,46 });
	frontright.PushBack({ 238,2,37,46 });
	frontright.PushBack({ 3,98,42,45 });
	frontright.PushBack({ 47,98,42,45 });

	frontright.loop = false;
	frontleft.loop = false;

	Right.PushBack({ 103,2,48,45 });
	Right.PushBack({ 53,2,48,45 });
	Right.speed = 0.15;

	Left.PushBack({ 310,50,48,45 });
	Left.PushBack({ 447,50,48,45 });
	Left.speed = 0.15;

	front.PushBack({ 365,2,48,46 });
	front.PushBack({ 91,98,48,46 });
	front.speed = 0.15;

	Back.PushBack({ 165,50,48,45 });
	Back.PushBack({ 215,50,48,45 });
	Back.speed = 0.15;


	animation = &Left;

	collider = App->collision->AddCollider({ 0, 0, 39, 42 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}


void Enemy_Metal_Bee::Move()
{
	// if()
	speed = 1.0f;


	Animation *Current;
	if (App->player->position.x < position.x) {

		animation = &frontright;

		frontleft.current_frame = frontleft.GetLastFrameNum() - frontright.current_frame;
		

		//frontleft.Reset();
		if (frontright.Finished()) {

			frontleft.Reset();

		}
		
		
	
	}
	else if (App->player->position.x > position.x) {
		animation = &frontleft;


		frontright.current_frame = frontright.GetLastFrameNum() - frontleft.current_frame;
		
		//frontright.Reset();
		if (frontleft.Finished()) {

			frontright.Reset();
		}
		
		
	}

	
	dirx = App->player->position.x - position.x;
	diry = App->player->relativeposition.y - position.y;
	hyp = sqrt(dirx*dirx + diry * diry);

	dirx /= hyp;
	diry /= hyp;

	if (dirx < 0) {
		dirx /= 2.4f;
	}
	if (dirx > 0) {
		dirx *= 1.2f;
	}
	/*if (diry < 0) {
	diry *= 1.05f;
	}*/

	position.x += dirx * speed * 1.6f;
	position.y += diry * speed;

}