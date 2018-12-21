#ifndef _SCENE_GRAPH_H
#define _SCENE_GRAPH_H

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class Camera;
class PlayerManager;
class SceneObject;
class ScriptManager;

class SceneGraph
{
protected:
	Camera * sceneCameraPtr;
	PlayerManager*	playerPtr;
	SceneObject*	gridPtr;
	ushort			graphIterator;
	static ushort	numberOfObjectsInScene;

public:
	// Initialization
	SceneGraph(bool useGrid, ushort* clientDimensions);

	// Update
	void UpdateScripts();

	// Public Interface
	static void ActivateObject(SceneObject* object);
	void CleanScene();
	bool CreateSceneObject(SceneObject* object);
	static void RemoveFromActive(SceneObject* object);

	// Clean Up
	~SceneGraph();

	// Accessors
	Camera& GetCamera() const { return *sceneCameraPtr; }
	PlayerManager& GetPlayer() const { return *playerPtr; }
	SceneObject& GetGrid() const { return *gridPtr; }
};

#endif