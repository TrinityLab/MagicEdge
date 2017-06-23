#include "StandardInc.h"
#include "Entity.h"
#include "Camera.h"
#include "Object.h"
#include "CircleTrigger.h"
#include "ObjectFactory.h"

void Entity::SetExp(int E)
{
	exp = E;
	if (exp >= GetLevel() * 20)
		SetLevel(GetLevel() + 1);
}

void Entity::SetLevel(int L)
{
	GetOwner()->GetComponent<Mana>()->SetMaxMana(L * 25);
	GetOwner()->GetComponent<Health>()->SetMaxHealth(L * 25);

	damage = L * 10;

	GetOwner()->GetComponent<Mana>()->SetMana(L * 25);
	GetOwner()->GetComponent<Health>()->SetHealth(L * 25);

	exp = 0;
	level = L;

	SetSpeed(75 * pow(1.1, L));
}

int Entity::GetLevel()
{
	return level;
}

int Entity::GetExp()
{
	return exp;
}

void Entity::OnKilled()
{
	Object::Destroy(GetOwner());
}

void Entity::SetSpeed(double S)
{
	speed = S;
}

double Entity::GetSpeed()
{
	return speed;
}

void Entity::OnCreated()
{
	if(GetOwner()->GetComponent<Health>() == nullptr)
		GetOwner()->AddComponent<Health>();

	if(GetOwner()->GetComponent<Mana>() == nullptr)
		GetOwner()->AddComponent<Mana>();

	SetExp(0);
	SetLevel(1);

	if (GetOwner()->GetComponent<CircleTrigger>() == nullptr)
	{
		CircleTrigger* trigger = GetOwner()->AddComponent<CircleTrigger>();
		trigger->SetRadius(GetOwner()->GetComponent<Transform>()->GetXSize() * 0.5f);
	}
}

void Entity::Move(double x, double y)
{
	Transform* t = GetOwner()->GetComponent<Transform>();

	int xPos = (int)(t->GetXPosition() / Block::TILE_SIZE);
	int yPos = (int)(t->GetYPosition() / Block::TILE_SIZE);

	int xNewPos = (int)((t->GetXPosition() + x) / Block::TILE_SIZE);
	int yNewPos = (int)((t->GetYPosition() + y + Block::TILE_SIZE / 2) / Block::TILE_SIZE);

	if (ObstacleMap::IsObstacle(xNewPos, yNewPos))
		return;

	t->Move(x, y);
}

int Entity::GetDamage()
{
	return damage;
}

void Entity::TakeDamage(float damage)
{
	GetOwner()->GetComponent<Health>()->HealthDown(damage);

	ObjectFactory::SpawnBlood(
		GetOwner()->GetComponent<Transform>()->GetXPosition(),
		GetOwner()->GetComponent<Transform>()->GetYPosition());

	if (GetOwner()->GetComponent<Health>()->GetHealth() <= 0)
		OnKilled();
}

void Entity::OnCollide(Object* obj)
{
	if (obj->HasTag("Shell"))
	{
		if(obj->GetComponent<Shell>()->GetCreator() != GetOwner())
			TakeDamage(obj->GetComponent<Shell>()->GetDamage());
	}
}