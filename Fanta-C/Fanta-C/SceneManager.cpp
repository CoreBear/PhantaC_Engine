#pragma region Dependencies
// My Headers
#include "SceneManager.h"		// Connection to declarations

#include "Agent.h"
#include "AudioManager.h"
#include "Camera.h"
#include "Cube.h"
#include "GlobalContainers.h"
#include "IntelligenceManager.h"
#include "PhysicsManager.h"
#include "RenderableObject.h"
#include "Renderer.h"
#pragma endregion

#pragma region Initialization
SceneManager::SceneManager(ushort* clientDimensions, HWND* windowHandle, uchar targetFPS)
{	
	#pragma region Camera Creation
	// Create camera
	cameraPtr = new Camera(clientDimensions, XMVectorSet(0, 3, -20, 1), XMVectorSet(0, 0, 1, 0), XMVectorSet(0, 1, 0, 0));
	#pragma endregion
	
	#pragma region Module Creation
	audioManagerPtr = new AudioManager;

	intelligenceManagerPtr = new IntelligenceManager;
	
	physicsManagerPtr = new PhysicsManager;

	rendererPtr = new Renderer(*windowHandle, this, clientDimensions, targetFPS, cameraPtr);
	#pragma endregion

	// Delete this when a solution to object creation is implemented
	#pragma region Temporary. Example of how to create a new gameobject. Will create a memory leak.
	// Create cube, make it non-collidable & renderable
	Agent* agent = new Agent(new Cube, false, true);

	// Add object to renderable container that is eventually passed to the renderer
	AddObjectToContainer<Mesh*>(&renderableObjects, agent->GetMeshPtr());
	#pragma endregion
}
#pragma endregion

#pragma region Update
void SceneManager::Update(float deltaTime)
{	
	audioManagerPtr->Update();									// Game audio
	intelligenceManagerPtr->Update(&autonomousAgents);			// AI
	physicsManagerPtr->Update(deltaTime, &collidableObjects);	// Movement and collision
	rendererPtr->Update(&renderableObjects, cameraPtr);			// Renders scene
}
#pragma endregion

#pragma region Clean Up
SceneManager::~SceneManager()
{
	delete audioManagerPtr;
	delete cameraPtr;
	delete intelligenceManagerPtr;
	delete physicsManagerPtr;
	delete rendererPtr;
}
#pragma endregion