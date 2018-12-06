#pragma region Dependencies
// My Headers
#include "EnvironmentManager.h"			// Connection to declarations

#include "AudioManager.h"
#include "GlobalConsoleWrite.h"
#include "GlobalThreading.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "PhysicsManager.h"
#include "Renderer.h"
#include "SceneGraph.h"
#include "SceneManager.h"
#include "SceneObject.h"
#include "SplashManager.h"
#pragma endregion

#pragma region Forward Declarations
EnvironmentManager* EnvironmentManager::environmentManagerInstance = nullptr;
float GlobalTime::deltaTime = 0;
#pragma endregion

#pragma region Initialization
EnvironmentManager::EnvironmentManager(HWND* inWindowHandle, ushort* clientDimensions)
{
	// Hacked to write to console
	handle = inWindowHandle;

	#pragma region Module Creation
	audioManagerPtr = AudioManager::GetInstance();

	sceneManagerPtr = SceneManager::GetInstance(clientDimensions, inWindowHandle, targetFPS);

	inputManagerPtr = InputManager::GetInstance(sceneManagerPtr->GetScenePtr()->GetPlayer());

	physicsManagerPtr = PhysicsManager::GetInstance(sceneManagerPtr->GetScenePtr()->GetGrid());
	
	rendererPtr = Renderer::GetInstance(inWindowHandle, sceneManagerPtr, clientDimensions, targetFPS, sceneManagerPtr->GetScenePtr()->GetCamera());
	#pragma endregion
}
#pragma endregion

#pragma region Public Interface
void EnvironmentManager::InitializeEnvironment(MSG* inMsg)
{	
	// Assigns the messaging system we will be checking against
	msg = inMsg;
	
	// Launch and run game threads (Input, Physics, Frame)
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
#pragma endregion

#pragma region Accessors
EnvironmentManager* EnvironmentManager::GetInstance(HWND * inWindowHandle, ushort * clientDimensions)
{
	// If instance has already been created
	if (environmentManagerInstance) return environmentManagerInstance;

	// If instance has not been created, create one and return it
	else
	{
		environmentManagerInstance = new EnvironmentManager(inWindowHandle, clientDimensions);
		return environmentManagerInstance;
	}
}
#pragma endregion

#pragma region Clean Up
EnvironmentManager::~EnvironmentManager()
{
	if (audioManagerPtr) delete audioManagerPtr;
	if (inputManagerPtr) delete inputManagerPtr;
	if (physicsManagerPtr) delete physicsManagerPtr;
	if (rendererPtr) delete rendererPtr;
	if (sceneManagerPtr) delete sceneManagerPtr;

	// Delete all threads
	for (uchar i = 0; i < numberOfThreads; ++i)
		delete threads[i];
}
#pragma endregion