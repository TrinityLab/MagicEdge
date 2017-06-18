#include "InsectEnemy.h"
#include "DifficultyInfo.h"
#include "Camera.h"
#include "Player.h"
#include "Ball.h"
#include "ScoreTable.h"

InsectEnemy::InsectEnemy(string name) : Entity(name)
{
	
}

void InsectEnemy::setLevel(int l)
{
	Entity::setLevel(l);

	attackReloadTime = max(0.3, 3.0);
	attackRadius = l * 5;
}

void InsectEnemy::Update()
{
	Entity::Update();

	Player* player = (Player*)SceneManager::GetCurrentScene()->FindObject("Player");
	if (player == NULL)
		return;

	double dirX = player->GetXPosition() - GetXPosition();
	double dirY = player->GetYPosition() - GetYPosition();

	double dist = sqrt(dirX * dirX + dirY * dirY);

	currentReloadTime -= Timer::GetDeltaTime();

	if (dist > attackRadius * Block::TILE_SIZE)
	{
		Move(dirX / dist * getSpeed() * Timer::GetDeltaTime(), dirY / dist * getSpeed() * Timer::GetDeltaTime());
	}
	else
	{
		if (currentReloadTime <= 0.0)
		{
			Ball* ball = new Ball("Ball", this);
			ball->SetPosition(GetXPosition() + (dirX / dist * Block::TILE_SIZE / 2), GetYPosition() + (dirY / dist * Block::TILE_SIZE));
			ball->setV(dirX / dist * 400.0, dirY / dist * 400.0);
			ball->setDamage(getDamage());
			ball->SetColor({ 255, 0, 0, 255 });

			currentReloadTime = attackReloadTime;
		}
	}
}

void InsectEnemy::Render()
{
	Entity::Render();
}

void InsectEnemy::OnCreated()
{
	Entity::OnCreated();

	setLevel(max(rand() % 3 - 1 + difficulty, 1));
	if (getLevel() <= 0)
		setLevel(1);

	SetSize(Block::TILE_SIZE * 1.5, Block::TILE_SIZE * 1.5);

	int type = rand() % 2;

	SetTexture(ResourceManager::GetTexture("InsectEnemy"), 1, 1, 0, false);

	setSpeed(75.0);

	currentReloadTime = attackReloadTime;

	World* world = (World*)SceneManager::GetCurrentScene()->FindObject("World");
	world->UpdateEnemiesCount(1);
}

void InsectEnemy::Move(double x, double y)
{
	Entity::Move(x, y);

	if (x < 0 && abs(y) < abs(x))
	{
		SetTexture(ResourceManager::GetTexture("InsectEnemyLeft"), 1, 1, 0, false);
	}
	else if (x > 0 && abs(y) < abs(x))
	{
		SetTexture(ResourceManager::GetTexture("InsectEnemyRight"), 1, 1, 0, false);
	}
	else if (y < 0)
	{
		SetTexture(ResourceManager::GetTexture("InsectEnemyBack"), 1, 1, 0, false);
	}
	else if (y > 0)
	{
		SetTexture(ResourceManager::GetTexture("InsectEnemy"), 1, 1, 0, false);
	}
}

int InsectEnemy::GetScore()
{
	return getLevel() * 1;
}