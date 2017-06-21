#include "StandardInc.h"
#include "Text.h"
#include "ResourceManager.h"
#include "Screen.h"
#include "Object.h"
#include "ResourceManager.h"

void Text::OnEnabled()
{
	GetOwner()->useCamera = false;
}

void Text::SetText(string text, SDL_Color color)
{
	this->text = text;

	Renderer* r = GetOwner()->GetComponent<Renderer>();

	SDL_Surface* surface = TTF_RenderText_Solid(ResourceManager::GetFont(font), text.c_str(), color);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Screen::GetRenderer(), surface);

	r->SetTexture(tex);
	SDL_FreeSurface(surface);

	SetFontSize(fontSize);
}

void Text::SetFont(string fontName)
{
	font = fontName;
}

void Text::SetSize(double x, double y)
{
	int width;
	int height;

	Renderer* r = GetOwner()->GetComponent<Renderer>();

	SDL_QueryTexture(r->GetTexture(), NULL, NULL, &width, &height);

	float aspectRatio = width / (float)height;

	Transform* t = GetOwner()->GetComponent<Transform>();

	if (aspectRatio > 1)
	{
		t->SetSize(x, x / aspectRatio);
	}
	else
	{
		t->SetSize(y, y * aspectRatio);
	}
}

void Text::SetFontSize(int size)
{
	fontSize = size;

	int width, height;

	Renderer* r = GetOwner()->GetComponent<Renderer>();

	SDL_QueryTexture(r->GetTexture(), NULL, NULL, &width, &height);

	double aspectRatio = width / (double)height;

	SetSizeForce(size * aspectRatio, size);
}

void Text::SetSizeForce(double x, double y)
{
	Transform* t = GetOwner()->GetComponent<Transform>();

	t->SetSize(x, y);
}