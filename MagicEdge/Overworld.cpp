#include "Overworld.h"
#include "VoidBlock.h"
#include "Water.h"
#include "Sand.h"
#include "time.h"
#include "Stone.h"
#include "Tree.h"
#include "Rock.h"
#include "Tump.h"
#include "ObstacleMap.h"
#include "Trees2.h"
#include "Altar.h"
#include "Portal.h"
#include "ScoreTable.h"
#include "Boss.h"

Overworld::Overworld(string name) : World(name)
{
	
}

void Overworld::Generate()
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
			SetBlock(i, j, 0, new Grass(i, j));
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
			}

			if (((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY)) == r * r)
			{
				SetBlock(i, j, 1, new Tree(i, j));
				
			}

			if (rand() % 1000 <= 10 && ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) - 15 > r*r))
			{
				for (int ix = i + 3; ix < i + 11; ix++)
					for (int jx = j + rand() % 3; jx < j + 3 + rand() % 10; jx++)
					{
						if (!ObstacleMap::IsObstacle(ix, jx))
							SetBlock(ix, jx, 0, new Sand(ix, jx));
					}
			}


			if (rand() % 1000 <= 1 /*&& ((i - centerX) * (i - centerX)+ (j - centerY) * (j - centerY) - 10>r*r)*/)
			{
				for (int ix = i + 3; ix < i + 11; ix++)
					for (int jx = j + rand() % 3; jx < j + 3 + rand() % 9; jx++)
					{
						if (!ObstacleMap::IsObstacle(ix, jx))
							SetBlock(ix, jx, 0, new Stone(ix, jx));
					}
			}
		}
	}

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < World::HEIGHT; j++)
		{
			if(ObstacleMap::IsObstacle(i, j))
				continue;

			if (rand() % 1000 < 9)
				SetBlock(i, j, 1, new Tree(i, j));
			if (rand() % 1000 < 9)
				SetBlock(i, j, 1, new Rock(i, j));
			if (rand() % 1000 < 2)
				SetBlock(i, j, 1, new Tump(i, j));
			if (rand() % 1000 < 3)
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

void Overworld::OnCreated()
{
	World::OnCreated();
}

void Overworld::OnDestroyd()
{
	World::OnDestroyd();
}
