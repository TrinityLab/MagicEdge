#include "AnimatedObject.h"
#include "Timer.h"

AnimatedObject::AnimatedObject(string name) : TexturedObject(name)
{
	currentFrameX = currentFrameY = 0;
}

void AnimatedObject::SetTexture(SDL_Texture* texture, int framesPerWidth, int framesPerHeight, int FPS, bool looped)
{
	TexturedObject::SetTexture(texture);

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

void AnimatedObject::Update()
{
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

void AnimatedObject::Pause()
{
	paused = true;
}

void AnimatedObject::Play()
{
	paused = false;
}