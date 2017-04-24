#include "Dirt.h"

Dirt::Dirt(int x, int y) : Block(x, y)
{
	SetTexture(ResourceManager::GetTexture("Dirt"));
}

string Dirt::GetBlockName()
{
	return "Dirt";
}