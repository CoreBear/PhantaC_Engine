#pragma region Dependencies
// My Headers
#include "SceneManager.h"		// Connection to declarations
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
	// Make sure the grid goes in first, since it's static
	// Figure out a way to make things static another way
	
	// Add cene's main camera
	AddObjectToScene(new Camera(&XMVectorSet(0, 3, -20, 1), &XMVectorSet(0, 0, 1, 0), &XMVectorSet(0, 1, 0, 0), 0.0075f, 0.2f));
	
	// In scene objects, other than camera
	AddObjectToScene(new Grid);
	AddObjectToScene(new Cube(&XMVectorSet(		  -5, 5, 0, 1), 1));
	//AddObjectToScene(new Cube(&XMVectorSet(		   5, 5, 0, 1), &XMVectorSet(0, 0, 1, 0), &XMVectorSet(0, 1, 0, 0), 1));
	//AddObjectToScene(new Pyramid(&XMVectorSet(  -5, 5, 0, 1), 1));
	//AddObjectToScene(new Triangle(&XMVectorSet(-10, 5, 0, 1), 1));
	//AddObjectToScene(new Quad(&XMVectorSet(     10, 5, 0, 1), 1));

	// Assigns a TransformObject to the player's pointer (currently the main camera)
	playerPtr = new Player(sceneObjects[0]);
}
#pragma endregion

#pragma region Update
void SceneManager::Update()
{
	// Skip the first place, because the grid is static
	for (iterators[0] = 1; iterators[0] < sceneObjects.size(); ++iterators[0])
		sceneObjects[iterators[0]]->Update();
}
#pragma endregion

#pragma region Black Box
void SceneManager::AddObjectToScene(TransformObject* object)
{
	sceneObjects.push_back(object);
}
void SceneManager::RemoveObjectFromScene(TransformObject* object)
{
	sceneObjects.erase(std::remove(sceneObjects.begin(), sceneObjects.end(), object), sceneObjects.end());
}
#pragma endregion