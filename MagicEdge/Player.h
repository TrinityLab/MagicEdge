#pragma once

#include "Entity.h"
#include "MessageManager.h"

class Player : public Entity, public IKillEnemyListener
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

	virtual void OnKillEnemy(Object* enemy, int score, int exp) override;
};