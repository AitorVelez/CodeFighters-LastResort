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

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 1;

	// Input -----

	position.x += speed; 

	if(App->input->keyboard[SDL_SCANCODE_W] == 1)
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
	if (App->input->keyboard[SDL_SCANCODE_S] == 1)
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
	if (App->input->keyboard[SDL_SCANCODE_D] == 1) {
		if (relativeposition.x < SCREEN_WIDTH - CHARACTER_WIDTH) {
			relativeposition.x += speed;
			position.x += speed;
		}
		else {
			relativeposition.x = SCREEN_WIDTH  - CHARACTER_WIDTH;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == 1) {
		if (relativeposition.x > 0) {
			relativeposition.x -= speed;
			position.x -= speed; 
		}
		else {
			relativeposition.x = 0; 
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_X] == 1) {
		App->particles->AddParticle(App->particles->shoot, position.x, position.y);
	}


	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	
	return UPDATE_CONTINUE;
}
