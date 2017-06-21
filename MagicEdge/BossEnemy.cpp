#include "StandardInc.h"
#include "BossEnemy.h"
#include "DifficultyInfo.h"
#include "Object.h"
#include "ResourceManager.h"

void BossEnemy::SetLevel(int l)
{
	Enemy::SetLevel(l);

	SetSpeed(40 * pow(1.05, l));
	damage = l * 30;

	GetOwner()->GetComponent<Health>()->SetMaxHealth(l * 1000);
	GetOwner()->GetComponent<Health>()->SetHealth(l * 1000);
	attackRadius = l * 3;
}

void BossEnemy::Render()
{
	Renderer* renderer = GetOwner()->GetComponent<Renderer>();

	Uint8 r, g, b;
	SDL_GetTextureColorMod(renderer->GetTexture(), &r, &g, &b);
	SDL_SetTextureColorMod(renderer->GetTexture(), 255, 0, 0);

	Enemy::Render();

	SDL_SetTextureColorMod(renderer->GetTexture(), r, g, b);
}

void BossEnemy::Move(double x, double y)
{
	Entity::Move(x, y);

	Renderer* r = GetOwner()->GetComponent<Renderer>();

	if (x < 0 && abs(y) < abs(x))
	{
		r->SetTexture(ResourceManager::GetTexture("CharacterLeft"), 1, 1, 0, false);
	}
	else if (x > 0 && abs(y) < abs(x))
	{
		r->SetTexture(ResourceManager::GetTexture("CharacterRight"), 1, 1, 0, false);
	}
	else if (y < 0)
	{
		r->SetTexture(ResourceManager::GetTexture("CharacterBack"), 1, 1, 0, false);
	}
	else if (y > 0)
	{
		r->SetTexture(ResourceManager::GetTexture("Character"), 1, 1, 0, false);
	}
}

void BossEnemy::OnCreated()
{
	Enemy::OnCreated();

	Renderer* r = GetOwner()->GetComponent<Renderer>();
	Transform* t = GetOwner()->GetComponent<Transform>();

	r->SetTexture(ResourceManager::GetTexture("Character"), 1, 1, 0, false);
	t->SetSize(Block::TILE_SIZE * 2, Block::TILE_SIZE * 2);

	SetLevel(max(rand() % 3 - 1 + difficulty, 1));
}