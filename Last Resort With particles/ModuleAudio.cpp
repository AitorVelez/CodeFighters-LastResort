#include "ModuleAudio.h"
#include "Application.h"
#include "SDL_mixer\include\SDL_mixer.h"
#pragma comment ( lib, "SDL_mixer/libx86/SDL2_mixer.lib")


bool ModuleAudio::Init()
{
	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2049);
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
	Mix_PlayMusic(mus, -1);
}

bool ModuleAudio::UnloadMus(Mix_Music* mus)
{
	bool ret = true; 
	Mix_FreeMusic(mus);
	if (mus != nullptr) {
		LOG("Could not unload the music properly");
		ret = false; 
	}
	return ret; 
}

Mix_Chunk * ModuleAudio::LoadChunk(const char * path)
{
	Mix_Chunk* chunky = nullptr; 
	chunky = Mix_LoadWAV(path);
	if (chunky == nullptr)
		LOG("There was a problem loading the chunk.");

	return chunky;
}

void ModuleAudio::PlayChunk(Mix_Chunk * chunk, int times)
{
	Mix_PlayChannel(-1, chunk, times-1);
}

bool ModuleAudio::UnloadChunk(Mix_Chunk* chunk)
{
	bool ret = true; 

	Mix_FreeChunk(chunk);
	if (chunk != nullptr)
	{
		LOG("Could not unload the chunk properly");
		ret = false;
	}
	return ret; 
}
