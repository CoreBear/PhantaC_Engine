#ifndef _CAMERA_H
#define _CAMERA_H

// My Headers
#include "ObjectTransform.h"

class Camera : public ObjectTransform
{
	XMMATRIX projectionMatrix;
	
public:
	// Initialization
	Camera(const ushort* clientDimensions, const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up);

	// Accessors
	const XMMATRIX& GetProjectionMatrix() const { return projectionMatrix; }
};

#endif