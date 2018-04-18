#ifndef __MODULEAUDIO_H__
#define __MODULEAUDO_H__

#include "Module.h"
#include "Globals.h"

#define MAX_MUSICS 5
#define MAX_CHUNKS 20

struct Mix_Music;
struct Mix_Chunk;

class ModuleAudio : public Module {

public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool CleanUp();

	Mix_Music* LoadMus(const char* path);
	void PlayMus(Mix_Music* mus);
	bool UnloadMus(Mix_Music* mus);
	void FadeMus(int time); 

	Mix_Chunk* LoadChunk(const char* path);
	void PlayChunk(Mix_Chunk* chunk, int times);
	bool UnloadChunk(Mix_Chunk* chunk); 
	
public: 
	Mix_Music* musics[MAX_MUSICS];
	int last_music = 0;
	Mix_Chunk* chunks[MAX_CHUNKS];
	int last_chunk = 0; 

};

#endif //_MODULEAUDIO_H__
