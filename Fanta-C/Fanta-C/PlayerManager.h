#ifndef _PLAYER_MANAGER_H
#define _PLAYER_MANAGER_H

// My Headers
#include "GlobalTransform.h"
#include "ScriptManager.h"

class PlayerManager : public ScriptManager
{
	// Release
	//float moveSpeed = 0.005;	// Abstract out...temp
	//float rotateSpeed = 0.03;	// Abstract out...temp

	// Debug
	float moveSpeed = 0.5f;		// Abstract out...temp
	float rotateSpeed = 3;		// Abstract out...temp

	void PlayerInput();

public:
	// Initialization
	PlayerManager(ObjectManager* inObject) : ScriptManager(inObject) { return; }

	// Update
	void Update() override;

	// Public Interface
	void Move(char x, char y, char z) { GlobalTransform::Translate(x * GlobalTime::deltaTime * moveSpeed, y * GlobalTime::deltaTime * moveSpeed, z * GlobalTime::deltaTime * moveSpeed, myObject->GetTransform()->GetWorldMatrix()); }
	void Pitch(char angle) { GlobalTransform::RotateOnXAxis(angle * GlobalTime::deltaTime * rotateSpeed, myObject->GetTransform()->GetWorldMatrix()); }
	void Roll(char angle) { GlobalTransform::RotateOnZAxis(angle * GlobalTime::deltaTime * rotateSpeed, myObject->GetTransform()->GetWorldMatrix()); }
	void Yaw(char angle) { GlobalTransform::RotateOnYAxis(angle * GlobalTime::deltaTime * rotateSpeed, myObject->GetTransform()->GetWorldMatrix()); }
};

#endif