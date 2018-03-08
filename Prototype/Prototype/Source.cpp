#include "..\SDL\include\SDL.h"
#include "..\SDL_Image\include\SDL_image.h"
#include "..\SDL_Mixer\include\SDL_mixer.h"
#include <iostream>

#pragma comment (lib, "SDL2.lib")
#pragma comment (lib, "SDL2main.lib")
#pragma comment (lib, "SDL2_Image.lib")
#pragma comment (lib, "SDL2_mixer.lib")

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 760
#define SPEED 7
#define PLAYER_SIZE 75
#define BULLET_SPEED 20
#define AMMO 5
#define BULLET_SIZE 10


struct projectile {

	int x, y;
	bool alive = false;

};

struct globals {

	SDL_Window* window = nullptr;

	SDL_Renderer* renderer = nullptr;

	SDL_Surface* surface = nullptr;
	SDL_Texture* background = nullptr;
	SDL_Texture* character = nullptr;
	SDL_Texture* fireball = nullptr;

	Mix_Chunk* fx_shot = nullptr;
	Mix_Music* music = nullptr;
	SDL_Rect player{ 300, SCREEN_HEIGHT / 2,PLAYER_SIZE,PLAYER_SIZE };
	projectile shots[AMMO];
	int last_shot = 0;

	bool up, down, right, left, fire = false;
}g;


void Start() {

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	Mix_Init(MIX_INIT_OGG);

	g.window = SDL_CreateWindow("My Super Awesome Game",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);

	g.renderer = SDL_CreateRenderer(g.window, -1, SDL_RENDERER_PRESENTVSYNC);


	//IMAGE SETTINGS


	g.surface = IMG_Load("assets/background.png");
	g.background = SDL_CreateTextureFromSurface(g.renderer, g.surface);
	SDL_FreeSurface(g.surface);

	g.surface = IMG_Load("assets/mario.png");
	g.character = SDL_CreateTextureFromSurface(g.renderer, g.surface);
	SDL_FreeSurface(g.surface);

	g.surface = IMG_Load("assets/fireball.png");
	g.fireball = SDL_CreateTextureFromSurface(g.renderer, g.surface);
	SDL_FreeSurface(g.surface);


	//SOUND SETTINGS

	Mix_OpenAudio(25000, MIX_DEFAULT_FORMAT, 2, 2500);

	g.fx_shot = Mix_LoadWAV("assets/laser.WAV");
	g.music = Mix_LoadMUS("assets/background_music.ogg");
	Mix_PlayMusic(g.music, -1);
}


void Finish() {

	//IMAGE QUIT

	SDL_DestroyTexture(g.background);
	SDL_DestroyTexture(g.character);
	SDL_DestroyTexture(g.fireball);
	IMG_Quit();

	//SOUND QUIT

	Mix_FreeChunk(g.fx_shot);
	Mix_FreeMusic(g.music);
	Mix_CloseAudio();
	Mix_Quit();

	// SDL QUIT

	SDL_DestroyRenderer(g.renderer);
	SDL_DestroyWindow(g.window);
	SDL_Quit();
}


bool Check_Input() {
	bool exit = false;
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				g.up = false;
				break;
			case SDLK_DOWN:
				g.down = false;
				break;
			case SDLK_RIGHT:
				g.right = false;
				break;
			case SDLK_LEFT:
				g.left = false;
				break;
			}
		}
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.scancode)
			{
			case SDL_SCANCODE_UP:
				g.up = true;
				break;
			case SDL_SCANCODE_DOWN:
				g.down = true;
				break;
			case SDL_SCANCODE_RIGHT:
				g.right = true;
				break;
			case SDL_SCANCODE_LEFT:
				g.left = true;
				break;
			case SDL_SCANCODE_SPACE:
				g.fire = true;
				break;
			case SDL_SCANCODE_ESCAPE:
				exit = true;
				break;
			}
		}
		if (e.type == SDL_QUIT)exit = true;
	}
	return exit;
}


void Movement() {

	if (g.up && g.player.y > 0)g.player.y -= SPEED;
	if (g.down && g.player.y < SCREEN_HEIGHT - 195)g.player.y += SPEED;
	if (g.left && g.player.x > -20)g.player.x -= SPEED;
	if (g.right && g.player.x < SCREEN_WIDTH - (PLAYER_SIZE - 10))g.player.x += SPEED;


	if (g.fire)
	{
		g.fire = false;
		Mix_PlayChannel(-1, g.fx_shot, 0);
		if (g.last_shot == AMMO) g.last_shot = 0;
		g.shots[g.last_shot].alive = true;
		g.shots[g.last_shot].x = g.player.x + PLAYER_SIZE;
		g.shots[g.last_shot].y = g.player.y + (PLAYER_SIZE / 2);

		g.last_shot++;
	}

	for (int i = 0; i < AMMO; i++)
	{
		if (g.shots[i].alive) {
			g.shots[i].x += BULLET_SPEED;
			if (g.shots[i].x > SCREEN_WIDTH)
				g.shots[i].alive = false;
		}
	}
}


void Render() {
	SDL_Rect target;
	target.h = BULLET_SIZE;
	target.w = BULLET_SIZE;

	SDL_RenderCopy(g.renderer, g.background, NULL, NULL);			//Background

	for (int i = 0; i < AMMO; i++)									//Bullets
	{
		target.x = g.shots[i].x;
		target.y = g.shots[i].y;
		SDL_RenderCopy(g.renderer, g.fireball, NULL, &target);
	}

	SDL_RenderCopy(g.renderer, g.character, NULL, &g.player);		//Character

	SDL_RenderPresent(g.renderer);									//Present
}



int main(int argc, char* argv[]) {

	Start();

	while (!Check_Input()) {

		Movement();
		Render();

	}

	Finish();


	return 0;
}