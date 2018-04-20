#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePowerUp.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Powerup.h"
#include "LPower.h"

#define SPAWN_MARGIN 50

ModulePowerUp::ModulePowerUp()
{
	for (uint i = 0; i < MAX_POWERUPS; ++i)
		powerups[i] = nullptr;
}

// Destructor
ModulePowerUp::~ModulePowerUp()
{
}

bool ModulePowerUp::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->textures->Load("assets/sprites/common_enemies1.png");


	return true;
}

update_status ModulePowerUp::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (queue[i].type != POWERUP_TYPES::NO_POWER_TYPE)
		{
			if (-queue[i].x * SCREEN_SIZE > App->render->camera.x - (App->render->camera.w * SCREEN_SIZE) - SPAWN_MARGIN)
			{
				SpawnPowerup(queue[i]);
				queue[i].type = POWERUP_TYPES::NO_POWER_TYPE;
				LOG("Spawning enemy at %d", queue[i].x * SCREEN_SIZE);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModulePowerUp::Update()
{
	/*for (uint i = 0; i < MAX_POWERUPS; ++i)
		if (powerups[i] != nullptr) powerups[i]->Move();*/

	for (uint i = 0; i < MAX_POWERUPS; ++i)
		if (powerups[i] != nullptr) powerups[i]->Draw(sprites);

	return UPDATE_CONTINUE;
}

update_status ModulePowerUp::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (powerups[i] != nullptr)
		{
			if (- powerups[i]->position.x * SCREEN_SIZE >(App->render->camera.x) + SPAWN_MARGIN * 2)
			{
				LOG("DeSpawning enemy at %d", powerups[i]->position.x * SCREEN_SIZE);
				delete powerups[i];
				powerups[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModulePowerUp::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(sprites);

	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (powerups[i] != nullptr)
		{
			delete powerups[i];
			powerups[i] = nullptr;
		}
	}

	return true;
}

bool ModulePowerUp::AddPowerup(POWERUP_TYPES type, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (queue[i].type == POWERUP_TYPES::NO_POWER_TYPE)
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

void ModulePowerUp::SpawnPowerup(const PowerupInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for (; powerups[i] != nullptr && i < MAX_POWERUPS; ++i);

	if (i != MAX_POWERUPS)
	{
		switch (info.type)
		{
		case POWERUP_TYPES::LPOWER:
			powerups[i] = new LaserPowerUp(info.x, info.y);
			break;
		}
	}

}


void ModulePowerUp::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_POWERUPS; ++i)
	{
		if (powerups[i] != nullptr && powerups[i]->GetCollider() == c1)
		{
			powerups[i]->OnCollision(c2);
			delete powerups[i];
			powerups[i] = nullptr;
			break;
		}
	}
}