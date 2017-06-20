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
	if (GetDistanceToPlayer() < 10 * TILE_SIZE)
	{
		if (rand() % 1000 < 100)
		{
			Player* player = (Player*)SceneManager::GetCurrentScene()->FindObjectWithTag("Player");
			if (player == NULL)
				return;

			player->setMana(player->getMana() + 1);
		}
	}
}