#ifndef _AGENT_MANAGER_H
#define _AGENT_MANAGER_H

// My Headers
#include "GlobalDirectX.h"
#include "MovingObject.h"
#include "SceneObject.h"

class AgentManager : public MovingObject
{
	SceneObject*	myObject;
	XMVECTOR*		targetPosition;

public:
	// Initialization
	AgentManager(SceneObject* inObject, float inVelocity = 1, float inAngularVelocity = 1) : myObject(inObject), MovingObject(inVelocity, inAngularVelocity) { return; }

	// Update
	void Update() override;

	void AssignTarget(XMVECTOR* inTargetPosition) { targetPosition = inTargetPosition; }

	// Accessors
	SceneObject* GetMyObject() { return myObject; }
};

#endif