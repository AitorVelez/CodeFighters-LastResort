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

public:

	SDL_Texture * TexNeoGeoImage = nullptr;
	SDL_Rect StImage;
	Mix_Music* mus = nullptr;

};

#endif // __MODULEINTRONEOGEO_H__