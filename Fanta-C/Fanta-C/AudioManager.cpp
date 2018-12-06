#pragma region Dependencies
// My Headers
#include "AudioManager.h"			// Connection to declarations
#pragma endregion

#pragma region Forward Declarations
AudioManager* AudioManager::audioManagerInstance = nullptr;
#pragma endregion

#pragma region Update
void AudioManager::Update()
{

}
#pragma endregion

#pragma region Accessors
AudioManager* AudioManager::GetInstance()
{
	// If instance has been created
	if (audioManagerInstance) return audioManagerInstance;

	// If instance has not been created, create one and return it
	else
	{
		audioManagerInstance = new AudioManager;
		return audioManagerInstance;
	}
}
#pragma endregion