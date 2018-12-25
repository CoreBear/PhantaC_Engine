#ifndef _PLAYER_MANAGER_H
#define _PLAYER_MANAGER_H

// My Headers
#include "GlobalTypedefs.h"
#include "MovingObject.h"

// Forward Declarations
class Camera;
class SceneGraph;
class SceneObject;

class PlayerManager : public MovingObject
{
	// Variables
	Camera*					cameraPtr;
	static PlayerManager*	playerManagerInstance;
	SceneObject*			hitObject;

	// Hacked together shooting mechanic. Will remove
	const uchar trailDistance = 50;

	// Initialization
	PlayerManager(Camera* inCamera, SceneObject* inSceneObject, float inPitchVelocity, float inRollVelocity, float inVelocity, float inYawVelocity) : cameraPtr(inCamera), MovingObject(inSceneObject, inPitchVelocity, inRollVelocity, inVelocity, inYawVelocity) { return; }
	PlayerManager(PlayerManager const&) = delete;
	PlayerManager operator=(PlayerManager const&) = delete;

public:
	// Public Interface
	void Move(char x, char y, char z);
	void Pitch(char angle);
	void Roll(char angle);
	void Shoot();
	void Yaw(char angle);

	// Accessors
	static PlayerManager* GetInstance(Camera* inCamera, SceneObject* inSceneObject, float inPitchVelocity, float inRollVelocity, float inVelocity, float inYawVelocity);
};

#endif