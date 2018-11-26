#pragma region Dependencies
// My Headers
#include "SceneManager.h"		// Connection to declarations

#include "SceneGraph.h"
#include "TestScene.h"
#pragma endregion

#pragma region Initialization
SceneManager::SceneManager(ushort* clientDimensions, HWND* windowHandle, uchar targetFPS)
{		
	// Assign whatever scene you want to run
	scenePtr = new TestScene(clientDimensions);
}
#pragma endregion

#pragma region Update
void SceneManager::Update()
{	
	scenePtr->Update();																// Runs scripts
}
#pragma endregion

#pragma region Clean Up
SceneManager::~SceneManager()
{
	if (scenePtr) delete scenePtr;
}
#pragma endregion