#include "StandardInc.h"
#include "TextField.h"
#include "ResourceManager.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "StandardInc.h"
#include "Object.h"

void TextField::SetDefaultText(string text)
{
	this->defaultText = text;
	if (!isFocused)
	{
		if (this->text == "")
		{
			SetText(defaultText);
		}
	}
}

void TextField::OnEnabled()
{
	Button::OnEnabled();

	GetOwner()->useCamera = false;
}

void TextField::Update()
{
	Button::Update();

	Renderer* r = GetOwner()->GetComponent<Renderer>();

	if (isFocused)
	{
		r->SetTexture(ResourceManager::GetTexture(Pressed));
	}

	if (IsPressed())
	{
		isFocused = true;
		if (text == "")
			SetText("|");
		else
			SetText(text + "|");
	}

	Transform* t = GetOwner()->GetComponent<Transform>();

	FRect rect = t->GetLocalBoundingBox();
	if (!IsHover())
	{
		if (Mouse::IsMouseDown(SDL_BUTTON_LEFT))
		{
			isFocused = false;
			if (text == "")
			{
				SetText(defaultText);
			}
			else
			{
				SetText(text);
			}
		}
	}

	if (!isFocused)
	{
		return;
	}

	for (int i = 0; i < Keyboard::GetKeyCount(); i++)
	{
		if (Keyboard::IsTextDown(i))
		{
			if (text.size() < maxLen || maxLen == 0)
			{
				if (i >= SDL_SCANCODE_A && i <= SDL_SCANCODE_Z)
				{
					if (Keyboard::IsKey(SDL_SCANCODE_LSHIFT) || Keyboard::IsKey(SDL_SCANCODE_RSHIFT))
					{
						text += (char)(i - 4 + 'A');
					}
					else
					{
						text += (char)(i - 4 + 'a');
					}
					SetText(text + "|");
				}

				if (i == SDL_SCANCODE_SPACE)
				{
					text += " ";
					SetText(text + "|");
				}

				if (i >= SDL_SCANCODE_1 && i <= SDL_SCANCODE_9)
				{
					text += (char)(i - 30 + '1');
					SetText(text + "|");
				}

				if (i == SDL_SCANCODE_0)
				{
					text += "0";
					SetText(text + "|");
				}
			}
			
			if (i == SDL_SCANCODE_BACKSPACE && text.size() > 0)
			{
				text.erase(text.size() - 1, 1);
				SetText(text + "|");
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

void TextField::SetMaxLen(int len)
{
	maxLen = len;
}

void TextField::SetFocused(bool f)
{
	isFocused = f;
}