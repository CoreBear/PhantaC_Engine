#pragma region Dependencies
#include "SceneManager.h"

#include "Camera.h"
#include "Cube.h"
#include "GeometricObject.h"
#include "Grid.h"
#include "InputController.h"
#include "Pyramid.h"
#include "Triangle.h"
#include "Quad.h"
#pragma endregion

#pragma region Initialization
SceneManager::SceneManager(InputController* inputController)
{
	cameraPtr = new Camera(XMVectorSet(0, 10, -15, 1), XMVectorSet(0, 0, 1, 1), XMVectorSet(0, 1, 0, 1), 0.0075f, 0.2f);
	inputController->AssignCamera(cameraPtr);
	AddObjectToScene(new Cube(	  -10, -1,  10, 1));		// Fix up direction, because the "-1" is up...
	AddObjectToScene(new Cube(	   10, -2,  10, 2));
	AddObjectToScene(new Cube(	  -10, -3, -10, 3));
	AddObjectToScene(new Cube(	   10, -4, -10, 4));
	AddObjectToScene(new Pyramid(	0, -5,   0, 4));
	AddObjectToScene(new Triangle(-10, -5,   0, 2));
	AddObjectToScene(new Quad(	   10, -5,   0, 3));
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