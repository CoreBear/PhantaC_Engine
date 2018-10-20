#pragma region Dependencies
// My Headers
#include "SceneManager.h"		// Connection to declarations
#include "Camera.h"
#include "Cube.h"
#include "Grid.h"
#include "InputController.h"
#include "MoveableObject.h"
#include "Player.h"
#include "Pyramid.h"
#include "TransformObject.h"
#include "Triangle.h"
#include "Quad.h"
#pragma endregion

#pragma region Initialization
SceneManager::SceneManager(InputController* inputController)
{	
	// Make sure the grid goes in first, since it's static
	// Figure out a way to make things static another way
	
	// Add cene's main camera
	AddObjectToScene(new Camera(&XMVectorSet(0, 3, -20, 1), &XMVectorSet(0, 0, 1, 0), &XMVectorSet(0, 1, 0, 0), 0.0075f, 0.1f));
	
	// In scene objects, other than camera
	AddObjectToScene(new Grid);
	AddObjectToScene(new Quad(&XMVectorSet(	  -10, 5, 0, 1), 1));
	AddObjectToScene(new Cube(&XMVectorSet(	   -5, 5, 0, 1), 2, 0.0075f, 0.1f));
	AddObjectToScene(new Pyramid(&XMVectorSet(  0, 5, 0, 1), 3));
	AddObjectToScene(new Cube(&XMVectorSet(	    5, 5, 0, 1), 2));
	AddObjectToScene(new Triangle(&XMVectorSet(10, 5, 0, 1), 1));

	// Assigns a TransformObject to the player's pointer (currently the main camera)
	playerPtr = new Player((MoveableObject*)sceneObjects[3], &sceneObjects[3]->GetWorldMatrix());

	// Point the input controller at the player
	inputController->AssignPlayer(playerPtr);
}
#pragma endregion

#pragma region Update
void SceneManager::Update()
{
	/*for (iterators[0] = 0; iterators[0] < sceneObjects.size(); ++iterators[0])
		sceneObjects[iterators[0]]->Update();*/
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