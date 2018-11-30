#ifndef _SCRIPT_MANAGER_H
#define _SCRIPT_MANAGER_H

// My Headers
#include "GlobalTime.h"
#include "ObjectManager.h"

class ScriptManager
{
protected:
	ObjectManager* myObject;

public:
	// Initialization
	ScriptManager(ObjectManager* inObject) { myObject = inObject; }

	// Update
	virtual void Update() = 0;
	
	// Just a hack to test functionality. Remove
	virtual void AssignTarget(XMVECTOR* inTargetPosition) { return; }

	// Accessors
	ObjectManager* GetMyObject() { return myObject; }
};

#endif