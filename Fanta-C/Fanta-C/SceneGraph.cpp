#pragma region Dependencies
// My Headers
#include "SceneGraph.h"			// Connection to declarations

#include "Camera.h"
#include "Grid.h"
#include "ScriptManager.h"
#include "TestScene.h"
#pragma endregion

#pragma region Initialization
SceneGraph::SceneGraph(ushort* clientDimensions)
{
	// DON'T TOUCH! 
	// Every scene needs a camera and for now a grid
	// Create Camera - Camera needs to always be first
	AddObjectToScene(new ObjectManager(new Camera(clientDimensions)), nullptr);

	// Create Grid
	AddObjectToScene(new ObjectManager(new Grid, false, true), nullptr);
}
#pragma endregion

#pragma region Update
void SceneGraph::Update()
{
	// Update every object in the scene
	for (graphIterator[0] = 0; graphIterator[0] < sceneObjects.size(); ++graphIterator[0])
		sceneObjects.at(graphIterator[0])->Update();
}
void SceneGraph::SceneObject::Update()
{
	// Run every script for object
	for (objectIterator[0] = 0; objectIterator[0] < myScripts.size(); ++objectIterator[0])
		myScripts.at(objectIterator[0])->Update();
}
#pragma endregion

#pragma region Public Interface
void SceneGraph::AddObjectToScene(ObjectManager* object, SceneObject* sceneObject)
{
	if (object)
	{
		sceneObjects.push_back(new SceneObject(object));

		// Put into containers to run collisions and rendering on it
		if (object->GetColliderManager()) collidableObjects.push_back(object);
		if (object->GetRenderable()) renderableObjects.push_back(object);
	}
	else
	{
		// Add object as scene object
		sceneObjects.push_back(sceneObject);
	}
}
void SceneGraph::AddScript(SceneObject* object, ScriptManager* script)
{
	object->myScripts.push_back(script);
}
void SceneGraph::RemoveObjectFromCollide(ObjectManager* object)
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
void SceneGraph::RemoveObjectFromScene(SceneObject * object)
{
	RemoveObjectFromCollide(object->object);
	RemoveObjectFromRender(object->object);

	// Remove object from scene
	sceneObjects.erase(std::remove(sceneObjects.begin(), sceneObjects.end(), object), sceneObjects.end());

	delete object;
}
void SceneGraph::RemoveScript(SceneObject* object, ScriptManager* script)
{
	// Remove script
	object->myScripts.erase(std::remove(object->myScripts.begin(), object->myScripts.end(), script), object->myScripts.end());
}
#pragma endregion

#pragma region Clean Up
SceneGraph::~SceneGraph()
{
	for (graphIterator[2] = 0; graphIterator[2] < sceneObjects.size(); ++graphIterator[2])
		if (sceneObjects.at(graphIterator[2])) { delete sceneObjects.at(graphIterator[2]); }
}
SceneGraph::SceneObject::~SceneObject()
{
	if (object) delete object;

	for (objectIterator[1] = 0; objectIterator[1] < myScripts.size(); ++objectIterator[1])
		if (myScripts.at(objectIterator[1])) { delete myScripts.at(objectIterator[1]); }
}
#pragma endregion
