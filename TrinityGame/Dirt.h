#pragma once

#include "Block.h"

class Dirt : public Block
{
public:
	Dirt(int x, int y);
	string GetBlockName() override;
};