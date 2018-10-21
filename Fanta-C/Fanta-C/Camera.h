#ifndef _CAMERA_H
#define _CAMERA_H

// My Headers
#include "GlobalDirectX.h"
#include "ObjectTransform.h"
#include "ProgramGlobals.h"
#include "WorldObject.h"

class Camera : public ObjectTransform
{
	XMMATRIX		projectionMatrix;
	
public:
	// Initialization
	Camera(ushort* clientDimensions, XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float inMoveSpeed = 0, float inRotationSpeed = 0);

	// Accessors
	const XMMATRIX& GetProjectionMatrix() const { return projectionMatrix; }
};

#endif