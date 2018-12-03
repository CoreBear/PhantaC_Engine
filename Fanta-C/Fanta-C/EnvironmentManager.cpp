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
#include "SplashManager.h"
#include "UiManager.h"
#pragma endregion

#pragma region Global Variables (Do This Better)
float GlobalTime::deltaTime = 0;
#pragma endregion

#pragma region Initialization
EnvironmentManager::EnvironmentManager(HWND* inWindowHandle, ushort* clientDimensions)
{
	// Hacked together for FPS update. Remove later
	windowHandle = inWindowHandle;

	#pragma region Module Creation
	audioManagerPtr = new AudioManager;

	inputManagerPtr = new InputManager;

	sceneManagerPtr = new SceneManager(clientDimensions, inWindowHandle, targetFPS);

	physicsManagerPtr = new PhysicsManager(sceneManagerPtr->GetScenePtr()->GetGrid());
	
	rendererPtr = new Renderer(inWindowHandle, sceneManagerPtr, clientDimensions, targetFPS, sceneManagerPtr->GetScenePtr()->GetCamera());
	
	uiManagerPtr = new UiManager;
	#pragma endregion

	// Runs splash screen(s)
	SplashManager splashManager;
}
#pragma endregion

#pragma region Public Interface
void EnvironmentManager::InitializeEnvironment(MSG* inMsg)
{	
	// Assigns the messaging system we will be checking against
	msg = inMsg;
	
	// Launch and run 3 new threads
	for (uchar i = 0; i < numberOfThreads; ++i)
		threads[i] = new std::thread(GlobalThreading::RunEnvironmentManagerThreads, i, this, inMsg);

	// Loose thread comes here to wait. Fix this later
	// Join threads before returning control over to the application level
	for (auto& thread : threads) thread->join();	
}
#pragma endregion

#pragma region Thread Functions
void EnvironmentManager::RunAudio() { audioManagerPtr->Update(); }
void EnvironmentManager::RunInput() { inputManagerPtr->Update(); }
void EnvironmentManager::RunPhysics() { physicsManagerPtr->Update(sceneManagerPtr->GetScenePtr()->GetCollidableObjects()); }
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
	for (uchar i = 0; i < numberOfThreads; ++i)
		delete threads[i];
}
#pragma endregion