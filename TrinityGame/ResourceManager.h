#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <map>
#include <string>

using namespace std;

class ResourceManager
{
private:
	static map<string, SDL_Texture*> textures;
	static map<string, TTF_Font*> fonts;
	static map<string, Mix_Chunk*> wavs;
	static map<string, Mix_Music*> musics;
public:
	static bool LoadTexture(string name, string fileName);
	static bool LoadFont(string name, string fileName, int ptSize);
	static bool LoadWAV(string name, string fileName);
	static bool LoadMusic(string name, string fileName);
	static SDL_Texture* GetTexture(string name);
	static TTF_Font* GetFont(string name);
	static Mix_Chunk* GetChunk(string name);
	static Mix_Music* GetMusic(string name);
	static void Clear();
};