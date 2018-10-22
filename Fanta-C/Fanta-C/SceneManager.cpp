#pragma region Dependencies
// My Headers
#include "SceneManager.h"		// Connection to declarations
#include "Camera.h"
#include "Circle.h"
#include "Cube.h"
#include "EnemyBase.h"
#include "GlobalTools.h"
#include "Grid.h"
#include "InputManager.h"
#include "ObjectTransform.h"
#include "Player.h"
#include "Pyramid.h"
#include "Quad.h"
#include "RenderableObject.h"
#include "Sphere.h"
#include "Triangle.h"
#pragma endregion

#pragma region Initialization
SceneManager::SceneManager(InputManager* inputManager, ushort* clientDimensions)
{	
	#pragma region Create Camera
	cameraPtr = new Camera(clientDimensions, XMVectorSet(0, 3, -20, 1), XMVectorSet(0, 0, 1, 0), XMVectorSet(0, 1, 0, 0));
	#pragma endregion

	#pragma region Add Renderable Objects (Visible)
	AddObjectToContainer<RenderableObject*>(&visibleSceneObjects, (RenderableObject*)new Grid);
	AddObjectToContainer<RenderableObject*>(&visibleSceneObjects, (RenderableObject*)new Quad(XMVectorSet(   -12.5f, 5, 0, 1), 1));
	AddObjectToContainer<RenderableObject*>(&visibleSceneObjects, (RenderableObject*)new Cube(XMVectorSet(	  -7.5f, 5, 0, 1), 1));
	AddObjectToContainer<RenderableObject*>(&visibleSceneObjects, (RenderableObject*)new Pyramid(XMVectorSet( -2.5f, 5, 0, 1), 1));
	AddObjectToContainer<RenderableObject*>(&visibleSceneObjects, (RenderableObject*)new Circle(XMVectorSet(   2.5f, 5, 0, 1), 1));
	AddObjectToContainer<RenderableObject*>(&visibleSceneObjects, (RenderableObject*)new Sphere(XMVectorSet(   7.5f, 5, 0, 1), 1));
	AddObjectToContainer<RenderableObject*>(&visibleSceneObjects, (RenderableObject*)new Triangle(XMVectorSet(12.5f, 5, 0, 1), 1));
	#pragma endregion
	
	#pragma region Create Player (Right now, a new camera is attached, but it can be any object, exactly like the enemies below)
	// Adds main camera to the scene and points player to it
	playerPtr = new Player((ObjectTransform*)cameraPtr, 15, 150);

	// Let the input controller know that there is a player
	inputManager->AssignPlayer(playerPtr);
	#pragma endregion

	#pragma region Create new enemies and point at physical/renderable bodies
	// Grabs onto any renderable (visible) object
	AddObjectToContainer<AutonomousAgent*>(&agents, new EnemyBase(visibleSceneObjects[1], 1, 0));
	AddObjectToContainer<AutonomousAgent*>(&agents, new EnemyBase(visibleSceneObjects[2], 0, 0));
	AddObjectToContainer<AutonomousAgent*>(&agents, new EnemyBase(visibleSceneObjects[3], 0, 0));
	AddObjectToContainer<AutonomousAgent*>(&agents, new EnemyBase(visibleSceneObjects[4], 0, 0));
	#pragma endregion
}
#pragma endregion

#pragma region Update
void SceneManager::Update(float deltaTime)
{	
	scene.Update(&agents);					// Updates the frame for the scene (Allows system to Plan about its movements, i.e. artificial intelligence)
	physicsMain.Update(deltaTime, &agents); // Movement and collision
	audio.Update();
}
#pragma endregion