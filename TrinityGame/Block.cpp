#include "Block.h"
#include "Camera.h"

Block::Block(int x, int y)
{
	this->x = x;
	this->y = y;

	this->width = TILE_SIZE;
	this->height = TILE_SIZE;

	xCenter = yCenter = 0.5;
}

void Block::Update()
{

}

void Block::OnPlayerInteract()
{

}

void Block::Render()
{
	int w, h;

	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	SDL_Rect srcRect = { 0, 0, w, h };
	SDL_Rect dstRect = { -Camera::GetXOffset() + x * TILE_SIZE + TILE_SIZE / 2 - (int)(width * xCenter), -Camera::GetYOffset() + y * TILE_SIZE + TILE_SIZE / 2 - (int)(height * yCenter), width, height };

	SDL_RenderCopy(Screen::GetRenderer(), texture, &srcRect, &dstRect);
}

bool Block::IsObstacle()
{
	return false;
}

Block::~Block()
{

}

void Block::SetTexture(SDL_Texture* texture)
{
	this->texture = texture;
}

SDL_Texture* Block::GetTexture()
{
	return texture;
}