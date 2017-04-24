#pragma once

#include "Block.h"

class Tree : public Block
{
public:
	Tree(int x, int y);
	virtual string GetBlockName() override;
};