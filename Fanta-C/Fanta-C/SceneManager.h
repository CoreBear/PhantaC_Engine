#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

#include <DirectXMath.h>
#include "Player.h"
#include "Pool.h"
#include "Projectile.h"
#include <vector>
class Camera;
class TransformObject;

class SceneManager
{
	Player*							playerPtr;
	//Pool<Projectile, 20>			pooledProjectiles;
	std::vector<TransformObject*>	sceneObjects;

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