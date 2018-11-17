#ifndef _PLAYER_MANAGER_H
#define _PLAYER_MANAGER_H

// My Headers
#include "ScriptManager.h"

class PlayerManager : public ScriptManager
{
	char moveSpeed = 15;		// Abstract out...temp
	uchar rotateSpeed = 175;	// Abstract out...temp
	float myDeltaTime;			// Temporary patch

public:
	// Initialization
	PlayerManager(ObjectManager* inObject) : ScriptManager(inObject) { return; }

	// Update
	void Update(float delteTime) override { myDeltaTime = delteTime; }

	// Public Interface
	void Move(char x, char y, char z) { myObject->GetTransform()->Translate(x * myDeltaTime * moveSpeed, y * myDeltaTime * moveSpeed, z * myDeltaTime * moveSpeed); }
	void Pitch(char angle) { myObject->GetTransform()->RotateOnXAxis(angle * myDeltaTime * rotateSpeed); }
	void Roll(char angle) { myObject->GetTransform()->RotateOnZAxis(angle * myDeltaTime * rotateSpeed); }
	void Yaw(char angle) { myObject->GetTransform()->RotateOnYAxis(angle * myDeltaTime * rotateSpeed); }
};

#endif