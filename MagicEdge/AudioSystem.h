#pragma once

#include "StandardInc.h"

class AudioSystem
{
public:
	static bool Init();
	static void Dispose();
	static void Play(FMOD::Sound* sound, int loopsCount = -1, string channelID = ""); // -1 - бесконечное проигрываение
	static void Stop(string channelID);
	static FMOD::System* GetAudioSystem();
private:
	static FMOD::System* audioSystem;
	static map<string, FMOD::Channel*> channels;
};