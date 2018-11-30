#pragma region Dependencies
// My Headers
#include "EnvironmentManager.h"			// Connection to declarations

#include "AudioManager.h"
#include "GlobalThreading.h"
#include "InputManager.h"
#include "PhysicsManager.h"
#include "Renderer.h"
#include "SceneGraph.h"
#include "SceneManager.h"
#include "UiManager.h"
#pragma endregion

#pragma region Global Variables (Do This Better)
float GlobalTime::deltaTime = 0;
#pragma endregion

#pragma region Initialization
EnvironmentManager::EnvironmentManager(HWND windowHandle, ushort* clientDimensions)
{
	#pragma region Module Creation
	audioManagerPtr = new AudioManager;

	inputManagerPtr = new InputManager;

	physicsManagerPtr = new PhysicsManager;

	sceneManagerPtr = new SceneManager(clientDimensions, &windowHandle, targetFPS);
	
	rendererPtr = new Renderer(windowHandle, sceneManagerPtr, clientDimensions, targetFPS, sceneManagerPtr->GetScenePtr()->GetCamera());
	
	uiManagerPtr = new UiManager;
	#pragma endregion
}
#pragma endregion

#pragma region Public Interface
void EnvironmentManager::ThreadLauncher(MSG* inMsg)
{	
	// Assigns the messaging system we will be checking against
	msg = inMsg;
	
	// Launch and run 2 new threads
	threads[0] = new std::thread(GlobalThreading::RunEnvironmentManagerThreads, 0, this, inMsg);
	threads[1] = new std::thread(GlobalThreading::RunEnvironmentManagerThreads, 1, this, inMsg);

	// Loose thread comes here to wait. Fix this later
	// Join threads before destroying them
	for (auto& thread : threads) thread->join();	
}
#pragma endregion

#pragma region Thread Functions
void EnvironmentManager::RunAudio() { audioManagerPtr->Update(); }
void EnvironmentManager::RunInput() { inputManagerPtr->Update(); }
void EnvironmentManager::RunPhysics() {} //physicsManagerPtr->Update(sceneManagerPtr->GetScenePtr()->GetCollidableObjects()); }
void EnvironmentManager::RunRenderer() { rendererPtr->Update(sceneManagerPtr->GetScenePtr()->GetRenderableObjects(), sceneManagerPtr->GetScenePtr()->GetCamera()); }
void EnvironmentManager::RunScene() { sceneManagerPtr->Update(); }
void EnvironmentManager::RunUI() { uiManagerPtr->Update(); }
#pragma endregion

#pragma region Clean Up
EnvironmentManager::~EnvironmentManager()
{
	if (audioManagerPtr) delete audioManagerPtr;
	if (inputManagerPtr) delete inputManagerPtr;
	if (physicsManagerPtr) delete physicsManagerPtr;
	if (rendererPtr) delete rendererPtr;
	if (sceneManagerPtr) delete sceneManagerPtr;
	if (uiManagerPtr) delete uiManagerPtr;

	// Delete all threads
	for (iterators[0] = 0; iterators[0] < numberOfThreads; ++iterators[0])
		delete threads[iterators[0]];
}
#pragma endregion