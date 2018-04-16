#ifndef __MODULESTARTINGIMAGE_H__
#define __MODULESTARTINGIMAGE_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Music;

class ModuleStartingImage : public Module
{
public:
	ModuleStartingImage();
	~ModuleStartingImage();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * TexStImage = nullptr;
	SDL_Rect StImage;
	Mix_Music* mus = nullptr;

};

#endif // __MODULESTARTINGIMAGE_H__