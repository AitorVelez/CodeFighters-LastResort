#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"
//#include "Enemy_Cockroach.h"

#define MAX_ENEMIES 500 //200

// TODO 2: Add a new enemy: Brown Cookies!

// TODO 3: Have the Brown Cookies describe a path in the screen

// TODO 4: Create a new enemy type: the Mech

enum ENEMY_TYPES
{
	NO_TYPE,
	COCKROACH,
	RHINO,	
	BLUE_CAR,
	RED_CAR,
	YELLOW_CAR,
	TANK,
	LAMELLA,
	RED_LAMELLA,
	TURRET,
	BARREL,
	HUNTER,
	HUNTER_ZIGZAG,
	HUNTER_ZIGZAG_DOWN,
	METAL_BEE,
	JUMPY,
	SPIDER_TANK,
	ROCKET,
	GUSTAV,
	BOSS,
	BOSSFIRE,
	GRENADE,
	GRENADEP2,
	HELLFIRE,
	HELLFIREP2,
	JUMPYRIDER,
	JUMPYRIDER2
};

class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
	int HP; 
};

class ModuleEnemies : public Module
{
public:

	ModuleEnemies();
	~ModuleEnemies();
	float dirx;
	float diry;
	float hyp;
	float proximx;
	float proximy;
	float proxim;
	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);
	void ForcedDeath(); 
	float nearbyenemyx(float x, float y);
	float nearbyenemyy(float x, float y);
	bool AddEnemy(ENEMY_TYPES type, int x, int y);

	Enemy* enemies[MAX_ENEMIES];

	bool BossFlameDespawn = false; 
	bool BOSSHASSPAWNED = false; 

private:

	void SpawnEnemy(const EnemyInfo& info);
	
private:

	EnemyInfo queue[MAX_ENEMIES];
	
	SDL_Texture* sprites = nullptr;
	SDL_Texture* sprites2 = nullptr;
	SDL_Texture* sprites3 = nullptr;
	SDL_Texture* sprites4 = nullptr;
	SDL_Texture* sprites5 = nullptr;
	SDL_Texture* sprites6 = nullptr;
	SDL_Texture* sprites7 = nullptr;
};

#endif // __ModuleEnemies_H__