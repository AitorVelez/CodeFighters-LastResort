#include "Application.h"
#include "Enemy.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"

Enemy::Enemy(float x, float y) : position(x, y)
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

	if (animation != nullptr)                                                                              // TANK
		App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
	if (animation2 != nullptr)
		App->render->Blit(sprites, position.x + Anim2Distance.x, position.y + Anim2Distance.y, &(animation2->GetCurrentFrame()));
	if (animation3 != nullptr)
		App->render->Blit(sprites, position.x + Anim3Distance.x, position.y + Anim3Distance.y, &(animation3->GetCurrentFrame()));
	if (animation4 != nullptr)
		App->render->Blit(sprites, position.x + Anim2Distance.x, position.y + Anim2Distance.y, &(animation2->GetCurrentFrame()));
	if (animation5 != nullptr)
		App->render->Blit(sprites, position.x + Anim3Distance.x, position.y + Anim3Distance.y, &(animation3->GetCurrentFrame()));
	if (animation6 != nullptr)
		App->render->Blit(sprites, position.x + Anim2Distance.x, position.y + Anim2Distance.y, &(animation2->GetCurrentFrame()));
	if (animation7 != nullptr)
		App->render->Blit(sprites, position.x + Anim3Distance.x, position.y + Anim3Distance.y, &(animation3->GetCurrentFrame()));
	if (animation8 != nullptr)
		App->render->Blit(sprites, position.x + Anim2Distance.x, position.y + Anim2Distance.y, &(animation2->GetCurrentFrame()));
	if (animation9 != nullptr)
		App->render->Blit(sprites, position.x + Anim3Distance.x, position.y + Anim3Distance.y, &(animation3->GetCurrentFrame()));
	if (animation10 != nullptr)
		App->render->Blit(sprites, position.x + Anim2Distance.x, position.y + Anim2Distance.y, &(animation2->GetCurrentFrame()));
	if (animation11 != nullptr)
		App->render->Blit(sprites, position.x + Anim3Distance.x, position.y + Anim2Distance.y, &(animation2->GetCurrentFrame()));
	if (animation12 != nullptr)
		App->render->Blit(sprites, position.x + Anim2Distance.x, position.y + Anim2Distance.y, &(animation2->GetCurrentFrame()));
	if (animation13 != nullptr)
		App->render->Blit(sprites, position.x + Anim3Distance.x, position.y + Anim3Distance.y, &(animation3->GetCurrentFrame()));
}

void Enemy::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->CommonExplosion, position.x, position.y);			//this function is repeated in Moduleparticles cpp line 176, if this is not commented
}																									//when an enemy is killed there will be shown 2 explosions