#include "Dungeon.h"
#include "Player.h"
#include "time.h"
#include "Altar.h"
#include "Stone.h"
#include "ObstacleMap.h"
#include "Rock.h"
#include "VoidBlock.h"
#include "Water.h"
#include "Trees2.h"
#include "Tump.h"
#include "Portal.h"
#include "ScoreTable.h"
#include "Boss.h"

Dungeon::Dungeon(string name) : World(name)
{
	
}

void Dungeon::Generate()
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
			blocks[0][i][j] = new Stone(i, j);
			blocks[1][i][j] = new VoidBlock(i, j);
		}
	}

	blocks[1][50][50] = new Altar(50, 50);

	int centerX = WIDTH / 2;
	int centerY = HEIGHT / 2;

	double r = WIDTH / 2 - 18;

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) > r * r)
			{
				delete blocks[0][i][j];
				delete blocks[1][i][j];

				blocks[0][i][j] = new Water(i, j);
				blocks[1][i][j] = new VoidBlock(i, j);
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
								blocks[0][ix][jx] = new Dirt(ix, jx);
						}
					}
				}
				if (rand() % 10000 <= 8)
				{
					for (int ix = i + 3; ix < i + 9; ix++)
						for (int jx = j + rand() % 3; jx < j + 3 + rand() % 9; jx++)
						{
							blocks[0][ix][jx] = new Water(ix, jx);
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
				blocks[1][i][j] = new Rock(i, j);
			if (rand() % 1000 < 2)
				blocks[1][i][j] = new Tump(i, j);
			if (rand() % 1000 < 9)
				blocks[1][i][j] = new Trees2(i, j);
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

void Dungeon::OnCreated()
{

}

void Dungeon::OnDestroyd()
{

}