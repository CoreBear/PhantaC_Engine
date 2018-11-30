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
	/// Summary
	/// Adds paramtered object into the collidable container that will be passed to the collision manager
	///
	/// Parameters
	/// object - The object that will be added to the collidable container
	void AddObjectToCollide(ObjectManager* object) { collidableObjects.push_back(object); }
	/// Summary
	/// Adds paramtered object into the renderable container that will be passed to the renderer manager
	///
	/// Parameters
	/// object - The object that will be added to the renderable container
	void AddObjectToRender(ObjectManager* object) { renderableObjects.push_back(object); }
	/// Summary
	/// Adds paramtered object into the scene container that updates scripts
	///
	/// Parameters
	/// object - The object that will be added to the scene container
	void AddObjectToScene(ObjectManager* object, SceneObject* sceneObject);
	/// Summary
	/// Adds a script to the scene object
	///
	/// Parameters
	/// object - The object that will receive the script
	/// script - The scrtip that will be added to the object
	void AddScript(SceneObject* object, ScriptManager* script);
	/// Summary
	/// Removes the parametered object from the collidable container
	///
	/// Parameters
	/// object - The object that will be removed from the collidable container
	void RemoveObjectFromCollide(ObjectManager* object);
	/// Summary
	/// Removes the parametered object from the renderable container
	///
	/// Parameters
	/// object - The object that will be removed from the renderable container
	void RemoveObjectFromRender(ObjectManager* object);
	/// Summary
	/// Removes the parametered object from the scene objects container
	///
	/// Parameters
	/// object - The object that will be removed from the scene objects container
	void RemoveObjectFromScene(SceneObject* object);
	/// Summary
	/// Removes script from scene object
	///
	/// Parameters
	/// object - The object that will lose the script
	/// script - The scrtip that will be removed from the object
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