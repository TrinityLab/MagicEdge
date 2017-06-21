#include "StandardInc.h"
#include "Stone.h"
#include "ResourceManager.h"

Stone::Stone(int x, int y) : Block(x, y)
{
	SetTexture(ResourceManager::GetTexture("Stone"));
}

string Stone::GetBlockName()
{
	return "Stone";
}