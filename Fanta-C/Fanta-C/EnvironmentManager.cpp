#pragma region Dependencies
// My Headers
#include "EnvironmentManager.h"			// Connection to declarations

#include "SceneManager.h"
#pragma endregion

#pragma region Initialization
EnvironmentManager::EnvironmentManager(HWND windowHandle, ushort* clientDimensions)
{
	// Loads the scene manager
	sceneManagerPtr = new SceneManager(clientDimensions, &windowHandle, targetFPS);
}
#pragma endregion

#pragma region Update
void EnvironmentManager::Update()
{
	// Stores how long it took to complete the frame
	chronoDelta = endTime - startTime;
	deltaTime = chronoDelta.count();
	
	// Stores the time at the beginning of the frame
	startTime = std::chrono::steady_clock::now();

	sceneManagerPtr->Update(deltaTime);
	
	// Stores the time at the end of the frame
	endTime = std::chrono::steady_clock::now();
}
#pragma endregion

#pragma region Clean Up
EnvironmentManager::~EnvironmentManager()
{
	delete sceneManagerPtr;
}
#pragma endregion