#include "Water.h"
#include "ObstacleMap.h"

Water::Water(int x, int y) : Block(x, y)
{
	SetTexture(ResourceManager::GetTexture("Water"));

	ObstacleMap::SetObstacle(x, y, true);
}

string Water::GetBlockName()
{
	return "Water";
}