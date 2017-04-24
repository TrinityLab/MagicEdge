#include "DungeonScene.h"
#include "Dungeon.h"
#include "Player.h"
#include "ScoreTable.h"

string DungeonScene::GetSceneName()
{
	return "DungeonScene";
}

void DungeonScene::OnOpened()
{
	Dungeon* world = new Dungeon("World");
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
}

void DungeonScene::OnClosed()
{
	Scene::OnClosed();

	ScoreTable::SaveScore();
}