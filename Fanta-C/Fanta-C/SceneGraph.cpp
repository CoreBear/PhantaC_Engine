#pragma region Dependencies
// My Headers
#include "SceneGraph.h"			// Connection to declarations

#include "AgentManager.h"
#include "Camera.h"
#include "Grid.h"
#include "PlayerManager.h"
#include "SceneObject.h"
#include "ScriptManager.h"
#include "TestScene.h"
#pragma endregion

#pragma region Initialization
SceneGraph::SceneGraph(ushort* clientDimensions) : poolerInstance(Pooler::GetInstance())
{
	// Figure out how to do this in container
	{
		// For each object, set to nullptr 
		for (graphIterator[0] = 0; graphIterator[0] < poolerInstance->sceneObjects.GetCapacity(); ++graphIterator[0])
			poolerInstance->sceneObjects.SetAt(graphIterator[0], nullptr);
	}

	#pragma region DONT TOUCH
	// Every scene needs a camera and for now a player and a grid
	// Create Camera - Camera needs to always be first
	sceneCameraPtr = Camera::GetInstance(clientDimensions);
	//AddObjectToScene(new SceneObject(new Camera(clientDimensions)));

	// Add player script to camera scene object and and camera to player script
	playerPtr = PlayerManager::GetInstance(sceneCameraPtr, this, 150, 150, 20, 20);

	// Create Grid
	AddObjectToScene(new SceneObject(new Grid(1), false, true));
	#pragma endregion
}
#pragma endregion

#pragma region Update
void SceneGraph::Update()
{
	//DON'T FORGET---------------------------Things will be popping in and out of the scene...make sure to wait until after update of every script before removing 
	//things from the sceneobjects container, so it won't conflict with the looping. Adding things is fine, so long as we add to the back of the container
	
	// Update player
	//playerPtr->Update();

	// Update every object in the scene
	for (graphIterator[0] = 0; graphIterator[0] < poolerInstance->sceneObjects.GetSize(); ++graphIterator[0])
		poolerInstance->sceneObjects.At(graphIterator[0])->Update();
}
#pragma endregion

#pragma region Public Interface
void SceneGraph::AddObjectToScene(SceneObject* object)
{
	if (poolerInstance->sceneObjects.GetSize() < GlobalSceneVariables::maxNumberOfSceneObjects)
	{
		// Add new object to scene objects
		poolerInstance->sceneObjects.AddToBack(object);

		// Put into containers to run collisions and rendering on it
		if (object->GetColliderManager()) poolerInstance->collidableObjects.AddToBack(object);
		if (object->GetRenderable()) poolerInstance->renderableObjects.AddToBack(object);
	}

	// This is specifically here to let you know that you've tried to instantiate more objects than the scene allows
	//else
	//	char mistake = 0;
}
void SceneGraph::CleanScene()
{
	// For each removable object, set active to false and remove from each container
	for (graphIterator[0] = 0; graphIterator[0] < poolerInstance->removableObjects.GetSize(); ++graphIterator[0])
	{
		poolerInstance->removableObjects.At(graphIterator[0])->SetActive(false);
		poolerInstance->collidableObjects.Remove(poolerInstance->removableObjects.At(graphIterator[0]));
		poolerInstance->renderableObjects.Remove(poolerInstance->removableObjects.At(graphIterator[0]));
		poolerInstance->sceneObjects.Remove(poolerInstance->removableObjects.At(graphIterator[0]));
	}

	// Clear the container for the next frame
	poolerInstance->removableObjects.Clear();
}
#pragma endregion

#pragma region Clean Up
SceneGraph::~SceneGraph()
{
	// Delete player
	delete playerPtr;

	// Delete camera
	delete sceneCameraPtr;

	// Delete pooler
	delete poolerInstance;
}
#pragma endregion
