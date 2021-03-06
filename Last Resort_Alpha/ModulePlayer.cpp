#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "ModuleFadeToBlack.h"
#include "ModuleBackground.h"
#include "ModuleStageClear.h"
#include "ModuleBall.h"
#include "ModulePowerUp.h"
#include "ModuleBackground2.h"
#include "SDL\include\SDL_timer.h"
#include "ModuleEnemies.h"


#define MAX_LIVES 3 
#define  SideLimit 15
#define  TopLimit 2
// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	current_animation = &idle;


	//playershowup.PushBack({ 0,130,111,16 });
	//playershowup.PushBack({ 6,155,105,16 });
	//playershowup.PushBack({ 32,180,79,16 });
	//playershowup.loop = false;
	//playershowup.speed = 0.1f;
	//playershowup2.PushBack({ 34,204,77,17 });
	//playershowup2.PushBack({ 46,224,65,22 }); //player shows up
	//playershowup2.PushBack({ 46,252,65,19 });
	//playershowup2.PushBack({ 57,274,56,22 });
	//playershowup2.PushBack({ 57,300,56,21 });
	//playershowup2.PushBack({ 44,325,67,21 });
	//playershowup2.PushBack({ 44,346,67,25 });
	//playershowup2.loop = false;
	//playershowup2.speed = 0.15f;
	//playershowup3.PushBack({ 51,371,60,25 });
	//playershowup3.PushBack({ 52,396,59,25 });
	//playershowup3.PushBack({ 72,425,39,18 });
	//playershowup3.PushBack({ 76,452,35,15 });
	//playershowup3.PushBack({ 64,3,32,14 });
	//playershowup3.loop = false;
	//playershowup3.speed = 0.2f;
	//playershowup3.anim.fx = 3;
	
	playershowup.PushBack({ 0,130,111,16 });
	playershowup.PushBack({ 6,155,105,16 });
	playershowup.PushBack({ 32,180,79,16 });
	playershowup.PushBack({ 34,204,77,17 });
	playershowup.PushBack({ 46,224,65,22 }); //player shows up
	playershowup.PushBack({ 46,252,65,19 });
	playershowup.PushBack({ 57,274,56,22 });
	playershowup.PushBack({ 57,300,56,21 });
	playershowup.PushBack({ 44,325,67,21 });
	playershowup.PushBack({ 44,346,67,25 });
	playershowup.PushBack({ 51,371,60,25 });
	playershowup.PushBack({ 52,396,59,25 });
	playershowup.PushBack({ 72,425,39,18 });
	playershowup.PushBack({ 76,452,35,15 });
	playershowup.PushBack({ 64,3,32,14 });
	playershowup.loop = false;
	playershowup.speed = 0.3f;


	// Death Animation 

	death.PushBack({ 18, 20, 37, 16 });
	death.PushBack({ 14, 37, 41, 17 });
	death.PushBack({ 9, 54, 46, 18 });
	death.PushBack({ 3, 71, 52, 16 });
	death.PushBack({ 2, 87, 54, 15 });
	death.PushBack({ 0, 104, 55, 16 });
	death.PushBack({ 57, 21, 53, 15 });
	death.PushBack({ 58, 36, 52, 16 });
	death.PushBack({ 55, 53, 55, 17 });
	death.PushBack({ 56, 70, 54, 17 });
	death.PushBack({ 55, 88, 55, 17 });
	death.PushBack({ 57, 106, 53, 15 });
	death.PushBack({ 112, 19, 53, 18 });
	death.PushBack({ 114, 38, 51, 14 });
	death.PushBack({ 118, 53, 47, 18 });
	death.PushBack({ 118, 72, 47, 14 });
	death.PushBack({ 124, 89, 41, 12 });
	death.PushBack({ 128, 108, 37, 10 });
	death.loop = false;
	death.speed = 0.15f;

	// idle animation (arcade sprite sheet)
	
	idle.PushBack({ 64,3,32,14 });

	// Up animation
	up.PushBack({ 32,3,32,14 });
	up.PushBack({ 0,3,32,14 });
	up.speed = 0.1;
	up.loop = false;

	re_up.PushBack({ 0,3,32,14 });
	re_up.PushBack({ 32,3,32,14 });
	re_up.PushBack({ 64,3,32,14 });
	re_up.speed = 0.1;
	re_up.loop = false;

	re_WaterUp.PushBack({ 787, 277, 32, 11 });
	re_WaterUp.PushBack({ 819, 277, 32, 12 });
	re_WaterUp.PushBack({ 851, 277, 32, 12 });
	re_WaterUp.speed = 0.1;
	re_WaterUp.loop = false;

	// Down animation
	down.PushBack({ 96,3,32,14 });
	down.PushBack({ 128,3,32,14 });
	down.speed = 0.1;
	down.loop = false;

	re_down.PushBack({ 128,3,32,14 });
	re_down.PushBack({ 96,3,32,14 });
	re_down.PushBack({ 64,3,32,14 });
	re_down.speed = 0.1;
	re_down.loop = false;

	re_WaterDown.PushBack({ 915, 275, 32, 13 });
	re_WaterDown.PushBack({ 883, 276, 32, 13 });
	re_WaterDown.PushBack({ 851, 277, 32, 12 });
	re_WaterDown.speed = 0.1;
	re_WaterDown.loop = false;

	WaterDown.PushBack({ 883, 276, 32, 13 });
	WaterDown.PushBack({ 915, 275, 32, 13 });
	WaterDown.speed = 0.1;
	WaterDown.loop = false;
	WaterUp.PushBack({ 819, 277, 32, 12 });
	WaterUp.PushBack({ 787, 277, 32, 11 });
	WaterUp.speed = 0.1;
	WaterUp.loop = false;
	Water.PushBack({ 851, 277, 32, 12 });
	Water.speed = 0.1;
	Water.loop = false;

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true; 
	if (App->player2->TwoPlayers == true) {
		if (death_played == true) {
			now = SDL_GetTicks();
			if (now > last + 1000) {
				if (lives > 0) {
				if (App->background->IsEnabled() == true) {
				position.x = App->background->bgpos + 50;                  //   IF BOTH PLAYERS ENABLED, RESPAWN
				position.y = 125;
				relativeposition.x = 50;
				relativeposition.y = position.y;
			} 
			else if (App->background2->IsEnabled() == true) {
				position.x = App->background2->bgpos + 50;  LOG("RESPAWN POS          -------------------- %i ", App->background2->bgpos + 50)
			 	position.y = 125;
				relativeposition.x = 50;
				relativeposition.y = position.y;
			  }
			}
		 }
			last = now;
		}
	}
	else {
		position.x = 50;
		position.y = 125;
		relativeposition.x = position.x;
		relativeposition.y = position.y;
	 }


	alive_p1 = true; 	

	/*if (SwitchToBg2 == false) {
		if (App->background2->IsEnabled() == true && App->background->IsEnabled() == false) {
			if (lives != 3) {
				lives = 3;
			}
		}
		SwitchToBg2 = true; 
	}*/

	graphics = App->textures->Load("assets/sprites/main_character.png"); // arcade version
	PlayerCollider = App->collision->AddCollider({ position.x,position.y, 32, 14 }, COLLIDER_PLAYER, this);
	current_animation = &playershowup;
	
		App->audio->PlayChunk(App->particles->chunks[5], 1);

	score_p1 = 0; 
	bullet_state = BULLET_STATE::BULLET_NO_TYPE; 
	death_played = false; 
	death.Reset();
	god_mode = false;
	return ret;
}


