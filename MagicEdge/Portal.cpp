#include "StandardInc.h"
#include "Portal.h"
#include "Player.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Object.h"
#include "SceneManager.h"

bool Portal::go;

void Portal::OnEnabled()
{
	Renderer* r = GetOwner()->GetComponent<Renderer>();
	if (r == nullptr)
		r = GetOwner()->AddComponent<Renderer>();

	go = false;
	r->SetTexture(ResourceManager::GetTexture("Portal"), 3, 1, 0, false);
	GetOwner()->AddTag("Portal");
}

void Portal::Update()
{
	Object* player = SceneManager::GetCurrentScene()->FindObjectWithTag("Player");
	if (player == nullptr)
		return;

	Transform* t = player->GetComponent<Transform>();

	double dirX = t->GetXPosition() - t->GetXPosition();
	double dirY = t->GetYPosition() - t->GetYPosition();

	double dist = sqrt(dirX * dirX + dirY * dirY);
	
	if (player->GetComponent<Player>()->GetLevel() >= 1)
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