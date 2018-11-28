#ifndef _PLAYER_MANAGER_H
#define _PLAYER_MANAGER_H

// My Headers
#include "GlobalTransform.h"
#include "MovingObject.h"

class PlayerManager : public MovingObject
{
	// Use these speeds in the constructor

	// Release
	//velocity = 0.005;
	//rotateSpeed = 0.03;	

	// Debug
	//velocity = 0.5f;		
	//rotateSpeed = 3;		

	void PlayerInput();

public:
	// Initialization
	PlayerManager(ObjectManager* inObject) : MovingObject(inObject, 20, 100) { return; }

	// Update
	void Update() override;

	// Public Interface
	void Move(char x, char y, char z) { GlobalTransform::Translate(x * GlobalTime::deltaTime * velocity, y * GlobalTime::deltaTime * velocity, z * GlobalTime::deltaTime * velocity, myObject->GetTransform()->GetWorldMatrix()); }
	void Pitch(char angle) { GlobalTransform::RotateOnXAxis(angle * GlobalTime::deltaTime * angularVelocity, myObject->GetTransform()->GetWorldMatrix()); }
	void Roll(char angle) { GlobalTransform::RotateOnZAxis(angle * GlobalTime::deltaTime * angularVelocity, myObject->GetTransform()->GetWorldMatrix()); }
	void Yaw(char angle) { GlobalTransform::RotateOnYAxis(angle * GlobalTime::deltaTime * angularVelocity, myObject->GetTransform()->GetWorldMatrix()); }
};

#endif