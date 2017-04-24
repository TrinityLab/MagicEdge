#include "Button.h"
#include "Mouse.h"
#include "ResourceManager.h"
#include "WriteText.h"

void Button::Update()
{
	isPressed = false;

	SetTexture(ResourceManager::GetTexture(Normal));

	TexturedObject::Update();
	if (Mouse::GetMouseX() <= GetXPosition() + GetXSize() / 2 && Mouse::GetMouseX() >= GetXPosition() - GetXSize() / 2 &&
		Mouse::GetMouseY() <= GetYPosition() + GetYSize() / 2 && Mouse::GetMouseY() >= GetYPosition() - GetYSize() / 2)
	{
		SetTexture(ResourceManager::GetTexture(Hover));

		if (Mouse::IsMousePressed(SDL_BUTTON_LEFT))
		{
			SetTexture(ResourceManager::GetTexture(Pressed));
			isPressed = true;
		}
	}
}

void Button::Render()
{
	TexturedObject::Render();

	int fontSize = (int)(GetYSize() * 0.65);
	int fontWidth = GetTextWidth(text.c_str(), fontSize);

	WriteText(text.c_str(), GetXPosition() - fontWidth / 2, GetYPosition() - fontSize / 2, { 0, 0, 0, 255 }, 60);
}

bool Button::IsPressed()
{
	return isPressed;
}