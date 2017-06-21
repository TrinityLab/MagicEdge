#include "StandardInc.h"
#include "AudioSystem.h"

FMOD::System* AudioSystem::audioSystem;
map<string, FMOD::Channel*> AudioSystem::channels;

bool AudioSystem::Init()
{
	FMOD::System_Create(&audioSystem);
	if (audioSystem->init(36, FMOD_INIT_NORMAL, 0) != FMOD_OK)
		return false;

	return true;
}

void AudioSystem::Dispose()
{
	audioSystem->release();
	audioSystem = NULL;
}

void AudioSystem::Play(FMOD::Sound* sound, int loopsCount, string channelID)
{
	sound->setMode(FMOD_LOOP_NORMAL);
	sound->setLoopCount(loopsCount);

	FMOD::Channel* channel;
	audioSystem->playSound(sound, NULL, false, &channel);

	if(channelID != "")
		channels.insert({ channelID, channel });
}

void AudioSystem::Stop(string channelID)
{
	if (channels.find(channelID) != channels.end())
	{
		channels[channelID]->stop();
		channels.erase(channelID);
	}
}

FMOD::System* AudioSystem::GetAudioSystem()
{
	return audioSystem;
}