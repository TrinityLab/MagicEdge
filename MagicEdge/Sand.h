#pragma once

#include "Block.h"

class Sand: public Block
{
public:
	Sand(int x, int y);
	string GetBlockName() override;
};