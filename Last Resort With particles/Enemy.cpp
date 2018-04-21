#include "Application.h"
#include "Enemy.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleRender.h"

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
		App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()), parallax);
	if (animation2 != nullptr)
		App->render->Blit(sprites, position.x + Anim2Distance.x, position.y + Anim2Distance.y, &(animation2->GetCurrentFrame()));
	if (animation3 != nullptr)
		App->render->Blit(sprites, position.x + Anim3Distance.x, position.y + Anim3Distance.y, &(animation3->GetCurrentFrame()));
/*	if (animation4 != nullptr)
		App->render->Blit(sprites, position.x + Anim4Distance.x, position.y + Anim4Distance.y, &(animation4->GetCurrentFrame()));
	if (animation5 != nullptr)
		App->render->Blit(sprites, position.x + Anim5Distance.x, position.y + Anim5Distance.y, &(animation5->GetCurrentFrame()));*/

}

void Enemy::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->CommonExplosion, position.x, position.y);			//this function is repeated in Moduleparticles cpp line 176, if this is not commented

	App->particles->AddParticle(App->particles->pilot_dying, position.x, position.y);
}																									

void Enemy::Shoot()
{
	
}
		
																							//when an enemy is killed there will be shown 2 explosions

//void Enemy::ShootStraightPlayerDirX(int PlayerPosX, int EnemyPosX, int SpeedX) {
//	StoredShotDirX = (PlayerPosX - EnemyPosX)*SpeedX;
//}
//void Enemy::ShootStraightPlayerDirY(int PlayerPosY, int EnemyPosY, int SpeedY) {
//	StoredShotDirY = (PlayerPosY- EnemyPosY)*SpeedY;
//}
//
