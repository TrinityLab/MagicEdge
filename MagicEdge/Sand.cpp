#include "StandardInc.h"
#include "Sand.h"
#include "ResourceManager.h"

Sand::Sand(int x, int y) : Block(x, y)
{
	SetTexture(ResourceManager::GetTexture("Sand"));
}

string Sand::GetBlockName()
{
	return "Sand";
}