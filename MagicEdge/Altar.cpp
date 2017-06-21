#include "StandardInc.h"
#include "Altar.h"
#include "ObstacleMap.h"
#include "Player.h"
#include "ResourceManager.h"
#include "SceneManager.h"

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
			Object* player = SceneManager::GetCurrentScene()->FindObjectWithTag("Player");
			if (player == nullptr)
				return;

			player->GetComponent<Mana>()->ManaUp(1);
		}
	}
}