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

	// Creating multiple scenes
	sceneGraphsPtr.push_back(new TestScene(clientDimensions));
	sceneGraphsPtr.push_back(new TestScene2(clientDimensions));

	// Manager will run this assigned scene
	currentScenePtr = sceneGraphsPtr.at(0);
	
	rendererPtr = new Renderer(*windowHandle, this, clientDimensions, targetFPS, currentScenePtr->GetCamera());
	#pragma endregion

	#pragma region Assign 1st Player
	// First player to navigate menus or whatever
	inputManagerPtr->AssignPlayer(currentScenePtr->GetPlayer());	
	#pragma endregion

	#pragma region Assign SceneManager to InputManager
	input->AssignSceneManager(this);
	#pragma endregion
}
#pragma endregion

#pragma region Public Interface
void SceneManager::ChangeScene(uchar index)
{
	// Change seen to update
	currentScenePtr = sceneGraphsPtr.at(index);

	// Change player to control
	inputManagerPtr->AssignPlayer(currentScenePtr->GetPlayer());
}
#pragma endregion

#pragma region Update
void SceneManager::Update(float deltaTime)
{	
	currentScenePtr->Update(deltaTime);															// Runs scripts
	audioManagerPtr->Update();																	// Game audio
	physicsManagerPtr->Update();																// Collision
	rendererPtr->Update(currentScenePtr->GetRenderableObjects(), currentScenePtr->GetCamera());	// Renders scene
}
#pragma endregion

#pragma region Clean Up
SceneManager::~SceneManager()
{
	if (audioManagerPtr) delete audioManagerPtr;
	if (physicsManagerPtr) delete physicsManagerPtr;
	if (rendererPtr) delete rendererPtr;

	for (iterators[0] = 0; iterators[0] < sceneGraphsPtr.size(); ++iterators[0])
		 if (sceneGraphsPtr.at(iterators[0])) delete sceneGraphsPtr.at(iterators[0]);
}
#pragma endregion