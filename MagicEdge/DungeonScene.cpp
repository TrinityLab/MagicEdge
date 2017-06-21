#include "StandardInc.h"
#include "DungeonScene.h"
#include "Dungeon.h"
#include "Player.h"
#include "ScoreTable.h"
#include "ObjectFactory.h"
#include "Scene.h"

string DungeonScene::GetSceneName()
{
	return "DungeonScene";
}

void DungeonScene::OnOpened()
{
	Object* world = ObjectFactory::CreateDungeon();
	world->GetComponent<Dungeon>()->Generate();

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
}

void DungeonScene::OnClosed()
{
	Scene::OnClosed();

	ScoreTable::SaveScore();
}