#ifndef _CAMERA_H
#define _CAMERA_H

// My Headers
#include "GlobalDirectX.h"
#include "MoveableObject.h"
#include "ProgramGlobals.h"
#include "TransformObject.h"

class Camera : public MoveableObject
{
	XMMATRIX		projectionMatrix;
	
public:
	// Initialization
	Camera(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float inMoveSpeed = 0, float inRotationSpeed = 0);

	// Accessors
	const XMMATRIX& GetProjectionMatrix() const { return projectionMatrix; }
};

#endif