#pragma once

#include "Button.h"

class TextField : public Button
{
private:
	bool isFocused;
	string text;
	string defaultText;
public:
	TextField(string name, string normalTex, string hoverTex, string focusedTex);
	void Update() override;
	void SetDefaultText(string text);
	string GetText();
};