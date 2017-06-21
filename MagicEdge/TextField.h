#pragma once

#include "Button.h"

class TextField : public Button
{
private:
	bool isFocused = false;
	string text = "";
	string defaultText;
	int maxLen = 0;

public:
	TextField(Object* owner) : Button(owner) {}
	void SetMaxLen(int len);
	void Update() override;
	void OnEnabled() override;
	void SetDefaultText(string text);
	void SetFocused(bool f);
	string GetText();
};