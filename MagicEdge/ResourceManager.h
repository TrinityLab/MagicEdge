#pragma once

#include "StandardInc.h"

class ResourceManager
{
private:
	static map<string, SDL_Texture*> textures;
	static map<string, TTF_Font*> fonts;
	static map<string, FMOD::Sound*> audios;
public:
	static bool LoadTexture(string name, string fileName);
	static bool LoadFont(string name, string fileName, int ptSize);
	static bool LoadAudio(string name, string fileName);
	static SDL_Texture* GetTexture(string name);
	static TTF_Font* GetFont(string name);
	static FMOD::Sound* GetAudio(string name);
	static void Clear();
};