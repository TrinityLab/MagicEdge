#pragma once

#include "TexturedObject.h"

class Button : public TexturedObject
{
protected:
	std::string Normal;
	std::string Hover;
	std::string Pressed;
	bool isPressed = false;

	std::string text;
public:
	Button(std::string name, std::string normalTex, std::string hoverTex, std::string pressedTex, std::string text) :TexturedObject(name)
	{
		Normal = normalTex;
		Hover = hoverTex;
		Pressed = pressedTex;
		this->text = text;
	}

	void Update() override;
	void Render() override;
	bool IsPressed();
};
