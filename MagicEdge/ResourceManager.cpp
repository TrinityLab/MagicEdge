#include "ResourceManager.h"
#include "Screen.h"
#include "AudioSystem.h"

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

bool ResourceManager::LoadAudio(string name, string fileName)
{
	FMOD::Sound* sound;

	AudioSystem::GetAudioSystem()->createSound(fileName.c_str(), FMOD_DEFAULT, NULL, &sound);

	audios.insert({ name, sound });

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

FMOD::Sound* ResourceManager::GetAudio(string name)
{
	auto iter = audios.find(name);

	if (iter == audios.end())
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

	for (auto audio : audios)
	{
		audio.second->release();
	}

	textures.clear();
	fonts.clear();
	audios.clear();
}