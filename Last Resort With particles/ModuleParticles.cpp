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
	shot = App->audio->LoadChunk("assets/SFX/shot.wav");		// Shot -> fx = 0 


	bulletEx.anim.PushBack({ 278,90,13,12 });
	bulletEx.anim.PushBack({ 291,90,13,12 });
	bulletEx.anim.PushBack({ 304,90,12,12 });
	bulletEx.anim.loop = true;
	bulletEx.anim.speed = 0.25f;
	bulletEx.speed.x = 1;
	bulletEx.life = 120;

	bullet.anim.PushBack({ 148,127,14,7 });
	bullet.anim.loop = false;
	bullet.anim.speed = 0.3f;
	bullet.speed.x = 8;
	bullet.life = 1000;
	bullet.fx = 0;

	SpaceshipAnim.anim.PushBack({ 0,122,111,1 });
	SpaceshipAnim.anim.PushBack({ 0,125,111,2 });
	SpaceshipAnim.anim.PushBack({ 0,127,77,5 });
	SpaceshipAnim.anim.PushBack({ 0,132,74,7 });
	SpaceshipAnim.anim.PushBack({ 0,142,64,15 });
	SpaceshipAnim.anim.PushBack({ 0,171,64,15 });
	SpaceshipAnim.anim.PushBack({ 0,193,64,16 });
	SpaceshipAnim.anim.PushBack({ 0,219,64,16 });
	SpaceshipAnim.anim.PushBack({ 64,143,64,16 });
	SpaceshipAnim.anim.PushBack({ 64,164,64,25 });
	SpaceshipAnim.anim.PushBack({ 64,189,64,25 });
	SpaceshipAnim.anim.PushBack({ 64,214,64,25 });
	SpaceshipAnim.anim.PushBack({ 128,143,64,19 });
	SpaceshipAnim.anim.PushBack({ 128,162,64,19 });
	SpaceshipAnim.anim.loop = false;
	SpaceshipAnim.speed.x = 1;
	SpaceshipAnim.anim.speed = 0.5f;


	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(playerPart);
	App->audio->UnloadChunk(shot);
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
			AddParticle(SpaceshipAnim, active[i]->position.x, active[i]->position.y);
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