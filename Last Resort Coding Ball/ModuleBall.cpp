#include "ModuleBall.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleBackground.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

ModuleBall::ModuleBall()
{
	current_animation = &E;

	E.PushBack({ 0, 0, 22, 16 });
	E.PushBack({ 22, 0, 22, 16 });
	E.PushBack({ 44, 0, 22, 16 });
	E.PushBack({ 66, 0, 22, 16 });
	E.PushBack({ 88, 0, 22, 16 });
	E.PushBack({ 110, 0, 22, 16 });
	E.PushBack({ 132, 0, 22, 16 });
	E.PushBack({ 154, 0, 22, 16 });
	E.speed = 0.3f;
	E.loop = true;

	NEE.PushBack({ 176, 0, 22, 17 });
	NEE.PushBack({ 198, 0, 22, 17 });
	NEE.PushBack({ 220, 0, 22, 17 });
	NEE.PushBack({ 0, 17, 22, 17 });
	NEE.PushBack({ 22, 17, 22, 17 });
	NEE.PushBack({ 44, 17, 22, 17 });
	NEE.PushBack({ 66, 17, 22, 17 });
	NEE.PushBack({ 88, 17, 22, 17 });
	NEE.speed = 0.3f;
	NEE.loop = true;

	NE.PushBack({ 110, 17, 21, 21 });
	NE.PushBack({ 131, 17, 21, 21 });
	NE.PushBack({ 152, 17, 21, 21 });
	NE.PushBack({ 173, 17, 21, 21 });
	NE.PushBack({ 194, 17, 21, 21 });
	NE.PushBack({ 215, 17, 21, 21 });
	NE.PushBack({ 0, 38, 21, 21 });
	NE.PushBack({ 21, 38, 21, 21 });
	NE.speed = 0.3f;
	NE.loop = true;

	NNE.PushBack({ 42, 38, 17, 23 });
	NNE.PushBack({ 59, 38, 17, 23 });
	NNE.PushBack({ 76, 38, 17, 23 });
	NNE.PushBack({ 93, 38, 17, 23 });
	NNE.PushBack({ 110, 38, 17, 23 });
	NNE.PushBack({ 127, 38, 17, 23 });
	NNE.PushBack({ 144, 38, 17, 23 });
	NNE.PushBack({ 161, 38, 17, 23 });
	NNE.speed = 0.3f;
	NNE.loop = true;

	N.PushBack({ 178, 38, 16, 22 });
	N.PushBack({ 194, 38, 16, 22 });
	N.PushBack({ 210, 38, 16, 22 });
	N.PushBack({ 226, 38, 16, 22 });
	N.PushBack({ 0, 61, 16, 22 });
	N.PushBack({ 16, 61, 16, 22 });
	N.PushBack({ 32, 61, 16, 22 });
	N.PushBack({ 48, 61, 16, 22 });
	N.loop = true;
	N.speed = 0.3f;

	NNW.PushBack({ 64, 61, 17, 23 });
	NNW.PushBack({ 81, 61, 17, 23 });
	NNW.PushBack({ 98, 61, 17, 23 });
	NNW.PushBack({ 115, 61, 17, 23 });
	NNW.PushBack({ 132, 61, 17, 23 });
	NNW.PushBack({ 149, 61, 17, 23 });
	NNW.PushBack({ 166, 61, 17, 23 });
	NNW.PushBack({ 183, 61, 17, 23 });
	NNW.loop = true;
	NNW.speed = 0.3f;

	NW.PushBack({ 200, 61, 21, 21 });
	NW.PushBack({ 221, 61, 21, 21 });
	NW.PushBack({ 0, 84, 21, 21 });
	NW.PushBack({ 21, 84, 21, 21 });
	NW.PushBack({ 42, 84, 21, 21 });
	NW.PushBack({ 63, 84, 21, 21 });
	NW.PushBack({ 84, 84, 21, 21 });
	NW.PushBack({ 105, 84, 21, 21 });
	NW.loop = true;
	NW.speed = 0.3f;

	NWW.PushBack({ 126, 84, 22, 17 });
	NWW.PushBack({ 148, 84, 22, 17 });
	NWW.PushBack({ 170, 84, 22, 17 });
	NWW.PushBack({ 192, 84, 22, 17 });
	NWW.PushBack({ 214, 84, 22, 17 });
	NWW.PushBack({ 0, 105, 22, 17 });
	NWW.PushBack({ 22, 105, 22, 17 });
	NWW.PushBack({ 44, 105, 22, 17 });
	NWW.loop = true;
	NWW.speed = 0.3f;

	W.PushBack({ 66, 105, 22, 16 });
	W.PushBack({ 88, 105, 22, 16 });
	W.PushBack({ 110, 105, 22, 16 });
	W.PushBack({ 132, 105, 22, 16 });
	W.PushBack({ 154, 105, 22, 16 });
	W.PushBack({ 176, 105, 22, 16 });
	W.PushBack({ 198, 105, 22, 16 });
	W.PushBack({ 220, 105, 22, 16 });
	W.loop = true;
	W.speed = 0.3f;

	SWW.PushBack({ 0, 122, 22, 17 });
	SWW.PushBack({ 22, 122, 22, 17 });
	SWW.PushBack({ 44, 122, 22, 17 });
	SWW.PushBack({ 66, 122, 22, 17 });
	SWW.PushBack({ 88, 122, 22, 17 });
	SWW.PushBack({ 110, 122, 22, 17 });
	SWW.PushBack({ 132, 122, 22, 17 });
	SWW.PushBack({ 154, 122, 22, 17 });
	SWW.loop = true;
	SWW.speed = 0.3f;

	SW.PushBack({ 176, 122, 21, 21 });
	SW.PushBack({ 197, 122, 21, 21 });
	SW.PushBack({ 218, 122, 21, 21 });
	SW.PushBack({ 0, 143, 21, 21 });
	SW.PushBack({ 21, 143, 21, 21 });
	SW.PushBack({ 42, 143, 21, 21 });
	SW.PushBack({ 63, 143, 21, 21 });
	SW.PushBack({ 84, 143, 21, 21 });
	SW.loop = true;
	SW.speed = 0.3f;

	SSW.PushBack({ 105, 143, 17, 23 });
	SSW.PushBack({ 122, 143, 17, 23 });
	SSW.PushBack({ 139, 143, 17, 23 });
	SSW.PushBack({ 156, 143, 17, 23 });
	SSW.PushBack({ 173, 143, 17, 23 });
	SSW.PushBack({ 190, 143, 17, 23 });
	SSW.PushBack({ 207, 143, 17, 23 });
	SSW.PushBack({ 224, 143, 17, 23 });
	SSW.loop = true;
	SSW.speed = 0.3f;

	S.PushBack({ 0, 166, 16, 22 });
	S.PushBack({ 16, 166, 16, 22 });
	S.PushBack({ 32, 166, 16, 22 });
	S.PushBack({ 48, 166, 16, 22 });
	S.PushBack({ 64, 166, 16, 22 });
	S.PushBack({ 80, 166, 16, 22 });
	S.PushBack({ 96, 166, 16, 22 });
	S.PushBack({ 112, 166, 16, 22 });
	S.loop = true;
	S.speed = 0.3f;

	SSE.PushBack({ 128, 166, 17,23 });
	SSE.PushBack({ 145, 166, 17,23 });
	SSE.PushBack({ 162, 166, 17,23 });
	SSE.PushBack({ 179, 166, 17,23 });
	SSE.PushBack({ 196, 166, 17,23 });
	SSE.PushBack({ 213, 166, 17,23 });
	SSE.PushBack({ 230, 166, 17,23 });
	SSE.PushBack({ 0, 189, 17,23 });
	SSE.loop = true;
	SSE.speed = 0.3f;

	SE.PushBack({ 17, 189, 21, 21 });
	SE.PushBack({ 38, 189, 21, 21 });
	SE.PushBack({ 59, 189, 21, 21 });
	SE.PushBack({ 80, 189, 21, 21 });
	SE.PushBack({ 101, 189, 21, 21 });
	SE.PushBack({ 122, 189, 21, 21 });
	SE.PushBack({ 143, 189, 21, 21 });
	SE.PushBack({ 164, 189, 21, 21 });
	SE.loop = true;
	SE.speed = 0.3f;

	SEE.PushBack({ 185, 189, 22, 17 });
	SEE.PushBack({ 207, 189, 22, 17 });
	SEE.PushBack({ 229, 189, 22, 17 });
	SEE.PushBack({ 0, 212, 22, 17 });
	SEE.PushBack({ 22, 212, 22, 17 });
	SEE.PushBack({ 44, 212, 22, 17 });
	SEE.PushBack({ 66, 212, 22, 17 });
	SEE.PushBack({ 88, 212, 22, 17 });
	SEE.loop = true;
	SEE.speed = 0.3f;

}

