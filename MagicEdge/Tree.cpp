#include "StandardInc.h"
#include "Tree.h"
#include "ObstacleMap.h"
#include "ResourceManager.h"

Tree::Tree(int x, int y) : Block(x, y)
{
	SetTexture(ResourceManager::GetTexture("Tree"));
	ObstacleMap::SetObstacle(x, y, true);

	width = Block::TILE_SIZE;
	height = Block::TILE_SIZE * 2;

	xCenter = 0.5;
	yCenter = 0.75;
}

string Tree::GetBlockName()
{
	return "Tree";
}