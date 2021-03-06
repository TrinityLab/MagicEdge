#include "Desert.h"
#include "Player.h"
#include "time.h"
#include "Altar.h"
#include "Sand.h"
#include "ObstacleMap.h"
#include "Rock.h"
#include "VoidBlock.h"
#include "Water.h"
#include "Trees2.h"
#include "Tump.h"
#include "Portal.h"
#include "ScoreTable.h"
#include "Boss.h"
#include "Stone.h"

Desert::Desert(string name) : Overworld(name)
{

}

void Desert::Generate()
{
	enemiesCount = 0;

	srand(time(0));

	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			ObstacleMap::SetObstacle(x, y, false);
		}
	}

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < World::HEIGHT; j++)
		{
			SetBlock(i, j, 0, new Sand(i, j));
			SetBlock(i, j, 1, new VoidBlock(i, j));
		}
	}

	SetBlock(50, 50, 1, new Altar(50, 50));

	int centerX = WIDTH / 2;
	int centerY = HEIGHT / 2;

	double r = WIDTH / 2 - 18;

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) > r * r)
			{
				SetBlock(i, j, 0, new Water(i, j));
				SetBlock(i, j, 1, new VoidBlock(i, j));
			}
			else
			{
				if (rand() % 1000 <= 1)
				{
					for (int ix = i + 3; ix < i + 10; ix++)
					{
						for (int jx = j + rand() % 3; jx < j + 3 + rand() % 9; jx++)
						{
							if (!ObstacleMap::IsObstacle(ix, jx))
								SetBlock(ix, jx, 0, new Dirt(ix, jx));
						}
					}
				}
				if (rand() % 10000 <= 8)
				{
					for (int ix = i + 3; ix < i + 9; ix++)
						for (int jx = j + rand() % 3; jx < j + 3 + rand() % 9; jx++)
						{
							SetBlock(ix, jx, 0, new Water(ix, jx));
						}
				}

				if (rand() % 10000 <= 8)
				{
					for (int ix = i + 3; ix < i + 9; ix++)
						for (int jx = j + rand() % 3; jx < j + 3 + rand() % 9; jx++)
						{
							SetBlock(ix, jx, 0, new Stone(ix, jx));
						}
				}
			}

		}
	}

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < World::HEIGHT; j++)
		{
			if (ObstacleMap::IsObstacle(i, j))
				continue;

			if (rand() % 1000 < 9)
				SetBlock(i, j, 1, new Rock(i, j));
			if (rand() % 1000 < 2)
				SetBlock(i, j, 1, new Tump(i, j));
			if (rand() % 1000 < 9)
				SetBlock(i, j, 1, new Trees2(i, j));
		}
	}

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

	(new Portal("Portal"))->SetPosition(x * Block::TILE_SIZE + Block::TILE_SIZE / 2, y * Block::TILE_SIZE + Block::TILE_SIZE / 2);
}

void Desert::OnCreated()
{

}

void Desert::OnDestroyd()
{

}