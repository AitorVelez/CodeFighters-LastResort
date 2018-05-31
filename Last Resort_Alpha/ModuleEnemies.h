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
	METAL_BEE,
	JUMPY,
	SPIDER_TANK
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

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddEnemy(ENEMY_TYPES type, int x, int y);

private:

	void SpawnEnemy(const EnemyInfo& info);

private:

	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites = nullptr;
	SDL_Texture* sprites2 = nullptr;
	SDL_Texture* sprites3 = nullptr;
};

#endif // __ModuleEnemies_H__