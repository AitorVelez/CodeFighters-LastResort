#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	playerPart = App->textures->Load("assets/sprites/main_character.png");
	shot = App->audio->LoadChunk("assets/SFX/shot.wav");							// Shot -> fx = 0 
	player_death_sfx = App->audio->LoadChunk("assets/SFX/player_death.wav");		// Death -> fx = 1

	bulletEx.anim.PushBack({ 278,90,13,12 });
	bulletEx.anim.PushBack({ 291,90,13,12 });
	bulletEx.anim.PushBack({ 304,90,12,12 });
	bulletEx.anim.loop = true;
	bulletEx.anim.speed = 0.25f;
	bulletEx.speed.x = 1;
	bulletEx.life = 100;

	bullet.anim.PushBack({ 148,127,14,7 });
	bullet.anim.loop = false;
	bullet.anim.speed = 0.3f;
	bullet.speed.x = 8;
	bullet.life = 1000;
	bullet.fx = 0;

	SpaceshipAnim.anim.PushBack({ 0,121,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,146,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,171,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,196,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,221,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,246,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,271,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,296,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,321,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,346,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,371,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,396,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,421,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,446,111,25 });
	SpaceshipAnim.anim.loop = false;
	SpaceshipAnim.speed.x = 1;
	SpaceshipAnim.anim.speed = 0.3f;

	ball_bullet.anim.PushBack({ 317, 176, 13, 13 });
	ball_bullet.anim.PushBack({ 332, 176, 13, 13 });
	ball_bullet.anim.PushBack({ 317, 191, 13, 13 });
	ball_bullet.anim.PushBack({ 332, 191, 13, 13 });
	ball_bullet.anim.PushBack({ 317, 206, 13, 13 });
	ball_bullet.anim.PushBack({ 332, 206, 13, 13 });
	ball_bullet.anim.PushBack({ 317, 221, 13, 13 });
	ball_bullet.anim.PushBack({ 332, 221, 13, 13 });
	ball_bullet.anim.speed = 0.3f;
	ball_bullet.anim.loop = true;
	ball_bullet.life = 10000;


	player_death.anim.PushBack({ 18, 20, 37, 16 });
	player_death.anim.PushBack({ 14, 37, 41, 17 });
	player_death.anim.PushBack({ 9, 54, 46, 18 });
	player_death.anim.PushBack({ 3, 71, 52, 16 });
	player_death.anim.PushBack({ 2, 87, 54, 15 });
	player_death.anim.PushBack({ 0, 104, 55, 16 });
	player_death.anim.PushBack({ 57, 21, 53, 15 });
	player_death.anim.PushBack({ 58, 36, 52, 16 });
	player_death.anim.PushBack({ 55, 53, 55, 17 });
	player_death.anim.PushBack({ 56, 70, 54, 17 });
	player_death.anim.PushBack({ 55, 88, 55, 17 });
	player_death.anim.PushBack({ 57, 106, 53, 15 });
	player_death.anim.PushBack({ 112, 19, 53, 18 });
	player_death.anim.PushBack({ 114, 38, 51, 14 });
	player_death.anim.PushBack({ 118, 53, 47, 18 });
	player_death.anim.PushBack({ 118, 72, 47, 14 });
	player_death.anim.PushBack({ 124, 89, 41, 12 });
	player_death.anim.PushBack({ 128, 108, 37, 10 });
	player_death.anim.loop = false;
	player_death.anim.speed = 0.25f;
	player_death.fx = 1; 

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(playerPart);
	App->audio->UnloadChunk(shot);
	App->audio->UnloadChunk(player_death_sfx);
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if (SDL_GetTicks() >= p->born)
		{
			App->render->Blit(playerPart, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
				// Play particle fx here				
				App->audio->PlayChunk(App->audio->chunks[p->fx], 1);
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}
// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) :
	anim(p.anim), position(p.position), speed(p.speed),
	fx(p.fx), born(p.born), life(p.life)
{}

Particle::~Particle()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}