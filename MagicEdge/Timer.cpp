#include "StandardInc.h"
#include "Timer.h"
#include "SDL.h"

int Timer::currentTicks;
int Timer::lastTicks;
double Timer::deltaTime;
double Timer::totalTime;

void Timer::Init()
{
	currentTicks = lastTicks = SDL_GetTicks();
	totalTime = deltaTime = 0.0;
}

void Timer::Update()
{
	lastTicks = currentTicks;
	currentTicks = SDL_GetTicks();

	deltaTime = (currentTicks - lastTicks) * 0.001;
	totalTime += deltaTime;
}

double Timer::GetDeltaTime()
{
	return deltaTime;
}

double Timer::GetTotalTime()
{
	return totalTime;
}