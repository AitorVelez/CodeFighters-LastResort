#include "Globals.h"
#include "Application.h"
#include "SDL_mixer\include\SDL_mixer.h"
#include "ModuleAudio.h"

ModuleAudio::ModuleAudio() : Module()
{
	Mix_LoadMUS("last resort wav music/02 - Jack to the Metro (Stage 1) - Last Resort (SNK Neo Geo) - OST - NeoGeo.ogg");
	//Mix_PlayMusic(Mix_Music "", 2);
}

ModuleAudio::~ModuleAudio()
{}