#include "ModuleAudio.h"
#include "Application.h"
#include "SDL_mixer\include\SDL_mixer.h"
#pragma comment ( lib, "SDL_mixer/libx86/SDL2_mixer.lib")


ModuleAudio::ModuleAudio()
{
	for (int i = 0; i < MAX_MUSICS; ++i) {
		musics[i] = nullptr;
	}
	for (int i = 0; i < MAX_CHUNKS; ++i) {
		chunks[i] = nullptr; 
	}
}

ModuleAudio::~ModuleAudio()
{
}

bool ModuleAudio::Init()
{
	LOG("Init Audio library");
	bool ret = true;

	int flags = MIX_INIT_OGG;
	int init = Mix_Init(flags);

	if ((init & flags) != flags)
	{
		LOG("Could not initialize Audio lib. Mix_Init: %s", Mix_GetError());
		ret = false;
	}

	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2049);
	return ret;
}

bool ModuleAudio::CleanUp()
{
	Mix_Quit(); 
	Mix_CloseAudio();
	return false;
}

Mix_Music* ModuleAudio::LoadMus(const char * path)
{
	Mix_Music* music = NULL;
	music = Mix_LoadMUS(path);

	if (music == NULL)
	{
		LOG("Could not load music with path: %s. Mus_Load: %s", path, Mix_GetError());
	}
	else
	{
		bool room = false;
		for (int i = 0; i < MAX_MUSICS; ++i)
			{
				if (musics[i] == nullptr)
				{
					musics[i] = music;
					room = true;
					break;
				}
			}
			if (room == false)
				LOG("Music buffer overflow")
	}
	return music;
}

void ModuleAudio::PlayMus(Mix_Music* mus)
{
	Mix_PlayMusic(mus, -1);
}

bool ModuleAudio::UnloadMus(Mix_Music* mus)
{
	bool ret = false; 
	if (mus != nullptr) {
		for (int i = 0; i < MAX_MUSICS; ++i)
		{
			if (musics[i] == mus)
			{		
				Mix_FreeMusic(musics[i]);
				musics[i] = nullptr;
				ret = true;
				LOG("Could unload the music properly");
				break;
			}
		}
	}

	return ret; 
}

void ModuleAudio::FadeMus(int time)
{
	Mix_FadeOutMusic(time);
}

Mix_Chunk * ModuleAudio::LoadChunk(const char * path)
{
	
	Mix_Chunk* chunk = NULL;
	chunk = Mix_LoadWAV(path);

	if (chunk == NULL)
	{
		LOG("Could not load chunk with path: %s. Mus_Load: %s", path, Mix_GetError());
	}
	else
	{
		bool room = false;
		for (int i = 0; i < MAX_CHUNKS; ++i)
		{
			if (chunks[i] == nullptr)
			{
				chunks[i] = chunk;
				room = true;
				break;
			}
		}
		if (room == false)
			LOG("Chunks buffer overflow")
	}
	return chunk;

}

void ModuleAudio::PlayChunk(Mix_Chunk * chunk, int times)
{
	Mix_PlayChannel(-1, chunk, times-1);
}

bool ModuleAudio::UnloadChunk(Mix_Chunk* chunk)
{
	/*bool ret = true; 

	Mix_FreeChunk(chunk);

	return ret; */

	bool ret = false;
	if (chunk != nullptr) {
		for (int i = 0; i < MAX_MUSICS; ++i)
		{
			if (chunks[i] == chunk)
			{		
				Mix_FreeChunk(chunks[i]);
				chunks[i] = nullptr;
				ret = true;
				LOG("Could unload the chunk properly");
				break;
			}
		}
	}
	if (ret = false) LOG("The chunk passed to unload is empty"); 

	return ret;

}
