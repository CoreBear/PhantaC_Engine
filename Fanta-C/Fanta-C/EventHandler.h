#ifndef _EVENT_HANDLER_H
#define _EVENT_HANDLER_H

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class SceneObject;

class EventHandler
{
	static void ContinuedCollision(SceneObject* collider, SceneObject* collidee);
	static void NewCollision(SceneObject* collider, SceneObject* collidee);
	static void NewSeparation(SceneObject* collider, SceneObject* collidee);

public:
	// Public Interface
	static void HandleEvent(uchar eventType, SceneObject* collider = nullptr, SceneObject* collidee = nullptr);
};

#endif
