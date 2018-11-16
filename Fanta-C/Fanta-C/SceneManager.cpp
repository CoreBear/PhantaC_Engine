#pragma region Dependencies
// My Headers
#include "SceneManager.h"		// Connection to declarations

#include "AudioManager.h"
#include "IntelligenceManager.h"
#include "PhysicsManager.h"
#include "SceneGraph.h"
#pragma endregion

#pragma region Initialization
SceneManager::SceneManager(ushort* clientDimensions, HWND* windowHandle, uchar targetFPS)
{	
	#pragma region Module Creation
	audioManagerPtr = new AudioManager;

	intelligenceManagerPtr = new IntelligenceManager;
	
	physicsManagerPtr = new PhysicsManager;

	sceneGraphPtr = new SceneGraph(clientDimensions);
	
	rendererPtr = new Renderer(*windowHandle, this, clientDimensions, targetFPS, sceneGraphPtr->GetCamera());
	#pragma endregion
}
#pragma endregion

#pragma region Update
void SceneManager::Update(float deltaTime)
{	
	audioManagerPtr->Update();																// Game audio
	intelligenceManagerPtr->Update();														// AI
	physicsManagerPtr->Update(deltaTime);													// Movement and collision
	rendererPtr->Update(sceneGraphPtr->GetRenderableObjects(), sceneGraphPtr->GetCamera());	// Renders scene
}
#pragma endregion

#pragma region Clean Up
SceneManager::~SceneManager()
{
	delete audioManagerPtr;
	delete intelligenceManagerPtr;
	delete physicsManagerPtr;
	delete rendererPtr;
	delete sceneGraphPtr;
}
#pragma endregion