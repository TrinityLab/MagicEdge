#pragma once

#include "TexturedObject.h"

class Text : public TexturedObject
{
protected:
	string text;
	string font;
	SDL_Color color;
public:
	Text(string name, string text = "");
	void SetText(string text);
	void SetFont(string font);
	void SetColor(SDL_Color color);
	virtual void SetSize(double x, double y) override;
};