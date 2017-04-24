#include "Tump.h"
#include "ObstacleMap.h"

Tump::Tump(int x, int y) : Block(x, y)
{
	SetTexture(ResourceManager::GetTexture("Tump"));

	ObstacleMap::SetObstacle(x, y, true);

	width = Block::TILE_SIZE * 0.75;
	height = Block::TILE_SIZE * 0.75;
}

string Tump::GetBlockName()
{
	return "Tump";
}