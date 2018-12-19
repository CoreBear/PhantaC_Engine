#ifndef _AGENT_MANAGER_H
#define _AGENT_MANAGER_H

// My Headers
#include "GlobalDirectX.h"
#include "MovingObject.h"
#include "SceneObject.h"

class AgentManager : public MovingObject
{
	// Variables
	XMVECTOR*		targetPosition;

protected:
	// Protected Functionality
	void CollisionEnter() override { myObject->GetMesh()->ChangeColor(Colors::Red); }
	void CollisionExit() override { myObject->GetMesh()->ChangeColor(Colors::Green); }
	void CollisionContinue() override { myObject->GetMesh()->ChangeColor(Colors::Red); }

public:
	// Initialization
	AgentManager(SceneGraph* inSceneGraph, SceneObject* inObject, float inPitchVelocity = 1, float inRollVelocity = 1, float inVelocity = 1, float inYawVelocity = 1) : MovingObject(inSceneGraph, inObject, inPitchVelocity, inRollVelocity, inVelocity, inYawVelocity) { return; }

	// Update - Runs object logic update
	void Update() override;

	// Hack
	void AssignTarget(XMVECTOR* inTargetPosition) { targetPosition = inTargetPosition; }

	// Accessors
	SceneObject* GetMyObject() { return myObject; }
};

#endif