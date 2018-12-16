#pragma region Dependencies
// My Headers
#include "InputManager.h"		// Connection to declarations

#include "ControllerManager.h"
#include "KeyboardManager.h"
#include "PlayerManager.h"
#include "SceneGraph.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Forward Declarations
InputManager* InputManager::inputManagerInstance = nullptr;
#pragma endregion

#pragma region Initialization
InputManager::InputManager(PlayerManager* inPlayerManager, SceneGraph* inSceneGraph) : sceneGraphPtr(inSceneGraph)
{
	controllerManagerPtr = ControllerManager::GetInstance(inPlayerManager);
	keyboardManagerPtr = KeyboardManager::GetInstance(inPlayerManager);
}
InputManager* InputManager::GetInstance(PlayerManager* inPlayerManager, SceneGraph* inSceneGraph)
{
	// If instance is already created, return it
	if (inputManagerInstance) return inputManagerInstance;

	// If instance has not been created, create it and return it
	else
	{
		inputManagerInstance = new InputManager(inPlayerManager, inSceneGraph);
		return inputManagerInstance;
	}
}
#pragma endregion

#pragma region Update
void InputManager::Update()
{
	// If a controller is plugged in, run it
	if (controllerManagerPtr->CheckControllerStatus())
	{

	}

	// If no controller
	else
		keyboardManagerPtr->Update();
}
#pragma endregion

#pragma region Clean Up
InputManager::~InputManager()
{
	if (controllerManagerPtr) delete controllerManagerPtr;
	if (keyboardManagerPtr) delete keyboardManagerPtr;
}
#pragma endregion
