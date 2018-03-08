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
#define PLAYER_SIZE 150
#define BULLET_SPEED 10
#define AMMO 30
#define BULLET_SIZE 30
#define HITS 35

struct projectile {

	int x, y;
	bool alive = false;

};

struct Hit {

	bool hit = false;
	int y; 
};

struct globals {

	SDL_Window* window = nullptr;

	SDL_Renderer* renderer = nullptr;

	SDL_Surface* surface = nullptr;
	SDL_Texture* background = nullptr;
	SDL_Texture* character = nullptr;
	SDL_Texture* ball = nullptr;	
	SDL_Texture* ball_2 = nullptr; 
	SDL_Texture* character_2 = nullptr; 
	SDL_Texture* splash = nullptr; 
	SDL_Texture* splash_2 = nullptr; 

	Mix_Chunk* fx_shot = nullptr;
	Mix_Chunk* fx_splash = nullptr; 
	Mix_Chunk* fx_hit = nullptr; 
	Mix_Music* music = nullptr;

	SDL_Rect player{ 80, SCREEN_HEIGHT / 2,PLAYER_SIZE,PLAYER_SIZE };
	SDL_Rect player_2{ 900, SCREEN_HEIGHT / 2,PLAYER_SIZE,PLAYER_SIZE };
	projectile shots[AMMO];
	projectile shots_2[AMMO];

	Hit hits[HITS];
	int last_hit = 0;
	Hit hits_2[HITS];
	int last_hit_2 = 0;

	int last_shot = 0;
	int last_shot_2 = 0;


	bool up, down, right, left, fire = false;
	bool up_2, down_2, right_2, left_2, fire_2 = false;

	bool hit = false;
	bool hit_2 = false; 
	int pos_hit_2 = 0; 
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

	for (int i = 0; i < AMMO; i++)
	{
		g.shots[i].alive = false; 
		g.shots[i].y = 2000;
		g.shots_2[i].alive = false;
		g.shots_2[i].y = 2000;

	}

	//IMAGE SETTINGS


	g.surface = IMG_Load("assets/background.png");
	g.background = SDL_CreateTextureFromSurface(g.renderer, g.surface);
	SDL_FreeSurface(g.surface);

	g.surface = IMG_Load("assets/mario.png");
	g.character = SDL_CreateTextureFromSurface(g.renderer, g.surface);
	SDL_FreeSurface(g.surface);

	g.surface = IMG_Load("assets/luigi.png");
	g.character_2 = SDL_CreateTextureFromSurface(g.renderer, g.surface);
	SDL_FreeSurface(g.surface);

	g.surface = IMG_Load("assets/ball_1.png");
	g.ball = SDL_CreateTextureFromSurface(g.renderer, g.surface);
	SDL_FreeSurface(g.surface);
	
	g.surface = IMG_Load("assets/ball_2.png");
	g.ball_2 = SDL_CreateTextureFromSurface(g.renderer, g.surface);
	SDL_FreeSurface(g.surface);


	g.surface = IMG_Load("assets/splash.png");
	g.splash = SDL_CreateTextureFromSurface(g.renderer, g.surface);
	SDL_FreeSurface(g.surface);

	g.surface = IMG_Load("assets/splash_2.png");
	g.splash_2 = SDL_CreateTextureFromSurface(g.renderer, g.surface);
	SDL_FreeSurface(g.surface); 


	//SOUND SETTINGS

	Mix_OpenAudio(25000, MIX_DEFAULT_FORMAT, 2, 2500);

	g.fx_shot = Mix_LoadWAV("assets/laser.WAV");
	g.fx_splash = Mix_LoadWAV("assets/splash.WAV"); 
	g.fx_hit = Mix_LoadWAV("assets/hit.WAV");
	g.music = Mix_LoadMUS("assets/music.ogg");
	Mix_PlayMusic(g.music, -1);
}


