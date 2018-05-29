#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer2.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "ModuleFadeToBlack.h"
#include "ModuleBackground.h"
#include "ModulePlayer.h"
#include "ModuleStageClear.h"
#include "ModuleBall_P2.h"
#include "ModuleUI.h"
#include "ModuleBackground2.h"
#include "SDL\include\SDL_timer.h"


#define  SideLimit 15
#define  TopLimit 2
// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer2::ModulePlayer2()
{
	lives = 3;

	current_animation = &idle;


	playershowup.PushBack({ 0,11,112,1 });
	playershowup.PushBack({ 5,37,105,2 });
	playershowup.PushBack({ 34,59,76,4 });
	playershowup.PushBack({ 57,82,54,18 });
	playershowup.PushBack({ 49,103,62,15 }); //player shows up
	playershowup.PushBack({ 49,131,62,15 });
	playershowup.PushBack({ 60,153,51,16 });
	playershowup.PushBack({ 60,180,51,16 });
	playershowup.PushBack({ 157,4,64,16 });
	playershowup.PushBack({ 158,25,64,25 });
	playershowup.PushBack({ 164,49,57,25 });
	playershowup.PushBack({ 166,75,56,25 });
	playershowup.PushBack({ 186,103,36,19 });
	playershowup.PushBack({ 190,130,32,15 });
	playershowup.PushBack({ 286,8,32,11 });
	playershowup.loop = false;
	playershowup.speed = 0.2f;

	//playershowup.PushBack({ 0,130,111,16 });
	//playershowup.PushBack({ 6,155,105,16 });
	//playershowup.PushBack({ 32,180,79,16 });
	//playershowup.PushBack({ 34,204,77,17 });
	//playershowup.PushBack({ 46,224,65,22 }); //player shows up
	//playershowup.PushBack({ 46,252,65,19 });
	//playershowup.PushBack({ 57,274,56,22 });
	//playershowup.PushBack({ 57,300,56,21 });
	//playershowup.PushBack({ 44,325,67,21 });
	//playershowup.PushBack({ 44,346,67,25 });
	//playershowup.PushBack({ 51,371,60,25 });
	//playershowup.PushBack({ 52,396,59,25 });
	//playershowup.PushBack({ 72,425,39,18 });
	//playershowup.PushBack({ 76,452,35,15 });
	//playershowup.PushBack({ 64,3,32,14 });
	//playershowup.loop = false;
	//playershowup.speed = 0.2f;

	// Death Animation 
	death.PushBack({ 255, 0, 63, 28 });
	death.PushBack({ 255, 28, 63, 28 });
	death.PushBack({ 255, 56, 63, 28 });
	death.PushBack({ 255, 84, 63, 28 });
	death.PushBack({ 255, 112, 63, 28 });
	death.PushBack({ 255, 140, 63, 28 });
	death.PushBack({ 255, 168, 63, 28 });
	death.PushBack({ 255, 196, 63, 28 });
	death.PushBack({ 318, 0, 63, 28 });
	death.PushBack({ 318, 28, 63, 28 });
	death.PushBack({ 318, 56, 63, 28 });
	death.PushBack({ 318, 84, 63, 28 });
	death.PushBack({ 318, 112, 63, 28 });
	death.PushBack({ 318, 140, 63, 28 });
	death.PushBack({ 318, 168, 63, 28 });
	death.PushBack({ 318, 196, 63, 28 });
	death.PushBack({ 381, 0, 63, 28 });
	death.PushBack({ 381, 28, 63, 28 });
	death.PushBack({ 381, 56, 63, 28 });
	death.PushBack({ 381, 84, 63, 28 });
	death.loop = false;
	death.speed = 0.15f;
	
	// idle animation (arcade sprite sheet)

	idle.PushBack({ 286,8,32,11 });

	// Up animation
	up.PushBack({ 223,12,32,11 });
	up.PushBack({ 223,0,32,11 });
	up.speed = 0.1;
	up.loop = false;

	re_up.PushBack({ 223,0,32,11 });
	re_up.PushBack({ 223,12,32,11 });
	re_up.PushBack({ 286,8,32,11 });
	re_up.speed = 0.1;
	re_up.loop = false;

	// Down animation
	down.PushBack({ 223,36,32,12 });
	down.PushBack({ 223,49,32,11 });
	down.speed = 0.1;
	down.loop = false;

	down.PushBack({ 223,49,32,11 });
	down.PushBack({ 223,36,32,12 });
	re_down.PushBack({ 286,8,32,11 });
	re_down.speed = 0.1;
	re_down.loop = false;

}

ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player 2 textures");
	bool ret = true;
	int i = App->render->camera.x;

		if (App->background->IsEnabled() == true) {
			position.x = App->background->bgpos + 50;      // IF BOTH PLAYERS ENABLED, RESPAWN
			position.y = 125;
			relativeposition.x = 50; 
			relativeposition.y = position.y;
		}
		else if (App->background2->IsEnabled() == true) {
			position.x = App->background2->bgpos + 50;
			position.y = 125;
			relativeposition.x = 50;
			relativeposition.y = position.y;
		}

	App->UI->pl2 = true;

	graphics = App->textures->Load("assets/sprites/SpritesPlayer2.png"); // arcade version
	PlayerCollider = App->collision->AddCollider({ position.x,position.y, 32, 11 }, COLLIDER_PLAYER, this);
	current_animation = &playershowup;
	if (lives > 0) {
		App->audio->PlayChunk(App->particles->chunks[5], 1);
	}
	
	/*if (SwitchToBg2 == false) {
		if (App->background2->IsEnabled() == true && App->background->IsEnabled() == false) {
			if (lives != 3) {
				lives = 3;
			}
		}
		SwitchToBg2 = true;
	}*/

	App->background->activ = true;
	score_p2 = 0;
	alive_p2 = true;
	bullet_state_2 = BULLET_NO_TYPE_2;
	death_played = false;
	death.Reset();
	god_mode = false;
	return ret;
}
	