bool ModuleBall::Start()
{
	texture = App->textures->Load("assets/sprites/blue_ball_axis.png");

	ball_position.x = App->player->position.x;
	ball_position.y = App->player->position.y;


	ball_collider = App->collision->AddCollider(current_animation->GetCurrentFrame(), COLLIDER_BALL, this);

	return true; 
}

void ModuleBall::Ball_Input_Movement()
{
	if (App->input->keyboard[SDL_SCANCODE_F] == KEY_DOWN)
	{
		if (ball_locked == false) ball_locked = true;
		else ball_locked = false;
	}


	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_REPEAT) {
		// The aiming angle grows or decreases to 90º dependending on its place 
		if (angle_aiming <= 270 && angle_aiming > 90)		// Using te shortest way always
			angle_aiming -= angle_speed;
		else if (angle_aiming > 270)
			angle_aiming += angle_aiming_speed;
		if (angle_aiming >= 0 && angle_aiming < 90)
			angle_aiming += angle_aiming_speed;

		// -------------

		if (!ball_locked)
		{													// The angle grows or decreases to get to 90º depending on its place 
			if (angle <= 270 && angle>90)					// Using the shortest way always
				angle -= angle_speed;
			else if (angle > 270)
				angle += angle_speed;
			if (angle >= 0 && angle < 90)
				angle += angle_speed;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_REPEAT) {

		if (angle_aiming >= 90 && angle_aiming<270)					// Using the shortest way always
			angle_aiming += angle_aiming_speed;
		else if (angle_aiming < 90) {
			angle_aiming -= angle_aiming_speed;
			if (angle_aiming <= 0) angle_aiming = 359;
		}
		if (angle_aiming <360 && angle_aiming > 270)
			angle_aiming -= angle_aiming_speed;

		// -------------

		if (!ball_locked)
		{													// The angle grows or decreases to get to 270º depending on its place 
			if (angle >= 90 && angle<270)					// Using the shortest way always
				angle += angle_speed;
			else if (angle < 90) {
				angle -= angle_speed;
				if (angle <= 0) angle = 359;
			}
			if (angle <360 && angle > 270)
				angle -= angle_speed;
		}
		else
		{
			ball_aiming = BALL_AIMING::BALL_AIMING_N;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_REPEAT) {

		if (angle_aiming <= 180 && angle_aiming > 0)
			angle_aiming -= angle_aiming_speed;
		if (angle_aiming > 180 && angle_aiming != 0)
			angle_aiming += angle_aiming_speed;

		// -------------

		if (!ball_locked)
		{													// The angle grows or decreases to get to 180º depending on its place 
			if (angle <= 180 && angle > 0)
				angle -= angle_speed;
			if (angle > 180 && angle != 0) {
				angle += angle_speed;
			}
		}
	}


	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_REPEAT) {

		if (angle_aiming > 180)
			angle_aiming -= angle_aiming_speed;
		if (angle_aiming < 180)
			angle_aiming += angle_aiming_speed;

		// -------------

		if (!ball_locked)
		{													// The angle grows or decreases to get to 270º depending on its place 
			if (angle > 180)
				angle -= angle_speed;
			if (angle < 180)
				angle += angle_speed;
		}
	}
}

