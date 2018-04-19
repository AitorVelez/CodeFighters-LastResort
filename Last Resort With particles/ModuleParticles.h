#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

#define MAX_ACTIVE_PARTICLES 100
#define MAX_PART_CHUNKS 25
#define MAX_PART_TEXTURES 10

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
	uint texture = -1; 
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

	SDL_Texture *BulletsAndLaser = nullptr;
	Particle* active[MAX_ACTIVE_PARTICLES];
	uint last_particle = 0;
	
public:

	Particle player_death;
	Particle CommonExplosion;
	Particle SpaceshipAnim;
	Particle bullet;
	Particle bullet_propulsion;
	Particle player2_death;
	Particle bullet_explosion; 

	Particle BigTankShot; 
	Particle SmallTankShot; 

	Particle carExplosion;

	/*SDL_Texture * player2Part = nullptr;
	SDL_Texture* Car_Explosion;
	SDL_Texture * playerPart = nullptr;*/


	/*Mix_Chunk* shot = nullptr;
	Mix_Chunk* player_death_sfx = nullptr;
	Mix_Chunk* common_explosion_sfx = nullptr;
	Mix_Chunk* player_showup_sfx = nullptr;*/

	SDL_Texture* textures[MAX_PART_TEXTURES];
	Mix_Chunk* chunks[MAX_PART_CHUNKS];
	
};

#endif // __MODULEPARTICLES_H__