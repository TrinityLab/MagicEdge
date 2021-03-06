#include "Rock.h"
#include "ObstacleMap.h"

Rock::Rock(int x, int y) : Block(x, y)
{
	SetTexture(ResourceManager::GetTexture("Rock"));
	ObstacleMap::SetObstacle(x, y, true);
}

string Rock::GetBlockName()
{
	return "Rock";
}