#include "TextField.h"
#include "ResourceManager.h"
#include "Mouse.h"
#include "Keyboard.h"

TextField::TextField(string name, string normalTex, string hoverTex, string focusedTex) :
	Button(name, normalTex, hoverTex, focusedTex)
{
	isFocused = false;
	text = "";
	SetText(defaultText);
}

void TextField::SetDefaultText(string text)
{
	this->defaultText = text;
}

void TextField::Update()
{
	Button::Update();

	if (isFocused)
	{
		SetTexture(ResourceManager::GetTexture(Pressed));
	}

	if (IsPressed())
	{
		isFocused = true;
	}

	FRect rect = GetLocalBoundingBox();
	if (Mouse::GetMouseX() < rect.x + GetXPosition() || Mouse::GetMouseY() < rect.y + GetYPosition() ||
		Mouse::GetMouseX() > rect.x + rect.w + GetXPosition() && Mouse::GetMouseY() > rect.y + rect.h + GetYPosition())
	{
		if (!Mouse::IsMouseDown(SDL_BUTTON_LEFT))
		{
			isFocused = false;
			if (text == "")
			{
				SetText(defaultText);
			}
		}
	}

	for (int i = 0; i < Keyboard::GetKeyCount(); i++)
	{
		if (Keyboard::IsKeyDown(i))
		{
			if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
			{
				text += (char)i;
				SetText(text);
			}
			
			if (i == '\b' && text.size() > 0)
			{
				text.erase(text.size() - 1, 1);
				SetText(text);
			}

			if (i == '\n')
			{
				isFocused = false;
			}
		}
	}
}

string TextField::GetText()
{
	return text;
}