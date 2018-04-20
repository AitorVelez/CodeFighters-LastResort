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
#include "ModuleStageClear.h"

#define  SideLimit 15
#define  TopLimit 2
// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer2::ModulePlayer2()
{
	current_animation = &idle;


	playershowup.PushBack({ 0,11,112,1 });
	playershowup.PushBack({ 5,37,105,2 });
	playershowup.PushBack({ 34,59,76,4 });
	playershowup.loop = false;
	playershowup.speed = 0.1f;
	playershowup2.PushBack({ 57,82,54,18 });
	playershowup2.PushBack({ 49,103,62,15 }); //player shows up
	playershowup2.PushBack({ 49,131,62,15 });
	playershowup2.PushBack({ 60,153,51,16 });
	playershowup2.PushBack({ 60,180,51,16 });
	playershowup2.PushBack({ 157,4,64,16 });
	playershowup2.PushBack({ 158,25,64,25 });
	playershowup2.loop = false;
	playershowup2.speed = 0.15f;
	playershowup3.PushBack({ 164,49,57,25 });
	playershowup3.PushBack({ 166,75,56,25 });
	playershowup3.PushBack({ 186,103,36,19 });
	playershowup3.PushBack({ 190,130,32,15 });
	playershowup3.PushBack({ 286,8,32,11 });
	playershowup3.loop = false;
	playershowup3.speed = 0.2f;

	

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
	position.x = 50;                             
	position.y = 175;
	relativeposition.x = position.x;                                                               
	relativeposition.y = position.y;
	alive_p2 = true;
	App->background->activ = true;
	graphics = App->textures->Load("assets/sprites/SpritesPlayer2.png"); // arcade version
	PlayerCollider = App->collision->AddCollider({ position.x,position.y, 32, 11 }, COLLIDER_PLAYER, this);

	death_played = false;
	death.Reset();
	playershowup.Reset();
	playershowup2.Reset();
	playershowup3.Reset();

	return ret;
}


bool ModulePlayer2::CleanUp()
{
	LOG("Closing Up Player 2 Module");
	// Free All textures
	App->textures->Unload(graphics);

	return true;
}

void ModulePlayer2::OnCollision(Collider * c1, Collider * c2)
{
	if (!god_mode) {
		alive_p2 = false;
	}
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	int scroll_speed = 1;
	int speed = 2;
	if (position.x <= 9150 && alive_p2 == true)
		position.x += scroll_speed;
	// player shows up
	if (App->render->camera.x >= -150) {
		if (App->render->camera.x >= -40) {
			current_animation = &playershowup;
		}
		else if (App->render->camera.x >= -100) {
			current_animation = &playershowup2;
		}
		else if (App->render->camera.x >= -149) {
			current_animation = &playershowup3;
		}
	}

	// Input -----
	else if (alive_p2) {

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




		if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN) {
		
			App->particles->AddParticle(App->particles->bullet_propulsion, position.x + 31, position.y - 12);
			App->particles->AddParticle(App->particles->bullet, position.x + 31, position.y - 9, COLLIDER_PLAYER_SHOT);

		}

		if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_STATE::KEY_DOWN) {
			if (god_mode == true) god_mode = false;
			else god_mode = true;
		}

	}

	if (god_mode == true) PlayerCollider->type = COLLIDER_TYPE::COLLIDER_NONE;
	else PlayerCollider->type = COLLIDER_TYPE::COLLIDER_PLAYER;

	if (alive_p2) {
		SDL_Rect r = current_animation->GetCurrentFrame();
		PlayerCollider->SetPos(position.x, position.y - r.h);
		App->render->Blit(graphics, position.x, position.y - r.h, &r);
	}

	// Draw everything --------------------------------------
	else {
		/*current_animation = &death;
		r = current_animation->GetCurrentFrame();*/                          // should do death animation for PLAYER 2 
		if (death_played == false) {
			App->particles->AddParticle(App->particles->player2_death, position.x - CHARACTER_WIDTH / 2 + 10, position.y - CHARACTER_HEIGHT - 5);
			death_played = true;                   
		}
	}
	return UPDATE_CONTINUE;
}
