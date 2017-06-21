#include "StandardInc.h"
#include "ObjectComponent.h"

Component::Component(Object* owner) : isActive(false)
{
	this->owner = owner;
}

Object* Component::GetOwner()
{
	return owner;
}

void Component::SetActive(bool active)
{
	if (active && !isActive)
	{
		isActive = active;
		OnEnabled();
	}
	else if (!active && isActive)
	{
		isActive = active;
		OnDisabled();
	}
}

bool Component::IsActive()
{
	return isActive;
}