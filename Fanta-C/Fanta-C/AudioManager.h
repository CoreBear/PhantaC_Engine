#ifndef _AUDIO_MANAGER_H
#define _AUDIO_MANAGER_H

class AudioManager
{
	static AudioManager* audioManagerInstance;

	AudioManager() { return; }
	AudioManager(AudioManager const&) = delete;
	AudioManager operator=(AudioManager const&) = delete;

public:
	//Update
	void Update();

	// Accessors
	static AudioManager* GetInstance();
};

#endif