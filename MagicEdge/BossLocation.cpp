#include "StandardInc.h"
#include "BossLocation.h"
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
#include "BossEnemy.h"
#include "Stone.h"

void BossLocation::Generate()
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
			SetBlock(i, j, 0, new Stone(i, j));
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
	/*		if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= (r-3) * (r-3) && (i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) > (r-4) * (r-4))
			{
				SetBlock(i, j, 0, new Dirt(i, j));
			}

		

			if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= (r-1) * (r-1) && (i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) >(r - 3) * (r - 3))
			{
				SetBlock(i, j, 1, new Sand(i, j));
			}

			if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= (r - 4) * (r - 4) && (i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) >(r - 10) * (r - 10))
			{
				SetBlock(i, j, 1, new Stone(i, j));
			}

			if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= (r - 10) * (r - 10) && (i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) >(r - 13) * (r - 13))
			{
				SetBlock(i, j, 1, new Sand(i, j));
			}

			if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= (r - 14) * (r - 14) && (i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) >(r - 18) * (r - 18))
			{
				SetBlock(i, j, 1, new Dirt(i, j));
			}


			if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= (r - 18) * (r - 18) && (i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) >(r - 26) * (r - 26))
			{
				SetBlock(i, j, 1, new Grass(i, j));
			}

			if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= (r - 13) * (r - 13) && (i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) >(r - 14) * (r - 14))
			{
				SetBlock(i, j, 1, new Sand(i, j));
			}
*/

			if(i==centerX || j== centerY)
				SetBlock(i, j, 0, new Sand(i, j));

			if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) > r * r)
			{
				SetBlock(i, j, 0, new Water(i, j));
				SetBlock(i, j, 1, new VoidBlock(i, j));
			}

			if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= (r-28) * (r-28) && (i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) >(r - 32) * (r - 32))
			{
				SetBlock(i, j, 0, new Sand(i, j));
			}

			if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= r * r && (i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) >(r - 2) * (r - 2))
			{
				SetBlock(i, j, 0, new Sand(i, j));
			}

			if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= r * r && (i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) >(r - 1) * (r - 1))
			{	
				SetBlock(i, j, 1, new Trees2(i, j));
				
			}

			if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= (r-1) * (r-1) && (i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) >(r - 28) * (r - 28)
				&& i != centerX && j!= centerY)
			{
				SetBlock(i, j, 0, new Grass(i, j));
			}


			else
			{
		/*		if (rand() % 1000 <= 1)
				{
					for (int ix = i + 3; ix < i + 10; ix++)
					{
						for (int jx = j + rand() % 3; jx < j + 3 + rand() % 9; jx++)
						{
							if (!ObstacleMap::IsObstacle(ix, jx))
								SetBlock(ix, jx, 0, new Stone(ix, jx));
						}
					}
				}*/
			/*	if (rand() % 10000 <= 8)
				{
					for (int ix = i + 3; ix < i + 9; ix++)
						for (int jx = j + rand() % 3; jx < j + 3 + rand() % 9; jx++)
						{
							SetBlock(ix, jx, 0, new Water(ix, jx));
						}
				}
*/
				//if (rand() % 10000 <= 8)
				//{
				//	for (int ix = i + 3; ix < i + 9; ix++)
				//		for (int jx = j + rand() % 3; jx < j + 3 + rand() % 9; jx++)
				//		{
				//			SetBlock(ix, jx, 0, new Stone(ix, jx));
				//		}
				//}
			}

		

		}
	}

	/*for (int i = 0; i < WIDTH; i++)
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
	}*/

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

	//(new Portal("Portal"))->SetPosition(x * Block::TILE_SIZE + Block::TILE_SIZE / 2, y * Block::TILE_SIZE + Block::TILE_SIZE / 2);
}

void BossLocation::OnCreated()
{
	World::OnCreated();
}

void BossLocation::OnDestroyd()
{
	World::OnDestroyd();
}