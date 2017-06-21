#pragma once

#include "Block.h"

class Grass : public Block
{
public:
	Grass(int x, int y);
	string GetBlockName() override;
};