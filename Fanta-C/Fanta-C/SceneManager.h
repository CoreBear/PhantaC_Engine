#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

// My Headers
#include "Audio.h"
#include "GlobalDirectX.h"
#include "Physics.h"
#include "Scene.h"
#include "Typedefs.h"

// System Headers
#include <vector>

// Forward Declaration
class WorldObject;

class SceneManager
{
	Audio							audio;					
	Physics							physics;				// Collisions and movement
	class Player*					playerPtr;
	Scene							scene;					// The actual running of the scene (game update. i.e. scene agents)
	std::vector<WorldObject*>		sceneObjects;

	// Private
	void AddObjectToScene(WorldObject* object);
	void RemoveObjectFromScene(WorldObject* object);

public:
	// Initialization
	SceneManager(class InputController* inputController, ushort* clientDimensions);

	// Update
	void Update();

	// Accessors
	std::vector<WorldObject*>* GetSceneObjectsPtr() { return &sceneObjects; }
};

#endif