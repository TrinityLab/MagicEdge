#pragma once
#include "TrinityFramework.h"
#include "Block.h"
#include "ObstacleMap.h"

class Entity : public AnimatedObject
{
protected:
	int Mana;
	int Health;
	double Speed;
	int MaxMana;
	int MaxHealth;
	int Level;
	int exp;
	int damage;
public:
	Entity(string name);
	virtual void Update() override;
	virtual void Render() override;
	virtual void OnCreated() override;
	virtual void OnDestroyd() override;
	virtual void setLevel(int L);
	virtual void setExp(int E);
	int getLevel();
	int getExp();
	int GetMaxMana();
	void Move(double deltaX, double deltaY);
	void setSpeed(double speed);
	double getSpeed();
	void setMana(int mana);
	int getMana();
	virtual void setHealth(int health);
	int getHealth();
	int GetMaxHealth();
	int getDamage();
};

