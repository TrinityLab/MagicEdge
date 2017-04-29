#include "Button.h"
#include "Mouse.h"
#include "ResourceManager.h"

Button::Button(string name, string normalTex, string hoverTex, string pressedTex) : TexturedObject(name)
{
	Normal = normalTex;
	Hover = hoverTex;
	Pressed = pressedTex;

	this->text = new Text(name + "_Text", "Visitor");
}

void Button::Update()
{
	isPressed = false;
	isHover = false;

	SetTexture(ResourceManager::GetTexture(Normal));

	TexturedObject::Update();
	if (Mouse::GetMouseX() <= GetXPosition() + GetXSize() / 2 && Mouse::GetMouseX() >= GetXPosition() - GetXSize() / 2 &&
		Mouse::GetMouseY() <= GetYPosition() + GetYSize() / 2 && Mouse::GetMouseY() >= GetYPosition() - GetYSize() / 2)
	{
		SetTexture(ResourceManager::GetTexture(Hover));
		isHover = true;

		if (Mouse::IsMouseUp(SDL_BUTTON_LEFT))
		{
			SetTexture(ResourceManager::GetTexture(Pressed));
			isPressed = true;
		}
	}
}

bool Button::IsPressed()
{
	return isPressed;
}

bool Button::IsHover()
{
	return isHover;
}

void Button::SetText(string txt, SDL_Color color)
{
	text->SetText(txt, color);
}

void Button::SetPosition(double x, double y)
{
	TexturedObject::SetPosition(x, y);

	text->SetPosition(x, y);
}

void Button::SetSize(double x, double y)
{
	TexturedObject::SetSize(x, y);

	text->SetFontSize((int)(y * 0.5));
}

void Button::SetRotation(double angle)
{
	TexturedObject::SetRotation(angle);

	text->SetRotation(angle);
}