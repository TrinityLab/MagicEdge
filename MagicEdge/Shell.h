#pragma once

#include "ObjectComponent.h"
#include "Entity.h"
#include "MessageManager.h"

class Shell : public Component, public ICollideEventListener
{
protected:
	float damage;
	float vx;
	float vy;
	SDL_Color color;
	Object* creator;
	double time = 5.0f;

public:
	Shell(Object* owner) : Component(owner) {}
	void SetVelocity(float vx, float vy);
	void SetDamage(float d);
	float GetDamage();
	void SetColor(SDL_Color c);
	void SetCreator(Object* obj);
	Object* GetCreator();
	SDL_Color GetColor();

	virtual void OnCreated() override;
	virtual void Update() override;

	virtual void OnCollide(Object* otherObject) override;
};