bool ModulePlayer::CleanUp()
{
	LOG("Closing Up Player Module");
	// Free All textures
	App->textures->Unload(graphics);
	App->ball->Disable(); 
	playershowup.Reset();
	current_animation = &none; 
	PlayerCollider = nullptr; 
	return true; 
}

void ModulePlayer::OnCollision(Collider * c1, Collider * c2)
{
	if (c2->type == COLLIDER_TYPE::COLLIDER_POWERUP_L)
	{
		if (App->ball->IsEnabled() == false)
			App->ball->Enable();

		if (bullet_state == BULLET_STATE::BULLET_NO_TYPE || bullet_state == BULLET_STATE::GRENADE1 || bullet_state == BULLET_STATE::HELLFIRE1)
			bullet_state = BULLET_STATE::LASER1;

		else if (bullet_state == BULLET_STATE::LASER1)
			bullet_state = BULLET_STATE::LASER2;
	}
	if (c2->type == COLLIDER_TYPE::COLLIDER_POWERUP_H) {
		if (App->ball->IsEnabled() == false)
			App->ball->Enable();
		if (bullet_state == BULLET_STATE::BULLET_NO_TYPE || bullet_state == BULLET_STATE::LASER1 || bullet_state == BULLET_STATE::LASER2 || bullet_state == BULLET_STATE::HELLFIRE1)
			bullet_state = BULLET_STATE::GRENADE1;
	}

	if (c2->type == COLLIDER_TYPE::COLLIDER_POWERUP_G)
	{
		if (App->ball->IsEnabled() == false)
			App->ball->Enable();
		if (bullet_state == BULLET_STATE::BULLET_NO_TYPE || bullet_state == BULLET_STATE::LASER1 || bullet_state == BULLET_STATE::LASER2 || bullet_state == BULLET_STATE::HELLFIRE1)
			bullet_state = BULLET_STATE::HELLFIRE1;
	}

		if (c2->type == COLLIDER_TYPE::COLLIDER_POWERUP_S)
			if(speed!=3) speed = 3; 

		if (c2->type == COLLIDER_TYPE::COLLIDER_ENEMY || c2->type == COLLIDER_TYPE::COLLIDER_ENEMY_SHOT || c2->type == COLLIDER_TYPE::COLLIDER_WALL)
		{
			alive_p1 = false; 
		}

		if (c2->type == COLLIDER_TYPE::COLLIDER_WALL)
			alive_p1 = false; 
}

