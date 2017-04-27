#include "StandardInc.h"
#include "Text.h"
#include "ResourceManager.h"
#include "Screen.h"

Text::Text(string name, string font, string text) : TexturedObject(name)
{
	SetFont(font);
	SetText(text, {0, 0, 0, 255});

	useCamera = false;
}

void Text::SetText(string text, SDL_Color color)
{
	this->text = text;

	SDL_Surface* surface = TTF_RenderText_Solid(ResourceManager::GetFont(font), text.c_str(), color);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Screen::GetRenderer(), surface);

	SetTexture(tex);
	SDL_FreeSurface(surface);

	int width, height;

	SDL_QueryTexture(tex, NULL, NULL, &width, &height);

	SetSrcRect({ 0, 0, width, height });

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

void Text::SetFontSize(int size)
{
	fontSize = size;

	int width, height;

	SDL_QueryTexture(GetTexture(), NULL, NULL, &width, &height);

	double aspectRatio = width / (double)height;

	SetSizeForce(size * aspectRatio, size);
}

void Text::SetSizeForce(double x, double y)
{
	xSize = x;
	ySize = y;
}