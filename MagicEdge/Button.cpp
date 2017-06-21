#include "StandardInc.h"
#include "Button.h"
#include "Mouse.h"
#include "ResourceManager.h"
#include "Object.h"
#include "ObjectFactory.h"

Button::Button(Object* owner) : Component(owner)
{
	text = ObjectFactory::UI_SpawnText(0, 0, 0, "", "Visitor");
}

void Button::OnEnabled()
{
	GetOwner()->AddComponent<Renderer>();

	Transform* bt = GetOwner()->GetComponent<Transform>();

	FRect boundingBox = bt->GetLocalBoundingBox();

	text->GetComponent<Transform>()->SetPosition(
		bt->GetXPosition() + boundingBox.x + boundingBox.w * 0.5f,
		bt->GetYPosition() + boundingBox.y + boundingBox.h * 0.5f);

	text->GetComponent<Text>()->SetFontSize(GetOwner()->GetComponent<Transform>()->GetYSize() * 0.7f);

	GetOwner()->useCamera = false;
}

void Button::Update()
{
	isPressed = false;
	isHover = false;

	Renderer* r = GetOwner()->GetComponent<Renderer>();
	Transform* t = GetOwner()->GetComponent<Transform>();

	r->SetTexture(ResourceManager::GetTexture(Normal));

	FRect rect = t->GetLocalBoundingBox();

	if (Mouse::GetMouseX() >= rect.x + t->GetXPosition() && Mouse::GetMouseX() <= rect.x + rect.w + t->GetXPosition() &&
		Mouse::GetMouseY() >= rect.y + t->GetYPosition() && Mouse::GetMouseY() <= rect.y + rect.h + t->GetYPosition())
	{
		r->SetTexture(ResourceManager::GetTexture(Hover));
		isHover = true;

		if (Mouse::IsMouseUp(SDL_BUTTON_LEFT))
		{
			r->SetTexture(ResourceManager::GetTexture(Pressed));
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
	text->GetComponent<Text>()->SetText(txt, color);
}

void Button::OnDestroyd()
{
	Object::Destroy(text);
}

void Button::SetNormalTex(string normal)
{
	Normal = normal;
}

void Button::SetHoverTex(string hover)
{
	Hover = hover;
}

void Button::SetPressedTex(string pressed)
{
	Pressed = pressed;
}
