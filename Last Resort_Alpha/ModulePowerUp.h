#ifndef __ModulePowerUp_H__
#define __ModulePowerUp_H__

#include "Module.h"


#define MAX_POWERUPS 150



enum POWERUP_TYPES
{
	NO_POWER_TYPE,
	LPOWER,
	SPOWER,
	GPOWER,
	HPOWER

};

class Powerup;

struct PowerupInfo
{
	POWERUP_TYPES type = POWERUP_TYPES::NO_POWER_TYPE;
	int x, y;
};

class ModulePowerUp : public Module
{
public:

	ModulePowerUp();
	~ModulePowerUp();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);
	
	bool AddPowerup(POWERUP_TYPES type, int x, int y);

private:

	void SpawnPowerup(const PowerupInfo& info);

private:

	PowerupInfo queue[MAX_POWERUPS];
	Powerup* powerups[MAX_POWERUPS];
	SDL_Texture* sprites = nullptr;
	SDL_Texture* sprites2 = nullptr;
};

#endif // __ModulePowerUp_H__