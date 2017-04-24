#include "Grass.h"

Grass::Grass(int x, int y) : Block(x, y)
{
	SetTexture(ResourceManager::GetTexture("Grass"));
}

string Grass::GetBlockName()
{
	return "Grass";
}