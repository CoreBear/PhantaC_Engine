#ifndef _PLAYER_MANAGER_H
#define _PLAYER_MANAGER_H

// My Headers
#include "Camera.h"
#include "GlobalTransform.h"
#include "MovingObject.h"
#include "ObjectManager.h"
#include "SceneGraph.h"
#include "SceneObject.h"

class PlayerManager : public MovingObject
{
	// Variables
	Camera*			camera;
	ObjectManager*	bulletTrail;		// Hacked together. Remove
	SceneGraph*		sceneGraphPtr;		// Look into creating a function pointer for this


public:
	// Initialization
	PlayerManager(Camera* inCamera, SceneGraph* sceneGraph, float inVelocity = 1, float inAngularVelocity = 1) : camera(inCamera), sceneGraphPtr(sceneGraph), MovingObject(inVelocity, inAngularVelocity) { return; }

	// Public Interface
	void Move(char x, char y, char z) {	GlobalTransform::Translate(x * GlobalTime::deltaTime * velocity, y * GlobalTime::deltaTime * velocity, z * GlobalTime::deltaTime * velocity, *camera->GetViewMatrix()); }
	void Pitch(char angle) { GlobalTransform::RotateOnXAxis(angle * GlobalTime::deltaTime * angularVelocity, *camera->GetViewMatrix()); }
	void Shoot();
	void Roll(char angle) { GlobalTransform::RotateOnZAxis(angle * GlobalTime::deltaTime * angularVelocity, *camera->GetViewMatrix()); }
	void Yaw(char angle) { GlobalTransform::RotateOnWorldYAxis(angle * GlobalTime::deltaTime * angularVelocity, *camera->GetViewMatrix()); }
};

#endif