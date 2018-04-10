#ifndef __MODULELVL2_H__
#define __MODULELVL2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleLvl2 : public Module
{
public:
	ModuleLvl2();
	~ModuleLvl2();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * TexLvl2Image = nullptr;
	SDL_Rect Lvl2Image;
};

#endif // __MODULESTAGECLEAR_H__