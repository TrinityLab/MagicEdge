#include "Sand.h"

Sand::Sand(int x, int y) : Block(x, y)
{
	SetTexture(ResourceManager::GetTexture("Sand"));
}

string Sand::GetBlockName()
{
	return "Sand";
}