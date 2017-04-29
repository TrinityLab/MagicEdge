#pragma once

#include "TexturedObject.h"

class Text : public TexturedObject
{
protected:
	string text;
	string font;
	float fontSize;
	void SetSizeForce(double w, double h);
public:
	Text(string name, string font, string text = "");
	void SetText(string text, SDL_Color color = {0, 0, 0, 255});
	void SetFont(string font);
	void SetFontSize(int size);
	virtual void SetSize(double x, double y) override;
};