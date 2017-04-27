#pragma once

#include "Button.h"

class TextField : public Button
{
private:
	bool isFocused;
	string text;
	string defaultText;
	int maxLen;
public:
	TextField(string name, string normalTex, string hoverTex, string focusedTex);
	void SetMaxLen(int len);
	void Update() override;
	void SetDefaultText(string text);
	string GetText();
};