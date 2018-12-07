#pragma region Dependencies
// My Headers
#include "EnvironmentManager.h"			// Connection to declarations

#include "AudioManager.h"
#include "EventManager.h"
#include "PhysicsManager.h"
#include "Renderer.h"
#include "SceneGraph.h"
#include "SceneManager.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Forward Declarations
EnvironmentManager* EnvironmentManager::environmentManagerInstance = nullptr;
#pragma endregion

#pragma region Initialization
EnvironmentManager::EnvironmentManager(HWND* inWindowHandle, ushort* clientDimensions)
{
	#pragma region Module Creation
	audioManagerPtr = AudioManager::GetInstance();

	sceneManagerPtr = SceneManager::GetInstance(clientDimensions, inWindowHandle, targetFPS);

	eventManagerPtr = EventManager::GetInstance(sceneManagerPtr->GetScenePtr()->GetPlayer());

	physicsManagerPtr = PhysicsManager::GetInstance(sceneManagerPtr->GetScenePtr()->GetGrid());
	
	rendererPtr = Renderer::GetInstance(inWindowHandle, sceneManagerPtr, clientDimensions, targetFPS, sceneManagerPtr->GetScenePtr()->GetCamera());
	#pragma endregion
}
#pragma endregion

#pragma region Thread Functions
void EnvironmentManager::RunAudio() { audioManagerPtr->Update(); }
void EnvironmentManager::RunEventHandler() { eventManagerPtr->Update(); }
void EnvironmentManager::RunPhysics() { physicsManagerPtr->Update(sceneManagerPtr->GetScenePtr()->GetcollidableObjects()); }
void EnvironmentManager::RunRenderer() { rendererPtr->Update(sceneManagerPtr->GetScenePtr()->GetrenderableObjects(), sceneManagerPtr->GetScenePtr()->GetCamera()); }
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
	if (eventManagerPtr) delete eventManagerPtr;
	if (physicsManagerPtr) delete physicsManagerPtr;
	if (rendererPtr) delete rendererPtr;
	if (sceneManagerPtr) delete sceneManagerPtr;
}
#pragma endregion