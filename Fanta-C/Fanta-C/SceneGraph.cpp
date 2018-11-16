#pragma region Dependencies
// My Headers
#include "SceneGraph.h"			// Connection to declarations

#include "Camera.h"
#include "Grid.h"
#include "ObjectManager.h"
#include "Pyramid.h"
#pragma endregion

#pragma region Initialization
SceneGraph::SceneGraph(ushort* clientDimensions)
{
	// Create Camera
	AddObjectToSceneAsParent(new ObjectManager(new Camera(clientDimensions), true, false, true, XMVectorSet(0, 3, -20, 1), XMVectorSet(0, 0, 1, 0), XMVectorSet(0, 1, 0, 0)), nullptr);
	
	// Examples
	AddObjectToSceneAsParent(new ObjectManager(new Grid, false, false, true), nullptr);
	AddObjectToSceneAsParent(new ObjectManager(new Pyramid, false, false, true), nullptr);
	RemoveObjectFromScene(sceneObjects.at(1));
}
#pragma endregion

#pragma region Public Interface
void SceneGraph::AddObjectToSceneAsParent(ObjectManager* object, SceneObject* sceneObject)
{
	if (object)
	{
		sceneObjects.push_back(new SceneObject(object));

		// Put into containers to run collisions and rendering on it
		if (object->GetMesh()) collidableObjects.push_back(object);
		if (object->GetTransform()) renderableObjects.push_back(object);
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
	for (graphIterator = 0; graphIterator < collidableObjects.size(); ++graphIterator)
	{
		// If object is a collidable object, remove it
		if (object == collidableObjects.at(graphIterator))
			collidableObjects.erase(collidableObjects.begin() + graphIterator);
	}
}
void SceneGraph::RemoveObjectFromRender(ObjectManager* object)
{
	// For each renderable object
	for (graphIterator = 0; graphIterator < renderableObjects.size(); ++graphIterator)
	{
		// If oject is a renderable object, remove it
		if (object == renderableObjects.at(graphIterator))
			renderableObjects.erase(renderableObjects.begin() + graphIterator);
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
	for (graphIterator = 0; graphIterator < sceneObjects.size(); ++graphIterator)
		delete sceneObjects.at(graphIterator);
}
SceneGraph::SceneObject::~SceneObject()
{
	if (object) delete object;

	for (objectIterator = 0; objectIterator < children.size(); ++objectIterator)
		delete children.at(objectIterator);
}
#pragma endregion
