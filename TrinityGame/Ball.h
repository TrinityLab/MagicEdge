#pragma once
#include "TrinityFramework.h"
#include "Entity.h"

class Ball : public AnimatedObject
{
protected:
	int Damage;
	double vx;
	double vy;
	SDL_Color color;
	Entity* owner;
	double time;
public:
	Ball(std::string name, Entity* owner);
	void setV(double vx, double vy);
	void setDamage(int damage);
	int getDamage();
	void SetColor(SDL_Color color);
	SDL_Color GetColor();
	virtual void OnCreated();
	virtual void OnDestroyd();
	virtual void Update();
	virtual void Render();
};
