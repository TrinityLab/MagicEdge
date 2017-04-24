#include "Portal.h"
#include "Player.h"

bool Portal::go;

Portal::Portal(string name) : AnimatedObject(name)
{
	go = false;
	SetTexture(ResourceManager::GetTexture("Portal"), 3, 1, 4, true);
	SetSize(Block::TILE_SIZE, Block::TILE_SIZE);
}

void Portal::Update()
{
	AnimatedObject::Update();

	Player* player = (Player*)SceneManager::GetCurrentScene()->FindObject("Player");
	if (player == NULL)
		return;

	double dirX = player->GetXPosition() - GetXPosition();
	double dirY = player->GetYPosition() - GetYPosition();

	double dist = sqrt(dirX * dirX + dirY * dirY);

	if (dist <= Block::TILE_SIZE)
	{
		go = true;
	}
}

bool Portal::NeedGo()
{
	return go;
}