#pragma region Dependencies
// My Headers
#include "SceneManager.h"		// Connection to declarations
#include "Agent.h"
#include "Audio.h"
#include "Camera.h"
#include "Circle.h"
#include "Cube.h"
#include "EnemyBase.h"
#include "FreeCamera.h"
#include "GlobalApplication.h"
#include "GlobalContainers.h"
#include "Grid.h"
#include "InputManager.h"
#include "Logic.h"
#include "ObjectTransform.h"
#include "Player.h"
#include "Pyramid.h"
#include "PhysicsMain.h"
#include "Quad.h"
#include "RenderableObject.h"
#include "Sphere.h"
#include "Triangle.h"
#pragma endregion

#pragma region Initialization
SceneManager::SceneManager(InputManager* inputManager, ushort* clientDimensions, HWND* windowHandle, uchar targetFPS)
{	
	#pragma region Camera Setup
	// Create camera
	cameraPtr = new Camera(clientDimensions, XMVectorSet(0, 3, -20, 1), XMVectorSet(0, 0, 1, 0), XMVectorSet(0, 1, 0, 0));

	// Wrap camera in an agent and place it into the agent's container
	AddObjectToContainer<Agent*>(&autonomousAgents, new Agent(cameraPtr, false, false));			// Use for player control
	//AddObjectToContainer<Agent*>(&autonomousAgents, new FreeCamera(cameraPtr, false, false));		// Use for autonomous control
	#pragma endregion
	
	#pragma region Modules
	// Load the audio module
	audio = new Audio;

	// Load the scene module
	logic = new Logic;

	// Load the physics module
	physicsMain = new PhysicsMain;

	// Load the render module
	renderer = new Renderer(*windowHandle, this, clientDimensions, targetFPS, cameraPtr);
	#pragma endregion

	#pragma region Add Any Object in the Scene
	// Create scene objects (Agents are static. Everything else is autonomous)
	CreateObjectAndStore(new Agent(new Grid, false, true, 0, 0), false, true);
	//CreateObjectAndStore(new EnemyBase(new Quad(XMVectorSet(-12.5f, 5, 0, 1), 1), false, true, 0.25f, 0), true, true);
	//CreateObjectAndStore(new EnemyBase(new Cube(XMVectorSet(-7.5f, 5, 0, 1), 1), false, true, 0.25f, 0), true, true);
	//CreateObjectAndStore(new EnemyBase(new Pyramid(XMVectorSet(-2.5f, 5, 0, 1), 1), false, true, 0.25f, 0), true, true);
	//CreateObjectAndStore(new EnemyBase(new Circle(XMVectorSet(2.5f, 5, 0, 1), 1), false, true, 0.25f, 0), true, true);
	//CreateObjectAndStore(new EnemyBase(new Sphere(XMVectorSet(7.5f, 5, 0, 1), 1), false, true, 0.25f, 0), true, true);
	//CreateObjectAndStore(new EnemyBase(new Triangle(XMVectorSet(12.5f, 5, 0, 1), 1), false, true, 0.25f, 0), true, true);
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
	audio->Update();													// Game audio
	logic->Update(&autonomousAgents);									// Updates the frame for the scene (Allows system to Plan its movements, i.e. artificial intelligence)
	physicsMain->Update(deltaTime, &autonomousAgents, &staticAgents);	// Movement and collision
	renderer->Update(&renderableAgents, cameraPtr);						// Renders scene
}
#pragma endregion

#pragma region Private
void SceneManager::CreateObjectAndStore(Agent* object, bool autonomous, bool renderable)
{
	// Send to moving or non-moving containers
	if (autonomous)
		AddObjectToContainer<Agent*>(&autonomousAgents, object);
	else
		AddObjectToContainer<Agent*>(&staticAgents, object);

	// Send to renderable container
	if (renderable) 
		AddObjectToContainer<Agent*>(&renderableAgents, object);
}
#pragma endregion

#pragma region Clean Up
SceneManager::~SceneManager()
{
	delete	audio;
	delete	cameraPtr;
	delete	logic;
	delete	physicsMain;
	delete	playerPtr;
	delete	renderer;

	size_t containerSize = autonomousAgents.size();

	for (iterators[0] = 0; iterators[0] < containerSize; ++iterators[0])
	{
		if (autonomousAgents.at(iterators[0]))
		{
			delete autonomousAgents.at(iterators[0]);
			autonomousAgents.at(iterators[0]) = nullptr;
		}
	}
	
	containerSize = renderableAgents.size();

	for (iterators[0] = 0; iterators[0] < containerSize; ++iterators[0])
	{
		if (renderableAgents.at(iterators[0]))
		{
			delete renderableAgents.at(iterators[0]);
			renderableAgents.at(iterators[0]) = nullptr;
		}
	}

	//containerSize = staticAgents.size();
	//
	//for (iterators[0] = 0; iterators[0] < containerSize; ++iterators[0])
	//{
	//	if (staticAgents.at(iterators[0]))
	//	{
	//		delete staticAgents.at(iterators[0]);
	//		staticAgents.at(iterators[0]) = nullptr;
	//	}
	//}
}
#pragma endregion