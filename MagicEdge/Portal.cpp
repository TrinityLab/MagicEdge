#include "Portal.h"
#include "Player.h"

bool Portal::go;

Portal::Portal(string name) : AnimatedObject()
{
	go = false;
	SetTexture(ResourceManager::GetTexture("Portal"), 3, 1, 0, false);
	SetSize(Block::TILE_SIZE, Block::TILE_SIZE);

	AddTag(name);
}

void Portal::Update()
{
	AnimatedObject::Update();

	Player* player = (Player*)SceneManager::GetCurrentScene()->FindObjectWithTag("Player");
	if (player == NULL)
		return;

	double dirX = player->GetXPosition() - GetXPosition();
	double dirY = player->GetYPosition() - GetYPosition();

	double dist = sqrt(dirX * dirX + dirY * dirY);
	
	if (player->getLevel() >= 1)
	{
		if (dist <= Block::TILE_SIZE)
		{
			go = true;
		}
	}
}

bool Portal::NeedGo()
{
	return go;
}