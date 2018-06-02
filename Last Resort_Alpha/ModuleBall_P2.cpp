#include "ModuleBall_P2.h"
#include "Application.h"
#include "ModulePlayer2.h"
#include "ModuleBackground.h"
#include "ModuleBackground2.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleUI.h"

ModuleBall_P2::ModuleBall_P2()
{
	current_animation = &E;

	E.PushBack({ 0, 0, 30, 30 });
	E.PushBack({ 30, 0, 30, 30 });
	E.PushBack({ 60, 0, 30, 30 });
	E.PushBack({ 90, 0, 30, 30 });
	E.PushBack({ 120, 0, 30, 30 });
	E.PushBack({ 150, 0, 30, 30 });
	E.PushBack({ 180, 0, 30, 30 });
	E.PushBack({ 210, 0, 30, 30 });
	E.speed = 0.3f;
	E.loop = true;

	NEE.PushBack({ 240, 0, 30, 30 });
	NEE.PushBack({ 270, 0, 30, 30 });
	NEE.PushBack({ 300, 0, 30, 30 });
	NEE.PushBack({ 330, 0, 30, 30 });
	NEE.PushBack({ 360, 0, 30, 30 });
	NEE.PushBack({ 390, 0, 30, 30 });
	NEE.PushBack({ 420, 0, 30, 30 });
	NEE.PushBack({ 0, 30, 30, 30 });
	NEE.speed = 0.3f;
	NEE.loop = true;

	NE.PushBack({ 30, 30, 30, 30 });
	NE.PushBack({ 60, 30, 30, 30 });
	NE.PushBack({ 90, 30, 30, 30 });
	NE.PushBack({ 120, 30, 30, 30 });
	NE.PushBack({ 150, 30, 30, 30 });
	NE.PushBack({ 180, 30, 30, 30 });
	NE.PushBack({ 210, 30, 30, 30 });
	NE.PushBack({ 240, 30, 30, 30 });
	NE.speed = 0.3f;
	NE.loop = true;

	NNE.PushBack({ 270, 30, 30, 30 });
	NNE.PushBack({ 300, 30, 30, 30 });
	NNE.PushBack({ 330, 30, 30, 30 });
	NNE.PushBack({ 360, 30, 30, 30 });
	NNE.PushBack({ 390, 30, 30, 30 });
	NNE.PushBack({ 420, 30, 30, 30 });
	NNE.PushBack({ 0, 60, 30, 30 });
	NNE.PushBack({ 30, 60, 30, 30 });
	NNE.speed = 0.3f;
	NNE.loop = true;

	N.PushBack({ 60, 60, 30, 30 });
	N.PushBack({ 90, 60, 30, 30 });
	N.PushBack({ 120, 60, 30, 30 });
	N.PushBack({ 150, 60, 30, 30 });
	N.PushBack({ 180, 60, 30, 30 });
	N.PushBack({ 210, 60, 30, 30 });
	N.PushBack({ 240, 60, 30, 30 });
	N.PushBack({ 270, 60, 30, 30 });
	N.loop = true;
	N.speed = 0.3f;

	NNW.PushBack({ 300, 60, 30, 30 });
	NNW.PushBack({ 330, 60, 30, 30 });
	NNW.PushBack({ 360, 60, 30, 30 });
	NNW.PushBack({ 390, 60, 30, 30 });
	NNW.PushBack({ 420, 60, 30, 30 });
	NNW.PushBack({ 0, 90, 30, 30 });
	NNW.PushBack({ 30, 90, 30, 30 });
	NNW.PushBack({ 60, 90, 30, 30 });
	NNW.loop = true;
	NNW.speed = 0.3f;

	NW.PushBack({ 90, 90, 30, 30 });
	NW.PushBack({ 120, 90, 30, 30 });
	NW.PushBack({ 150, 90, 30, 30 });
	NW.PushBack({ 180, 90, 30, 30 });
	NW.PushBack({ 210, 90, 30, 30 });
	NW.PushBack({ 240, 90, 30, 30 });
	NW.PushBack({ 270, 90, 30, 30 });
	NW.PushBack({ 300, 90, 30, 30 });
	NW.loop = true;
	NW.speed = 0.3f;

	NWW.PushBack({ 330, 90, 30, 30 });
	NWW.PushBack({ 360, 90, 30, 30 });
	NWW.PushBack({ 390, 90, 30, 30 });
	NWW.PushBack({ 420, 90, 30, 30 });
	NWW.PushBack({ 0, 120, 30, 30 });
	NWW.PushBack({ 30, 120, 30, 30 });
	NWW.PushBack({ 60, 120, 30, 30 });
	NWW.PushBack({ 90, 120, 30, 30 });
	NWW.loop = true;
	NWW.speed = 0.3f;

	W.PushBack({ 120, 120, 30, 30 });
	W.PushBack({ 150, 120, 30, 30 });
	W.PushBack({ 180, 120, 30, 30 });
	W.PushBack({ 210, 120, 30, 30 });
	W.PushBack({ 240, 120, 30, 30 });
	W.PushBack({ 270, 120, 30, 30 });
	W.PushBack({ 300, 120, 30, 30 });
	W.PushBack({ 330, 120, 30, 30 });
	W.loop = true;
	W.speed = 0.3f;

	SWW.PushBack({ 360, 120, 30, 30 });
	SWW.PushBack({ 390, 120, 30, 30 });
	SWW.PushBack({ 420, 120, 30, 30 });
	SWW.PushBack({ 0, 150, 30, 30 });
	SWW.PushBack({ 30, 150, 30, 30 });
	SWW.PushBack({ 60, 150, 30, 30 });
	SWW.PushBack({ 90, 150, 30, 30 });
	SWW.PushBack({ 120, 150, 30, 30 });
	SWW.loop = true;
	SWW.speed = 0.3f;

	SW.PushBack({ 150, 150, 30, 30 });
	SW.PushBack({ 180, 150, 30, 30 });
	SW.PushBack({ 210, 150, 30, 30 });
	SW.PushBack({ 240, 150, 30, 30 });
	SW.PushBack({ 270, 150, 30, 30 });
	SW.PushBack({ 300, 150, 30, 30 });
	SW.PushBack({ 330, 150, 30, 30 });
	SW.PushBack({ 360, 150, 30, 30 });
	SW.loop = true;
	SW.speed = 0.3f;

	SSW.PushBack({ 390, 150, 30, 30 });
	SSW.PushBack({ 420, 150, 30, 30 });
	SSW.PushBack({ 0, 180, 30, 30 });
	SSW.PushBack({ 30, 180, 30, 30 });
	SSW.PushBack({ 60, 180, 30, 30 });
	SSW.PushBack({ 90, 180, 30, 30 });
	SSW.PushBack({ 120, 180, 30, 30 });
	SSW.PushBack({ 150, 180, 30, 30 });
	SSW.loop = true;
	SSW.speed = 0.3f;

	S.PushBack({ 180, 180, 30, 30 });
	S.PushBack({ 210, 180, 30, 30 });
	S.PushBack({ 240, 180, 30, 30 });
	S.PushBack({ 270, 180, 30, 30 });
	S.PushBack({ 300, 180, 30, 30 });
	S.PushBack({ 330, 180, 30, 30 });
	S.PushBack({ 360, 180, 30, 30 });
	S.PushBack({ 390, 180, 30, 30 });
	S.loop = true;
	S.speed = 0.3f;

	SSE.PushBack({ 420, 180, 30,30 });
	SSE.PushBack({ 0, 210, 30,30 });
	SSE.PushBack({ 30, 210, 30,30 });
	SSE.PushBack({ 60, 210, 30,30 });
	SSE.PushBack({ 90, 210, 30,30 });
	SSE.PushBack({ 120, 210, 30,30 });
	SSE.PushBack({ 150, 210, 30,30 });
	SSE.PushBack({ 180, 210, 30,30 });
	SSE.loop = true;
	SSE.speed = 0.3f;

	SE.PushBack({ 210, 210, 30, 30 });
	SE.PushBack({ 240, 210, 30, 30 });
	SE.PushBack({ 270, 210, 30, 30 });
	SE.PushBack({ 300, 210, 30, 30 });
	SE.PushBack({ 330, 210, 30, 30 });
	SE.PushBack({ 360, 210, 30, 30 });
	SE.PushBack({ 390, 210, 30, 30 });
	SE.PushBack({ 420, 210, 30, 30 });
	SE.loop = true;
	SE.speed = 0.3f;

	SEE.PushBack({ 0, 240, 30, 30 });
	SEE.PushBack({ 30, 240, 30, 30 });
	SEE.PushBack({ 60, 240, 30, 30 });
	SEE.PushBack({ 90, 240, 30, 30 });
	SEE.PushBack({ 120, 240, 30, 30 });
	SEE.PushBack({ 150, 240, 30, 30 });
	SEE.PushBack({ 180, 240, 30, 30 });
	SEE.PushBack({ 210, 240, 30, 30 });
	SEE.loop = true;
	SEE.speed = 0.3f;

	flying.PushBack({ 241,244,30,30 });
	flying.PushBack({ 271,244,30,30 });
	flying.PushBack({ 301,244,30,30 });
	flying.PushBack({ 331,244,30,30 });
	flying.PushBack({ 361,244,30,30 });
	flying.PushBack({ 391,244,30,30 });
	flying.PushBack({ 421,244,30,30 });
	flying.PushBack({ 451,244,30,30 });
	flying.speed = 0.3f;
	flying.loop = true;

}

