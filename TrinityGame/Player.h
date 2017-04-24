#pragma once
#include "TrinityFramework.h"
#include "Entity.h"
#include "Camera.h"

class Player : public Entity
{
private:
	bool movement = false;

public:
	Player(string name);
	virtual void OnCreated() override;
	virtual void OnDestroyd() override;
	virtual void Render() override;
	virtual void Update() override;
	virtual void Move(double x, double y) override;
	virtual void SetPosition(double x, double y) override;
	virtual void setLevel(int l) override;
	virtual void setHealth(int health) override;
};