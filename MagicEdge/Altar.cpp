#include "Altar.h"
#include "ObstacleMap.h"
#include "Player.h"

Altar::Altar(int x, int y) : Block(x, y)
{
	SetTexture(ResourceManager::GetTexture("Altar"));
	ObstacleMap::SetObstacle(x, y, true);
}

string Altar::GetBlockName()
{
	return "Altar";
}
