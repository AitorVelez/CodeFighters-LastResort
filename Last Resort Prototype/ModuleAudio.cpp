#include "ModuleAudio.h"
#include "Application.h"
#include "SDL_mixer\include\SDL_mixer.h"
#pragma comment ( lib, "SDL_mixer/libx86/SDL2_mixer.lib")


bool ModuleAudio::Init()
{
	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(60000, MIX_DEFAULT_FORMAT, 2, 2500);
	return true;
}


bool ModuleAudio::CleanUp()
{
	Mix_Quit(); 
	Mix_CloseAudio();
	return false;
}

Mix_Music* ModuleAudio::LoadMus(const char * path)
{
	Mix_Music* mus = NULL;
	mus = Mix_LoadMUS(path);
	if (mus == NULL)
		LOG("There was a problem loading a OGG");

	return mus; 
}

void ModuleAudio::PlayMus(Mix_Music* mus)
{
	Mix_PlayMusic(mus, 1);
}
