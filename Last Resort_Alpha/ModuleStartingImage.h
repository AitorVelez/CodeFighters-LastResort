#ifndef __MODULESTARTINGIMAGE_H__
#define __MODULESTARTINGIMAGE_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct Mix_Music;



class ModuleStartingImage : public Module
{
public:
	ModuleStartingImage();
	~ModuleStartingImage();

	bool Start();
	update_status Update();
	bool CleanUp();
	unsigned int lastTime = 0;
	unsigned int currentTime=0;
	


public:
	SDL_Texture* Starts = nullptr;
	SDL_Texture * TexStImage = nullptr;

	SDL_Texture* TitleTex1 = nullptr;
	SDL_Texture* TitleTex2 = nullptr;
	SDL_Texture* TitleTex3 = nullptr;
	SDL_Texture* TitleTex4 = nullptr;
	SDL_Texture* TitleTex5 = nullptr;
	SDL_Texture* TitleTex6 = nullptr;
	SDL_Texture* TitleTex7 = nullptr;
	SDL_Texture* TitleTex8 = nullptr;
	SDL_Texture* TitleTex9 = nullptr;
	SDL_Texture* TitleTex10 = nullptr;
	SDL_Texture* TitleTex11 = nullptr;
	SDL_Texture* TitleTex12 = nullptr;
	SDL_Texture* TitleTex13 = nullptr;
	SDL_Texture* TitleTex14 = nullptr;
	SDL_Texture* TitleTex15 = nullptr;
	SDL_Texture* TitleTex16 = nullptr;
	SDL_Texture* TitleTex17 = nullptr;


	Animation Press;
	Animation Title1;
	Animation Title2;
	Animation Title3;
	Animation Title4;
	Animation Title5;
	Animation Title6;
	Animation Title7;
	Animation Title8;
	Animation Title9;
	Animation Title10;
	Animation Title11;
	Animation Title12;
	Animation Title13;
	Animation Title14;
	Animation Title15;
	Animation Title16;
	Animation Title17;

	SDL_Rect StImage;
	Mix_Music* mus = nullptr;


	bool PlayerLifeReset = false; 
};

#endif // __MODULESTARTINGIMAGE_H__