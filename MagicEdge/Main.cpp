#include "StandardInc.h"
#include "ResourceManager.h"
#include "MasterManager.h"
#include "Application.h"

map<string, SDL_Texture*> ResourceManager::textures;
map<string, TTF_Font*> ResourceManager::fonts;
map<string, FMOD::Sound*> ResourceManager::audios;

int main(int argv, char** argc)
{
	Application app;

	return app.Run("Magic Edge", 50, 50, 1280, 720, SDL_WINDOW_SHOWN);
}