#include "ResourceManager.h"
#include "Screen.h"

bool ResourceManager::LoadTexture(string name, string fileName)
{
	SDL_Texture* texture = IMG_LoadTexture(Screen::GetRenderer(), fileName.c_str());

	if (texture == NULL)
		return false;

	textures.insert({ name, texture });

	return true;
}

bool ResourceManager::LoadFont(string name, string fileName, int ptSize)
{
	TTF_Font* font = TTF_OpenFont(fileName.c_str(), ptSize);

	if (font == NULL)
		return false;

	fonts.insert({ name, font });

	return true;
}

bool ResourceManager::LoadWAV(string name, string fileName)
{
	Mix_Chunk* chunk = Mix_LoadWAV(fileName.c_str());

	if (chunk == NULL)
		return false;

	wavs.insert({ name, chunk });

	return true;
}

bool ResourceManager::LoadMusic(string name, string fileName)
{
	Mix_Music* music = Mix_LoadMUS(fileName.c_str());

	if (music == NULL)
		return false;

	musics.insert({ name, music });

	return true;
}

SDL_Texture* ResourceManager::GetTexture(string name)
{
	auto iter = textures.find(name);

	if (iter == textures.end())
		return NULL;

	return iter->second;
}

TTF_Font* ResourceManager::GetFont(string name)
{
	auto iter = fonts.find(name);

	if (iter == fonts.end())
		return NULL;

	return iter->second;
}

Mix_Chunk* ResourceManager::GetChunk(string name)
{
	auto iter = wavs.find(name);

	if (iter == wavs.end())
		return NULL;

	return iter->second;
}

Mix_Music* ResourceManager::GetMusic(string name)
{
	auto iter = musics.find(name);

	if (iter == musics.end())
		return NULL;

	return iter->second;
}

void ResourceManager::Clear()
{
	for (auto tx : textures)
	{
		SDL_DestroyTexture(tx.second);
	}

	for (auto f : fonts)
	{
		TTF_CloseFont(f.second);
	}

	for (auto w : wavs)
	{
		Mix_FreeChunk(w.second);
	}

	for (auto m : musics)
	{
		Mix_FreeMusic(m.second);
	}

	textures.clear();
	fonts.clear();
	wavs.clear();
	musics.clear();
}