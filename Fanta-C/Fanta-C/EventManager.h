#ifndef _EVENT_MANAGER_H
#define _EVENT_MANAGER_H

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class PlayerManager;
class SceneObject;

class EventManager
{
	class ControllerManager*	controllerManagerPtr;
	static EventManager*		eventManagerInstance;
	class KeyboardManager*		keyboardManagerPtr;

	EventManager(PlayerManager* inPlayerManager);
	EventManager(EventManager const&) = delete;
	EventManager operator=(EventManager const&) = delete;

	// Collision
	void ContinuedCollision(SceneObject* collider, SceneObject* collidee);
	void NewCollision(SceneObject* collider, SceneObject* collidee);
	void NewSeparation(SceneObject* collider, SceneObject* collidee);

public:
	// Update
	void Update();

	// Public Interface
	void HandleEvent(uchar eventType, SceneObject* collider = nullptr, SceneObject* collidee = nullptr);

	// Accessor
	static EventManager* GetInstance(PlayerManager* inPlayerManager = nullptr);

	// Clean Up
	~EventManager();
};

#endif
