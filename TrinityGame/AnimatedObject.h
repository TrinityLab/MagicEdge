#pragma once

#include "TexturedObject.h"

class AnimatedObject : public TexturedObject
{
private:
	double time;
protected:
	int framesPerWidth;
	int framesPerHeight;
	int FPS;
	int frameWidth;
	int frameHeight;
	int currentFrameX;
	int currentFrameY;

	bool looped;
	bool paused;

	virtual void Update() override;
public:
	AnimatedObject(std::string name);
	void SetTexture(SDL_Texture* texture, int framesPerWidth, int framesPerHeight, int FPS, bool looped = false);
	void Pause();
	void Play();
};