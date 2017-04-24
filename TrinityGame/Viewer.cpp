#include "TrinityFramework.h"
#include "Viewer.h"
#include "Camera.h"

Viewer::Viewer(string name) : Object(name)
{

}

void Viewer::Update()
{
	if (Keyboard::IsKey(SDL_SCANCODE_A))
		Camera::Move(-200 * Timer::GetDeltaTime(), 0);

	if (Keyboard::IsKey(SDL_SCANCODE_D))
		Camera::Move(200 * Timer::GetDeltaTime(), 0);

	if (Keyboard::IsKey(SDL_SCANCODE_W))
		Camera::Move(0, -200 * Timer::GetDeltaTime());

	if (Keyboard::IsKey(SDL_SCANCODE_S))
		Camera::Move(0, 200 * Timer::GetDeltaTime());
}

void Viewer::Render()
{

}

void Viewer::OnCreated()
{

}

void Viewer::OnDestroyd()
{

}