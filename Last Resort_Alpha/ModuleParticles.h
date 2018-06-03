#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

#define MAX_ACTIVE_PARTICLES 1000 //50
#define MAX_PART_CHUNKS 50
#define MAX_PART_TEXTURES 20

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
	fPoint speed;
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
	uint explosion;
	uint finished;
	bool TNT = true;

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);
	void UnderWater();
	void AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type = COLLIDER_NONE, Uint32 delay = 0);

private:

	SDL_Texture *BulletsAndLaser = nullptr;
	/*SDL_Texture *bubbles = nullptr;*/
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
	Particle bullet_laser;
	Particle firing_laser;
	Particle bullet_laser2;
	Particle ball_bullet; 
	Particle bullet_laser2_1;
	Particle Charging_Ball;
	Particle Releasing_Ball;
	Particle Bubbles;
	Particle Underwater_splash;
	Particle MisileSpidy;
	Particle GPower; 

	Particle pilot_dying;
	Particle BigTankShot; 
	Particle SmallTankShot; 
	Particle TurretShot;
	Particle BossGreenShot; 
	Particle PreBossGreenShot;
	Particle PreBossGreenShot2;
	Particle PreBossGreenShot3;

	Particle Red_Car_Explosion;
	Particle Blue_Car_Explosion;
	Particle Yellow_Car_Explosion;

	Particle Fire; 

	SDL_Texture* textures[MAX_PART_TEXTURES];
	Mix_Chunk* chunks[MAX_PART_CHUNKS];
	
};

#endif // __MODULEPARTICLES_H__