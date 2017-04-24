#include "Button.h"
#include "Mouse.h"
#include "ResourceManager.h"

Button::Button(string name, string normalTex, string hoverTex, string pressedTex, string text) :TexturedObject(name)
{
	Normal = normalTex;
	Hover = hoverTex;
	Pressed = pressedTex;

	this->text = new Text(name + "_Text");
	
	SetText(text);
}

void Button::Update()
{
	isPressed = false;

	SetTexture(ResourceManager::GetTexture(Normal));

	TexturedObject::Update();
	if (Mouse::GetMouseX() <= GetXPosition() + GetXSize() / 2 && Mouse::GetMouseX() >= GetXPosition() - GetXSize() / 2 &&
		Mouse::GetMouseY() <= GetYPosition() + GetYSize() / 2 && Mouse::GetMouseY() >= GetYPosition() - GetYSize() / 2)
	{
		SetTexture(ResourceManager::GetTexture(Hover));

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

void Button::SetText(string txt)
{
	text->SetText(txt);
}

void Button::SetTextColor(SDL_Color color)
{
	text->SetColor(color);
}

void Button::SetPosition(double x, double y)
{
	TexturedObject::SetPosition(x, y);

	text->SetPosition(x, y);
}

void Button::SetSize(double x, double y)
{
	TexturedObject::SetSize(x, y);

	text->SetSize(GetXSize() * 0.7, GetYSize() * 0.7);
}

void Button::SetRotation(double angle)
{
	TexturedObject::SetRotation(angle);

	text->SetRotation(angle);
}