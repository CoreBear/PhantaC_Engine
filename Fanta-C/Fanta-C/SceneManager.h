#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

// My Headers
#include "GlobalDirectX.h"

// System Headers
#include <vector>

// Forward Declaration
class TransformObject;

class SceneManager
{
	class Player*						playerPtr;
	std::vector<TransformObject*>		sceneObjects;

	// Black Box
	void AddObjectToScene(TransformObject* object);
	void RemoveObjectFromScene(TransformObject* object);

public:
	// Initialization
	SceneManager(class InputController* inputController);

	// Update
	void Update();

	// Accessors
	std::vector<TransformObject*>* GetSceneObjectsPtr() { return &sceneObjects; }
};

#endif