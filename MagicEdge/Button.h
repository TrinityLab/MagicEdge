#pragma once

#include "StandardInc.h"
#include "TexturedObject.h"
#include "Text.h"

class Button : public TexturedObject
{
protected:
	std::string Normal;
	std::string Hover;
	std::string Pressed;
	bool isPressed = false;

	Text* text;
public:
	Button(string name, string normalTex, string hoverTex, string pressedTex);
	void Update() override;
	bool IsPressed();
	void SetText(string text, SDL_Color color = {0, 0, 0, 255});
	virtual void SetPosition(double x, double y) override;
	virtual void SetSize(double x, double y) override;
	virtual void SetRotation(double angle) override;
};
