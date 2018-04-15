#ifndef __ModuleBackground_H__
#define __ModuleBackground_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Music; 
struct Collider;

class ModuleBackground : public Module
{
public:
	ModuleBackground();
	~ModuleBackground();

	bool Start();
	update_status Update();
	bool CleanUp(); 

	void MoveUp();
	void MoveCameraUp();
	void MoveDown();
	void MoveCameraDown();
	void CameraOscillation(int since, int to, bool up); 
	void CameraOscillationShake(int since, int to, bool up);
	void RenderCrater();

	void RenderBackgroundSpaceships(); 
	void RenderDeepBuildingLights(); 
	void RenderBuildingLights(); 
	void RenderDiscoLights(); 
	void RenderStreetLights(); 
	void RenderTunnelLights();
	void RenderEnemyTest();
	void RenderEnemyColliders();

	

public:
	
	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr; 
	SDL_Texture* graphics3 = nullptr;
	SDL_Texture* graphics4 = nullptr;
	SDL_Texture* graphics5 = nullptr;
	SDL_Texture* graphics6 = nullptr;
	SDL_Texture* graphics7 = nullptr;
	SDL_Texture* graphics8 = nullptr;
	SDL_Texture* graphics9 = nullptr;

	Mix_Music* mus = nullptr; 

	SDL_Rect background;
	SDL_Rect crater;
	SDL_Rect building_1; 
	SDL_Rect building_2; 

	Animation backgroundLights;
	Animation streetLights;
	Animation streetLights_2; 	
	Animation lightFloor;
	Animation lightFloor_2;
	Animation light;	
	Animation lightNew;
	Animation tunnelLights;
	Animation tunnelLights_2;
	Animation DeepBackgroundLights;
	Animation DeepBackgroundLights2;
	Animation MidBackgroundLights;
	Animation MidBackgroundLights2;
	Animation MidBackgroundLights3;
	Animation ships;
	Animation EnemyTest;

	Collider *EnemyCollider = nullptr;

	float posx = -200;
	float posxx = -200;
	
	int enposx = 450;
	bool render_light = false;
	bool scroll = true; 
	float depth_1;
	float depth_2;
	float depth_3; 
};

#endif
