#ifndef __ModuleUI_H__
#define __ModuleUI_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"



class ModuleUI : public Module

{
public:

	ModuleUI();
	~ModuleUI();

	bool Start();
	update_status Update();
	bool CleanUp();


public:

	int font_score = -1;
	char score_text[10];
	


};

#endif

