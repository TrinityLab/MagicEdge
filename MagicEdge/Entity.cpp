#include "Entity.h"
#include "Camera.h"

Entity::Entity(string name) : AnimatedObject(name), CircleTrigger(Block::TILE_SIZE * 0.5f, &xPosition, &yPosition)
{
	
}

void Entity::setExp(int E)
{
	exp = E;
}

void Entity::setLevel(int L)
{
	MaxMana = L * 25;
	MaxHealth = L * 25;
	damage = L * 10;

	Health = MaxHealth;
	Mana = MaxMana;

	exp = 0;
	Level = L;

	setSpeed(75 * pow(1.1, L));
}

int Entity::getLevel()
{
	return Level;
}

int Entity::getExp()
{
	return exp;
}

int Entity::GetMaxMana()
{
	return MaxMana;
}

int Entity::GetMaxHealth()
{
	return MaxHealth;
}

void Entity::setHealth(int h)
{
	Health = h;

	if (Health <= 0)
	{
		Object::Destroy(this);
	}
}

int Entity::getHealth()
{
	return Health;
}

void Entity::setMana(int M)
{
	if (M >= MaxMana)
		Mana=MaxMana;
	else Mana = M;
}
int Entity::getMana()
{
	return Mana;
}

void Entity::setSpeed(double S)
{
	Speed = S;
}

double Entity::getSpeed()
{
	return Speed;
}

void Entity::OnCreated()
{
	setExp(0);
	setLevel(1);
}

void Entity::OnDestroyd()
{

}

void Entity::Update()
{
	AnimatedObject::Update();
}

void Entity::Move(double x, double y)
{
	int xPos = (int)(xPosition / Block::TILE_SIZE);
	int yPos = (int)(yPosition / Block::TILE_SIZE);

	int xNewPos = (int)((xPosition + x) / Block::TILE_SIZE);
	int yNewPos = (int)((yPosition + y + Block::TILE_SIZE / 2) / Block::TILE_SIZE);

	if (ObstacleMap::IsObstacle(xNewPos, yNewPos))
		return;

	xPosition += x;
	yPosition += y;
}

int Entity::getDamage()
{
	return damage;
}

void Entity::Render()
{
	AnimatedObject::Render();
}

void Entity::OnObjectCollide(IEventListener* other)
{

}