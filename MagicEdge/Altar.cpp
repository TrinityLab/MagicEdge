#include "Altar.h"
#include "ObstacleMap.h"
#include "Player.h"

Altar::Altar(int x, int y) : Block(x, y)
{
	SetTexture(ResourceManager::GetTexture("Altar"));
	ObstacleMap::SetObstacle(x, y, true);
}

string Altar::GetBlockName()
{
	return "Altar";
}

void Altar::Update()
{
	Player* player = (Player*)SceneManager::GetCurrentScene()->FindObject("Player");
	if (player == NULL)
		return;
	
	double dirX = player->GetXPosition() / TILE_SIZE - x;
	double dirY = player->GetYPosition() / TILE_SIZE - y;

	double dist = dirX * dirX + dirY * dirY;

	if (dist <= 5)
	{
		if (rand() % 1000 < 100)
		{
			player->setMana(player->getMana() + 1);
		}
	}
}