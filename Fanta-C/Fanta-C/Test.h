#pragma once
#include "MovingObject.h"
#include "GlobalDirectX.h"
#include "SceneObject.h"

class Test : public MovingObject
{
	SceneObject*	myObject;
	XMVECTOR*		targetPosition;

public:
	// Initialization
	Test(SceneObject* inObject, float inVelocity = 1, float inAngularVelocity = 1) : myObject(inObject), MovingObject(inVelocity, inAngularVelocity) { return; }

	// Update
	void Update() override;

	void AssignTarget(XMVECTOR* inTargetPosition) override { targetPosition = inTargetPosition; }

	// Accessors
	SceneObject* GetMyObject() { return myObject; }
};