#pragma once

#include "StandardInc.h"
#include "ObjectComponent.h"
#include "Text.h"

class Button : public Component
{
protected:
	std::string Normal;
	std::string Hover;
	std::string Pressed;
	bool isPressed = false;
	bool isHover = false;

	Object* text;

public:
	Button(Object* obj);
	void Update() override;
	void OnDestroyd() override;
	void OnEnabled() override;
	bool IsPressed();
	bool IsHover();
	void SetText(string text, SDL_Color color = {0, 0, 0, 255});

	void SetNormalTex(string normal);
	void SetHoverTex(string hover);
	void SetPressedTex(string pressed);

	Text* GetText();
};
