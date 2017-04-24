#pragma once

#include "Block.h"

class Water : public Block
{
public:
	Water(int x, int y);
	string GetBlockName() override;
};