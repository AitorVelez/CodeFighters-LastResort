#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "ModuleFadeToBlack.h"
#include "ModuleBackground.h"
#include "ModuleStageClear.h"

#define  SideLimit 15
#define  TopLimit 2
// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	current_animation = &idle;


	playershowup.PushBack({ 0,122, 111, 1 });
	playershowup.PushBack({ 6,125, 105, 2 });
	playershowup.PushBack({ 1,127, 77, 5 });
	playershowup.PushBack({ 0,124, 74, 7 });
	playershowup.PushBack({ 0,132, 111, 1 });
	playershowup.loop = false;
	playershowup.speed = 0.1f;
	playershowup2.PushBack({ 2,142, 62, 15 });   // player shows up
	playershowup2.PushBack({ 2, 172, 62, 15 });
	playershowup2.PushBack({ 13, 193, 51, 16 });
	playershowup2.PushBack({ 13, 219, 51, 16 });
	playershowup2.PushBack({ 64, 143, 64, 16 });
	playershowup2.PushBack({ 64, 164, 64, 24 });
	playershowup2.PushBack({ 71, 189, 57, 25 });
	playershowup2.loop = false;
	playershowup2.speed = 0.25f;
	playershowup3.PushBack({ 72, 214, 56, 25 });
	playershowup3.PushBack({ 156, 143, 36, 19 });
	playershowup3.PushBack({ 160, 171, 32, 15 });
	playershowup3.PushBack({ 64,3,32,14 });
	playershowup3.loop = false;
	playershowup3.speed = 0.2f;



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

	re1.PushBack({ 0,3,32,14 });
	re1.PushBack({ 32,3,32,14 });
	re1.PushBack({ 64,3,32,14 });
	re1.speed = 0.1;
	re1.loop = false;

	// Down animation
	down.PushBack({ 96,3,32,14 });
	down.PushBack({ 128,3,32,14 });
	down.speed = 0.1;
	down.loop = false;

	re2.PushBack({ 128,3,32,14 });
	re2.PushBack({ 96,3,32,14 });
	re2.PushBack({ 64,3,32,14 });
	re2.speed = 0.1;
	re2.loop = false;

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
	alive = true; 

	graphics = App->textures->Load("assets/sprites/main_character.png"); // arcade version
	PlayerCollider = App->collision->AddCollider({ position.x,position.y, 32, 14 }, COLLIDER_PLAYER, this);
	
	death_played = false; 
	death.Reset();
	playershowup.Reset();
	playershowup2.Reset(); 
	playershowup3.Reset();

	return ret;
}


bool ModulePlayer::CleanUp()
{
	LOG("Closing Up Player Module");
	// Free All textures
	App->textures->Unload(graphics);

	return true; 
}

void ModulePlayer::OnCollision(Collider * c1, Collider * c2)
{
	// in this function is written what happens when the player collides with something

	//Add an explosion here
	alive = false; 
	App->fade->FadeToBlack((Module*)App->background, (Module*)App->loseimage,2.5f);
}

/*
void SwitchToDown(Animation* anim) {
	if (//player has reached the top animation) {
	anim.PushBack({ 32,3,32,14 });   
    anim.PushBack({ 64,3,32,14 });    // up anim and then idle //

	}
	else {
	anim.PushBack({ 64,3,32,14 });  // only idle //
	}
};*/

/*
void SwitchToUp(Animation* anim) {
if (// player has reached the bottom animation ) {
anim.PushBack({ 96,3,32,14 });
anim.PushBack({ 64,3,32,14 });    // it does the remaining down anim and then idle //      

	}
	else {
		anim.PushBack({ 64,3,32,14 });  // it does only idle //
	}
};*/


 