bool ModulePlayer2::CleanUp()
{
	LOG("Closing Up Player 2 Module");
	// Free All textures
	App->textures->Unload(graphics);
	App->ball_p2->Disable(); 
	playershowup.Reset();
	return true;
}

void ModulePlayer2::OnCollision(Collider * c1, Collider * c2)
{
	if (c2->type == COLLIDER_TYPE::COLLIDER_POWERUP_L)
	{
		if(App->ball_p2->IsEnabled() == false)
			App->ball_p2->Enable(); 

		if (bullet_state_2 == BULLET_STATE_2::BULLET_NO_TYPE_2)
			bullet_state_2 = BULLET_STATE_2::LASER1_2;

		else if (bullet_state_2 == BULLET_STATE_2::LASER1_2)
			bullet_state_2 = BULLET_STATE_2::LASER2_2;
	}

	if (c2->type == COLLIDER_TYPE::COLLIDER_POWERUP_S)
		if (speed != 3) speed = 3; 

	if (c2->type == COLLIDER_TYPE::COLLIDER_ENEMY || c2->type == COLLIDER_TYPE::COLLIDER_ENEMY || c2->type == COLLIDER_TYPE::COLLIDER_WALL)
	{
		alive_p2 = false;

	}
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	int scroll_speed = 1;

	if (position.x <= 9150 && alive_p2 == true)
		position.x += scroll_speed;

	// Input -----
	if (alive_p2 && playershowup.Finished()) {

		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
		{
			if (relativeposition.y > CHARACTER_HEIGHT + TopLimit) {
				current_animation = &up;
				relativeposition.y -= speed;
				position.y -= speed;
				re_up.Reset();
				re_down.Reset();
			}
			else {
				relativeposition.y = CHARACTER_HEIGHT + TopLimit;
				current_animation = &up;
				re_up.Reset();
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_UP) {

			up.Reset();
			current_animation = &re_up;
		}


		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
		{
			if (relativeposition.y < SCREEN_HEIGHT - TopLimit -1) {
				current_animation = &down;
				relativeposition.y += speed;
				position.y += speed;
				re_up.Reset();
				re_down.Reset();
			}
			else {
				relativeposition.y = SCREEN_HEIGHT - TopLimit -1;
				current_animation = &down;
				re_down.Reset();
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_UP) {

			down.Reset();
			current_animation = &re_down;

		}

		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) {
			if (relativeposition.x < SCREEN_WIDTH - CHARACTER_WIDTH - SideLimit) {
				relativeposition.x += speed;
				position.x += speed;
			}
			else {
				relativeposition.x = SCREEN_WIDTH - CHARACTER_WIDTH - SideLimit;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) {
			if (relativeposition.x > SideLimit) {
				relativeposition.x -= speed;
				position.x -= speed;
			}
			else {
				relativeposition.x = SideLimit;
			}
		}


		current_time = SDL_GetTicks();

		if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN) {
			App->particles->AddParticle(App->particles->bullet, position.x + 31, position.y - 12, COLLIDER_PLAYER2_SHOT);
			App->particles->AddParticle(App->particles->bullet_propulsion, position.x + 31, position.y - 15);
			if (bullet_state_2 == LASER1_2 && current_time > last_time + 500) {
				App->particles->AddParticle(App->particles->bullet_laser, position.x, position.y - 10, COLLIDER_PLAYER2_SHOT);
				last_time = current_time; 
			}
			if (bullet_state_2 == LASER2_2 && current_time > last_time + 700) {
				App->particles->AddParticle(App->particles->bullet_laser2_1, position.x, position.y - 10, COLLIDER_PLAYER2_SHOT);
				App->particles->AddParticle(App->particles->bullet_laser2, position.x, position.y - 24, COLLIDER_PLAYER2_SHOT);
				App->particles->AddParticle(App->particles->bullet_laser2, position.x + 14, position.y - 24, COLLIDER_PLAYER2_SHOT);
				App->particles->AddParticle(App->particles->bullet_laser2, position.x + 28, position.y - 24, COLLIDER_PLAYER2_SHOT);
				//App->particles->AddParticle(App->particles->bullet_laser2, position.x + 73, position.y - 24, COLLIDER_PLAYER2_SHOT);
				last_time = current_time; 
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_STATE::KEY_DOWN) {
			if (god_mode == true) god_mode = false;
			else god_mode = true;
		}
		if (App->input->keyboard[SDL_SCANCODE_8] == KEY_STATE::KEY_DOWN) {
			alive_p2 = false;
			App->audio->PlayChunk(App->particles->chunks[11], 1);
		}
	}

	if (god_mode == true) PlayerCollider->type = COLLIDER_TYPE::COLLIDER_GOD;
	else PlayerCollider->type = COLLIDER_TYPE::COLLIDER_PLAYER;

	if (alive_p2) {
		SDL_Rect r = current_animation->GetCurrentFrame();
		PlayerCollider->SetPos(position.x, position.y - r.h);
		App->render->Blit(graphics, position.x, position.y - r.h, &r);
	}

	// Draw everything --------------------------------------
	else {
		if (death_played == false) {
			App->ball_p2->Disable();
			App->particles->AddParticle(App->particles->player2_death, position.x - CHARACTER_WIDTH / 2 + 10, position.y - CHARACTER_HEIGHT - 5);


			death_played = true;
			LOG("PLAYER 2 LIVES BEFORE DYING: %i", lives);
			lives --;
			LOG("PLAYER 2 LIVES AFTER DYING : %i", lives);
			if (TwoPlayers == true) {
				LOG("PLAYER 2 LIVES BEFORE ENABLE: %i", lives);
				App->player2->Disable(); LOG("PLAYER 2 HAS BEEN DISABLED"); 
					if (lives != 0) {
						App->player2->Enable();
						LOG("PLAYER 2 LIVES AFTER ENABLE: %i", lives);
					}
			}
			/*
			if (SwitchToBg2 == false) {
				if (App->background2->IsEnabled() == true) {
					lives = 4;
					SwitchToBg2 = true;
				}
			}*/
		}
	}
	return UPDATE_CONTINUE;
}
