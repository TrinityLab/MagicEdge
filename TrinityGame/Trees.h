#pragma once

#include "Block.h"

class Trees: public Block
{
public:
	Trees(int x, int y);
	string GetBlockName() override;
};