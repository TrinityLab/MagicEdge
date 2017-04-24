#pragma once

#include "TrinityFramework.h"
#include "Block.h"
#include "Grass.h"
#include "Dirt.h"

class World : public Object
{
protected:
	int enemiesCount;
public:
	World(string name);
	virtual void Generate();
	void Update();
	void Render();

	static const int WIDTH = 101;
	static const int HEIGHT = 101;

	virtual void OnCreated() = 0;
	virtual void OnDestroyd() = 0;

	void UpdateEnemiesCount(int add);

	string GetBlockType(int x, int y, int layer);
protected:
	Block* blocks[2][WIDTH][HEIGHT];
};