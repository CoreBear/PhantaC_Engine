#pragma region Dependencies
// My Headers
#include "EventManager.h"		// Connection to declarations

#include "ControllerManager.h"
#include "GlobalEventVariables.h"
#include "KeyboardManager.h"
#include "PlayerManager.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Forward Declarations
EventManager* EventManager::eventManagerInstance = nullptr;
#pragma endregion

#pragma region Initialization
EventManager::EventManager(PlayerManager* inPlayerManager)
{
	controllerManagerPtr = ControllerManager::GetInstance(inPlayerManager);
	keyboardManagerPtr = KeyboardManager::GetInstance(inPlayerManager);
}
#pragma endregion

#pragma region Public Interface
void EventManager::HandleEvent(uchar eventType, SceneObject* collider, SceneObject* collidee)
{
	switch (eventType)
	{
	case GlobalEventVariables::EVENT::CONTINUED_COLLISION:
		ContinuedCollision(collider, collidee);
		break;
	case GlobalEventVariables::EVENT::NEW_COLLISION:
		NewCollision(collider, collidee);
		break;
	case GlobalEventVariables::EVENT::NEW_SEPARATION:
		NewSeparation(collider, collidee);
		break;
	}
}
#pragma endregion

#pragma region Update
void EventManager::Update()
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

#pragma region Private
void EventManager::ContinuedCollision(SceneObject* collider, SceneObject* collidee)
{

}
void EventManager::NewCollision(SceneObject* collider, SceneObject* collidee)
{
	// Change collider's color
	collider->GetMesh()->ChangeColor(Colors::Red);
}
void EventManager::NewSeparation(SceneObject* collider, SceneObject* collidee)
{
	// Change collider's color
	collider->GetMesh()->ChangeColor(Colors::Green);
}
#pragma endregion

#pragma region Accessors
EventManager* EventManager::GetInstance(PlayerManager* inPlayerManager)
{
	// If instance is already created, return it
	if (eventManagerInstance) return eventManagerInstance;

	// If instance has not been created, create it and return it
	else
	{
		eventManagerInstance = new EventManager(inPlayerManager);
		return eventManagerInstance;
	}
}
#pragma endregion

#pragma region Clean Up
EventManager::~EventManager()
{
	if (controllerManagerPtr) delete controllerManagerPtr;
	if (keyboardManagerPtr) delete keyboardManagerPtr;
}
#pragma endregion
