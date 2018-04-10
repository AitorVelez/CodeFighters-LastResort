#ifndef __MODULESTAGECLEAR_H__
#define __MODULESTAGECLEAR_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleStageClear : public Module
{
public:
	ModuleStageClear();
	~ModuleStageClear();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * TexStageImage = nullptr;
	SDL_Rect StageImage;
};

#endif // __MODULESTAGECLEAR_H__