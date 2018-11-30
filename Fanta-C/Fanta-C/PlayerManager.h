#ifndef _PLAYER_MANAGER_H
#define _PLAYER_MANAGER_H

// My Headers
#include "GlobalTransform.h"
#include "MovingObject.h"

class PlayerManager : public MovingObject
{
	void PlayerInput();

public:
	// Initialization
	PlayerManager(ObjectManager* inObject, float inVelocity = 1, float inAngularVelocity = 1) : MovingObject(inObject, inVelocity, inAngularVelocity) { return; }

	// Update
	void Update() override;

	// Public Interface
	void Move(char x, char y, char z) { GlobalTransform::Translate(x * GlobalTime::deltaTime * velocity, y * GlobalTime::deltaTime * velocity, z * GlobalTime::deltaTime * velocity, *myObject->GetTransform()->GetLocalMatrix()); }
	void Pitch(char angle) { GlobalTransform::RotateOnWorldXAxis(angle * GlobalTime::deltaTime * angularVelocity, *myObject->GetTransform()->GetLocalMatrix()); }
	void Roll(char angle) { GlobalTransform::RotateOnWorldZAxis(angle * GlobalTime::deltaTime * angularVelocity, *myObject->GetTransform()->GetLocalMatrix()); }
	void Yaw(char angle) { GlobalTransform::RotateOnWorldYAxis(angle * GlobalTime::deltaTime * angularVelocity, *myObject->GetTransform()->GetLocalMatrix()); }
};

#endif