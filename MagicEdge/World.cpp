#include "World.h"
#include "Camera.h"
#include "ObstacleMap.h"
#include "OrkEnemy.h"
#include "Boss.h"
#include "DifficultyInfo.h"
#include "AudioSystem.h"

World::World(string name) : Object(name)
{
	enemiesCount = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			for (int k = 0; k < HEIGHT; k++)
			{
				blocks[i][j][k] = NULL;
			}
		}
	}
}

void World::Generate()
{

}

void World::OnCreated()
{
	AudioSystem::Play(ResourceManager::GetAudio("BackMusic"), -1, "BackMusic");
}

void World::OnDestroyd()
{
	AudioSystem::Stop("BackMusic");
}

void World::Update()
{
	int left = (int)(Camera::GetXOffset() / Block::TILE_SIZE - 5);
	int right = (int)((Camera::GetXOffset() + Screen::GetWidth()) / Block::TILE_SIZE + 10);
	int top = (int)(Camera::GetYOffset() / Block::TILE_SIZE - 5);
	int bottom = (int)((Camera::GetYOffset() + Screen::GetHeight()) / Block::TILE_SIZE + 10);

	for (int i = max(0, left); i < min(WIDTH, right); i++)
	{
		for (int j = max(0, top); j < min(HEIGHT, bottom); j++)
		{
			blocks[0][i][j]->Update();
			blocks[1][i][j]->Update();
		}
	}

	if (SceneManager::GetCurrentScene()->GetSceneName() != "DesertScene")
	{
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

				int dist = (int)((x - player->GetXPosition() / Block::TILE_SIZE) * (x - player->GetXPosition() / Block::TILE_SIZE) +
					(y - player->GetYPosition() / Block::TILE_SIZE) * (y - player->GetYPosition() / Block::TILE_SIZE));

				if (dist <= 20)
				{
					continue;
				}

				break;
			}

			if (rand() % 100 > 20)
				(new InsectEnemy("Enemy"))->SetPosition(x * Block::TILE_SIZE, y * Block::TILE_SIZE);
			else
				(new OrkEnemy("Enemy"))->SetPosition(x * Block::TILE_SIZE, y * Block::TILE_SIZE);
		}
	}

	//if (rand() % 1000000 < 10)
	//{
	//	int x, y;
	//	while (true)
	//	{
	//		x = rand() % WIDTH;
	//		y = rand() % HEIGHT;

	//		if (ObstacleMap::IsObstacle(x, y))
	//		{
	//			continue;
	//		}

	//		break;
	//	}

	//	(new Boss("Enemy"))->SetPosition(x * Block::TILE_SIZE + Block::TILE_SIZE / 2, y * Block::TILE_SIZE + Block::TILE_SIZE / 2);
	//}
}

void World::Render()
{
	int left = (int)(Camera::GetXOffset() / Block::TILE_SIZE - 5);
	int right = (int)((Camera::GetXOffset() + Screen::GetWidth()) / Block::TILE_SIZE + 10);
	int top = (int)(Camera::GetYOffset() / Block::TILE_SIZE - 5);
	int bottom = (int)((Camera::GetYOffset() + Screen::GetHeight()) / Block::TILE_SIZE + 10);

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

void World::SetBlock(int x, int y, int layer, Block* block)
{
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT || layer < 0 || layer > 1)
		return;

	if (blocks[layer][x][y] != NULL)
	{
		delete blocks[layer][x][y];
	}

	blocks[layer][x][y] = block;
}