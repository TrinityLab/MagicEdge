#pragma once

#include "World.h"

class ObstacleMap
{
private:
	static int data[World::WIDTH][World::HEIGHT];
public:
	static void SetObstacle(int x, int y, bool obstacle);
	static bool IsObstacle(int x, int y);
};