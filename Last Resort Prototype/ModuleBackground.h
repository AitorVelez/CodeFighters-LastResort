#ifndef __ModuleBackground_H__
#define __ModuleBackground_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Music; 

class ModuleBackground : public Module
{
public:
	ModuleBackground();
	~ModuleBackground();

	bool Start();
	update_status Update();
	bool CleanUp(); 
	void MoveUp();
	void MoveDown();
	void CameraScroll(); 
	void RenderLights(); 

public:
	
	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr; 
	SDL_Texture* graphics3 = nullptr;
	Mix_Music* mus = nullptr; 
	SDL_Rect background;
	SDL_Rect crater;
	SDL_Rect building_1; 
	SDL_Rect building_2; 
	Animation backgroundLights;
	Animation streetLights;
	Animation light;	
	Animation lightNew;

	bool render_light = false;
	bool scroll = true; 
};

#endif
