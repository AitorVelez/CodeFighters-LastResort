#ifndef __ModuleUI_H__
#define __ModuleUI_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleUI : public Module

{
public:

	ModuleUI();
	~ModuleUI();

	bool Start();
	update_status Update();
	bool CleanUp();


public:

	Animation Player2;
	int font_score = -1;
	char score_text[10];
	SDL_Texture * P2 = nullptr;
	SDL_Texture * UIS = nullptr;
	bool ready = false;
	SDL_Rect UIstable;
	char * score;
	int sflag;


};

#endif
