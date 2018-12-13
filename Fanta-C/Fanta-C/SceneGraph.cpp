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
SceneGraph::SceneGraph(ushort* clientDimensions)
{
	#pragma region DONT TOUCH
	// Every scene needs a camera and for now a player and a grid
	// Create Camera - Camera needs to always be first
	sceneCameraPtr = Camera::GetInstance(clientDimensions);
	//AddObjectToScene(new SceneObject(new Camera(clientDimensions)));

	// Add player script to camera scene object and and camera to player script
	playerPtr = PlayerManager::GetInstance(sceneCameraPtr, this, 20, 100);

	// Create Grid
	AddObjectToScene(new SceneObject(new Grid, false, true));
	#pragma endregion
}
#pragma endregion

#pragma region Update
void SceneGraph::Update()
{
	//DON'T FORGET---------------------------Things will be popping in and out of the scene...make sure to wait until after update of every script before removing 
	//things from the sceneobjects container, so it won't conflict with the looping. Adding things is fine, so long as we add to the back of the container
	
	// Update player
	playerPtr->Update();

	// Update every object in the scene
	for (graphIterator[0] = 0; graphIterator[0] < sceneObjects.GetSize(); ++graphIterator[0])
		sceneObjects.At(graphIterator[0])->Update();
}
#pragma endregion

#pragma region Public Interface
void SceneGraph::AddObjectToScene(SceneObject* object)
{
	if (sceneObjects.GetSize() < GlobalSceneVariables::maxNumberOfSceneObjects)
	{
		// Add new object to scene objects
		sceneObjects.AddToBack(object);

		// Put into containers to run collisions and rendering on it
		if (object->GetColliderManager()) collidableObjects.AddToBack(object);
		if (object->GetRenderable()) renderableObjects.AddToBack(object);
	}

	// This is specifically here to let you know that you've tried to instantiate more objects than the scene allows
	else
		char mistake = 0;
}
void SceneGraph::AddScript(SceneObject* object, ScriptManager* script)
{
	object->GetMyScripts()->push_back(script);
}
void SceneGraph::ChildObjectToParent(SceneObject* child, SceneObject* parent)
{
	// If child is not already childed to parent, child it
	if (!CheckIfAlreadyChildToParent(child, parent))
		parent->GetMyChildren()->push_back(child);
}
void SceneGraph::RemoveObjectFromCollide(SceneObject* object)
{
	// For each collidable object
	for (graphIterator[2] = 0; graphIterator[2] < collidableObjects.GetSize(); ++graphIterator[2])
	{
		// If object is a collidable object, remove it
		if (object == collidableObjects.At(graphIterator[2]))
			collidableObjects.RemoveAt(graphIterator[2]);
	}
}
void SceneGraph::RemoveObjectFromRender(SceneObject* object)
{
	// For each renderable object
	for (graphIterator[2] = 0; graphIterator[2] < renderableObjects.GetSize(); ++graphIterator[2])
	{
		// If oject is a renderable object, remove it
		if (object == renderableObjects.At(graphIterator[2]))
			renderableObjects.RemoveAt(graphIterator[2]);
	}
}
void SceneGraph::RemoveObjectFromScene(SceneObject* object)
{
	RemoveObjectFromCollide(object);
	RemoveObjectFromRender(object);

	// Remove object from scene
	sceneObjects.Remove(object);

	delete object;
}
void SceneGraph::RemoveScript(SceneObject* object, ScriptManager* script)
{
	// Remove script
	object->GetMyScripts()->erase(std::remove(object->GetMyScripts()->begin(), object->GetMyScripts()->end(), script), object->GetMyScripts()->end());
}
#pragma endregion

#pragma region Private
bool SceneGraph::CheckIfAlreadyChildToParent(SceneObject* child, SceneObject* parent)
{
	// If child is already childed to parent
	if (std::find(parent->GetMyChildren()->begin(), parent->GetMyChildren()->end(), child) != parent->GetMyChildren()->end())
		return true;

	// If child is not already childed to parent
	return false;
}
#pragma endregion

#pragma region Clean Up
SceneGraph::~SceneGraph()
{
	// Delete player
	delete playerPtr;

	// Delete camera
	delete sceneCameraPtr;

	for (graphIterator[0] = 0; graphIterator[0] < sceneObjects.GetSize(); ++graphIterator[0])
	{
		if (sceneObjects.At(graphIterator[0]))
		{
			delete sceneObjects.At(graphIterator[0]);
			sceneObjects.At(graphIterator[0]);
		}
	}
}
#pragma endregion
