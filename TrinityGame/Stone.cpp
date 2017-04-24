#include "Stone.h"

Stone::Stone(int x, int y) : Block(x, y)
{
	SetTexture(ResourceManager::GetTexture("Stone"));
}

string Stone::GetBlockName()
{
	return "Stone";
}