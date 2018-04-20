#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"
//#include "Enemy_Cockroach.h"

#define MAX_ENEMIES 300

// TODO 2: Add a new enemy: Brown Cookies!

// TODO 3: Have the Brown Cookies describe a path in the screen

// TODO 4: Create a new enemy type: the Mech

enum ENEMY_TYPES
{
	NO_TYPE,
	COCKROACH,
	RHINO,	
	LAMELLA,
	BLUE_CAR,
	RED_CAR,
	YELLOW_CAR,
	TANK,
	POWERUP,
};

class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
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
	SDL_Texture* sprites;
	SDL_Texture* sprites2;
};

#endif // __ModuleEnemies_H__