#include "Application.h"
#include <time.h>
#include <stdlib.h>
#include "Enemy.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

Enemy::Enemy(float x, float y, int HP) : position(x, y)
{}

Enemy::~Enemy()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

const Collider* Enemy::GetCollider() const
{
	return collider;
}

void Enemy::Draw(SDL_Texture* sprites)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	if (animation != nullptr)
		App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
	if (animation2 != nullptr)
		App->render->Blit(sprites, position.x + Anim2Distance.x, position.y + Anim2Distance.y, &(animation2->GetCurrentFrame()));
	if (animation3 != nullptr)
		App->render->Blit(sprites, position.x + Anim3Distance.x, position.y + Anim3Distance.y, &(animation3->GetCurrentFrame()));
	/*	if (animation4 != nullptr)
			App->render->Blit(sprites, position.x + Anim4Distance.x, position.y + Anim4Distance.y, &(animation4->GetCurrentFrame()));
		if (animation5 != nullptr)
			App->render->Blit(sprites, position.x + Anim5Distance.x, position.y + Anim5Distance.y, &(animation5->GetCurrentFrame()));*/
	
}
void Enemy::Draw2(SDL_Texture* sprites2)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	if (anim2ndLevel != nullptr)
		App->render->Blit(sprites2, position.x, position.y, &(anim2ndLevel->GetCurrentFrame()));

	
}


void Enemy::Draw3(SDL_Texture* sprites3)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);
	if (SpiderTank != nullptr)
		App->render->Blit(sprites3, position.x, position.y, &(SpiderTank->GetCurrentFrame()));
}

void Enemy::Draw4(SDL_Texture* sprites4)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);
	
	    
	if (BossFireThrower != nullptr) {
		App->render->Blit(sprites4, position.x, position.y, &(BossFireThrower->GetCurrentFrame()));
	}

	if (BossAnim != nullptr)
		App->render->Blit(sprites4, position.x, position.y, &(BossAnim->GetCurrentFrame()));
}

void Enemy::Draw5(SDL_Texture* sprites5)
{
	if (AsignedFirePos == false) {
		FireFakePos.x = position.x - 20;
		FireFakePos.y = position.y - 20;
		AsignedFirePos = true;
	}

	if (BossFireAnim != nullptr) {
		App->render->Blit(sprites5, position.x -20, position.y +20, &(BossFireAnim->GetCurrentFrame()));
		//FireFakePos.x += 0.5f; 
			}
	

}

void Enemy::Draw6(SDL_Texture* sprites6)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);
	if (Bullets != nullptr)
		App->render->Blit(sprites6, position.x, position.y, &(Bullets->GetCurrentFrame()));
}

void Enemy::Draw7(SDL_Texture* sprites7)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);
	if (Barrels_boy != nullptr)
		App->render->Blit(sprites7, position.x, position.y, &(Barrels_boy->GetCurrentFrame()));
}
/*
void Enemy::Draw5(SDL_Texture* sprites4)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);
	if (SpiderTank != nullptr)
		App->render->Blit(sprites4, position.x, position.y, &(BossFire->GetCurrentFrame()));
}*/

void Enemy::OnCollision(Collider* collider)
{
	hp--;
	if (hp <= 0) {
		if (is_a_car!=0)
		{
			switch (is_a_car) {
			case 1: 
				App->particles->AddParticle(App->particles->Blue_Car_Explosion, position.x,position.y);
				break;
			case 2:
				App->particles->AddParticle(App->particles->Red_Car_Explosion, position.x, position.y);
				break; 
			case 3:
				App->particles->AddParticle(App->particles->Yellow_Car_Explosion, position.x, position.y);
				break; 
			}
		}
		else if (alliedgrenade == 1) {
			App->particles->AddParticle(App->particles->CommonExplosion, position.x, position.y, COLLIDER_PLAYER1_EXPLOSION, 0);
			App->particles->AddParticle(App->particles->CommonExplosion, position.x, position.y+10, COLLIDER_PLAYER1_EXPLOSION, 100);
			App->particles->AddParticle(App->particles->CommonExplosion, position.x, position.y-10, COLLIDER_PLAYER1_EXPLOSION, 100);
			App->particles->AddParticle(App->particles->CommonExplosion, position.x, position.y+20, COLLIDER_PLAYER1_EXPLOSION, 200);
			App->particles->AddParticle(App->particles->CommonExplosion, position.x, position.y-20, COLLIDER_PLAYER1_EXPLOSION, 200);
			App->particles->CommonExplosion.fx = 8;

		}
		else if (alliedgrenade == 1) {
			App->particles->AddParticle(App->particles->CommonExplosion, position.x, position.y, COLLIDER_PLAYER2_EXPLOSION, 0);
			App->particles->AddParticle(App->particles->CommonExplosion, position.x, position.y + 10, COLLIDER_PLAYER2_EXPLOSION, 100);
			App->particles->AddParticle(App->particles->CommonExplosion, position.x, position.y - 10, COLLIDER_PLAYER2_EXPLOSION, 100);
			App->particles->AddParticle(App->particles->CommonExplosion, position.x, position.y + 20, COLLIDER_PLAYER2_EXPLOSION, 200);
			App->particles->AddParticle(App->particles->CommonExplosion, position.x, position.y - 20, COLLIDER_PLAYER2_EXPLOSION, 200);
			App->particles->CommonExplosion.fx = 8;
		}
		else {
			int number;
			srand(time(NULL));
			number = rand() % 2;
			if (number == 1)
				App->particles->CommonExplosion.fx = 8;
			else
				App->particles->CommonExplosion.fx = 2;

			App->particles->AddParticle(App->particles->CommonExplosion, position.x, position.y);
			App->particles->AddParticle(App->particles->pilot_dying, position.x, position.y);

			if (original_hp > 1) {
				App->particles->AddParticle(App->particles->CommonExplosion, position.x, position.y);
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 20, position.y + 10, COLLIDER_NONE, 100);
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 10, position.y + 5, COLLIDER_NONE, 150);
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 15, position.y + 20, COLLIDER_NONE, 200);
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 5, position.y + 25, COLLIDER_NONE, 250);
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 10, position.y + 10, COLLIDER_NONE, 300);
			}
			if (original_hp > 6) {
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 30, position.y + 20, COLLIDER_NONE, 350);
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 25, position.y + 25, COLLIDER_NONE, 350);
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 35, position.y + 30, COLLIDER_NONE, 400);
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 50, position.y + 20, COLLIDER_NONE, 150);
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 75, position.y + 25, COLLIDER_NONE, 200);
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 60, position.y + 30, COLLIDER_NONE, 250);
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 80, position.y + 20, COLLIDER_NONE, 550);
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 55, position.y + 25, COLLIDER_NONE, 600);
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 80, position.y + 30, COLLIDER_NONE, 550);
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 90, position.y + 20, COLLIDER_NONE, 550);
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 85, position.y + 25, COLLIDER_NONE, 600);
				App->particles->AddParticle(App->particles->CommonExplosion, position.x + 75, position.y + 30, COLLIDER_NONE, 550);
			}
		}
	}
}																									

void Enemy::Shoot()
{
	
}
		
	
