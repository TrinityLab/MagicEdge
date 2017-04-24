#pragma once

#include "Block.h"

class Tump: public Block
{
public:
	Tump(int x, int y);
	string GetBlockName() override;
};