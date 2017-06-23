#pragma once

#include "ObjectComponent.h"

class Renderer : public Component
{
protected:
	SDL_Texture* texture = nullptr;
	SDL_Rect srcRect;
	double time = 0.0;

	int framesPerWidth;
	int framesPerHeight;
	int FPS = 0;
	int frameWidth;
	int frameHeight;
	int currentFrameX = 0;
	int currentFrameY = 0;

	bool looped = false;
	bool paused = true;

public:
	Renderer(Object* obj) : Component(obj) {}

	void Render();
	void Update();

	void SetTexture(SDL_Texture* t);
	void SetSrcRect(SDL_Rect src);

	SDL_Texture* GetTexture();
	SDL_Rect GetSrcRect();

	void SetTexture(SDL_Texture* texture, int framesPerWidth, int framesPerHeight, int FPS, bool looped = false);
	void Pause();
	void Play();
};