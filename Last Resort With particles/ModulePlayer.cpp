#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	playershowup.PushBack({ 0,122, 111, 1 });
	playershowup.PushBack({ 6,125, 105, 2 });
	playershowup.PushBack({ 1,127, 77, 5 });
	playershowup.PushBack({ 0,124, 74, 7 });
	playershowup.PushBack({ 0,132, 111, 1 });
	playershowup.PushBack({ 2,142, 62, 15 });   // player shows up
	playershowup.PushBack({ 2, 172, 62, 15 });
	playershowup.PushBack({ 13, 193, 51, 16 });
	playershowup.PushBack({ 13, 219, 51, 16 });
	playershowup.PushBack({ 64, 143, 64, 16 });
	playershowup.PushBack({ 64, 164, 64, 24 });
	playershowup.PushBack({ 71, 189, 57, 25 });
	playershowup.PushBack({ 72, 214, 56, 25 });
	playershowup.PushBack({ 156, 143, 36, 19 });
	playershowup.PushBack({ 160, 171, 32, 15 });
	playershowup.speed = 0.26f;


	// idle animation (arcade sprite sheet)
	
	idle.PushBack({ 64,3,32,14 });

	// Up animation
	up.PushBack({ 32,3,32,14 });
	up.PushBack({ 0,3,32,14 });
	up.speed = 0.2f;
	up.loop = false; 


	// Down animation
	down.PushBack({ 96,3,32,14 });
	down.PushBack({ 128,3,32,14 });
	down.speed = 0.2f;
	down.loop = false; 
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
	relativeposition.x = 50;
	relativeposition.y = 125; 

	graphics = App->textures->Load("assets/sprites/main_character.png"); // arcade version
	chunk = App->audio->LoadChunk("assets/SFX/shot.wav");




	//App->particles->AddParticle(App->particles->SpaceshipAnim, position.x - 30, position.y - 20, 200);

	return ret;
}


bool ModulePlayer::CleanUp()
{
	LOG("Closing Up Player Module");
	// Free All textures
	App->textures->Unload(graphics);

	// Free all audio material
	App->audio->UnloadChunk(chunk);

	return true; 
}


void ModulePlayer::RenderStartingAnim() {
	App->render->Blit(graphics, 50 , 125 , &playershowup.GetCurrentFrame(), 0);
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;
	int scroll_speed = 1;
	int speed = 2;
	if (position.x <= 9150)
		position.x += scroll_speed;
	// Input -----
	if (App->render->camera.x >= -150) {
		current_animation = &playershowup; 
	}
	else {
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
		{
			if (relativeposition.y > CHARACTER_HEIGHT) {
				current_animation = &up;
				relativeposition.y -= speed;
				position.y -= speed;
			}
			else {
				relativeposition.y = CHARACTER_HEIGHT;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
		{
			if (relativeposition.y < SCREEN_HEIGHT) {
				current_animation = &down;
				relativeposition.y += speed;
				position.y += speed;
			}
			else {
				relativeposition.y = SCREEN_HEIGHT;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT) {
			if (relativeposition.x < SCREEN_WIDTH - CHARACTER_WIDTH) {
				relativeposition.x += speed;
				position.x += speed;
			}
			else {
				relativeposition.x = SCREEN_WIDTH - CHARACTER_WIDTH;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) {
			if (relativeposition.x > 0) {
				relativeposition.x -= speed;
				position.x -= speed;
			}
			else {
				relativeposition.x = 0;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_J] == KEY_STATE::KEY_DOWN) {
			App->particles->AddParticle(App->particles->bullet, position.x + 33, position.y - 13);
			App->particles->AddParticle(App->particles->bulletEx, position.x + 33, position.y - 14);
			App->audio->PlayChunk(chunk, 1);
		}
	}
	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, (float)position.x, (float)position.y - r.h, &r);
	
	return UPDATE_CONTINUE;
}