// Update: draw background
update_status ModulePlayer::Update()
{
	int scroll_speed = 1;
	int speed = 2;
	if (position.x <= 9150 && alive == true)
		position.x += scroll_speed;

	// Input -----
	if (App->render->camera.x >= -150) {
<<<<<<< HEAD
<<<<<<< HEAD
		if (App->render->camera.x >= -40) {
			current_animation = &playershowup;
=======
		if(App->render->camera.x >= -40){
			current_animation = &playershowup;     // player shows up
>>>>>>> parent of c29244f... Merge branch 'master' of https://github.com/AitorVelez/CodeFighters-LastResort
=======
		if(App->render->camera.x >= -40){
			current_animation = &playershowup;    
>>>>>>> parent of 3d09a3a... Experimenting
		}
		else if(App->render->camera.x >= -100){
			current_animation = &playershowup2;
		}
		else {
			current_animation = &playershowup3;
		}
<<<<<<< HEAD
	}
<<<<<<< HEAD

	// Input -----

	else if (alive) {
=======
	else if (alive){
>>>>>>> parent of c29244f... Merge branch 'master' of https://github.com/AitorVelez/CodeFighters-LastResort
=======
	}	
	
	// Input -----

	else if (alive){
>>>>>>> parent of 3d09a3a... Experimenting

		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
		{
			if (relativeposition.y > CHARACTER_HEIGHT + TopLimit) {
				// SwitchToUp(current_animation);   // first does the remaining animations (in the function)
				current_animation = &up;         // then does the up animation 
				relativeposition.y -= speed;
				position.y -= speed;
				re1.Reset();
				re2.Reset();

			}
			else {
				relativeposition.y = CHARACTER_HEIGHT + TopLimit;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_UP) {

			up.Reset();
			current_animation = &re1;
		}
		

		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
		{
			if (relativeposition.y < SCREEN_HEIGHT - TopLimit) {
				// SwitchToDown(current_animation);   // first does the remaining animations (in the function)
				current_animation = &down;         // then does the down animation 
				relativeposition.y += speed;
				position.y += speed;
				re1.Reset();
				re2.Reset();
			}
			else {
				relativeposition.y = SCREEN_HEIGHT - TopLimit;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP) {

			down.Reset();
			current_animation = &re2;

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
<<<<<<< HEAD
<<<<<<< HEAD


<<<<<<< HEAD


		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
			/*if (App->background->notscrolling == false) {
				if (App->background->downscroll == true) {
					App->particles->bullet.speed.y += 0.1f;
					App->particles->AddParticle(App->particles->bullet, position.x + 31, position.y - 12, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->bulletEx, position.x + 31, position.y - 15);
					//App->particles->bullet.speed.y -= 0.1f;
				}
				else {
					App->particles->bullet.speed.y -= 0.1f;
					App->particles->AddParticle(App->particles->bullet, position.x + 31, position.y - 12, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->bulletEx, position.x + 31, position.y - 15);
					//App->particles->bullet.speed.y += 0.1f;
				}
=======
=======
>>>>>>> parent of 3d09a3a... Experimenting
		/*if (App->background->notscrolling == false) {
			if (App->background->downscroll == true) {
				App->particles->bullet.speed.y += 0.1f;
				App->particles->AddParticle(App->particles->bullet, position.x + 31, position.y - 12, COLLIDER_PLAYER_SHOT);
<<<<<<< HEAD
				App->particles->AddParticle(App->particles->bulletEx, position.x + 31, position.y - 15);
				App->particles->bullet.speed.y -= 0.1f;
>>>>>>> parent of c29244f... Merge branch 'master' of https://github.com/AitorVelez/CodeFighters-LastResort
			}
			else {*/
=======
>>>>>>> parent of 3d09a3a... Experimenting
				App->particles->AddParticle(App->particles->bulletEx, position.x + 31, position.y - 15);
				App->particles->bullet.speed.y -= 0.1f;
			}
			else{
				App->particles->bullet.speed.y -= 0.1f;
				App->particles->AddParticle(App->particles->bullet, position.x + 31, position.y - 12, COLLIDER_PLAYER_SHOT);
<<<<<<< HEAD
			//}
		}
<<<<<<< HEAD

		if (alive) {
			SDL_Rect r = current_animation->GetCurrentFrame();
			PlayerCollider->SetPos(position.x, position.y - r.h);
			App->render->Blit(graphics, position.x, position.y - r.h, &r);
		}
		// Draw everything --------------------------------------
		else {
			/*current_animation = &death;
			r = current_animation->GetCurrentFrame();*/
			if (death_played == false) {
				App->particles->AddParticle(App->particles->player_death, position.x - CHARACTER_WIDTH / 2 + 10, position.y - CHARACTER_HEIGHT - 5);
				death_played = true;
=======
				App->particles->AddParticle(App->particles->bulletEx, position.x + 31, position.y - 15);
				App->particles->bullet.speed.y += 0.1f;
>>>>>>> parent of 3d09a3a... Experimenting
			}
=======
		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
			App->particles->AddParticle(App->particles->bullet, position.x + 31, position.y - 12, COLLIDER_PLAYER_SHOT);
			App->particles->AddParticle(App->particles->bulletEx, position.x + 31, position.y - 15);		
		}
	
=======
		else {*/
		App->particles->AddParticle(App->particles->bullet, position.x + 31, position.y - 12, COLLIDER_PLAYER_SHOT);
		App->particles->AddParticle(App->particles->bulletEx, position.x + 31, position.y - 15);
	}
>>>>>>> parent of c29244f... Merge branch 'master' of https://github.com/AitorVelez/CodeFighters-LastResort
		
	}
		
	if (alive) {
		SDL_Rect r = current_animation->GetCurrentFrame();
		PlayerCollider->SetPos(position.x, position.y - r.h);
		App->render->Blit(graphics, position.x, position.y - r.h, &r);
	}
	// Draw everything --------------------------------------
	else {
		/*current_animation = &death;
		r = current_animation->GetCurrentFrame();*/	
		if (death_played == false) {
			App->particles->AddParticle(App->particles->player_death, position.x - CHARACTER_WIDTH / 2 + 10, position.y - CHARACTER_HEIGHT - 5);
			death_played = true;
>>>>>>> parent of 6f9de38... I wanna become a programmer
		}
		else {*/
		App->particles->AddParticle(App->particles->bullet, position.x + 31, position.y - 12, COLLIDER_PLAYER_SHOT);
		App->particles->AddParticle(App->particles->bulletEx, position.x + 31, position.y - 15);
	}
		
=======
		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
			App->particles->AddParticle(App->particles->bulletEx, position.x + 31, position.y - 15);
			App->particles->AddParticle(App->particles->bullet, position.x + 31, position.y - 12, COLLIDER_PLAYER_SHOT);
		}		
>>>>>>> b580d79ed6067d94a9e0261f3681791537a0a9e0
	}
		
	if (alive) {
		SDL_Rect r = current_animation->GetCurrentFrame();
		PlayerCollider->SetPos(position.x, position.y - r.h);
		App->render->Blit(graphics, position.x, position.y - r.h, &r);
	}
	// Draw everything --------------------------------------
	else {
		/*current_animation = &death;
		r = current_animation->GetCurrentFrame();*/	
		if (death_played == false) {
			App->particles->AddParticle(App->particles->player_death, position.x - CHARACTER_WIDTH / 2 + 10, position.y - CHARACTER_HEIGHT - 5);
			death_played = true;
		}
	}

	
	return UPDATE_CONTINUE;
}
