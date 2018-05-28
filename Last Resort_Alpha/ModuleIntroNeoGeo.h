#ifndef __MODULEINTRONEOGEO_H__
#define __MODULEINTRONEOGEO_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Music;

class ModuleIntroNeoGeo : public Module
{
public:
	ModuleIntroNeoGeo();
	~ModuleIntroNeoGeo();

	bool Start();
	update_status Update();
	bool CleanUp();
	unsigned int lastTime = 0;
	unsigned int currentTime = 0;

public:

	SDL_Texture * TexNeoGeoImage = nullptr;
	SDL_Texture* NeoGeoTex1 = nullptr;
	SDL_Texture* NeoGeoTex2 = nullptr;
	SDL_Texture* NeoGeoTex3 = nullptr;
	SDL_Texture* NeoGeoTex4 = nullptr;
	SDL_Texture* NeoGeoTex5 = nullptr;
	SDL_Texture* NeoGeoTex6 = nullptr;
	SDL_Texture* NeoGeoTex7 = nullptr;
	SDL_Texture* NeoGeoTex8 = nullptr;
	SDL_Texture* NeoGeoTex9 = nullptr;

	Animation Title1;
	Animation Title2;
	Animation Title3;
	Animation Title4;
	Animation Title5;
	Animation Title6;
	Animation Title7;
	Animation Title8;
	Animation Title9;


	SDL_Rect NeoGeoImage;
	Mix_Music* mus = nullptr;

};

#endif // __MODULEINTRONEOGEO_H__