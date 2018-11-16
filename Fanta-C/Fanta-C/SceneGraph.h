#ifndef _SCENE_GRAPH_H
#define _SCENE_GRAPH_H

// System Headers
#include <vector>

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class ObjectManager;

class SceneGraph
{
	ushort graphIterator;

	struct SceneObject
	{
		ushort objectIterator;

		// Variables
		ObjectManager*				object;
		SceneObject*				parent = nullptr;
		std::vector<SceneObject*>	children;

		// Initialization
		SceneObject(ObjectManager* inObject) { object = inObject; }

		// Clean Up
		~SceneObject();
	};

	// Camera will always be the first object in the scene
	std::vector<ObjectManager*> collidableObjects;
	std::vector<ObjectManager*> renderableObjects;
	std::vector<SceneObject*>	sceneObjects;

public:
	// Initialization
	SceneGraph(ushort* clientDimensions);

	// Public Interface
	void AddObjectToCollide(ObjectManager* object) { collidableObjects.push_back(object); }
	void AddObjectToRender(ObjectManager* object) { renderableObjects.push_back(object); }
	void AddObjectToSceneAsParent(ObjectManager* object, SceneObject* sceneObject);
	void ChildObjectToParent(SceneObject* parent, ObjectManager* object, SceneObject* childObject);
	void RemoveObjectFromCollide(ObjectManager* object);
	void RemoveObjectFromRender(ObjectManager* object);
	void RemoveObjectFromScene(SceneObject* object);

	// Clean Up
	~SceneGraph();

	// Accessors
	ObjectManager* GetCamera() { return sceneObjects.at(0)->object; }
	std::vector<ObjectManager*>* GetRenderableObjects() { return &renderableObjects; }
};

#endif