ModuleBall_P2::~ModuleBall_P2()
{
}

bool ModuleBall_P2::Start()
{
	blue_ball_texture = App->textures->Load("assets/sprites/blue_ball_axis.png");
	orange_ball_texture = App->textures->Load("assets/sprites/orange_ball_axis.png");
	Pball = App->textures->Load("assets/sprites/Bolitatoflama.png");

	ball_position.x = App->player2->position.x;
	ball_position.y = App->player2->position.y;

	angle = 0;
	angle_aiming = 0;

	ball_collider = App->collision->AddCollider({ ball_position.x + 5, ball_position.y + 5, 20, 20}, COLLIDER_BALL2, this);

	return true;
}

void ModuleBall_P2::Ball_Input_Movement()
{
	if (App->input->keyboard[SDL_SCANCODE_RSHIFT] == KEY_DOWN)
	{
		if (ball_locked == false) ball_locked = true;
		else ball_locked = false;
	}


	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_REPEAT) {
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

	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_REPEAT) {

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
	}

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_REPEAT) {

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


	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_REPEAT) {

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

void ModuleBall_P2::Ball_Input_Attack()
{

	if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->ball_bullet, ball_position.x + 8, ball_position.y + 10, COLLIDER_PLAYER_SHOT);
	}

	if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_REPEAT)
	{
		charge += 20;
		App->render->Blit(Pball, 200, 208, &App->UI->Bola2.GetCurrentFrame(), 0, false);
	}
	if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_UP)
	{
		if (charge < 500) charge = 0;
		App->UI->Bola2.Reset();
	}
}

