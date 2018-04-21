#include "ModuleUI.h"
#include "Globals.h"
#include "ModuleFonts.h"
#include "Application.h"


ModuleUI::ModuleUI()

{



}

ModuleUI::~ModuleUI()
{}

bool ModuleUI::Start(){
	LOG("Loading UI");

	font_score = App->Fonts->Load("assets/sprites/chars2.png", "0123456789A", 1);




	return true;
}

bool ModuleUI::CleanUp()
{
	LOG("Unloading player");

	
	App->Fonts->UnLoad(font_score);
	

	return true;
}


update_status ModuleUI::Update()
{


	App->Fonts->BlitText(50, 120, 0, "123456789");


	return UPDATE_CONTINUE;
}