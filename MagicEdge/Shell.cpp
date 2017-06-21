#include "StandardInc.h"
#include "Shell.h"
#include "ObjectFactory.h"
#include "ResourceManager.h"
#include "Timer.h"
#include "SceneManager.h"
#include "AudioSystem.h"
#include "Player.h"
#include "ScoreTable.h"

void Shell::OnCreated()
{
	GetOwner()->AddTag("Shell");

	GetOwner()->GetComponent<Transform>()->SetSize(Block::TILE_SIZE * 0.5f, Block::TILE_SIZE * 0.5f);
	GetOwner()->GetComponent<Renderer>()->SetTexture(ResourceManager::GetTexture("MagicBall"), 3, 1, 30, true);
}

void Shell::SetVelocity(float vx, float vy)
{
	this->vx = vx;
	this->vy = vy;
}

void Shell::SetDamage(float d)
{
	damage = d;
}

float Shell::GetDamage()
{
	return damage;
}

void Shell::SetColor(SDL_Color c)
{
	color = c;
}

SDL_Color Shell::GetColor()
{
	return color;
}

void Shell::Update()
{
	time -= Timer::GetDeltaTime();
	if (time <= 0)
	{
		Object::Destroy(GetOwner());
		return;
	}

	Transform* t = GetOwner()->GetComponent<Transform>();

	t->Move(vx*Timer::GetDeltaTime(), vy*Timer::GetDeltaTime());

	Object* player = SceneManager::GetCurrentScene()->FindObjectWithTag("Player");
	if (player == NULL)
		return;

	Transform* pt = player->GetComponent<Transform>();

	if (player != owner)
	{
		if (t->GetXPosition() >= pt->GetXPosition() - pt->GetXSize() / 2 && t->GetXPosition() <= pt->GetXPosition() + pt->GetXSize() / 2
			&& t->GetYPosition() <= pt->GetYPosition() + pt->GetYSize() / 2 && t->GetYPosition() >= pt->GetYPosition() - pt->GetYSize() / 2)
		{
			Object::Destroy(GetOwner());
			player->GetComponent<Health>()->SetHealth(player->GetComponent<Health>()->GetHealth() - damage);

			ObjectFactory::SpawnBlood(pt->GetXPosition(), pt->GetYPosition());
		}
	}

	int count;
	Object** objects = SceneManager::GetCurrentScene()->FindObjectsWithTag("Enemy", &count);

	for (int i = 0; i < count; i++)
	{
		Transform* ot = objects[i]->GetComponent<Transform>();

		if (t->GetXPosition() >= ot->GetXPosition() - ot->GetXSize() / 2 && t->GetXPosition() <= ot->GetXPosition() + ot->GetXSize() / 2 &&
			t->GetYPosition() >= ot->GetYPosition() - ot->GetYSize() / 2 && t->GetYPosition() <= ot->GetYPosition() + ot->GetYSize() / 2)
		{
			if (objects[i] == owner)
				continue;

			objects[i]->GetComponent<Health>()->HealthDown(GetDamage());
			Object::Destroy(GetOwner());

			AudioSystem::Play(ResourceManager::GetAudio("EnemyDamageSound"), 1);

			if (objects[i]->GetComponent<Health>()->GetHealth() <= 0)
			{
				double dirX = pt->GetXPosition() / Block::TILE_SIZE - World::WIDTH / 2;
				double dirY = pt->GetYPosition() / Block::TILE_SIZE - World::HEIGHT / 2;
				double dist = sqrt(dirX * dirX + dirY * dirY);

				Player* pl = player->GetComponent<Player>();

				if ((pl->GetExp() + (int)(dist / 2)) >= pl->GetLevel() * 100)
				{
					pl->SetLevel(pl->GetLevel() + 1);
					pl->SetExp(0);
				}
				else
				{
					pl->SetExp(pl->GetExp() + (int)(dist / 2));
				}

				ScoreTable::AddScore(objects[i]->GetComponent<Enemy>()->GetRewardScore());
				World* world = (World*)SceneManager::GetCurrentScene()->FindObjectWithTag("World");
				world->UpdateEnemiesCount(-1);
			}

			ObjectFactory::SpawnBlood(ot->GetXPosition(), ot->GetYPosition());
		}
	}
}

void Shell::SetCreator(Object* obj)
{
	creator = obj;
}