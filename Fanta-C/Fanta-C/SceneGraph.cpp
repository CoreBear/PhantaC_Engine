#pragma region Dependencies
// My Headers
#include "SceneGraph.h"			// Connection to declarations

#include "Camera.h"
#include "Grid.h"
#include "ObjectManager.h"
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
	//AddObjectToScene(new ObjectManager(new Camera(clientDimensions)));

	// Add player script to camera scene object and and camera to player script
	playerPtr = new PlayerManager(sceneCameraPtr, this, 20, 100);

	// Create Grid
	AddObjectToScene(new ObjectManager(new Grid, false, true));
	#pragma endregion
}
#pragma endregion

#pragma region Update
void SceneGraph::Update()
{
	// Update player
	playerPtr->Update();

	// Update every object in the scene
	for (graphIterator[0] = 0; graphIterator[0] < sceneObjects.size(); ++graphIterator[0])
		sceneObjects.at(graphIterator[0])->Update();
}
#pragma endregion

#pragma region Public Interface
void SceneGraph::AddObjectToScene(ObjectManager* object)
{
	// Create new scene object
	SceneObject* newSceneObject = new SceneObject(object);

	// Add new object to scene objects
	sceneObjects.push_back(newSceneObject);

	// Put into containers to run collisions and rendering on it
	if (object->GetColliderManager()) collidableObjects.push_back(newSceneObject);
	if (object->GetRenderable()) renderableObjects.push_back(object);
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
	for (graphIterator[2] = 0; graphIterator[2] < collidableObjects.size(); ++graphIterator[2])
	{
		// If object is a collidable object, remove it
		if (object == collidableObjects.at(graphIterator[2]))
			collidableObjects.erase(collidableObjects.begin() + graphIterator[2]);
	}
}
void SceneGraph::RemoveObjectFromRender(ObjectManager* object)
{
	// For each renderable object
	for (graphIterator[2] = 0; graphIterator[2] < renderableObjects.size(); ++graphIterator[2])
	{
		// If oject is a renderable object, remove it
		if (object == renderableObjects.at(graphIterator[2]))
			renderableObjects.erase(renderableObjects.begin() + graphIterator[2]);
	}
}
void SceneGraph::RemoveObjectFromScene(SceneObject* object)
{
	RemoveObjectFromCollide(object);
	RemoveObjectFromRender(object->GetMyObject());

	// Remove object from scene
	sceneObjects.erase(std::remove(sceneObjects.begin(), sceneObjects.end(), object), sceneObjects.end());

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

	// Delete all scene objects
	for (graphIterator[2] = 0; graphIterator[2] < sceneObjects.size(); ++graphIterator[2])
		if (sceneObjects.at(graphIterator[2])) delete sceneObjects.at(graphIterator[2]);
}
#pragma endregion
