#pragma once

#include "Entity.h"

class Enemy : public Entity
{
protected:
	double attackRadius;
	double attackReloadTime;
	double currentReloadTime;
public:
	Enemy(string name);
	void Update() override;
	void Render() override;
	void OnCreated() override;
	virtual void Move(double x, double y) override;
	virtual void setLevel(int l) override;
	virtual int GetScore();
};