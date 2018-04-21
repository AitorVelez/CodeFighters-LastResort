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

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	position.x = 50;
	position.y = 125;
	relativeposition.x = position.x;
	relativeposition.y = position.y;
	alive_p1 = true; 	

	graphics = App->textures->Load("assets/sprites/main_character.png"); // arcade version
	PlayerCollider = App->collision->AddCollider({ position.x,position.y, 32, 14 }, COLLIDER_PLAYER, this);
	current_animation = &playershowup;
	App->audio->PlayChunk(App->particles->chunks[5], 1);

	score_p1 = 0; 
	bullet_state = BULLET_STATE::BULLET_NO_TYPE; 
	death_played = false; 
	death.Reset();

	return ret;
}


bool ModulePlayer::CleanUp()
{
	LOG("Closing Up Player Module");
	// Free All textures
	App->textures->Unload(graphics);
	App->ball->Disable(); 
	playershowup.Reset();
	return true; 
}

void ModulePlayer::OnCollision(Collider * c1, Collider * c2)
{
		if (c2->type == COLLIDER_TYPE::COLLIDER_POWERUP_L)
		{
			if (App->ball->IsEnabled() == false)
				App->ball->Enable(); 

			if (bullet_state == BULLET_STATE::BULLET_NO_TYPE)
				bullet_state = BULLET_STATE::LASER1;

			else if (bullet_state == BULLET_STATE::LASER1)
				bullet_state = BULLET_STATE::LASER2; 
		}

		if (c2->type == COLLIDER_TYPE::COLLIDER_POWERUP_S)
			if(speed!=3) speed = 3; 

		if (c2->type == COLLIDER_TYPE::COLLIDER_ENEMY || c2->type == COLLIDER_TYPE::COLLIDER_ENEMY_SHOT)
		{
			alive_p1 = false; 
		}
}

// Update: draw background
update_status ModulePlayer::Update()
{
	int scroll_speed = 1;
//	int speed = 2;

	if (position.x <= 9150 && alive_p1 == true)
		position.x += scroll_speed;


	if (alive_p1 && playershowup.Finished()) {
		
		current_animation = &idle;

		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
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
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_UP) {

			up.Reset();
			current_animation = &re_up;
		}
		




		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
		{
			if (relativeposition.y < SCREEN_HEIGHT - TopLimit) {
				current_animation = &down;
				relativeposition.y += speed;
				position.y += speed;
				re_up.Reset();
				re_down.Reset();
			}
			else {
				relativeposition.y = SCREEN_HEIGHT - TopLimit;
				current_animation = &down;
				re_down.Reset();
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP) {

			down.Reset();
			current_animation = &re_down;

		}

		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT) {
			if (relativeposition.x < SCREEN_WIDTH - CHARACTER_WIDTH - SideLimit) {
				relativeposition.x += speed;
				position.x += speed;
			}
			else {
				relativeposition.x = SCREEN_WIDTH - CHARACTER_WIDTH - SideLimit;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) {
			if (relativeposition.x > SideLimit) {
				relativeposition.x -= speed;
				position.x -= speed;
			}
			else {
				relativeposition.x = SideLimit;
			}
		}


		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
			App->particles->AddParticle(App->particles->bullet_propulsion, position.x + 31, position.y - 15);
			App->particles->AddParticle(App->particles->bullet, position.x + 31, position.y - 12, COLLIDER_PLAYER_SHOT);
			//App->particles->AddParticle(App->particles->bullet_propulsion, position.x + 31, position.y - 15);
			if (bullet_state == LASER1) {
 				App->particles->AddParticle(App->particles->bullet_laser, position.x + 31, position.y - 10, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->firing_laser, position.x + 32, position.y-16);
			}
			if (bullet_state == LASER2) {
				App->particles->AddParticle(App->particles->bullet_laser2_1, position.x + 31, position.y - 10, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->bullet_laser2, position.x + 31, position.y - 24, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->bullet_laser2, position.x + 45, position.y - 24, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->bullet_laser2, position.x + 59, position.y - 24, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->firing_laser, position.x + 32, position.y -16);
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN) {
			if (god_mode == true) god_mode = false;
			else god_mode = true; 
		}

	}

	if (god_mode == true) PlayerCollider->type = COLLIDER_TYPE::COLLIDER_NONE;
	else PlayerCollider->type = COLLIDER_TYPE::COLLIDER_PLAYER;

	if (alive_p1) {
		SDL_Rect r = current_animation->GetCurrentFrame();
		PlayerCollider->SetPos(position.x, position.y - r.h);
		App->render->Blit(graphics, position.x, position.y - r.h, &r);
	}
	else {
		if (death_played == false) {
			App->particles->AddParticle(App->particles->player_death, position.x - CHARACTER_WIDTH / 2 + 10, position.y - CHARACTER_HEIGHT - 5);
			death_played = true;
		}
	}
	return UPDATE_CONTINUE;
}
