#include "Trees.h"
#include "ObstacleMap.h"

Trees::Trees(int x, int y) : Block(x, y)
{
	SetTexture(ResourceManager::GetTexture("Trees"));
	ObstacleMap::SetObstacle(x, y, true);

	width = Block::TILE_SIZE;
	height = Block::TILE_SIZE * 2;

	xCenter = 0.5;
	yCenter = 0.75;
}

string Trees::GetBlockName()
{
	return "Trees";
}