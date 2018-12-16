#ifndef _PLAYER_MANAGER_H
#define _PLAYER_MANAGER_H

// My Headers
#include "GlobalTypedefs.h"
#include "MovingObject.h"

// Forward Declarations
class Camera;
class SceneGraph;

class PlayerManager : public MovingObject
{
	// Variables
	Camera*					camera;
	static PlayerManager*	playerManagerInstance;

	// Hacked together shooting mechanic. Will remove
	class SceneObject*	bulletTrail;	
	SceneGraph*			sceneGraphPtr;		
	const uchar			trailDistance = 50;
	
	// Initialization
	PlayerManager(Camera* inCamera, SceneGraph* sceneGraph, float inVelocity, float inAngularVelocity) : camera(inCamera), sceneGraphPtr(sceneGraph), MovingObject(inVelocity, inAngularVelocity) { return; }
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
	static PlayerManager* GetInstance(Camera* inCamera, SceneGraph* sceneGraph, float inVelocity, float inAngularVelocity);
};

#endif