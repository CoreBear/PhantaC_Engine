#ifndef _CAMERA_H
#define _CAMERA_H

#include "TransformObject.h"
#include "ProgramGlobals.h"

class Camera : public TransformObject
{
	XMMATRIX		projectionMatrix;
	
public:
	// Initialization
	Camera(XMVECTOR position, XMVECTOR forward, XMVECTOR up, float inMoveSpeed = 0, float inRotationSpeed = 0);

	// Accessors
	const XMMATRIX& GetProjectionMatrix() const { return projectionMatrix; }
};

#endif