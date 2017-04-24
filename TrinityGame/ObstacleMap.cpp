#include "ObstacleMap.h"

int ObstacleMap::data[World::WIDTH][World::HEIGHT] = {};

void ObstacleMap::SetObstacle(int x, int y, bool obstacle)
{
	data[x][y] = obstacle;
}

bool ObstacleMap::IsObstacle(int x, int y)
{
	return data[x][y];
}