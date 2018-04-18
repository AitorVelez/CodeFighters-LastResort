#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

#define MAX_ACTIVE_PARTICLES 100

struct SDL_Texture;
struct Collider;
struct Mix_Chunk; 
enum COLLIDER_TYPE;

struct Particle
{
	Collider* collider = nullptr;
	Animation anim;
	uint fx = -1;
	iPoint position;
	iPoint speed;
	Uint32 born = 0;
	Uint32 life = 0;
	
	bool fx_played = false;

	Particle();
	Particle(const Particle& p);
	~Particle();
	bool Update();
};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	void AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type = COLLIDER_NONE, Uint32 delay = 0);

private:

	SDL_Texture * playerPart = nullptr;
	SDL_Texture *BulletsAndLaser = nullptr;
	Particle* active[MAX_ACTIVE_PARTICLES];
	uint last_particle = 0;
	SDL_Texture * player2Part = nullptr;
public:

	Particle player_death;
	Particle CommonExplosion;
	Particle SpaceshipAnim;
	Particle bullet;
	Particle bulletEx;
	Particle player2_death;

	Mix_Chunk* shot = nullptr; 
	Mix_Chunk* player_death_sfx = nullptr; 
};

#endif // __MODULEPARTICLES_H__