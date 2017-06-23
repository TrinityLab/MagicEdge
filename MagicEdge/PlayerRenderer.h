#pragma once

#include "Renderer.h"
#include "Player.h"

class PlayerRenderer : public Renderer
{
private:
	Player* player;

public:
	PlayerRenderer(Object* owner) : Renderer(owner) {}
	virtual void Render() override;
	virtual void OnCreated() override;
};