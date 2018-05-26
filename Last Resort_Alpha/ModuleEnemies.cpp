#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "Enemy.h"
#include "Enemy_Cockroach.h"
#include "Enemy_Rhino.h"
#include "Enemy_Lamella.h"
#include "Blue_Car.h"
#include "Red_Car.h"
#include "ModulePlayer2.h"
#include "Yellow_Car.h"
#include "Enemy_Tank.h"
#include "Enemy_RedLamella.h"
#include "Enemy_Turret.h"
#include "Enemy_Barrel.h"
#include "Enemy_Hunter.h"
#include "Enemy_Metal_Bee.h"
#define SPAWN_MARGIN 50

ModuleEnemies::ModuleEnemies()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->textures->Load("assets/sprites/common_enemies1.png");
	sprites2 = App->textures->Load("assets/sprites/CommonEnemies2.png");
	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
				LOG("Spawning enemy at %d", queue[i].x * SCREEN_SIZE);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Move();

	for (uint i = 0; i < MAX_ENEMIES; ++i) {
		if (enemies[i] != nullptr) { enemies[i]->Draw(sprites); }
		if (enemies[i] != nullptr) { enemies[i]->Draw2(sprites2); }
	}
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Shoot();

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(sprites);
	App->textures->Unload(sprites2);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for (; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if (i != MAX_ENEMIES)
	{
		switch (info.type)
		{
		case ENEMY_TYPES::COCKROACH:
			enemies[i] = new Enemy_Cockroach(info.x, info.y, info.HP);
			break;

		case ENEMY_TYPES::RHINO:
			enemies[i] = new Enemy_Rhino(info.x, info.y, info.HP);
			break;
		case ENEMY_TYPES::BLUE_CAR:
			enemies[i] = new Blue_Car(info.x, info.y, info.HP);
			break;
		case ENEMY_TYPES::RED_CAR:
			enemies[i] = new Red_Car(info.x, info.y, info.HP);
			break;
		case ENEMY_TYPES::YELLOW_CAR:
			enemies[i] = new Yellow_Car(info.x, info.y, info.HP);
			break;
		case ENEMY_TYPES::TANK:
			enemies[i] = new Enemy_Tank(info.x, info.y, info.HP);
			break;
		case ENEMY_TYPES::LAMELLA:
			enemies[i] = new Enemy_Lamella(info.x, info.y, info.HP);
			break;
	
		case ENEMY_TYPES::RED_LAMELLA:
			enemies[i] = new Enemy_RedLamella(info.x, info.y, info.HP);
			break;
		case ENEMY_TYPES::TURRET:
			enemies[i] = new Enemy_Turret(info.x, info.y, info.HP);
			break;

		case ENEMY_TYPES::BARREL:
			enemies[i] = new Enemy_Barrel(info.x, info.y, info.HP);
			break;
		case ENEMY_TYPES::HUNTER:
			enemies[i] = new Enemy_Hunter(info.x, info.y, info.HP);
			break;
		case ENEMY_TYPES::METAL_BEE:
			enemies[i] = new Enemy_Metal_Bee(info.x, info.y, info.HP);
			break;
		}
	}
	
}


void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			enemies[i]->OnCollision(c2);
			if (enemies[i]->hp <= 0) {			// IF HP <= 0 DELETE
				delete enemies[i];    
				if (c2->type == COLLIDER_PLAYER_SHOT || c2->type == COLLIDER_BALL) App->player->score_p1 += 100;
				else if (c2->type == COLLIDER_PLAYER2_SHOT || c2->type == COLLIDER_BALL2) App->player2->score_p2 += 100; 
				enemies[i] = nullptr;
			}
			break;
		}
	}
}