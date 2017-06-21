#include "StandardInc.h"
#include "Dirt.h"
#include "ResourceManager.h"

Dirt::Dirt(int x, int y) : Block(x, y)
{
	SetTexture(ResourceManager::GetTexture("Dirt"));
}

string Dirt::GetBlockName()
{
	return "Dirt";
}