void ModuleBall_P2::Ball_Launch()
{
	if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_UP)
	{
		ball_launched = true;
		App->UI->Bola2.Reset();
		App->audio->PlayChunk(App->particles->chunks[10], 1);
	}
	current_animation = &flying;

	if (!go_back) {
		ball_position.x = ball_position.x + 5 * cos(angle*PI / 180);
		ball_position.y = ball_position.y + 5 * sin(angle*PI / 180);
	}
	else if (!in_place) {
		ball_position.x = ball_position.x + 0.08* (center_player.x - ball_position.x);
		ball_position.y = ball_position.y + 0.08* (center_player.y - ball_position.y);
	}

	//original_position.x = center_player.x + 25 * cos(angle*PI / 180);
	//original_position.x = center_player.x + 25 * sin(angle*PI / 180);
	if ((ball_position.x <  center_player.x + 30 && ball_position.x > center_player.x - 30) &&
		(ball_position.y < center_player.y + 30 && ball_position.y > center_player.y - 30) && go_back) in_place = true;

	if (ball_position.x < App->background2->bgpos || ball_position.x > App->background2->bgpos + SCREEN_WIDTH || ball_position.y < -50 || ball_position.y > SCREEN_HEIGHT) {
		go_back = true;
	}

	if (in_place) {
		ball_launched = false;
		go_back = false;
		in_place = false;
		charge = 0;
	}
}

void ModuleBall_P2::Ball_Set_Angle()
{
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
}

void ModuleBall_P2::Ball_Set_Position()
{
	App->particles->ball_bullet.speed.x = (7 * cos(angle_aiming*PI / 180)) + 2;
	App->particles->ball_bullet.speed.y = 7 * sin(angle_aiming*PI / 180);

	ball_position.x = center_player.x + 30 * cos(angle*PI / 180) - BALL_SIZE / 2;
	ball_position.y = center_player.y + 30 * sin(angle*PI / 180) - BALL_SIZE / 2;
}


update_status ModuleBall_P2::Update()
{
	center_player.x = App->player2->position.x + 16;
	center_player.y = App->player2->position.y - 6;

	if (!ball_launched) {

		Ball_Set_Angle();

		Ball_Set_Position();
		Ball_Input_Attack();
	}

	if (charge > 500)
		Ball_Launch();

	ball_collider->SetPos(ball_position.x + 5, ball_position.y + 5);

	SDL_Rect r = current_animation->GetCurrentFrame();

	if (ball_type == BALL2_TYPE::BLUE_BALL2)
		App->render->Blit(blue_ball_texture, ball_position.x, ball_position.y, &r);

	else
		App->render->Blit(orange_ball_texture, ball_position.x, ball_position.y, &r);

	return update_status::UPDATE_CONTINUE;
}

bool ModuleBall_P2::CleanUp()
{
	App->textures->Unload(blue_ball_texture);
	App->textures->Unload(orange_ball_texture);
	App->textures->Unload(Pball);
	return true;
}
