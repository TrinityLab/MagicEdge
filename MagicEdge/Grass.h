#pragma once

#include "System.h"
#include "Block.h"

class Grass : public Block
{
public:
	Grass(int x, int y);
	string GetBlockName() override;
};