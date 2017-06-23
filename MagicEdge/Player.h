#pragma once

#include "Entity.h"
#include "MessageManager.h"
#include "Text.h"

class Player : public Entity, public IKillEnemyListener
{
private:
	int score;

	bool movement = false;

	Text* levelText = nullptr;
	Text* nameText = nullptr;
	Text* scoreText = nullptr;

	Object* exitButton2 = nullptr;

public:
	Player(Object* obj) : Entity(obj) {}

	virtual void OnCreated() override;
	virtual void Render() override;
	virtual void Update() override;
	virtual void Move(double x, double y) override;
	virtual void SetLevel(int l) override;
	virtual void OnKilled() override;
	virtual void OnKillEnemy(Object* enemy, int score, int exp) override;

	void SetScore(int s);
	void AddScore(int s);
	int GetScore();
};