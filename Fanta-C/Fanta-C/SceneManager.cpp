#pragma region Dependencies
// My Headers
#include "SceneManager.h"		// Connection to declarations
#include "Agent.h"
#include "Camera.h"
#include "Circle.h"
#include "Cube.h"
#include "EnemyBase.h"
#include "FreeCamera.h"
#include "GlobalContainers.h"
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
	#pragma region Camera Setup
	// Create camera
	cameraPtr = new Camera(clientDimensions, XMVectorSet(0, 3, -20, 1), XMVectorSet(0, 0, 1, 0), XMVectorSet(0, 1, 0, 0));

	// Wrap camera in an agent and place it into the agent's container
	AddObjectToContainer<Agent*>(&autonomousAgents, new Agent(cameraPtr, false, false));			// Use for player control
	//AddObjectToContainer<Agent*>(&autonomousAgents, new FreeCamera(cameraPtr, false, false));		// Use for autonomous control
	#pragma endregion

	#pragma region Add Any Object in the Scene
	// Create scene objects (Agents are static. Everything else is autonomous)
	AddObjectToContainer<Agent*>(&staticAgents, new Agent(new Grid, false, true, 0, 0));
	AddObjectToContainer<Agent*>(&autonomousAgents, new EnemyBase(new Quad(XMVectorSet(	  -12.5f, 5, 0, 1), 1), false, true, 0.25f, 0));
	AddObjectToContainer<Agent*>(&autonomousAgents, new EnemyBase(new Cube(XMVectorSet(	   -7.5f, 5, 0, 1), 1), false, true, 0.25f, 0));
	AddObjectToContainer<Agent*>(&autonomousAgents, new EnemyBase(new Pyramid(XMVectorSet( -2.5f, 5, 0, 1), 1), false, true, 0.25f, 0));
	AddObjectToContainer<Agent*>(&autonomousAgents, new EnemyBase(new Circle(XMVectorSet(   2.5f, 5, 0, 1), 1), false, true, 0.25f, 0));
	AddObjectToContainer<Agent*>(&autonomousAgents, new EnemyBase(new Sphere(XMVectorSet(	7.5f, 5, 0, 1), 1), false, true, 0.25f, 0));
	AddObjectToContainer<Agent*>(&autonomousAgents, new EnemyBase(new Triangle(XMVectorSet(12.5f, 5, 0, 1), 1), false, true, 0.25f, 0));
	#pragma endregion
	
	#pragma region Create Player (Right now, a new camera is attached, but it can be any object, exactly like the enemies below)
	// Creates player wrapper around whatever object we choose
	playerPtr = new Player((ObjectTransform*)cameraPtr, false, false, 15, 150);

	// Let the input controller know what the player is
	inputManager->AssignPlayer(playerPtr);
	#pragma endregion
}
#pragma endregion

#pragma region Update
void SceneManager::Update(float deltaTime)
{	
	scene.Update(&autonomousAgents);									// Updates the frame for the scene (Allows system to Plan its movements, i.e. artificial intelligence)
	physicsMain.Update(deltaTime, &autonomousAgents, &staticAgents);	// Movement and collision
	audio.Update();
}
#pragma endregion