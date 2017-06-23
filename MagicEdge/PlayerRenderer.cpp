#include "StandardInc.h"
#include "PlayerRenderer.h"
#include "Object.h"
#include "Camera.h"
#include "ResourceManager.h"
#include "Screen.h"
#include "Timer.h"

void PlayerRenderer::OnCreated()
{
	player = GetOwner()->GetComponent<Player>();
}

void PlayerRenderer::Render()
{
	Transform* t = GetOwner()->GetComponent<Transform>();

	{
		FRect shadowRect = t->GetLocalBoundingBox();
		shadowRect.x += t->GetXPosition() - Camera::GetXOffset();
		shadowRect.y += t->GetYPosition() + Block::TILE_SIZE / 2 - Camera::GetYOffset();

		SDL_Rect srect = { (int)shadowRect.x, (int)shadowRect.y, (int)shadowRect.w, (int)shadowRect.h };

		int width, height;
		SDL_QueryTexture(ResourceManager::GetTexture("Shadow"), NULL, NULL, &width, &height);

		SDL_Rect srcRect = { 0, 0, width, height };

		SDL_RenderCopy(Screen::GetRenderer(), ResourceManager::GetTexture("Shadow"), &srcRect, &srect);
	}

	{
		double offset = player->IsMove() ? (5 * sin(Timer::GetTotalTime() * 10)) : 0;

		float xPos = t->GetXPosition();
		float yPos = t->GetYPosition();

		if (owner->useCamera)
		{
			xPos -= Camera::GetXOffset();
			yPos -= Camera::GetYOffset();
		}

		FRect rect = t->GetLocalBoundingBox();
		SDL_Rect dst = { rect.x + xPos, rect.y + yPos + offset, rect.w, rect.h };

		SDL_Point p = { t->GetXOrigin() * rect.w, t->GetYOrigin() * rect.h };

		SDL_RenderCopyEx(Screen::GetRenderer(), texture, &srcRect, &dst, 0.0, &p, SDL_FLIP_NONE);
	}
}