#include "Application.h"
#include "Powerup.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleBall.h"
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


void Powerup::Draw(SDL_Texture* sprites)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	if (animation != nullptr)
		App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
}

void Powerup::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->type == COLLIDER_TYPE::COLLIDER_PLAYER)
	{
		if (type != SPEED_POWER && type != ZPOWER)
		{
			if (App->ball->IsEnabled() == false)
			{
				App->ball->Enable();
			}

			else
			{
				if (color == BLUE)
					App->ball->ball_type = BALL_TYPE::BLUE_BALL;
				else App->ball->ball_type = BALL_TYPE::ORANGE_BALL;
			}

			switch (type)
			{
			case LASER_POWER:
				if (App->player->bullet_state == BULLET_STATE::BULLET_NO_TYPE)
					App->player->bullet_state = BULLET_STATE::LASER1;

				else if (App->player->bullet_state == BULLET_STATE::LASER1)
					App->player->bullet_state = BULLET_STATE::LASER2;
				break;

				// Case HPOWER etc
			}
		}
	}
}
																								//when an enemy is killed there will be shown 2 explosions