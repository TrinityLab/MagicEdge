#include "Blood.h"
#include "ResourceManager.h"
#include "Timer.h"
#include "Block.h"

Blood::Blood(string name) : AnimatedObject(name)
{
	time = 0.5;

	SetSize(Block::TILE_SIZE * 1.5, Block::TILE_SIZE * 1.5);
	SetTexture(ResourceManager::GetTexture("Blood"), 4, 1, 8, false);
}

void Blood::Update()
{
	AnimatedObject::Update();

	time -= Timer::GetDeltaTime();

	if (time <= 0)
	{
		Object::Destroy(this);
	}
}