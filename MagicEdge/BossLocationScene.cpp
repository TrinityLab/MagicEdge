#include "BossLocationScene.h"
#include "BossLocation.h"
#include "Player.h"
#include "ScoreTable.h"
#include "Boss.h"

string BossLocationScene::GetSceneName()
{
	return "BossLocationScene";
}

void BossLocationScene::OnOpened()
{
	BossLocation* world = new BossLocation("World");
	world->Generate();

	Player* player = new Player("Player");

	int x, y;
	while (true)
	{
		x = World::WIDTH / 4 + rand() % World::WIDTH / 2;
		y = World::HEIGHT / 4 + rand() % World::HEIGHT / 2;

		if (!ObstacleMap::IsObstacle(x, y))
		{
			break;
		}
	}

	player->SetPosition(x * Block::TILE_SIZE, y * Block::TILE_SIZE);

	int xb, yb;
	while (true)
	{
		xb = rand() % World::WIDTH;
		yb = rand() % World::HEIGHT;

		if (ObstacleMap::IsObstacle(xb, yb))
		{
			continue;
		}
		break;
	}

	(new Boss("Enemy"))->SetPosition(x * Block::TILE_SIZE + Block::TILE_SIZE / 2, y * Block::TILE_SIZE + Block::TILE_SIZE / 2);

}

void BossLocationScene::OnClosed()
{
	Scene::OnClosed();

	ScoreTable::SaveScore();
}