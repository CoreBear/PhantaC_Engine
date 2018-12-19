#ifndef _NON_PLAYER_MANAGER_H
#define _NON_PLAYER_MANAGER_H

// My Headers
#include "SceneObject.h"
#include "ScriptManager.h"

class NonPlayerManager : public ScriptManager
{
protected:
	SceneObject* myObject;

public:
	// Initialization
	NonPlayerManager(SceneObject* inObject) : myObject(inObject) { return; }

	// Update
	virtual void Update() { return; }

	// Accessors
	SceneObject* GetMyObject() { return myObject; }
};

#endif