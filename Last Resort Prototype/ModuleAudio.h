#ifndef __MODULEAUDIO_H__
#define __MODULEAUDO_H__

#include "Module.h"
#include "Globals.h"


struct Mix_Music;

class ModuleAudio : public Module {

public:

	bool Init();
	bool CleanUp();

	Mix_Music* LoadMus(const char* path);
	void PlayMus(Mix_Music* mus);

};

#endif //_MODULEAUDIO_H__
