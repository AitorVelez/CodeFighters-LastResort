#include "Application.h"
#include "Powerup.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleBall.h"
#include "ModuleBall_P2.h"
#include "ModulePlayer2.h"
#include "SDL\include\SDL_timer.h"

Powerup::Powerup(int x, int y) : position(x, y)
{}

Powerup::~Powerup()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

const Collider* Powerup::GetCollider() const
{
	return collider;
}

void Powerup::Draw(SDL_Texture* sprites)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	if (animation != nullptr)
		App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
}

void Powerup::SwapColor()
{
	now = SDL_GetTicks();

	if (now > last_time + 1000)
	{
	if (color == ORANGE)
	color = BLUE;
	else color = ORANGE;

	last_time = now;
	}
	
}

void Powerup::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->callback == App->player) 
	{
		if (type != SPEED_POWER && type != ZPOWER)
		{
			if (App->ball->IsEnabled() == false)
			{
				App->ball->Enable();
			}	
			if (color == BLUE)
				App->ball->ball_type = BALL_TYPE::BLUE_BALL;
			else App->ball->ball_type = BALL_TYPE::ORANGE_BALL;
			
			switch (type)
			{
			case LASER_POWER:
				if (App->player->bullet_state == BULLET_STATE::BULLET_NO_TYPE || App->player->bullet_state == BULLET_STATE::GRENADE1 
					|| App->player->bullet_state == BULLET_STATE::HELLFIRE1)
					App->player->bullet_state = BULLET_STATE::LASER1;

				else if (App->player->bullet_state == BULLET_STATE::LASER1)
					App->player->bullet_state = BULLET_STATE::LASER2;
				break;

			case GRENADER_POWER:
				if (App->player->bullet_state == BULLET_STATE::BULLET_NO_TYPE || App->player->bullet_state == BULLET_STATE::LASER1 
					|| App->player->bullet_state == BULLET_STATE::LASER2 || App->player->bullet_state == BULLET_STATE::HELLFIRE1)
					App->player->bullet_state = BULLET_STATE::GRENADE1;
				break;

			case HELL_POWER:
				if (App->player->bullet_state == BULLET_STATE::BULLET_NO_TYPE || App->player->bullet_state == BULLET_STATE::LASER1 
					|| App->player->bullet_state == BULLET_STATE::LASER2 || App->player->bullet_state == BULLET_STATE::GRENADE1)
					App->player->bullet_state = BULLET_STATE::HELLFIRE1;
				break;
			}
		}
	}

	/*if (c2->callback = App->player2)
	{
		if (type != SPEED_POWER && type != ZPOWER)
		{
			if (App->ball_p2->IsEnabled() == false)
			{
				App->ball_p2->Enable();
			}

			else
			{
				if (color == BLUE)
					App->ball_p2->ball_type = BALL2_TYPE::BLUE_BALL2;
				else App->ball_p2->ball_type = BALL2_TYPE::ORANGE_BALL2;
			}


			switch (type)
			{
			case LASER_POWER:
				if (App->player2->bullet_state_2== BULLET_STATE_2::BULLET_NO_TYPE_2 || App->player2->bullet_state_2 == BULLET_STATE_2::GRENADE1_2 || 
					App->player2->bullet_state_2 == BULLET_STATE_2::HELLFIRE1_2)
					App->player2->bullet_state_2 = BULLET_STATE_2::LASER1_2;

				else if (App->player2->bullet_state_2 == BULLET_STATE_2::LASER1_2)
					App->player2->bullet_state_2 = BULLET_STATE_2::LASER2_2;
				break;

			case GRENADER_POWER:
				if (App->player2->bullet_state_2 == BULLET_STATE_2::BULLET_NO_TYPE_2 || App->player2->bullet_state_2 == BULLET_STATE_2::LASER1_2 || 
					App->player2->bullet_state_2 == BULLET_STATE_2::LASER2_2 || App->player2->bullet_state_2 == BULLET_STATE_2::HELLFIRE1_2)
					App->player2->bullet_state_2 = BULLET_STATE_2::GRENADE1_2;
				break;

			case HELL_POWER:
				if (App->player2->bullet_state_2 == BULLET_STATE_2::BULLET_NO_TYPE_2 || App->player2->bullet_state_2 == BULLET_STATE_2::LASER1_2 || 
					App->player2->bullet_state_2 == BULLET_STATE_2::LASER2_2 || App->player2->bullet_state_2 == BULLET_STATE_2::GRENADE1_2)
					App->player2->bullet_state_2 = BULLET_STATE_2::HELLFIRE1_2;
				break;
			}
		}
	}*/
}
																								//when an enemy is killed there will be shown 2 explosions