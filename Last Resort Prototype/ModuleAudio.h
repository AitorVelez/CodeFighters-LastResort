#ifndef __MODULEAUDIO_H__
#define __MODULEAUDO_H__

#include "Module.h"
#include "Globals.h"


struct Mix_Music;
struct Mix_Chunk;

class ModuleAudio : public Module {

public:

	bool Init();
	bool CleanUp();

	Mix_Music* LoadMus(const char* path);
	void PlayMus(Mix_Music* mus);
	
	Mix_Chunk* LoadChunk(const char* path);
	void PlayChunk(Mix_Chunk* chunk, int times);

};

#endif //_MODULEAUDIO_H__
