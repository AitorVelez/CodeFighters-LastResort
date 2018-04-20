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

	for (uint i = 0; i < MAX_PART_CHUNKS; ++i)
		chunks[i] = nullptr; 

	for (uint i = 0; i < MAX_PART_TEXTURES; ++i)
		textures[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	chunks[0] = App->audio->LoadChunk("assets/SFX/shot.wav");							// Shot -> fx = 0 
	chunks[1]= App->audio->LoadChunk("assets/SFX/player_death.wav");					// Death -> fx = 1
	chunks[2] = App->audio->LoadChunk("assets/SFX/Explosion1.wav");						// Common Explosion -> fx = 2
	chunks[3] = App->audio->LoadChunk("assest/SFX/player_showup.WAV");					// Player_showup -> fx = 3
	

	textures[0] = App->textures->Load("assets/sprites/main_character.png");			// Texture -> 0
	textures[1] = App->textures->Load("assets/sprites/SpritesPlayer2.png");			// Texture -> 1
	textures[2] = App->textures->Load("assets/sprites/cars_bottom.png");			// Texture -> 2
	textures[3] = App->textures->Load("assets/sprites/common_enemies1.png");
	textures[4] = App->textures->Load("assets/sprites/falling_man.png");

	bullet_propulsion.anim.PushBack({ 278, 90,13,12 });
	bullet_propulsion.anim.PushBack({ 291, 92,10,9 });
	bullet_propulsion.anim.PushBack({ 304, 92,10,9 });
	bullet_propulsion.anim.loop = false;
	bullet_propulsion.anim.speed = 0.25f;
	bullet_propulsion.speed.x = 1;
	bullet_propulsion.life = 20;
	bullet_propulsion.texture = 0; 
	

	bullet.anim.PushBack({ 148,127,14,7 });
	bullet.anim.loop = false;
	bullet.anim.speed = 0.3f;
	bullet.speed.x = 15;
	bullet.life = 1000;
	bullet.fx = 0;
	bullet.texture = 0; 

	bullet_explosion.anim.PushBack({ 248,7,12,12 });
	bullet_explosion.anim.PushBack({ 262,7,13,13 });
	bullet_explosion.anim.PushBack({ 277,7,14,14 });
	bullet_explosion.anim.PushBack({ 293,7,12,12 });
	bullet_explosion.anim.PushBack({ 248,23,14,14 });
	bullet_explosion.anim.PushBack({ 264,23,16,16 });
	bullet_explosion.anim.PushBack({ 282,23,14,14 });
	bullet_explosion.anim.speed = 0.3f; 
	bullet_explosion.anim.loop = false; 
	bullet_explosion.texture = 0; 
	


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
	SpaceshipAnim.fx = 3;
	SpaceshipAnim.anim.speed = 0.3f;
	SpaceshipAnim.texture = 1; 

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
	player_death.texture = 0; 

	carExplosion.anim.PushBack({ 278,680,21,18 });
	carExplosion.anim.PushBack({ 299,680,20,18 });
	carExplosion.anim.PushBack({ 318,680,21,18 });
	carExplosion.anim.PushBack({ 339,680,21,18 });
	carExplosion.anim.PushBack({ 359,680,21,18 });
	carExplosion.anim.PushBack({ 256,699,27,13 });
	carExplosion.anim.PushBack({ 283,699,28,13 });
	carExplosion.anim.PushBack({ 314,699,35,13 });
	carExplosion.anim.loop = false;
	carExplosion.anim.speed = 0.2;
	carExplosion.texture = 3; 
	// player 2 death

	player2_death.anim.PushBack({ 286, 35, 33, 11 });
	player2_death.anim.PushBack({ 286, 62, 32, 12 });
	player2_death.anim.PushBack({ 283, 88, 36, 15 });
	player2_death.anim.PushBack({ 277, 114, 40, 18 });
	player2_death.anim.PushBack({ 273, 140, 45, 19 });
	player2_death.anim.PushBack({ 266, 167, 51, 20 });
	player2_death.anim.PushBack({ 259, 196, 59, 21 });
	player2_death.anim.PushBack({ 319, 1, 62, 22 });
	player2_death.anim.PushBack({ 318, 29, 63, 24 });
	player2_death.anim.PushBack({ 318, 58, 63, 23 });
	player2_death.anim.PushBack({ 320, 86, 60, 23 });
	player2_death.anim.PushBack({ 321, 113, 60, 24 });
	player2_death.anim.PushBack({ 323, 143, 58, 25 });
	player2_death.anim.PushBack({ 327, 170, 54, 26 });
	player2_death.anim.PushBack({ 323, 197, 58, 27 });
	player2_death.anim.PushBack({ 383, 0, 60, 28 });
	player2_death.anim.PushBack({ 388, 28, 55, 28 });
	player2_death.anim.PushBack({ 390, 56, 54, 28 });
	player2_death.anim.PushBack({ 392, 85, 52, 27 });
	player2_death.anim.PushBack({ 394, 115, 50, 21 });
	player2_death.anim.loop = false;
	player2_death.anim.speed = 0.3f;
	player2_death.fx = 1;
	player2_death.texture = 1; 
	



	//   TANK BULLETS 

	BigTankShot.anim.PushBack({ 196, 746, 13, 13 });
	BigTankShot.anim.PushBack({ 184, 746, 13, 13 });
	BigTankShot.anim.PushBack({ 206, 762, 13, 13 });
	BigTankShot.anim.PushBack({ 237, 746, 13, 13 });
	BigTankShot.anim.speed = 0.3f;
	BigTankShot.speed.y = -3;
	BigTankShot.life = 1000;
	BigTankShot.texture = 3; 

	SmallTankShot.anim.PushBack({ 245, 831, 5, 5 });
	SmallTankShot.anim.PushBack({ 250, 831, 5, 5 });
	SmallTankShot.anim.PushBack({ 235, 831, 5, 5 });
	SmallTankShot.anim.PushBack({ 240, 831, 5, 5 });
	SmallTankShot.anim.speed = 0.3f;
	SmallTankShot.speed.x = 3;
	SmallTankShot.life = 1000;
	SmallTankShot.texture = 3; 

	CommonExplosion.anim.PushBack({ 393,0,0,16 });//													
	CommonExplosion.anim.PushBack({ 411,0,20,20 });//
	CommonExplosion.anim.PushBack({ 433,0,30,20 });//
	CommonExplosion.anim.PushBack({ 465,0,26,26 });//
	CommonExplosion.anim.PushBack({ 393,28,32,22 });//
	CommonExplosion.anim.PushBack({ 427,28,22,29 });//
	CommonExplosion.anim.PushBack({ 461,28,32,29 });//
	CommonExplosion.anim.PushBack({ 393,59,32,30 });//
	CommonExplosion.anim.PushBack({ 427,59,32,32 });//
	CommonExplosion.anim.PushBack({ 461,59,32,32 });//
	CommonExplosion.anim.PushBack({ 393,93,32,30 });//
	CommonExplosion.anim.PushBack({ 427,93,32,32 });//
	CommonExplosion.anim.PushBack({ 461,93,32,32 });//
	CommonExplosion.anim.PushBack({ 393,127,32,32 });//
	CommonExplosion.anim.loop = false;
	CommonExplosion.anim.speed = 0.5f;
	CommonExplosion.fx = 2;
	CommonExplosion.texture = 0;
	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	/*App->textures->Unload(playerPart);
	App->textures->Unload(BulletsAndLaser);
	App->textures->Unload(player2Part);
	App->textures->Unload(Car_Explosion);*/
	/*App->audio->UnloadChunk(shot);
	App->audio->UnloadChunk(player_death_sfx);
	App->audio->UnloadChunk(common_explosion_sfx);
	App->audio->UnloadChunk(player_showup_sfx);*/
	
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	for (uint i = 0; i < MAX_PART_CHUNKS; ++i)
	{
		if (chunks[i] != nullptr) {
			App->audio->UnloadChunk(chunks[i]);
			chunks[i] = nullptr; 
		}
			
	}

	for (uint i = 0; i < MAX_PART_TEXTURES; ++i) 
	{
		if (textures[i] != nullptr) {
			App->textures->Unload(textures[i]);
			textures[i] = nullptr; 
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
			App->render->Blit(textures[p->texture], p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
		
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
			AddParticle(bullet_explosion, active[i]->position.x, active[i]->position.y -3);
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
	fx(p.fx), born(p.born), life(p.life), texture(p.texture)
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