#include "StandardInc.h"
#include "Entity.h"
#include "Camera.h"
#include "Object.h"

void Entity::SetExp(int E)
{
	exp = E;
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

void Entity::OnEnabled()
{
	GetOwner()->AddComponent<Health>();
	GetOwner()->AddComponent<Mana>();
	GetOwner()->AddComponent<Renderer>();

	SetExp(0);
	SetLevel(1);
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
