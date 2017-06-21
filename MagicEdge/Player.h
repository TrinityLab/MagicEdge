#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
	bool movement = false;

	/*Text* level;
	Text* name;
	Text* score;*/

public:
	Player(Object* obj) : Entity(obj) {}

	virtual void OnCreated() override;
	virtual void Render() override;
	virtual void Update() override;
	virtual void Move(double x, double y) override;
	virtual void SetLevel(int l) override;
	virtual void OnKilled() override;
};