void ModuleBall::Ball_Input_Attack()
{
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->ball_bullet, ball_position.x, ball_position.y, COLLIDER_PLAYER_SHOT);
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_REPEAT)
	{
		charge += 20; 
	}
	if (charge < 1000) charge = 0; 
}

void ModuleBall::Ball_Launch()
{

}


update_status ModuleBall::Update()
{
	angle_speed = 10;
	angle_aiming_speed = 11.25;
	center_player.x = App->player->position.x + 16;
	center_player.y = App->player->position.y - 6;


	if (angle >= 360) angle = 0;
	if (angle_aiming >= 360) angle_aiming = 0;

	// ----- BALL INPUT -----

	Ball_Input_Movement();

	// ----- BALL AIMING ANIMATIONS -----	(Depends on the angle it is aiming)

	// First quarter
	if (angle_aiming <= 11.25 || angle_aiming > 348.75) 
		current_animation = &E;
	if (angle_aiming > 11.25 && angle_aiming <= 33.75)
		current_animation = &SEE;
	if (angle_aiming > 33.75 && angle_aiming <= 56.25)
		current_animation = &SE;
	if (angle_aiming > 56.25 && angle_aiming <= 78.75)
		current_animation = &SSE;

	// Second quarter
	if (angle_aiming > 78.75 && angle_aiming <= 101.25) 
		current_animation = &S;
	if (angle_aiming > 101.25 && angle_aiming <= 123.75)
		current_animation = &SSW;
	if (angle_aiming > 123.75 && angle_aiming <= 146.25)
		current_animation = &SW;
	if (angle_aiming > 146.25 && angle_aiming <= 168.75)
		current_animation = &SWW;


	// Third quarter
	if (angle_aiming > 168.75 && angle_aiming <= 191.25) 
		current_animation = &W;
	if (angle_aiming > 191.25 && angle_aiming <= 213.75)
		current_animation = &NWW;
	if (angle_aiming > 213.75 && angle_aiming <= 236.25)
		current_animation = &NW;
	if (angle_aiming > 236.25 && angle_aiming <= 258.75)
		current_animation = &NNW;

	// Fourth quarter
	if (angle_aiming > 258.75 && angle_aiming <= 281.25) 
		current_animation = &N;
	if (angle_aiming > 281.25 && angle_aiming <= 303.75)
		current_animation = &NNE;
	if (angle_aiming > 303.75 && angle_aiming <= 326.25)
		current_animation = &NE;
	if (angle_aiming > 326.25 && angle_aiming <= 348.75)
		current_animation = &NEE;
		
	App->particles->ball_bullet.speed.x = (7 * cos(angle_aiming*PI / 180))+2;
	App->particles->ball_bullet.speed.y = 7 * sin(angle_aiming*PI / 180);

	ball_position.x = center_player.x + 25*cos(angle*PI/180);
	ball_position.y = center_player.y + 25*sin(angle*PI/180);

	ball_collider->SetPos(ball_position.x, ball_position.y);

	Ball_Input_Attack();


	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(texture, ball_position.x, ball_position.y, &r); 
	return update_status::UPDATE_CONTINUE;
}

bool ModuleBall::CleanUp()
{
	App->textures->Unload(texture); 
	return true;
}
