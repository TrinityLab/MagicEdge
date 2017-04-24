#include "StandardInc.h"
#include "Text.h"
#include "ResourceManager.h"
#include "Screen.h"

Text::Text(string name, string text) : TexturedObject(name)
{
	SetText(text);
}

void Text::SetText(string text)
{
	/*this->text = text;

	SDL_Surface* surface = TTF_RenderText_Solid(ResourceManager::GetFont(font), text.c_str(), color);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Screen::GetRenderer(), surface);

	SetTexture(tex);
	SDL_FreeSurface(surface);*/
}

void Text::SetFont(string fontName)
{
	font = fontName;
}

void Text::SetColor(SDL_Color color)
{
	this->color = color;
}

void Text::SetSize(double x, double y)
{
	int width;
	int height;

	SDL_QueryTexture(GetTexture(), NULL, NULL, &width, &height);

	float aspectRatio = width / (float)height;

	if (aspectRatio > 1)
	{
		xSize = x;
		ySize = xSize / aspectRatio;
	}
	else
	{
		ySize = y;
		xSize = ySize * aspectRatio;
	}
}