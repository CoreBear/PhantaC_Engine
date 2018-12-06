#ifndef _SCRIPT_MANAGER_H
#define _SCRIPT_MANAGER_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalTime.h"
#include "SceneObject.h"

class ScriptManager
{
public:
	// Update
	virtual void Update() { return; }

	// Just a hack to test functionality. Remove
	virtual void AssignTarget(XMVECTOR* inTargetPosition) { return; }
};

#endif