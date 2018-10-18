#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

#include <vector>
class Camera;
class GeometricObject;

class SceneManager
{
	Camera*							cameraPtr;
	std::vector<GeometricObject*>	objectsToRender;

public:
	// Initialization
	SceneManager(class InputController* inputController);

	// Scene Modifiers
	void AddObjectToScene(GeometricObject* object);
	void RemoveObjectFromScene(GeometricObject* object);

	// Accessors
	Camera* GetCameraPtr() { return cameraPtr; }
	std::vector<GeometricObject*>* GetObjectsToRenderPtr() { return &objectsToRender; }
};

#endif