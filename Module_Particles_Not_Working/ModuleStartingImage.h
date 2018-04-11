#ifndef __MODULESTARTINGIMAGE_H__
#define __MODULESTARTINGIMAGE_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

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


};

#endif // __MODULESTARTINGIMAGE_H__