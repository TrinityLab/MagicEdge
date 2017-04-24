#include "WriteText.h"

int GetTextWidth(const char* str, int size)
{
	return (strlen(str) - 1) * size / 2;
}

void WriteText(const char* str, int x, int y, SDL_Color color, int size)
{
	SDL_Rect rect = { x,y,GetTextWidth(str, size),size };

	SDL_Surface* TextSurface = TTF_RenderText_Solid(ResourceManager::GetFont("Visitor"), str, color);
	SDL_Texture* Texture = SDL_CreateTextureFromSurface(Screen::GetRenderer(), TextSurface);

	SDL_RenderCopy(Screen::GetRenderer(), Texture, NULL, &rect);
	SDL_FreeSurface(TextSurface);
	SDL_DestroyTexture(Texture);
}