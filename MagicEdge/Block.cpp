#include "Block.h"
#include "Camera.h"
#include "Player.h"

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
	SDL_Rect dstRect = { 
		(int)(-Camera::GetXOffset() + x * TILE_SIZE + TILE_SIZE / 2 - width * xCenter),
		(int)(-Camera::GetYOffset() + y * TILE_SIZE + TILE_SIZE / 2 - height * yCenter),
		width, height };

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

double Block::GetDistanceToPlayer()
{
	Player* player = (Player*)SceneManager::GetCurrentScene()->FindObjectWithTag("Player");
	if (player == NULL)
		return INT_MAX;

	double dirX = x * TILE_SIZE - player->GetXPosition();
	double dirY = y * TILE_SIZE - player->GetYPosition();

	double dist = sqrt(dirX * dirX + dirY * dirY);

	return dist;
}