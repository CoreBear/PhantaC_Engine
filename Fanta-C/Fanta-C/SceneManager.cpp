#pragma region Dependencies
// My Headers
#include "SceneManager.h"		// Connection to declarations
#include "Camera.h"
#include "Circle.h"
#include "Cube.h"
#include "EnemyBase.h"
#include "Grid.h"
#include "InputController.h"
#include "ObjectTransform.h"
#include "Player.h"
#include "Pyramid.h"
#include "Quad.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Camera.h"
#include "RenderableObject.h"
#pragma endregion

#pragma region Initialization
SceneManager::SceneManager(InputController* inputController, ushort* clientDimensions)
{	
	#pragma region Add Autonomous Objects (Not visible. Remember that if they have a body, it will be in the other container)
	// Add main camera to autonomous container
	AddObjectToContainer<Agent*>(&autonomousAgents, new Agent((ObjectTransform*)new Camera(clientDimensions, XMVectorSet(0, 3, -20, 1), XMVectorSet(0, 0, 1, 0), XMVectorSet(0, 1, 0, 0)), 0, 0));
	#pragma endregion

	#pragma region Add Renderable Objects (Visible)
	AddObjectToContainer<RenderableObject*>(&visibleSceneObjects, (RenderableObject*)new Grid);
	AddObjectToContainer<RenderableObject*>(&visibleSceneObjects, (RenderableObject*)new Quad(XMVectorSet(	 -12.5f, 5, 0, 1), 1));
	AddObjectToContainer<RenderableObject*>(&visibleSceneObjects, (RenderableObject*)new Cube(XMVectorSet(	  -7.5f, 5, 0, 1), 1));
	AddObjectToContainer<RenderableObject*>(&visibleSceneObjects, (RenderableObject*)new Pyramid(XMVectorSet( -2.5f, 5, 0, 1), 1));
	AddObjectToContainer<RenderableObject*>(&visibleSceneObjects, (RenderableObject*)new Sphere(XMVectorSet(   2.5f, 5, 0, 1), 1));
	AddObjectToContainer<RenderableObject*>(&visibleSceneObjects, (RenderableObject*)new Cube(XMVectorSet(	   7.5f, 5, 0, 1), 1));
	AddObjectToContainer<RenderableObject*>(&visibleSceneObjects, (RenderableObject*)new Triangle(XMVectorSet(12.5f, 5, 0, 1), 1));
	#pragma endregion
	
	#pragma region Attach Player Pointer
	// Currently pointing at the camera, but can point at world objects, just like the enemy below
	// Assigns a worldObject to the player's pointer (different controller for camera and worldObjects, look at "player.cpp")
	playerPtr = new Player((ObjectTransform*)autonomousAgents[0]->GetPhysicalBodyPtr(), 15, 150);

	// Point the input controller at the player
	inputController->AssignPlayer(playerPtr);
	#pragma endregion

	#pragma region Attack Enemies
	// Grabs onto any renderable (visible) object
	AddObjectToContainer<Agent*>(&autonomousAgents, new EnemyBase(visibleSceneObjects[2], 5, 0));
	#pragma endregion
}
#pragma endregion

#pragma region Update
void SceneManager::Update(float deltaTime)
{
	// Agent 0 is reserved for the camera
	//static_cast<EnemyBase*>(autonomousAgents[1])->Update(deltaTime);
	
	scene.Update(deltaTime, &autonomousAgents);	// Updates the frame for the scene (Allows system to think about its movements, i.e. artificial intelligence)
	physics.Update();			// Movement and collision
	audio.Update();
}
#pragma endregion