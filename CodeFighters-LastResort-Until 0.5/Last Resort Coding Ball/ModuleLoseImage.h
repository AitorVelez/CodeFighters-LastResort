#ifndef __MODULELOSEIMAGE_H__
#define __MODULELOSEIMAGE_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Music;

class ModuleLoseImage : public Module
{
public:
	ModuleLoseImage();
	~ModuleLoseImage();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * TexLoseImage = nullptr;
	SDL_Rect LoseImage;
	Mix_Music* LoseMus = nullptr;

};

#endif // __MODULESTARTINGIMAGE_H__