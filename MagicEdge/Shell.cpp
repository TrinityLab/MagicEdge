#include "StandardInc.h"
#include "Shell.h"
#include "ObjectFactory.h"
#include "ResourceManager.h"
#include "Timer.h"
#include "SceneManager.h"
#include "AudioSystem.h"
#include "Player.h"
#include "ScoreTable.h"
#include "CircleTrigger.h"

void Shell::OnCreated()
{
	GetOwner()->AddTag("Shell");

	GetOwner()->GetComponent<Transform>()->SetSize(Block::TILE_SIZE * 0.8f, Block::TILE_SIZE * 0.8f);
	GetOwner()->GetComponent<Renderer>()->SetTexture(ResourceManager::GetTexture("MagicBall"), 3, 1, 30, true);

	CircleTrigger* trigger = GetOwner()->AddComponent<CircleTrigger>();
	trigger->SetRadius(Block::TILE_SIZE * 0.4f);
}

void Shell::SetVelocity(float vx, float vy)
{
	this->vx = vx;
	this->vy = vy;
}

void Shell::SetDamage(float d)
{
	damage = d;
}

float Shell::GetDamage()
{
	return damage;
}

void Shell::SetColor(SDL_Color c)
{
	color = c;
}

SDL_Color Shell::GetColor()
{
	return color;
}

void Shell::Update()
{
	time -= Timer::GetDeltaTime();
	if (time <= 0)
	{
		Object::Destroy(GetOwner());
		return;
	}

	Transform* t = GetOwner()->GetComponent<Transform>();

	t->Move(vx*Timer::GetDeltaTime(), vy*Timer::GetDeltaTime());
}

void Shell::SetCreator(Object* obj)
{
	creator = obj;
}

void Shell::OnCollide(Object* otherObject)
{
	if (otherObject != creator)
		Object::Destroy(GetOwner());
	else if (otherObject->HasTag("Shell") && otherObject->GetComponent<Shell>()->GetCreator() != creator)
		Object::Destroy(GetOwner());
}

Object* Shell::GetCreator()
{
	return creator;
}