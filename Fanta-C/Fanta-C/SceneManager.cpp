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
	cameraPtr = new Camera(&XMVectorSet(0, 2, -20, 1), &XMVectorSet(0, 0, 1, 0), &XMVectorSet(0, 1, 0, 0), 0.0075f, 0.2f);
	inputController->AssignPlayer(GetCameraPtr());

	// Make sure the grid goes in first, since it's static
	// Figure out a way to make things static another way
	AddObjectToScene(new Grid);
	AddObjectToScene(new Cube(&XMVectorSet(		  -5, 5, 0, 1), 1));
	AddObjectToScene(new Cube(&XMVectorSet(		   5, 5, 0, 1), &XMVectorSet(0, 0, 1, 0), &XMVectorSet(0, 1, 0, 0), 1));
	//AddObjectToScene(new Pyramid(&XMVectorSet(  -5, 5, 0, 1), 1));
	//AddObjectToScene(new Triangle(&XMVectorSet(-10, 5, 0, 1), 1));
	//AddObjectToScene(new Quad(&XMVectorSet(     10, 5, 0, 1), 1));
}
#pragma endregion

#pragma region Update
void SceneManager::UpdateScene()
{
	// Skip the first place, because the grid is static
	for (iterators[0] = 1; iterators[0] < objectsToRender.size(); ++iterators[0])
	{
		objectsToRender[iterators[0]]->Update();
	}
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