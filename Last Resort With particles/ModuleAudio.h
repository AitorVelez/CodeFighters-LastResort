#ifndef __MODULEAUDIO_H__
#define __MODULEAUDO_H__

#include "Module.h"
#include "Globals.h"


struct Mix_Music;
struct Mix_Chunk;

enum audio_status{
	AUDIO_OUT,
	AUDIO_PLAY,
	AUDIO_UNLOAD
};

class ModuleAudio : public Module {

public:

	bool Init();
	bool CleanUp();

	Mix_Music* LoadMus(const char* path);
	void PlayMus(Mix_Music* mus);
	bool UnloadMus(Mix_Music* mus);
	void FadeMus(int time); 

	Mix_Chunk* LoadChunk(const char* path);
	void PlayChunk(Mix_Chunk* chunk, int times);
	bool UnloadChunk(Mix_Chunk* chunk); 

};

#endif //_MODULEAUDIO_H__
