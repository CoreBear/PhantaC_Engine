#ifndef _CAMERA_H
#define _CAMERA_H

// My Headers
#include "GlobalDirectX.h"
#include "ProgramGlobals.h"
#include "TransformObject.h"

class Camera : public TransformObject
{
	XMMATRIX		projectionMatrix;
	
public:
	// Initialization
	Camera(XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up);

	// Accessors
	const XMMATRIX& GetProjectionMatrix() const { return projectionMatrix; }
};

#endif