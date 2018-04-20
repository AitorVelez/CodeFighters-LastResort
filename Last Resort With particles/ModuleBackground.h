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

	// Camera movements
	void CameraUpDown();
	void MoveUp();
	void MoveDown();
	void CameraOscillation(int since, int to, bool up); 
	void NotScrolling(int since, int to); 

	// Renders
	void RenderCrater();
	void RenderBackgroundSpaceships(); 
	void RenderDeepBuildingLights(); 
	void RenderBuildingLights(); 
	void RenderDiscoLights(); 
	void RenderStreetLights(); 
	void RenderTunnelLights();
	void RenderPowerUps();
	

public:
	
	SDL_Texture* BackgroundLvl1 = nullptr;
	SDL_Texture* BackgroundLvl1_extra = nullptr; 
	SDL_Texture* StreetLightsTex = nullptr;
	SDL_Texture* TunnelLightsTex = nullptr;
	SDL_Texture* BackgroundSpaceshipLvl1 = nullptr;
	SDL_Texture* BackLights = nullptr;
	SDL_Texture* BackLights2 = nullptr;
	SDL_Texture* BackLights3 = nullptr;
	SDL_Texture* PowerupTex = nullptr;

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
	Animation powerupL;

	bool activ = false;
	float background_spaceship_posx = 0;
	int craterx = 0;
	int cratery = 0;
	int falscamara = 0;
	bool render_light = false;
	bool scroll = true; 
	float depth_1;
	float depth_2;
	float depth_3; 
	bool downscroll = false; 
    bool notscrolling = true;
	bool upscroll = false;
	int bgpos; 
};

#endif
