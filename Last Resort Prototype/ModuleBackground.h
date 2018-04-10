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
	void RenderDiscoLights(); 
	void RenderStreetLights(); 

public:
	
	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr; 
	SDL_Texture* graphics3 = nullptr;
	SDL_Texture* graphics4 = nullptr;
<<<<<<< HEAD
=======

>>>>>>> 75a373bf08888d78bff3981053c0cc0a169ecf26
	Mix_Music* mus = nullptr; 

	SDL_Rect background;
	SDL_Rect crater;
	SDL_Rect building_1; 
	SDL_Rect building_2; 

	Animation backgroundLights;
	Animation streetLights;
	Animation streetLights_2; 
	Animation light;	
	Animation lightNew;
	Animation lightFloor;
<<<<<<< HEAD
	Animation tunnelLights;
=======
	Animation Ships;
>>>>>>> 75a373bf08888d78bff3981053c0cc0a169ecf26

	bool render_light = false;
	bool scroll = true; 
};

#endif
