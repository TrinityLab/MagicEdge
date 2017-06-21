#include "StandardInc.h"
#include "Renderer.h"
#include "Camera.h"
#include "Screen.h"
#include "Timer.h"
#include "Object.h"

void Renderer::SetTexture(SDL_Texture* t)
{
	this->texture = t;

	SDL_Rect srcRect;

	int width, height;
	SDL_QueryTexture(t, nullptr, nullptr, &width, &height);

	srcRect = { 0, 0, width, height };
	SetSrcRect(srcRect);

	paused = true;
}

SDL_Texture* Renderer::GetTexture()
{
	return texture;
}

void Renderer::SetSrcRect(SDL_Rect src)
{
	srcRect = src;
}

SDL_Rect Renderer::GetSrcRect()
{
	return srcRect;
}

void Renderer::Render()
{
	Transform* t = owner->GetComponent<Transform>();

	if (texture == nullptr || t == nullptr)
		return;

	float xPos = t->GetXPosition();
	float yPos = t->GetYPosition();

	if (owner->useCamera)
	{
		xPos -= Camera::GetXOffset();
		yPos -= Camera::GetYOffset();
	}

	FRect rect = t->GetLocalBoundingBox();
	SDL_Rect dst = { rect.x + xPos, rect.y + yPos, rect.w, rect.h };

	SDL_Point p = { t->GetXOrigin() * rect.w, t->GetYOrigin() * rect.h };

	SDL_RenderCopyEx(Screen::GetRenderer(), texture, &srcRect, &dst, 0.0, &p, SDL_FLIP_NONE);
}

void Renderer::SetTexture(SDL_Texture* texture, int framesPerWidth, int framesPerHeight, int FPS, bool looped /* = false */)
{
	SetTexture(texture);

	this->framesPerHeight = framesPerHeight;
	this->framesPerWidth = framesPerWidth;
	this->FPS = FPS;

	int width, height;

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	frameWidth = width / framesPerWidth;
	frameHeight = height / framesPerHeight;

	this->looped = looped;

	time = 1.0 / FPS;

	currentFrameX = 0;
	currentFrameY = 0;

	Play();
}

void Renderer::Update()
{
	if (paused)
		return;

	double frameTime = 1.0 / FPS;

	time -= Timer::GetDeltaTime();

	while (time <= 0)
	{
		currentFrameX++;
		if (currentFrameX >= framesPerWidth)
		{
			currentFrameX = 0;
			currentFrameY++;

			if (currentFrameY >= framesPerHeight)
			{
				currentFrameY = 0;

				if (!looped)
				{
					Pause();
				}
			}
		}

		time += frameTime;
	}

	SetSrcRect({ currentFrameX * frameWidth, currentFrameY * frameHeight, frameWidth, frameHeight });
}

void Renderer::Pause()
{
	paused = true;
}

void Renderer::Play()
{
	paused = false;
}