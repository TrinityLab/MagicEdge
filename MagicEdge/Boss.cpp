#include "Boss.h"
#include "DifficultyInfo.h"

Boss::Boss(string name) : OrkEnemy(name)
{
	SetTexture(ResourceManager::GetTexture("Character"), 1, 1, 0, false);
	SetSize(Block::TILE_SIZE * 2, Block::TILE_SIZE * 2);

	setLevel(max(rand() % 3 - 1 + difficulty, 1));
}

void Boss::setLevel(int l)
{
	OrkEnemy::setLevel(l);

	setSpeed(40 * pow(1.05, l));
	damage = l * 30;

	MaxHealth = l * 1000;
	Health = MaxHealth;
	attackRadius = l * 3;
}

void Boss::Render()
{
	SDL_SetTextureColorMod(GetTexture(), 255, 0, 0);

	OrkEnemy::Render();

	SDL_SetTextureColorMod(GetTexture(), 255, 255, 255);
}

void Boss::Move(double x, double y)
{
	Entity::Move(x, y);

	if (x < 0 && abs(y) < abs(x))
	{
		SetTexture(ResourceManager::GetTexture("CharacterLeft"), 1, 1, 0, false);
	}
	else if (x > 0 && abs(y) < abs(x))
	{
		SetTexture(ResourceManager::GetTexture("CharacterRight"), 1, 1, 0, false);
	}
	else if (y < 0)
	{
		SetTexture(ResourceManager::GetTexture("CharacterBack"), 1, 1, 0, false);
	}
	else if (y > 0)
	{
		SetTexture(ResourceManager::GetTexture("Character"), 1, 1, 0, false);
	}
}