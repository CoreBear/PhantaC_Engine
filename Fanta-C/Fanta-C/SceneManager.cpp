#pragma region Dependencies
// My Headers
#include "SceneManager.h"		// Connection to declarations

#include "Agent.h"
#include "AudioManager.h"
#include "Camera.h"
#include "IntelligenceManager.h"
#include "PhysicsManager.h"
#include "RenderableObject.h"
#include "Renderer.h"

// Just here to demonstrate adding and removing to and from containers
#include "Cube.h"
#include "GlobalContainerManipulation.h"
#include "GlobalIterators.h"
#include "Pyramid.h"
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

	// Temporary example of how to create a renderable game object.
	// Look in destructor for deletion, or leak will be created
	// Look into object pooling to counteract the "new" call
	AddObjectToContainer<Mesh*>(&renderableObjects, new Cube);
	AddObjectToContainer<Mesh*>(&renderableObjects, new Pyramid);
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
	
	// Temporary example of how to create a renderable game object.
	for (iterators[0] = 0; iterators[0] < renderableObjects.size(); ++iterators[0])
		delete renderableObjects.at(iterators[0]);
}
#pragma endregion