#ifndef _SCENE_GRAPH_H
#define _SCENE_GRAPH_H

// System Headers
#include <vector>

// My Headers
#include "GlobalTransform.h"
#include "GlobalTypedefs.h"
#include "ObjectManager.h"

// Forward Declarations
class PlayerManager;

class SceneGraph
{
protected:
	struct SceneObject
	{
		// Variables
		std::vector<class ScriptManager*>	myScripts;
		ObjectManager*						object = nullptr;
		ushort								objectIterator[3];

		// Initialization
		SceneObject(ObjectManager* inObject) { object = inObject; }

		// Update
		void Update();

		// Clean Up
		~SceneObject();
	};

	// Camera will always be the first object in the scene
	PlayerManager*				playerPtr;
	std::vector<ObjectManager*> collidableObjects;
	std::vector<ObjectManager*> renderableObjects;
	std::vector<SceneObject*>	sceneObjects;
	ushort						graphIterator[3];

public:
	// Initialization
	SceneGraph(ushort* clientDimensions);

	// Update
	void Update();

	// Public Interface
	void AddObjectToCollide(ObjectManager* object) { collidableObjects.push_back(object); }
	void AddObjectToRender(ObjectManager* object) { renderableObjects.push_back(object); }
	void AddObjectToScene(ObjectManager* object, SceneObject* sceneObject);
	void AddScript(SceneObject* object, ScriptManager* script);
	void RemoveObjectFromCollide(ObjectManager* object);
	void RemoveObjectFromRender(ObjectManager* object);
	void RemoveObjectFromScene(SceneObject* object);
	void RemoveScript(SceneObject* object, ScriptManager* script);

	// Clean Up
	~SceneGraph();

	// Accessors
	ObjectManager* GetCamera() { return sceneObjects.at(0)->object; }
	PlayerManager* GetPlayer() { return playerPtr; }
	std::vector<ObjectManager*>* GetCollidableObjects() { return &collidableObjects; }
	std::vector<ObjectManager*>* GetRenderableObjects() { return &renderableObjects; }
};

#endif