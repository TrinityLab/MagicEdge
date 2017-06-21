#include "StandardInc.h"
#include "AutoDestroy.h"
#include "Timer.h"
#include "Object.h"

void AutoDestroy::Update()
{
	time -= Timer::GetDeltaTime();

	if (time <= 0.0f)
	{
		Object::Destroy(GetOwner());
	}
}

void AutoDestroy::SetTime(float time)
{
	this->time = time;
}