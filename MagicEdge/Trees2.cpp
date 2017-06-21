#include "StandardInc.h"
#include "Trees2.h"
#include "ObstacleMap.h"
#include "ResourceManager.h"

Trees2::Trees2(int x, int y) : Block(x, y)
{
	SetTexture(ResourceManager::GetTexture("Trees2"));
	ObstacleMap::SetObstacle(x, y, true);

	width = Block::TILE_SIZE;
	height = Block::TILE_SIZE * 2;

	xCenter = 0.5;
	yCenter = 0.75;
}

string Trees2::GetBlockName()
{
	return "Trees2";
}