// Update: draw background
update_status ModulePlayer::Update()
{
	int scroll_speed = 1;
	//	int speed = 2;

	if (position.x <= 9150 && alive_p1 == true)
		position.x += scroll_speed;


	if (alive_p1 && playershowup.Finished()) {
		if (App->background2->IsEnabled() == true) {
			if (position.y > 202) {
				current_animation = &Water;
			}
			else {
				current_animation = &idle;
			}
		}
		else {
			current_animation = &idle;
		}

		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || 
			SDL_GameControllerGetAxis(App->input->controller[0].controller, SDL_GameControllerAxis::SDL_CONTROLLER_AXIS_LEFTY) < -15000)
		{
			if (relativeposition.y > CHARACTER_HEIGHT + TopLimit + 4) {
				if (App->background2->IsEnabled() == true) {
					if (position.y > 202) {
						current_animation = &WaterUp;
						re_WaterUp.Reset();
						re_WaterDown.Reset();
					}
					else {
						current_animation = &up;
						re_up.Reset();
						re_down.Reset();
					}
				}
				else {
					current_animation = &up;
					re_up.Reset();
					re_down.Reset();
				}
				relativeposition.y -= speed;
				position.y -= speed;

			}
			else {
				relativeposition.y = CHARACTER_HEIGHT + TopLimit + 4;
				if (App->background2->IsEnabled() == true) {
					if (position.y > 202) {
						current_animation = &WaterUp;
						re_WaterUp.Reset();
					}
					else {
						current_animation = &up;
						re_up.Reset();
					}
				}
				else {
					current_animation = &up;
					re_up.Reset();
				}
			}
		}
			if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_UP) {
				if (App->background2->IsEnabled() == true) {
					if (position.y > 202) {
						WaterUp.Reset();
						current_animation = &re_WaterUp;
					}
					else {
						up.Reset();
						current_animation = &re_up;
					}
				}
				else {
					up.Reset();
					current_animation = &re_up;
				}
			}





			if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT 
				|| SDL_GameControllerGetAxis(App->input->controller[0].controller, SDL_GameControllerAxis::SDL_CONTROLLER_AXIS_LEFTY) > 15000)
			{
				if (relativeposition.y < SCREEN_HEIGHT - TopLimit) {
					if (App->background2->IsEnabled() == true) {
						if (position.y > 202) {
							current_animation = &WaterDown;
							re_WaterUp.Reset();
							re_WaterDown.Reset();
						}
						else {
							current_animation = &down;
							re_up.Reset();
							re_down.Reset();
						}
					}
					else {
						current_animation = &down;
						re_up.Reset();
						re_down.Reset();
					}
					relativeposition.y += speed;
					position.y += speed;

				}
				else {
					relativeposition.y = SCREEN_HEIGHT - TopLimit;
					if (App->background2->IsEnabled() == true) {
						if (position.y > 202) {
							current_animation = &WaterDown;
							re_WaterDown.Reset();
						}
						else {
							current_animation = &down;
							re_down.Reset();
						}
					}
					else {
						current_animation = &down;
						re_down.Reset();
					}
				}
			}

			if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP) {
				if (App->background2->IsEnabled() == true) {
					if (position.y > 202) {
						WaterDown.Reset();
						current_animation = &re_WaterDown;
					}
					else {
						down.Reset();
						current_animation = &re_down;
					}
				}
				else {
					down.Reset();
					current_animation = &re_down;
				}
			}

			if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT 
				|| SDL_GameControllerGetAxis(App->input->controller[0].controller, SDL_GameControllerAxis::SDL_CONTROLLER_AXIS_LEFTX) > 15000) {
				if (relativeposition.x < SCREEN_WIDTH - CHARACTER_WIDTH - SideLimit) {
					relativeposition.x += speed;
					position.x += speed;
				}
				else {
					relativeposition.x = SCREEN_WIDTH - CHARACTER_WIDTH - SideLimit;
				}
			}
			if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT 
				|| SDL_GameControllerGetAxis(App->input->controller[0].controller, SDL_GameControllerAxis::SDL_CONTROLLER_AXIS_LEFTX) < -15000) {
				if (relativeposition.x > SideLimit) {
					relativeposition.x -= speed;
					position.x -= speed;
				}
				else {
					relativeposition.x = SideLimit;
				}
			}


			current_time = SDL_GetTicks();

			if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN 
				|| App->input->Controller_1[SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_A] == KEY_DOWN) {
				
				App->particles->AddParticle(App->particles->bullet_propulsion, position.x + 31, position.y - 15);
				App->particles->AddParticle(App->particles->bullet, position.x + 31, position.y - 12, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->bullet_propulsion, position.x + 31, position.y - 15);
				
				if (bullet_state == LASER1 && current_time > last_time + 500) {
					App->particles->AddParticle(App->particles->bullet_laser2_1, position.x, position.y - 10, COLLIDER_PLAYER_SHOT);
					//App->particles->AddParticle(App->particles->firing_laser, position.x + 32, position.y-16);
					last_time = current_time; 
				}
				if (bullet_state == LASER2 && current_time > last_time + 700) {
					App->particles->AddParticle(App->particles->bullet_laser2_1, position.x, position.y - 10, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->bullet_laser2, position.x, position.y - 24, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->bullet_laser2, position.x + 14, position.y - 24, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->bullet_laser2, position.x + 28, position.y - 24, COLLIDER_PLAYER_SHOT);
					//App->particles->AddParticle(App->particles->firing_laser, position.x + 32, position.y -16);
					last_time = current_time; 
				}
				if (bullet_state == GRENADE1 && current_time > last_time + 2000) {
					App->enemies->AddEnemy(ENEMY_TYPES::GRENADE, position.x + 31, position.y-8);
					App->enemies->AddEnemy(ENEMY_TYPES::GRENADE, position.x + 31, position.y + 8);
					last_time = current_time;

				}
				if (bullet_state == HELLFIRE1 && current_time > last_time + 1000) {
					App->enemies->AddEnemy(ENEMY_TYPES::HELLFIRE, position.x + 31, position.y -24);
					App->enemies->AddEnemy(ENEMY_TYPES::HELLFIRE, position.x + 31, position.y + 7);
					last_time = current_time;
				}
			}

			if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_STATE::KEY_DOWN) {
				if (god_mode == true) god_mode = false;
				else god_mode = true;
			}
			if (App->input->keyboard[SDL_SCANCODE_F7] == KEY_STATE::KEY_DOWN) {
				//App->audio->PlayChunk(App->particles->chunks[11], 1);
				alive_p1 = false; 
			}
			
			if (App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN) {
				if(App->ball->ball_type == BALL_TYPE::ORANGE_BALL) App->ball->ball_type = BALL_TYPE::BLUE_BALL;
				else App->ball->ball_type = ORANGE_BALL;
			}
		}

		if (god_mode == true) PlayerCollider->type = COLLIDER_TYPE::COLLIDER_GOD;
		else PlayerCollider->type = COLLIDER_TYPE::COLLIDER_PLAYER;

		if (alive_p1) {
			SDL_Rect r = current_animation->GetCurrentFrame();
			PlayerCollider->SetPos(position.x, position.y - r.h);
			App->render->Blit(graphics, position.x, position.y - r.h, &r);
		}
		else {
			if (death_played == false) {
				App->ball->Disable();
				App->particles->AddParticle(App->particles->player_death, position.x - CHARACTER_WIDTH / 2 + 10, position.y - CHARACTER_HEIGHT - 5);

				death_played = true;
				//lives -= 1;
				lives--;
				if (App->player2->TwoPlayers == true) {
					LOG("PLAYER 1 LIVES BEFORE ENABLE: %i", lives); 
				    App->player->Disable();
					if (lives != 0) {
						App->player->Enable();
						LOG("PLAYER 1 LIVES AFTER ENABLE: %i", lives);
					}
				}
				/*
				if (SwitchToBg2 == false) {
					if (App->background2->IsEnabled() == true) {
						lives = 3;
						SwitchToBg2 = true;
					}
				}*/
			}
		}
		return UPDATE_CONTINUE;
	}

