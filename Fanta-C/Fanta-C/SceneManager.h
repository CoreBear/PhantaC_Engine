#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

// My Headers
#include "GlobalDirectX.h"

// System Headers
#include <vector>

// Forward Declaration
class WorldObject;

class SceneManager
{
	class Player*						playerPtr;
	std::vector<WorldObject*>		sceneObjects;

	// Private
	void AddObjectToScene(WorldObject* object);
	void RemoveObjectFromScene(WorldObject* object);

public:
	// Initialization
	SceneManager(class InputController* inputController);

	// Update
	void Update();

	// Accessors
	std::vector<WorldObject*>* GetSceneObjectsPtr() { return &sceneObjects; }
};

#endif