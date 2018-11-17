#ifndef _SCENE_GRAPH_H
#define _SCENE_GRAPH_H

// System Headers
#include <vector>

// My Headers
#include "GlobalTypedefs.h"
#include "ObjectManager.h"

// Forward Declarations
class ObjectManager;
class PlayerManager;

class SceneGraph
{
protected:
	struct SceneObject
	{
		ushort objectIterator[3];

		// Variables
		std::vector<class ScriptManager*>	myScripts;
		ObjectManager*						object = nullptr;
		SceneObject*						parent = nullptr;
		std::vector<SceneObject*>			children;

		// Update
		void Update(float delteTime);

		// Initialization
		SceneObject(ObjectManager* inObject) { object = inObject; }

		// Clean Up
		~SceneObject();
	};

	PlayerManager*				playerPtr;
	// Camera will always be the first object in the scene
	std::vector<ObjectManager*> collidableObjects;
	std::vector<ObjectManager*> renderableObjects;
	std::vector<SceneObject*>	sceneObjects;
	ushort graphIterator[3];

public:
	// Initialization
	SceneGraph(ushort* clientDimensions);

	// Update
	void Update(float delteTime);

	// Public Interface
	void AddObjectToCollide(ObjectManager* object) { collidableObjects.push_back(object); }
	void AddObjectToRender(ObjectManager* object) { renderableObjects.push_back(object); }
	void AddObjectToSceneAsParent(ObjectManager* object, SceneObject* sceneObject);
	void AddScript(SceneObject* object, ScriptManager* script);
	void ChildObjectToParent(SceneObject* parent, ObjectManager* object, SceneObject* childObject);
	void RemoveObjectFromCollide(ObjectManager* object);
	void RemoveObjectFromRender(ObjectManager* object);
	void RemoveObjectFromScene(SceneObject* object);

	// Clean Up
	~SceneGraph();

	// Accessors
	ObjectManager* GetCamera() { return sceneObjects.at(0)->object; }
	PlayerManager* GetPlayer() { return playerPtr; }
	std::vector<ObjectManager*>* GetRenderableObjects() { return &renderableObjects; }
};

#endif