#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

#include "Pool.h"
#include "Projectile.h"
#include <vector>
class Camera;
class GeometricObject;

class SceneManager
{
	Camera*							cameraPtr;
	std::vector<GeometricObject*>	objectsToRender;
	Pool<Projectile, 20>			pooledProjectiles;

public:
	// Initialization
	SceneManager(class InputController* inputController);

	// Update
	void UpdateScene();

	// Scene Modifiers
	void AddObjectToScene(GeometricObject* object);
	void RemoveObjectFromScene(GeometricObject* object);

	// Accessors
	Camera* GetCameraPtr() { return cameraPtr; }
	std::vector<GeometricObject*>* GetObjectsToRenderPtr() { return &objectsToRender; }
};

#endif