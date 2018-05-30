#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;

	for (uint i = 0; i < MAX_PART_CHUNKS; ++i)
		chunks[i] = nullptr; 

	for (uint i = 0; i < MAX_PART_TEXTURES; ++i)
		textures[i] = nullptr;


	Releasing_Ball.anim.PushBack({ 241,244,30,30 });
	Releasing_Ball.anim.PushBack({ 271,244,30,30 });
	Releasing_Ball.anim.PushBack({ 301,244,30,30 });
	Releasing_Ball.anim.PushBack({ 331,244,30,30 });
	Releasing_Ball.anim.PushBack({ 361,244,30,30 });
	Releasing_Ball.anim.PushBack({ 391,244,30,30 });
	Releasing_Ball.anim.PushBack({ 421,244,30,30 });
	Releasing_Ball.anim.PushBack({ 451,244,30,30 });
	Releasing_Ball.anim.speed = 0.3f;
	Releasing_Ball.anim.loop = true;
	Releasing_Ball.texture = 3;
	Releasing_Ball.fx = 10;

	Charging_Ball.anim.PushBack({ 0,274,46,45 });
	Charging_Ball.anim.PushBack({ 46,274,46,45 });
	Charging_Ball.anim.PushBack({ 92,274,46,45 });
	Charging_Ball.anim.PushBack({ 138,274,46,45 });
	Charging_Ball.anim.PushBack({ 184,274,46,45 });
	Charging_Ball.anim.PushBack({ 230,274,46,45 });
	Charging_Ball.anim.PushBack({ 0,319,46,45 });
	Charging_Ball.anim.PushBack({ 46,319,46,45 });
	Charging_Ball.anim.PushBack({ 92,319,46,45 });
	Charging_Ball.anim.PushBack({ 138,319,46,45 });
	Charging_Ball.anim.PushBack({ 184,319,46,45 });
	Charging_Ball.anim.PushBack({ 230,319,46,45 });
	Charging_Ball.anim.PushBack({ 0,364,46,45 });
	Charging_Ball.anim.PushBack({ 46,364,46,45 });
	Charging_Ball.anim.PushBack({ 92,364,46,45 });
	Charging_Ball.anim.speed = 0.3f;
	Charging_Ball.anim.loop = true;
	Charging_Ball.texture = 3;
	//Charging_Ball.fx = 10;

	bullet_propulsion.anim.PushBack({ 278, 90,13,12 });
	bullet_propulsion.anim.PushBack({ 291, 92,10,9 });
	bullet_propulsion.anim.PushBack({ 304, 92,10,9 });
	bullet_propulsion.anim.loop = false;
	bullet_propulsion.anim.speed = 0.25f;
	bullet_propulsion.speed.x = 1;
	bullet_propulsion.life = 20;
	bullet_propulsion.texture = 0;


	bullet.anim.PushBack({ 148,127,15,7 });
	bullet.anim.loop = false;
	bullet.anim.speed = 0.3f;
	bullet.speed.x = 15;
	bullet.life = 1000;
	bullet.fx = 0;
	bullet.texture = 0;

	bullet_explosion.anim.PushBack({ 248,7,12,12 });
	bullet_explosion.anim.PushBack({ 262,7,13,13 });
	bullet_explosion.anim.PushBack({ 277,7,14,14 });
	bullet_explosion.anim.PushBack({ 293,7,12,12 });
	bullet_explosion.anim.PushBack({ 248,23,14,14 });
	bullet_explosion.anim.PushBack({ 264,23,16,16 });
	bullet_explosion.anim.PushBack({ 282,23,14,14 });
	bullet_explosion.anim.speed = 0.4f;
	bullet_explosion.anim.loop = false;
	bullet_explosion.texture = 0;

	BigTankShot.anim.PushBack({ 196, 746, 13, 13 });
	BigTankShot.anim.PushBack({ 184, 746, 13, 13 });
	BigTankShot.anim.PushBack({ 206, 762, 13, 13 });
	BigTankShot.anim.PushBack({ 237, 746, 13, 13 });
	BigTankShot.anim.speed = 0.3f;
	BigTankShot.life = 3000;
	BigTankShot.texture = 2;
	BigTankShot.fx = 7;

	SmallTankShot.anim.PushBack({ 245, 831, 5, 5 });
	SmallTankShot.anim.PushBack({ 250, 831, 5, 5 });
	SmallTankShot.anim.PushBack({ 235, 831, 5, 5 });
	SmallTankShot.anim.PushBack({ 240, 831, 5, 5 });
	SmallTankShot.anim.speed = 0.3f;
	SmallTankShot.speed.x = 2;
	SmallTankShot.life = 3000;
	SmallTankShot.texture = 2;
	SmallTankShot.fx = 7;


	SmallTurretShot.anim.PushBack({ 245, 831, 5, 5 });
	SmallTurretShot.anim.PushBack({ 250, 831, 5, 5 });
	SmallTurretShot.anim.PushBack({ 235, 831, 5, 5 });
	SmallTurretShot.anim.PushBack({ 240, 831, 5, 5 });
	SmallTurretShot.anim.speed = 0.3f;
	SmallTurretShot.speed.x = 2;
	SmallTurretShot.life = 3000;
	SmallTurretShot.texture = 2;
	SmallTurretShot.fx = 7;

	////PowerUp Laser Particle

	bullet_laser.anim.PushBack({ 389,240,56,3 });
	bullet_laser.anim.PushBack({ 447,240,48,3 });
	bullet_laser.anim.PushBack({ 389,245,64,3 });
	bullet_laser.anim.PushBack({ 455,245,40,3 });
	bullet_laser.anim.PushBack({ 389,250,24,3 });
	bullet_laser.anim.PushBack({ 415,250,16,3 });
	bullet_laser.anim.PushBack({ 433,250,32,3 });
	bullet_laser.anim.PushBack({ 415,250,16,3 });
	bullet_laser.anim.PushBack({ 389,250,24,3 });
	bullet_laser.anim.PushBack({ 433,250,32,3 });
	bullet_laser.anim.PushBack({ 455,245,40,3 });
	bullet_laser.anim.PushBack({ 447,240,48,3 });
	bullet_laser.anim.PushBack({ 389,240,56,3 });
	bullet_laser.anim.PushBack({ 389,245,64,3 });
	bullet_laser.anim.speed = 0.3f;
	bullet_laser.anim.loop = false;
	bullet_laser.speed.x = 5;
	bullet_laser.fx = 4;
	bullet_laser.life = 1500;
	bullet_laser.texture = 0;


	firing_laser.anim.PushBack({ 165,80,33,13 });
	firing_laser.anim.PushBack({ 165,93,33,13 });
	firing_laser.anim.PushBack({ 165,105,33,13 });
	firing_laser.anim.PushBack({ 165,118,33,13 });
	firing_laser.anim.PushBack({ 198,131,33,13 });
	firing_laser.anim.PushBack({ 198,80,33,13 });
	firing_laser.anim.PushBack({ 198,92,33,13 });
	firing_laser.anim.PushBack({ 198,105,33,13 });
	firing_laser.anim.speed = 0.3f;
	firing_laser.speed.x = 1;
	firing_laser.anim.loop = false;
	firing_laser.life = 200;
	firing_laser.texture = 0;

	bullet_laser2_1.anim.PushBack({ 960,1021,64,3 });
	bullet_laser2_1.anim.PushBack({ 415,250,16,3 });
	bullet_laser2_1.anim.PushBack({ 389,250,24,3 });
	bullet_laser2_1.anim.PushBack({ 433,250,32,3 });
	bullet_laser2_1.anim.PushBack({ 455,245,40,3 });
	bullet_laser2_1.anim.PushBack({ 447,240,48,3 });
	bullet_laser2_1.anim.PushBack({ 389,240,56,3 });
	bullet_laser2_1.anim.PushBack({ 389,245,64,3 });
	bullet_laser2_1.anim.speed = 0.3f;
	bullet_laser2_1.speed.x = 5;
	bullet_laser2_1.anim.loop = false;
	bullet_laser2_1.life = 1500;
	bullet_laser2_1.texture = 0;

	bullet_laser2.anim.PushBack({ 209,209,13,31 });
	bullet_laser2.anim.PushBack({ 222,209,13,31 });
	bullet_laser2.anim.PushBack({ 235,209,13,31 });
	bullet_laser2.anim.PushBack({ 235,209,13,31 });
	bullet_laser2.anim.PushBack({ 235,209,13,31 });
	bullet_laser2.anim.PushBack({ 235,209,13,31 });
	bullet_laser2.anim.PushBack({ 235,209,13,31 });
	bullet_laser2.anim.PushBack({ 235,209,13,31 });
	bullet_laser2.anim.PushBack({ 235,209,13,31 });
	bullet_laser2.anim.PushBack({ 235,209,13,31 });
	bullet_laser2.anim.PushBack({ 235,209,13,31 });
	bullet_laser2.anim.PushBack({ 235,209,13,31 });
	bullet_laser2.anim.speed = 0.15f;
	bullet_laser2.speed.x = 5;
	bullet_laser2.life = 1500;
	bullet_laser2.texture = 0;
	bullet_laser2.fx = 6;

	pilot_dying.anim.PushBack({ 243,576,12,64 });
	pilot_dying.anim.PushBack({ 260,576,13,64 });
	pilot_dying.anim.PushBack({ 278,576,14,64 });
	pilot_dying.anim.PushBack({ 297,576,13,64 });
	pilot_dying.anim.PushBack({ 315,576,15,64 });
	pilot_dying.anim.PushBack({ 335,576,12,64 });
	pilot_dying.anim.PushBack({ 352,576,11,64 });
	pilot_dying.anim.PushBack({ 368,576,12,64 });
	pilot_dying.anim.speed = 0.2f;
	pilot_dying.speed.x = 2;
	pilot_dying.life = 8000;
	pilot_dying.speed.y = 1 + pilot_dying.life / 8000;
	pilot_dying.texture = 2;
	pilot_dying.anim.loop = false;


	SpaceshipAnim.anim.PushBack({ 0,121,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,146,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,171,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,196,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,221,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,246,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,271,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,296,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,321,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,346,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,371,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,396,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,421,111,25 });
	SpaceshipAnim.anim.PushBack({ 0,446,111,25 });
	SpaceshipAnim.anim.loop = false;
	SpaceshipAnim.speed.x = 1;
	SpaceshipAnim.fx = 3;
	SpaceshipAnim.anim.speed = 0.3f;
	SpaceshipAnim.texture = 1;

	player_death.anim.PushBack({ 18, 20, 37, 16 });
	player_death.anim.PushBack({ 14, 37, 41, 17 });
	player_death.anim.PushBack({ 9, 54, 46, 18 });
	player_death.anim.PushBack({ 3, 71, 52, 16 });
	player_death.anim.PushBack({ 2, 87, 54, 15 });
	player_death.anim.PushBack({ 0, 104, 55, 16 });
	player_death.anim.PushBack({ 57, 21, 53, 15 });
	player_death.anim.PushBack({ 58, 36, 52, 16 });
	player_death.anim.PushBack({ 55, 53, 55, 17 });
	player_death.anim.PushBack({ 56, 70, 54, 17 });
	player_death.anim.PushBack({ 55, 88, 55, 17 });
	player_death.anim.PushBack({ 57, 106, 53, 15 });
	player_death.anim.PushBack({ 112, 19, 53, 18 });
	player_death.anim.PushBack({ 114, 38, 51, 14 });
	player_death.anim.PushBack({ 118, 53, 47, 18 });
	player_death.anim.PushBack({ 118, 72, 47, 14 });
	player_death.anim.PushBack({ 124, 89, 41, 12 });
	player_death.anim.PushBack({ 128, 108, 37, 10 });
	player_death.anim.loop = false;
	player_death.anim.speed = 0.25f;
	player_death.fx = 1;
	player_death.texture = 0;

	Blue_Car_Explosion.anim.PushBack({ 390,510,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 428,510,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 466,510,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 390,542,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 428,542,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 466,542,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 390,574,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 428,574,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 466,574,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 390,606,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 428,606,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 466,606,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 390,638,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 428,638,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 466,638,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 390,670,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 428,670,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 466,670,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 390,702,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 428,702,38,32 });
	Blue_Car_Explosion.anim.PushBack({ 466,702,38,32 });
	Blue_Car_Explosion.anim.loop = false;
	Blue_Car_Explosion.anim.speed = 0.2;
	Blue_Car_Explosion.texture = 2;

	Yellow_Car_Explosion.anim.PushBack({ 466,798,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 390,830,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 428,830,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 466,830,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 390,862,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 428,862,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 466,862,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 390,894,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 466,574,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 390,606,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 428,606,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 466,606,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 390,638,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 428,638,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 466,638,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 390,670,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 428,670,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 466,670,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 390,702,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 428,702,38,32 });
	Yellow_Car_Explosion.anim.PushBack({ 466,702,38,32 });
	Yellow_Car_Explosion.anim.loop = false;
	Yellow_Car_Explosion.anim.speed = 0.2;
	Yellow_Car_Explosion.texture = 2;

	Red_Car_Explosion.anim.PushBack({ 390,734,38,32 });
	Red_Car_Explosion.anim.PushBack({ 428,734,38,32 });
	Red_Car_Explosion.anim.PushBack({ 466,734,38,32 });
	Red_Car_Explosion.anim.PushBack({ 390,766,38,32 });
	Red_Car_Explosion.anim.PushBack({ 428,766,38,32 });
	Red_Car_Explosion.anim.PushBack({ 466,766,38,32 });
	Red_Car_Explosion.anim.PushBack({ 390,798,38,32 });
	Red_Car_Explosion.anim.PushBack({ 428,798,38,32 });
	Red_Car_Explosion.anim.PushBack({ 466,574,38,32 });
	Red_Car_Explosion.anim.PushBack({ 390,606,38,32 });
	Red_Car_Explosion.anim.PushBack({ 428,606,38,32 });
	Red_Car_Explosion.anim.PushBack({ 466,606,38,32 });
	Red_Car_Explosion.anim.PushBack({ 390,638,38,32 });
	Red_Car_Explosion.anim.PushBack({ 428,638,38,32 });
	Red_Car_Explosion.anim.PushBack({ 466,638,38,32 });
	Red_Car_Explosion.anim.PushBack({ 390,670,38,32 });
	Red_Car_Explosion.anim.PushBack({ 428,670,38,32 });
	Red_Car_Explosion.anim.PushBack({ 466,670,38,32 });
	Red_Car_Explosion.anim.PushBack({ 390,702,38,32 });
	Red_Car_Explosion.anim.PushBack({ 428,702,38,32 });
	Red_Car_Explosion.anim.PushBack({ 466,702,38,32 });
	Red_Car_Explosion.anim.loop = false;
	Red_Car_Explosion.anim.speed = 0.2;
	Red_Car_Explosion.texture = 3;
	


	player2_death.anim.PushBack({ 286, 35, 33, 11 });
	player2_death.anim.PushBack({ 286, 62, 32, 12 });
	player2_death.anim.PushBack({ 283, 88, 36, 15 });
	player2_death.anim.PushBack({ 277, 114, 40, 18 });
	player2_death.anim.PushBack({ 273, 140, 45, 19 });
	player2_death.anim.PushBack({ 266, 167, 51, 20 });
	player2_death.anim.PushBack({ 259, 196, 59, 21 });
	player2_death.anim.PushBack({ 319, 1, 62, 22 });
	player2_death.anim.PushBack({ 318, 29, 63, 24 });
	player2_death.anim.PushBack({ 318, 58, 63, 23 });
	player2_death.anim.PushBack({ 320, 86, 60, 23 });
	player2_death.anim.PushBack({ 321, 113, 60, 24 });
	player2_death.anim.PushBack({ 323, 143, 58, 25 });
	player2_death.anim.PushBack({ 327, 170, 54, 26 });
	player2_death.anim.PushBack({ 323, 197, 58, 27 });
	player2_death.anim.PushBack({ 383, 0, 60, 28 });
	player2_death.anim.PushBack({ 388, 28, 55, 28 });
	player2_death.anim.PushBack({ 390, 56, 54, 28 });
	player2_death.anim.PushBack({ 392, 85, 52, 27 });
	player2_death.anim.PushBack({ 394, 115, 50, 21 });
	player2_death.anim.loop = false;
	player2_death.anim.speed = 0.3f;
	player2_death.fx = 1;
	player2_death.texture = 1;




	//   TANK BULLETS 

	CommonExplosion.anim.PushBack({ 224,928,32,32 });//													
	CommonExplosion.anim.PushBack({ 256,928,32,32 });//	
	CommonExplosion.anim.PushBack({ 288,928,32,32 });//	
	CommonExplosion.anim.PushBack({ 320,928,32,32 });//	
	CommonExplosion.anim.PushBack({ 352,928,32,32 });//	
	CommonExplosion.anim.PushBack({ 384,928,32,32 });//	
	CommonExplosion.anim.PushBack({ 416,928,32,32 });//	
	CommonExplosion.anim.PushBack({ 448,928,32,32 });//	
	CommonExplosion.anim.PushBack({ 480,928,32,32 });//	
	CommonExplosion.anim.PushBack({ 224,960,32,32 });//	
	CommonExplosion.anim.PushBack({ 256,960,32,32 });//	
	CommonExplosion.anim.PushBack({ 288,960,32,32 });//	
	CommonExplosion.anim.PushBack({ 320,960,32,32 });//	
	CommonExplosion.anim.PushBack({ 352,960,32,32 });//	
	CommonExplosion.anim.PushBack({ 384,960,32,32 });//	
	CommonExplosion.anim.PushBack({ 416,960,32,32 });//	
	CommonExplosion.anim.PushBack({ 448,960,32,32 });//	
	CommonExplosion.anim.PushBack({ 480,960,32,32 });//		
	CommonExplosion.anim.loop = false;
	CommonExplosion.anim.speed = 0.5f;
	CommonExplosion.texture = 2;

	ball_bullet.anim.PushBack({ 317, 176, 13, 13 });
	ball_bullet.anim.PushBack({ 332, 176, 13, 13 });
	ball_bullet.anim.PushBack({ 317, 191, 13, 13 });
	ball_bullet.anim.PushBack({ 332, 191, 13, 13 });
	ball_bullet.anim.PushBack({ 317, 206, 13, 13 });
	ball_bullet.anim.PushBack({ 332, 206, 13, 13 });
	ball_bullet.anim.PushBack({ 317, 221, 13, 13 });
	ball_bullet.anim.PushBack({ 332, 221, 13, 13 });
	ball_bullet.anim.speed = 0.3f;
	ball_bullet.anim.loop = true;
	ball_bullet.life = 2000;
	ball_bullet.texture = 0;

	Bubbles.anim.PushBack({ 0,0,15,15 });
	Bubbles.anim.PushBack({ 15,0,15,15 });
	Bubbles.anim.PushBack({ 30,0,15,15 });
	Bubbles.anim.PushBack({ 45,0,15,15 });
	Bubbles.anim.loop = false;
	Bubbles.anim.speed = 0.1;
	Bubbles.life = 100;
	Bubbles.texture = 4;

	 
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	chunks[0] = App->audio->LoadChunk("assets/SFX/shot.wav");							// Shot -> fx = 0 
	chunks[1] = App->audio->LoadChunk("assets/SFX/player_death.wav");					// Death -> fx = 1
	chunks[2] = App->audio->LoadChunk("assets/SFX/Explosion1.wav");						// Common Explosion -> fx = 2
	chunks[3] = App->audio->LoadChunk("assets/SFX/Showup_sound.wav");					// Player_showup -> fx = 3
	chunks[4] = App->audio->LoadChunk("assets/SFX/Laser_1.wav");                        // Laser_1 -> fx = 4
	chunks[5] = App->audio->LoadChunk("assets/SFX/showup_sound.wav");
	chunks[6] = App->audio->LoadChunk("assets/SFX/Laser_2.wav");
	chunks[7] = App->audio->LoadChunk("assets/SFX/TankShot.wav");
	chunks[8] = App->audio->LoadChunk("assets/SFX/Explosion2.wav");
	chunks[9] = App->audio->LoadChunk("assets/SFX/Charging shot.wav");
	chunks[10] = App->audio->LoadChunk("assets/SFX/Releasing charged shot.wav");
	chunks[11] = App->audio->LoadChunk("assets/SFX/BOOM_ALLAHU.wav");

	textures[0] = App->textures->Load("assets/sprites/main_character.png");			// Texture -> 0
	textures[1] = App->textures->Load("assets/sprites/SpritesPlayer2.png");			// Texture -> 1
	textures[2] = App->textures->Load("assets/sprites/common_enemies1.png");
	textures[3] = App->textures->Load("assets/sprites/blue_ball_axis.png");
	textures[4] = App->textures->Load("Ship_Underwater_Perticles.png");


	return true; 
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
		
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	for (uint i = 0; i < MAX_PART_CHUNKS; ++i)
	{
		if (chunks[i] != nullptr) {
			App->audio->UnloadChunk(chunks[i]);
			chunks[i] = nullptr; 
		}
			
	}

	for (uint i = 0; i < MAX_PART_TEXTURES; ++i) 
	{
		if (textures[i] != nullptr) {
			App->textures->Unload(textures[i]);
			textures[i] = nullptr; 
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}

		else if (SDL_GetTicks() >= p->born)
		{
			App->render->Blit(textures[p->texture], p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
		
 			if (p->fx_played == false)
			{
				p->fx_played = true;
				// Play particle fx here				
				App->audio->PlayChunk(App->audio->chunks[p->fx], 1);
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (active[i] != nullptr && active[i]->collider == c1)
		{
		/*	if ((c2->type == COLLIDER_ENEMY || c2->type == COLLIDER_CAR) && c1->type == COLLIDER_PLAYER_SHOT) App->player->score_p1 += 100;
			else if ((c2->type == COLLIDER_ENEMY || c2->type == COLLIDER_CAR) && c1->type == COLLIDER_PLAYER2_SHOT) App->player2->score_p2 += 100; */
			LOG("HEY SOMEONE SCORED %i", App->player->score_p1);
			AddParticle(bullet_explosion, active[i]->position.x, active[i]->position.y -3);
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}
// -------------------------------------------------------------
// -------------------------------------------------------------
//void ModuleParticles::UnderWater() {
//	if (App->player->position.y == 100) {
//		AddParticle(Bubbles, position.x - 15, position.y - 11);
//	}
//}

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) :
	anim(p.anim), position(p.position), speed(p.speed),
	fx(p.fx), born(p.born), life(p.life), texture(p.texture)
{}

Particle::~Particle()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}