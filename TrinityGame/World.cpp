#include "World.h"
#include "Camera.h"
#include "ObstacleMap.h"
#include "Enemy2.h"
#include "Boss.h"
#include "DifficultyInfo.h"

World::World(string name) : Object(name)
{
	enemiesCount = 0;
}

void World::Generate()
{

}

void World::Update()
{
	int left = Camera::GetXOffset() / Block::TILE_SIZE - 5;
	int right = (Camera::GetXOffset() + Screen::GetWidth()) / Block::TILE_SIZE + 10;
	int top = Camera::GetYOffset() / Block::TILE_SIZE - 5;
	int bottom = (Camera::GetYOffset() + Screen::GetHeight()) / Block::TILE_SIZE + 10;

	for (int i = max(0, left); i < min(WIDTH, right); i++)
	{
		for (int j = max(0, top); j < min(HEIGHT, bottom); j++)
		{
			blocks[0][i][j]->Update();
			blocks[1][i][j]->Update();
		}
	}

	if (enemiesCount < 150 && rand() % 10000 < 100 * difficulty)
	{
		int x;
		int y;

		while (true)
		{
			x = rand() % WIDTH;
			y = rand() % HEIGHT;

			if (ObstacleMap::IsObstacle(x, y))
				continue;

			Object* player = SceneManager::GetCurrentScene()->FindObject("Player");
			if (player == NULL)
				return;

			int dist = (x - player->GetXPosition() / Block::TILE_SIZE) * (x - player->GetXPosition() / Block::TILE_SIZE) +
				(y - player->GetYPosition() / Block::TILE_SIZE) * (y - player->GetYPosition() / Block::TILE_SIZE);

			if (dist <= 20)
			{
				continue;
			}

			break;
		}

		if(rand() % 100 > 20)
			(new Enemy("Enemy"))->SetPosition(x * Block::TILE_SIZE, y * Block::TILE_SIZE);
		else
			(new Enemy2("Enemy"))->SetPosition(x * Block::TILE_SIZE, y * Block::TILE_SIZE);
	}

	if (rand() % 1000000 < 10)
	{
		int x, y;
		while (true)
		{
			x = rand() % WIDTH;
			y = rand() % HEIGHT;

			if (ObstacleMap::IsObstacle(x, y))
			{
				continue;
			}

			break;
		}

		(new Boss("Enemy"))->SetPosition(x * Block::TILE_SIZE + Block::TILE_SIZE / 2, y * Block::TILE_SIZE + Block::TILE_SIZE / 2);
	}
}

void World::Render()
{
	int left = Camera::GetXOffset() / Block::TILE_SIZE - 5;
	int right = (Camera::GetXOffset() + Screen::GetWidth()) / Block::TILE_SIZE + 10;
	int top = Camera::GetYOffset() / Block::TILE_SIZE - 5;
	int bottom = (Camera::GetYOffset() + Screen::GetHeight()) / Block::TILE_SIZE + 10;

	for (int i = max(0, left); i < min(WIDTH, right); i++)
	{
		for (int j = max(0, top); j < min(HEIGHT, bottom); j++)
		{
			blocks[0][i][j]->Render();
		}
	}

	for (int i = max(0, left); i < min(WIDTH, right); i++)
	{
		for (int j = max(0, top); j < min(HEIGHT, bottom); j++)
		{
			blocks[1][i][j]->Render();
		}
	}
}

string World::GetBlockType(int x, int y, int layer)
{
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return "Unknown";

	return blocks[layer][x][y]->GetBlockName();
}

void World::UpdateEnemiesCount(int add)
{
	enemiesCount += add;
}