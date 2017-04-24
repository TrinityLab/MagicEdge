#pragma once

#include "SDL.h"
#include "System.h"

class Block
{
protected:
	int x, y;
	int width, height;
	double xCenter, yCenter;
	SDL_Texture* texture;
public:
	Block(int x, int y);
	~Block();
	virtual void Update();
	virtual void Render();
	virtual void OnPlayerInteract();
	virtual bool IsObstacle();
	virtual string GetBlockName() = 0;
	double GetDistanceToPlayer();
	void SetTexture(SDL_Texture* texture);
	SDL_Texture* GetTexture();

	static const int TILE_SIZE = 50;
};