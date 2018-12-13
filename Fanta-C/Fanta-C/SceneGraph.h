#ifndef _SCENE_GRAPH_H
#define _SCENE_GRAPH_H

// My Headers
#include "GlobalSceneVariables.h"
#include "GlobalTransform.h"
#include "GlobalTypedefs.h"
#include "MyArray.h"
#include "SceneObject.h"

// Forward Declarations
class Camera;
class PlayerManager;
class ScriptManager;

class SceneGraph
{
protected:
	Camera*																	sceneCameraPtr;
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>	collidableObjects;
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>	renderableObjects;
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>	sceneObjects;
	PlayerManager*															playerPtr;
	ushort																	graphIterator[3];

	/// Summary
	/// Checks if child is a child of parent
	///
	/// Parameters
	/// child - The object that wants to be added to parent's child list
	/// parent - The object that may receive child in it's child list
	bool CheckIfAlreadyChildToParent(SceneObject* child, SceneObject* parent);

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
	void AddObjectToCollide(SceneObject* object) { collidableObjects.AddToBack(object); }
	/// Summary
	/// Adds paramtered object into the renderable container that will be passed to the renderer manager
	///
	/// Parameters
	/// object - The object that will be added to the renderable container
	void AddObjectToRender(SceneObject* object) { renderableObjects.AddToBack(object); }
	/// Summary
	/// Adds paramtered object into the scene container that updates scripts
	///
	/// Parameters
	/// object - The object that will be added to the scene container
	void AddObjectToScene(SceneObject* object);
	/// Summary
	/// Adds a script to the scene object
	///
	/// Parameters
	/// object - The object that will receive the script
	/// script - The scrtip that will be added to the object
	void AddScript(SceneObject* object, ScriptManager* script);
	/// Summary
	/// Childs object to parent
	///
	/// Parameters
	/// child - The object that wants to be added to parent's child list
	/// parent - The object that may receive child in it's child list
	void ChildObjectToParent(SceneObject* child, SceneObject* parent);
	/// Summary
	/// Removes the parametered object from the collidable container
	///
	/// Parameters
	/// object - The object that will be removed from the collidable container
	void RemoveObjectFromCollide(SceneObject* object);
	/// Summary
	/// Removes the parametered object from the renderable container
	///
	/// Parameters
	/// object - The object that will be removed from the renderable container
	void RemoveObjectFromRender(SceneObject* object);
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
	Camera* GetCamera() { return sceneCameraPtr; }
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* GetSceneObjects() { return &sceneObjects; }
	PlayerManager* GetPlayer() { return playerPtr; }
	SceneObject* GetGrid() { return sceneObjects.At(0); }
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* GetCollidableObjects() { return &collidableObjects; }
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* GetRenderableObjects() { return &renderableObjects; }
};

#endif