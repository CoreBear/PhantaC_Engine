#pragma region Dependencies
// My Headers
#include "SceneManager.h"		// Connection to declarations
#include "Camera.h"
#include "Circle.h"
#include "Cube.h"
#include "Grid.h"
#include "InputController.h"
#include "ObjectTransform.h"
#include "Player.h"
#include "Pyramid.h"
#include "Quad.h"
#include "Sphere.h"
#include "Triangle.h"
#include "WorldObject.h"
#pragma endregion

#pragma region Initialization
SceneManager::SceneManager(InputController* inputController, ushort* clientDimensions)
{	
	// Make sure the grid goes in first, since it's static
	// Figure out a way to make things static another way
	
	// Add cene's main camera
	AddObjectToScene(new Camera(clientDimensions, &XMVectorSet(0, 3, -20, 1), &XMVectorSet(0, 0, 1, 0), &XMVectorSet(0, 1, 0, 0), 10, 100));// 0.0075f, 0.1f));
	
	// In scene objects, other than camera
	// Additional arguements are for move and rotation speed
	// Objects pointed to will not move if there is no move or rotation speed
	AddObjectToScene(new Grid);
	AddObjectToScene(new Sphere(&XMVectorSet(0, 5, 0, 1)));

	// For showing off
	/*AddObjectToScene(new Quad(&XMVectorSet(	  -10, 5, 0, 1), 1));
	AddObjectToScene(new Cube(&XMVectorSet(	   -5, 5, 0, 1), 1));
	AddObjectToScene(new Pyramid(&XMVectorSet(  0, 5, 0, 1), 1));
	AddObjectToScene(new Cube(&XMVectorSet(	    5, 5, 0, 1), 1));
	AddObjectToScene(new Triangle(&XMVectorSet(10, 5, 0, 1), 1));*/
	 
	// Assigns a WorldObject to the player's pointer (different controller for camera "player.cpp")
	playerPtr = new Player((ObjectTransform*)sceneObjects[0], &sceneObjects[0]->GetWorldMatrix());

	// Point the input controller at the player
	inputController->AssignPlayer(playerPtr);
}
#pragma endregion

#pragma region Update
void SceneManager::Update()
{
	scene.Update();				// Updates the frame for the scene (i.e. artificial intelligence)
	physics.Update();			// Movement and collision
	audio.Update();
}
#pragma endregion

#pragma region Private
void SceneManager::AddObjectToScene(WorldObject* object)
{
	sceneObjects.push_back(object);
}
void SceneManager::RemoveObjectFromScene(WorldObject* object)
{
	sceneObjects.erase(std::remove(sceneObjects.begin(), sceneObjects.end(), object), sceneObjects.end());
}
#pragma endregion