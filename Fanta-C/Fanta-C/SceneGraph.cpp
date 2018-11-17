#pragma region Dependencies
// My Headers
#include "SceneGraph.h"			// Connection to declarations

#include "Camera.h"
#include "PlayerManager.h"
#include "ScriptManager.h"
#include "TestScene.h"
#pragma endregion

#pragma region Initialization
SceneGraph::SceneGraph(ushort* clientDimensions)
{
	#pragma region Dont Touch (Creates scene camera and assigns scene player)
	// Create Camera - Camera needs to always be first
	AddObjectToSceneAsParent(new ObjectManager(new Camera(clientDimensions), true, false, true, true, XMVectorSet(0, 3, -20, 1), XMVectorSet(0, 0, 1, 0), XMVectorSet(0, 1, 0, 0)), nullptr);
	
	// Add player script to camera scene object and and camera to player script
	AddScript(sceneObjects.at(0), new PlayerManager(sceneObjects.at(0)->object));

	// Assign scene's player
	playerPtr = (PlayerManager*)sceneObjects.at(0)->myScripts.at(0);
	#pragma endregion

	//// Examples------------------------------------------------------------------------------------
	//// Creating visible game objects
	//AddObjectToSceneAsParent(new ObjectManager(new Pyramid, false, false, true, true), nullptr);
	//AddObjectToSceneAsParent(new ObjectManager(new Grid, false, false, true, true), nullptr);
	//AddObjectToSceneAsParent(new ObjectManager(new Cube, false, false, true, true), nullptr);
	//
	//// Creating non visible game objects
	//AddObjectToSceneAsParent(new ObjectManager(new Sphere, false, false, false, true), nullptr);
	//AddObjectToSceneAsParent(new ObjectManager(new Cube, false, false, false, true), nullptr);
	//
	//// Removing the grid
	////RemoveObjectFromScene(sceneObjects.at(2));
	//
	//// Adding a script to the object
	//AddScript(sceneObjects.at(1), new Test(sceneObjects.at(1)->object));
	//// End Examples--------------------------------------------------------------------------------
}
#pragma endregion

#pragma region Update
void SceneGraph::Update(float delteTime)
{
	// Update every object in the scene
	for (graphIterator[0] = 0; graphIterator[0] < sceneObjects.size(); ++graphIterator[0])
		sceneObjects.at(graphIterator[0])->Update(delteTime);
}
void SceneGraph::SceneObject::Update(float delteTime)
{
	// Run every script for object
	for (objectIterator[0] = 0; objectIterator[0] < myScripts.size(); ++objectIterator[0])
		myScripts.at(objectIterator[0])->Update(delteTime);
}
#pragma endregion

#pragma region Public Interface
void SceneGraph::AddObjectToSceneAsParent(ObjectManager* object, SceneObject* sceneObject)
{
	if (object)
	{
		sceneObjects.push_back(new SceneObject(object));

		// Put into containers to run collisions and rendering on it
		if (object->GetCollider()) collidableObjects.push_back(object);
		if (object->GetRenderable()) renderableObjects.push_back(object);
	}
	else
	{
		// Add object as scene object
		sceneObjects.push_back(sceneObject);

		// Remove child from previous parent
		if (sceneObject->parent)
			sceneObject->parent->children.erase(std::remove(sceneObject->parent->children.begin(), sceneObject->parent->children.end(), sceneObject), sceneObject->parent->children.end());

		// Assign child's parent
		sceneObject->parent = nullptr;
	}
}
void SceneGraph::AddScript(SceneObject* object, ScriptManager* script)
{
	object->myScripts.push_back(script);
}
void SceneGraph::ChildObjectToParent(SceneObject* parent, ObjectManager* object, SceneObject* childObject)
{
	if (object)
	{
		// Create new child scene object
		SceneObject* newChild = new SceneObject(object);

		// Add child to new parent
		parent->children.push_back(newChild);

		// Assign child's parent
		newChild->parent = parent;
	}
	else
	{
		// Add child to new parent
		parent->children.push_back(childObject);

		// Remove child from previous parent
		if (childObject->parent)
			childObject->parent->children.erase(std::remove(childObject->parent->children.begin(), childObject->parent->children.end(), childObject), childObject->parent->children.end());

		// Assign child's parent
		childObject->parent = parent;
	}
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
#pragma endregion

#pragma region Clean Up
SceneGraph::~SceneGraph()
{
	for (graphIterator[2] = 0; graphIterator[2] < sceneObjects.size(); ++graphIterator[2])
		if (sceneObjects.at(graphIterator[2])) delete sceneObjects.at(graphIterator[2]);
}
SceneGraph::SceneObject::~SceneObject()
{
	if (object) delete object;
	if (parent) delete parent;

	for (objectIterator[1] = 0; objectIterator[1] < myScripts.size(); ++objectIterator[1])
		if (myScripts.at(objectIterator[1])) delete myScripts.at(objectIterator[1]);

	for (objectIterator[1] = 0; objectIterator[1] < children.size(); ++objectIterator[1])
		if (children.at(objectIterator[1])) delete children.at(objectIterator[1]);
}
#pragma endregion
