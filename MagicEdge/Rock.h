#pragma once

#include "Block.h"

class Rock : public Block
{
public:
	Rock(int x, int y);
	string GetBlockName() override;
};