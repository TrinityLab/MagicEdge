#pragma once

#include "System.h"
#include "Block.h"
#include "Grass.h"
#include "Dirt.h"

class World : public Object
{
public:
	World(string name);
	virtual void Generate();
	void Update();
	void Render();

	static const int WIDTH = 101;
	static const int HEIGHT = 101;

	virtual void OnCreated();
	virtual void OnDestroyd();

	void UpdateEnemiesCount(int add);

	string GetBlockType(int x, int y, int layer);
	void SetBlock(int x, int y, int layer, Block* block);
protected:
	int enemiesCount;
private:
	Block* blocks[2][WIDTH][HEIGHT];
};