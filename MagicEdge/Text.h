#pragma once

#include "ObjectComponent.h"

class Text : public Component
{
protected:
	string text;
	string font;
	float fontSize;
	void SetSizeForce(double w, double h);

public:
	Text(Object* owner) : Component(owner) {}
	void SetText(string text, SDL_Color color = {0, 0, 0, 255});
	void SetFont(string font);
	void SetFontSize(int size);
	void SetSize(double x, double y);

	virtual void OnEnabled() override;
};