#include "TextField.h"
#include "ResourceManager.h"

TextField::TextField(string name, string normalTex, string hoverTex, string focusedTex) :
	Button(name, normalTex, hoverTex, focusedTex)
{
	isFocused = false;
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


}