#include "Application.h"
#include "Powerup.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"

Powerup::Powerup(int x, int y) : position(x, y)
{}

Powerup::~Powerup()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

const Collider* Powerup::GetCollider() const
{
	return collider;
}

void Powerup::Draw(SDL_Texture* sprites)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	if (animation != nullptr)
		App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
	if (animation2 != nullptr)
		App->render->Blit(sprites, position.x + Anim2Distance.x, position.y + Anim2Distance.y, &(animation2->GetCurrentFrame()));
	if (animation3 != nullptr)
		App->render->Blit(sprites, position.x + Anim3Distance.x, position.y + Anim3Distance.y, &(animation3->GetCurrentFrame()));
}

void Powerup::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->CommonExplosion, position.x, position.y);			//this function is repeated in Moduleparticles cpp line 176, if this is not commented
}																									//when an enemy is killed there will be shown 2 explosions