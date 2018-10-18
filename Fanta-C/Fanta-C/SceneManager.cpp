#pragma region Dependencies
#include "SceneManager.h"

#include "Camera.h"
#include "Cube.h"
#include "GeometricObject.h"
#include "Grid.h"
#include "InputController.h"
#pragma endregion

#pragma region Initialization
SceneManager::SceneManager(InputController* inputController)
{
	cameraPtr = new Camera;
	inputController->AssignCamera(cameraPtr);
	AddObjectToScene(new Cube(-5, 0,  5));				
	AddObjectToScene(new Cube( 5, 0,  5));
	AddObjectToScene(new Cube(-5, 0, -5));
	AddObjectToScene(new Cube( 5, 0, -5));
	AddObjectToScene(new Grid);
}
#pragma endregion

#pragma region Scene Modifiers
void SceneManager::AddObjectToScene(GeometricObject* object)
{
	objectsToRender.push_back(object);
}
void SceneManager::RemoveObjectFromScene(GeometricObject* object)
{
	objectsToRender.erase(std::remove(objectsToRender.begin(), objectsToRender.end(), object), objectsToRender.end());
}
#pragma endregion