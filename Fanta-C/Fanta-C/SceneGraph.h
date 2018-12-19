#ifndef _SCENE_GRAPH_H
#define _SCENE_GRAPH_H

// My Headers
#include "GlobalSceneVariables.h"
#include "GlobalTypedefs.h"
#include "MyArray.h"
#include "Pooler.h"
#include "SceneObject.h"

// Forward Declarations
class Camera;
class PlayerManager;
class Pooler;
class ScriptManager;

class SceneGraph
{
protected:
	Camera*			sceneCameraPtr;
	PlayerManager*	playerPtr;
	Pooler*			poolerInstance;
	ushort			graphIterator[2];

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
	void AddObjectToCollide(SceneObject* object) { poolerInstance->collidableObjects.AddToBack(object); }
	/// Summary
	/// Adds paramtered object into the removable container that will be cleared at the end of the frame
	///
	/// Parameters
	/// object - The object that will be added to the removable container
	void AddObjectToRemove(SceneObject* object) { poolerInstance->removableObjects.AddToBack(object); }
	/// Summary
	/// Adds paramtered object into the renderable container that will be passed to the renderer manager
	///
	/// Parameters
	/// object - The object that will be added to the renderable container
	void AddObjectToRender(SceneObject* object) { poolerInstance->renderableObjects.AddToBack(object); }
	/// Summary
	/// Adds paramtered object into the scene container that updates scripts
	///
	/// Parameters
	/// object - The object that will be added to the scene container
	void AddObjectToScene(SceneObject* object);
	/// Summary
	/// Removes objects that are cleared for removal
	/// Does this after scene has been rendered
	void CleanScene();

	// Clean Up
	~SceneGraph();

	// Accessors
	Camera* GetCamera() { return sceneCameraPtr; }
	PlayerManager* GetPlayer() { return playerPtr; }
	SceneObject* GetGrid() { return poolerInstance->sceneObjects.At(0); }
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* GetCollidableObjects() { return &poolerInstance->collidableObjects; }
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* GetRemovableObjects() { return &poolerInstance->removableObjects; }
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* GetRenderableObjects() { return &poolerInstance->renderableObjects; }
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* GetSceneObjects() { return &poolerInstance->sceneObjects; }
};

#endif