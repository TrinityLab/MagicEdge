#include "TexturedObject.h"
#include "Utility.h"
#include "Screen.h"
#include "Camera.h"

TexturedObject::TexturedObject(string name) : Object(name)
{
	texture = NULL;
}

void TexturedObject::SetTexture(SDL_Texture* texture)
{
	this->texture = texture;

	int width, height;

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	SetSrcRect({ 0, 0, width, height });
}

SDL_Texture* TexturedObject::GetTexture()
{
	return texture;
}

void TexturedObject::SetSrcRect(SDL_Rect srcRect)
{
	this->srcRect = srcRect;
}

SDL_Rect TexturedObject::GetSrcRect()
{
	return srcRect;
}

void TexturedObject::Render()
{
	if (texture == NULL)
		return;

	if (useCamera)
	{
		xPosition -= Camera::GetXOffset();
		yPosition -= Camera::GetYOffset();
	}

	FRect rect = GetLocalBoundingBox();
	SDL_Rect dst = { (int)rect.x + (int)GetXPosition(), (int)rect.y + (int)GetYPosition(), (int)rect.w, (int)rect.h };

	SDL_Point point;
	point.x = (int)(GetXOrigin() * GetXSize());
	point.y = (int)(GetYOrigin() * GetYSize());

	SDL_RenderCopyEx(Screen::GetRenderer(), texture, &srcRect, &dst, GetRotation() * 180.0 / M_PI, &point, SDL_FLIP_NONE);

	if (useCamera)
	{
		xPosition += Camera::GetXOffset();
		yPosition += Camera::GetYOffset();
	}
}

void TexturedObject::Update()
{
	
}

void TexturedObject::OnCreated()
{
	
}

void TexturedObject::OnDestroyd()
{
	
}