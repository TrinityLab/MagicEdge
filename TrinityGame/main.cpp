#include "TrinityFramework.h"

#include "MasterManager.h"

map<string, SDL_Texture*> ResourceManager::textures;
map<string, TTF_Font*> ResourceManager::fonts;
map<string, Mix_Chunk*> ResourceManager::wavs;
map<string, Mix_Music*> ResourceManager::musics;

int main(int argv, char** argc)
{
	Application app;

	return app.Run("Magic Edge", 50, 50, 1280, 720, SDL_WINDOW_SHOWN);
}