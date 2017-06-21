#include "StandardInc.h"
#include "DesertScene.h"
#include "Desert.h"
#include "Player.h"
#include "ScoreTable.h"
#include "BossEnemy.h"
#include "ObjectFactory.h"
#include "Scene.h"

string DesertScene::GetSceneName()
{
	return "DesertScene";
}

void DesertScene::OnOpened()
{
	Object* world = ObjectFactory::CreateDesert();
	world->GetComponent<Desert>()->Generate();

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

void DesertScene::OnClosed()
{
	Scene::OnClosed();

	ScoreTable::SaveScore();
}