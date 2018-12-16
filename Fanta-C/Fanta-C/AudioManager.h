#ifndef _AUDIO_MANAGER_H
#define _AUDIO_MANAGER_H

class AudioManager
{
	// Variables
	static AudioManager* audioManagerInstance;

	// Initialzation
	AudioManager() { return; }
	AudioManager(AudioManager const&) = delete;
	AudioManager operator=(AudioManager const&) = delete;

public:
	// Initialization
	static AudioManager* GetInstance();

	//Update
	void Update();
};

#endif