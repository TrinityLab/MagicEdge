#include "StandardInc.h"
#include "BossLocationScene.h"
#include "BossLocation.h"
#include "Player.h"
#include "ScoreTable.h"
#include "BossEnemy.h"
#include "ObjectFactory.h"
#include "Scene.h"

string BossLocationScene::GetSceneName()
{
	return "BossLocationScene";
}

void BossLocationScene::OnOpened()
{
	Object* world = ObjectFactory::CreateBossLocation();
	world->GetComponent<BossLocation>()->Generate();

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

	Object* player = ObjectFactory::SpawnPlayer(x * Block::TILE_SIZE, y * Block::TILE_SIZE);

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

	ObjectFactory::SpawnBossEnemy(x * Block::TILE_SIZE + Block::TILE_SIZE / 2, y * Block::TILE_SIZE + Block::TILE_SIZE / 2);
}

void BossLocationScene::OnClosed()
{
	Scene::OnClosed();

	ScoreTable::SaveScore();
}