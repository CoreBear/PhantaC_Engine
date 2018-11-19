#pragma region Dependencies
// My Headers
#include "SceneManager.h"		// Connection to declarations

#include "AudioManager.h"
#include "InputManager.h"
#include "PhysicsManager.h"
#include "SceneGraph.h"
#include "TestScene.h"
#include "TestScene2.h"
#pragma endregion

#pragma region Initialization
SceneManager::SceneManager(ushort* clientDimensions, HWND* windowHandle, uchar targetFPS, InputManager* input) : inputManagerPtr(input)
{	
	#pragma region Module Creation
	audioManagerPtr = new AudioManager;
	
	physicsManagerPtr = new PhysicsManager;

	// Assign whatever scene you want to run
	scenePtr = new TestScene(clientDimensions);
	
	rendererPtr = new Renderer(*windowHandle, this, clientDimensions, targetFPS, scenePtr->GetCamera());
	#pragma endregion

	#pragma region Assign 1st Player
	// First player to navigate menus or whatever
	inputManagerPtr->AssignPlayer(scenePtr->GetPlayer());
	#pragma endregion

	#pragma region Assign SceneManager to InputManager
	input->AssignSceneManager(this);
	#pragma endregion
}
#pragma endregion

#pragma region Update
void SceneManager::Update(float deltaTime)
{	
	scenePtr->Update(deltaTime);													// Runs scripts
	audioManagerPtr->Update();														// Game audio
	physicsManagerPtr->Update(scenePtr->GetCollidableObjects());					// Collision
	rendererPtr->Update(scenePtr->GetRenderableObjects(), scenePtr->GetCamera());	// Renders scene
}
#pragma endregion

#pragma region Clean Up
SceneManager::~SceneManager()
{
	if (audioManagerPtr) delete audioManagerPtr;
	if (physicsManagerPtr) delete physicsManagerPtr;
	if (rendererPtr) delete rendererPtr;
	if (scenePtr) delete scenePtr;
}
#pragma endregion