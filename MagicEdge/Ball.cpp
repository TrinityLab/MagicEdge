#include "Ball.h"
#include "Block.h"
#include "Player.h"
#include "InsectEnemy.h"
#include "SceneManager.h"
#include "Blood.h"
#include "ScoreTable.h"

Ball::Ball(string name, Entity* owner) : AnimatedObject(name)
{
	this->owner = owner;
	time = 10.0;
}

void Ball::setV(double VX, double VY)
{
	vx = VX;
	vy = VY;
}

void Ball::setDamage(int D)
{
	Damage = D;
}

int Ball::getDamage()
{
	return Damage;
}

void Ball::OnCreated()
{
	SetSize(Block::TILE_SIZE, Block::TILE_SIZE);
	SetTexture(ResourceManager::GetTexture("MagicBall"), 3, 1, 30, true);
}

void Ball::OnDestroyd()
{
	
}

void Ball::Update()
{
	AnimatedObject::Update();

	time -= Timer::GetDeltaTime();
	if (time <= 0)
	{
		Object::Destroy(this);
		return;
	}

	Move(vx*Timer::GetDeltaTime(), vy*Timer::GetDeltaTime());

	Player* player = (Player*)SceneManager::GetCurrentScene()->FindObject("Player");
	if (player == NULL)
		return;

	if (player != owner)
	{
		if (GetXPosition() >= player->GetXPosition() - player->GetXSize() / 2 && GetXPosition() <= player->GetXPosition() + player->GetXSize() / 2
			&& GetYPosition() <= player->GetYPosition() + player->GetYSize() / 2 && GetYPosition() >= player->GetYPosition() - player->GetYSize() / 2)
		{
			Object::Destroy(this);
			player->setHealth(player->getHealth() - Damage);

			(new Blood("Blood"))->SetPosition(player->GetXPosition(), player->GetYPosition());
		}
	}

	int count;
	InsectEnemy** objects = (InsectEnemy**)SceneManager::GetCurrentScene()->GetObjectsOfName("Enemy", &count);

	for (int i = 0; i < count; i++)
	{
		if (GetXPosition() >= objects[i]->GetXPosition() - objects[i]->GetXSize() / 2 && GetXPosition() <= objects[i]->GetXPosition() + objects[i]->GetXSize() / 2 &&
			GetYPosition() >= objects[i]->GetYPosition() - objects[i]->GetYSize() / 2 && GetYPosition() <= objects[i]->GetYPosition() + objects[i]->GetYSize() / 2)
		{
			if(objects[i] == owner)
				continue;

			objects[i]->setHealth(objects[i]->getHealth() - getDamage());
			Object::Destroy(this);

			if (objects[i]->getHealth() <= 0)
			{
				if (player->getExp() >= player->getLevel() * 100)
				{
					player->setLevel(player->getLevel() + 1);
					player->setExp(0);
				}
				else
				{
					double dirX = player->GetXPosition() / Block::TILE_SIZE - World::WIDTH / 2;
					double dirY = player->GetYPosition() / Block::TILE_SIZE - World::HEIGHT / 2;
					double dist = sqrt(dirX * dirX + dirY * dirY);

					player->setExp(player->getExp() + (int)(dist / 2));
				}

				ScoreTable::AddScore(objects[i]->GetScore());
				World* world = (World*)SceneManager::GetCurrentScene()->FindObject("World");
				world->UpdateEnemiesCount(-1);
			}

			(new Blood("Blood"))->SetPosition(objects[i]->GetXPosition(), objects[i]->GetYPosition());
		}
	}
}

void Ball::Render()
{
	SDL_SetTextureColorMod(GetTexture(), color.r, color.g, color.b);

	AnimatedObject::Render();

	SDL_SetTextureColorMod(GetTexture(), 255, 255, 255);
}

void Ball::SetColor(SDL_Color color)
{
	this->color = color;
}

SDL_Color Ball::GetColor()
{
	return color;
}