void Finish() {

	//IMAGE QUIT

	SDL_DestroyTexture(g.background);
	SDL_DestroyTexture(g.character);
	SDL_DestroyTexture(g.character_2);
	SDL_DestroyTexture(g.ball);
	SDL_DestroyTexture(g.ball_2);
	SDL_DestroyTexture(g.splash);
	SDL_DestroyTexture(g.splash_2);
	IMG_Quit();

	//SOUND QUIT

	Mix_FreeChunk(g.fx_shot);
	Mix_FreeChunk(g.fx_hit);
	Mix_FreeChunk(g.fx_splash);
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

				// PLAYER 1

			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				g.up_2 = false;
				break;
			case SDLK_DOWN:
				g.down_2 = false;
				break;
			case SDLK_RIGHT:
				g.right_2 = false;
				break;
			case SDLK_LEFT:
				g.left_2 = false;
				break;

				// PLAYER 2

			case SDLK_w:
				g.up = false;
				break;
			case SDLK_s:
				g.down = false; 
				break;
			case SDLK_a:
				g.left = false; 
				break;
			case SDLK_d:
				g.right = false; 
				break;
			}
		}
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.scancode)
			{

				// PLAYER 1

			case SDL_SCANCODE_UP:
				g.up_2 = true;
				break;
			case SDL_SCANCODE_DOWN:
				g.down_2 = true;
				break;
			case SDL_SCANCODE_RIGHT:
				g.right_2 = true;
				break;
			case SDL_SCANCODE_LEFT:
				g.left_2 = true;
				break;
			case SDL_SCANCODE_KP_ENTER:
				g.fire_2 = true;
				break;

				// PLAYER 2

			case SDL_SCANCODE_W:
				g.up = true;
				break;
			case SDL_SCANCODE_S:
				g.down = true;
				break;
			case SDL_SCANCODE_D:
				g.right = true;
				break;
			case SDL_SCANCODE_A:
				g.left = true;
				break;
			case SDL_SCANCODE_SPACE:
				g.fire = true; 
				break;

				//  EXIT

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
	//if (g.down && g.player.y < SCREEN_HEIGHT - 250)g.player.y += SPEED;
	if (g.down && g.player.y < SCREEN_HEIGHT - PLAYER_SIZE)g.player.y += SPEED;
	if (g.left && g.player.x > 0)g.player.x -= SPEED;
	if (g.right && g.player.x < SCREEN_WIDTH - (PLAYER_SIZE - 10))g.player.x += SPEED;


	if (g.up_2 && g.player_2.y > 0)g.player_2.y -= SPEED;
	/*if (g.down_2 && g.player_2.y < SCREEN_HEIGHT - 250)g.player_2.y += SPEED;*/
	if (g.down_2 && g.player_2.y < SCREEN_HEIGHT - PLAYER_SIZE)g.player_2.y += SPEED;
	if (g.left_2 && g.player_2.x > 0)g.player_2.x -= SPEED;
	if (g.right_2 && g.player_2.x < SCREEN_WIDTH - (PLAYER_SIZE - 10))g.player_2.x += SPEED;


	//PLAYER 1 SHOTS

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
				if (g.shots[i].x > SCREEN_WIDTH) {
				if (g.last_hit == HITS)g.last_hit = 0;
				g.shots[i].alive = false;
				g.hits[g.last_hit].hit = true;
				g.hits[g.last_hit].y = g.shots[i].y - 50;
				g.last_hit++;
				Mix_PlayChannel(-1, g.fx_splash, 0);
			}
			if (g.shots[i].x > g.player_2.x && g.shots[i].y >(g.player_2.y - 30) && g.shots[i].y < (g.player_2.y + 140)) {
				Mix_PlayChannel(-1, g.fx_hit, 0);
				g.shots[i].alive = false;
				g.shots[i].x = 2000;
			}
		}
	}


	// PLAYER 2 SHOTS

	if (g.fire_2)
	{
		g.fire_2 = false;
		Mix_PlayChannel(-1, g.fx_shot, 0);
		if (g.last_shot_2 == AMMO) g.last_shot_2 = 0;
		g.shots_2[g.last_shot_2].alive = true;
		g.shots_2[g.last_shot_2].x = g.player_2.x;
		g.shots_2[g.last_shot_2].y = g.player_2.y + (PLAYER_SIZE / 2);

		g.last_shot_2++;
	}

	for (int i = 0; i < AMMO; i++)
	{
		if (g.shots_2[i].alive) {
			g.shots_2[i].x -= BULLET_SPEED;
			if (g.shots_2[i].x < -40) {
				if (g.last_hit_2 == HITS)g.last_hit_2 = 0;
				g.shots_2[i].alive = false;
				g.hits_2[g.last_hit_2].hit = true; 
				g.hits_2[g.last_hit_2].y = g.shots_2[i].y-60;
				g.last_hit_2++;
				Mix_PlayChannel(-1, g.fx_splash, 0);
			}
			if (g.shots_2[i].x < (g.player.x + 120) && g.shots_2[i].y >(g.player.y - 30) && g.shots_2[i].y < (g.player.y + 140)) {
				Mix_PlayChannel(-1, g.fx_hit, 0);
				g.shots_2[i].alive = false;
				g.shots_2[i].x = 2000;	
			

			}
		}
	}

}


void Render() {
	SDL_Rect target;


	SDL_RenderCopy(g.renderer, g.background, NULL, NULL);			//Background

	for (int i = 0; i < AMMO; i++)									//Bullets
	{
		target.x = g.shots[i].x;
		target.y = g.shots[i].y;
		target.h = 41;
		target.w = 70;
		SDL_RenderCopy(g.renderer, g.ball_2, NULL, &target);
	}

	for (int i = 0; i < AMMO; i++)									//Bullets
	{
		target.x = g.shots_2[i].x;
		target.y = g.shots_2[i].y;
		target.h = 40;
		target.w = 70;
		SDL_RenderCopy(g.renderer, g.ball, NULL, &target);
	}

	for (int i = 0; i < HITS; i++) {
		if (g.hits_2[i].hit) {
			target.x = -20;
			target.y = g.hits_2[i].y;
			target.h = 120;
			target.w = 50;

			SDL_RenderCopy(g.renderer, g.splash_2, NULL, &target);
		}
	}

	for (int i = 0; i < HITS; i++) {
		if (g.hits[i].hit) {
			target.x = SCREEN_WIDTH - 30;
			target.y = g.hits[i].y;
			target.h = 120;
			target.w = 50; 
			SDL_RenderCopy(g.renderer, g.splash, NULL, &target); 
		}
	}


	SDL_RenderCopy(g.renderer, g.character, NULL, &g.player);		//Character
	SDL_RenderCopy(g.renderer, g.character_2, NULL, &g.player_2);

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