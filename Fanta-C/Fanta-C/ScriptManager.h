#ifndef _SCRIPT_MANAGER_H
#define _SCRIPT_MANAGER_H

// System Headers
#include <unordered_map>

// My Headers
#include "SceneGraph.h"
#include "SceneObject.h"

	// Abstract Base Class
class ScriptManager
{
public:
	// Update - Runs entire object update
	virtual void Update() = 0;

	// Collision Interface
	virtual void ContinuedCollision(std::unordered_map<ushort, SceneObject*>* inCollidingObjects) { return; }
	virtual void NewCollision(SceneObject* inCollidingObject) { return; }
	virtual void NewSeparation() { return; }
};

#endif