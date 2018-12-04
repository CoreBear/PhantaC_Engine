#ifndef _PLAYER_MANAGER_H
#define _PLAYER_MANAGER_H

// My Headers
#include "Camera.h"
#include "GlobalTransform.h"
#include "MovingObject.h"
#include "ObjectManager.h"
#include "SceneObject.h"

class PlayerManager : public MovingObject
{
	Camera* camera;

	void PlayerInput();

public:
	// Initialization
	PlayerManager(Camera* inCamera, float inVelocity = 1, float inAngularVelocity = 1) : camera(inCamera), MovingObject(inVelocity, inAngularVelocity) { return; }

	// Update
	void Update() override;

	// Public Interface
	void Move(char x, char y, char z) { GlobalTransform::Translate(x * GlobalTime::deltaTime * velocity, y * GlobalTime::deltaTime * velocity, z * GlobalTime::deltaTime * velocity, *camera->GetViewMatrix()); }
	void Pitch(char angle) { GlobalTransform::RotateOnWorldXAxis(angle * GlobalTime::deltaTime * angularVelocity, *camera->GetViewMatrix()); }
	void Roll(char angle) { GlobalTransform::RotateOnWorldZAxis(angle * GlobalTime::deltaTime * angularVelocity, *camera->GetViewMatrix()); }
	void Yaw(char angle) { GlobalTransform::RotateOnWorldYAxis(angle * GlobalTime::deltaTime * angularVelocity, *camera->GetViewMatrix()); }
};

#endif