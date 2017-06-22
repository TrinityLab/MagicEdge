#include "StandardInc.h"
#include "Enemy.h"
#include "Utility.h"
#include "ScoreTable.h"
#include "DifficultyInfo.h"
#include "ObjectFactory.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Timer.h"
#include "Player.h"

void Enemy::OnCreated()
{
	Transform* t = GetOwner()->GetComponent<Transform>();
	t->SetSize(Block::TILE_SIZE * 1.5, Block::TILE_SIZE * 1.5);

	Entity::OnCreated();

	GetOwner()->AddTag("Enemy");

	SetLevel(rand() % 3 - 1 + difficulty);
	if (GetLevel() <= 0)
		SetLevel(1);

	int type = rand() % 2;

	Renderer* r = GetOwner()->GetComponent<Renderer>();
	r->SetTexture(ResourceManager::GetTexture("InsectEnemy"), 1, 1, 0, false);

	SetSpeed(75.0);

	currentReloadTime = reloadTime;

	World* world = (World*)SceneManager::GetCurrentScene()->FindObjectWithTag("World");
	world->UpdateEnemiesCount(1);
}

void Enemy::SetLevel(int L)
{
	Entity::SetLevel(L);

	reloadTime = max(0.3, 3.0);
	attackRadius = L * 5;
}

int Enemy::GetRewardScore()
{
	return GetLevel();
}

void Enemy::Move(double x, double y)
{
	Entity::Move(x, y);

	Renderer* r = GetOwner()->GetComponent<Renderer>();

	if (x < 0 && abs(y) < abs(x))
	{
		r->SetTexture(ResourceManager::GetTexture("InsectEnemyLeft"), 1, 1, 0, false);
	}
	else if (x > 0 && abs(y) < abs(x))
	{
		r->SetTexture(ResourceManager::GetTexture("InsectEnemyRight"), 1, 1, 0, false);
	}
	else if (y < 0)
	{
		r->SetTexture(ResourceManager::GetTexture("InsectEnemyBack"), 1, 1, 0, false);
	}
	else if (y > 0)
	{
		r->SetTexture(ResourceManager::GetTexture("InsectEnemy"), 1, 1, 0, false);
	}
}

void Enemy::Update()
{
	Entity::Update();

	Object* player = SceneManager::GetCurrentScene()->FindObjectWithTag("Player");
	if (player == NULL)
		return;

	Transform* pt = player->GetComponent<Transform>();
	Transform* t = GetOwner()->GetComponent<Transform>();

	double dirX = pt->GetXPosition() - t->GetXPosition();
	double dirY = pt->GetYPosition() - t->GetYPosition();

	double dist = sqrt(dirX * dirX + dirY * dirY);

	currentReloadTime -= Timer::GetDeltaTime();

	if (dist > attackRadius * Block::TILE_SIZE)
	{
		Move(dirX / dist * GetSpeed() * Timer::GetDeltaTime(), dirY / dist * GetSpeed() * Timer::GetDeltaTime());
	}
	else
	{
		if (currentReloadTime <= 0.0)
		{
			ObjectFactory::SpawnDefaultShell(
				GetOwner(),
				t->GetXPosition() + (dirX / dist * Block::TILE_SIZE / 2),
				t->GetYPosition() + (dirY / dist * Block::TILE_SIZE),
				dirX / dist * 400.0, dirY / dist * 400.0,
				GetDamage(), { 255, 0, 0, 255 });

			currentReloadTime = reloadTime;
		}
	}
}

void Enemy::OnKilled()
{
	Entity::OnKilled();

	Object* player = SceneManager::GetCurrentScene()->FindObjectWithTag("Player");

	__int64 scoreExp = GetRewardScore() << 32;
	scoreExp |= (__int64)GetLevel();
	MessageManager::SendMessage(GetOwner(), player, Message::OnPlayerKillEnemy, scoreExp);
}