#pragma once

class Object;

class Component
{
protected:
	bool isActive;

	Object* owner;
	virtual void Render() {}
	virtual void Update() {}

	virtual void OnCreated() {}
	virtual void OnDestroyd() {}

	virtual void OnEnabled() {}
	virtual void OnDisabled() {}

public:
	Component(Object* owner);
	Object* GetOwner();

	void SetActive(bool active);
	bool IsActive();

	friend class Object;
};