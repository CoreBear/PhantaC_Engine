#ifndef _EVENT_MANAGER_H
#define _EVENT_MANAGER_H

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class PlayerManager;
class SceneObject;
class SceneGraph;

class EventManager
{
	class ControllerManager*												controllerManagerPtr;
	static EventManager*													eventManagerInstance;
	class KeyboardManager*													keyboardManagerPtr;
	SceneGraph*																sceneGraphPtr;

	EventManager(PlayerManager* inPlayerManager, SceneGraph* inSceneGraph);
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
	void HandleCollision(uchar eventType, SceneObject* collider, SceneObject* collidee);

	// Accessor
	static EventManager* GetInstance(PlayerManager* inPlayerManager = nullptr, SceneGraph* inSceneGraph = nullptr);

	// Clean Up
	~EventManager();
};

#endif
