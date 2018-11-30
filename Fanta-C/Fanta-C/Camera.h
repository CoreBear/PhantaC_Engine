#ifndef _CAMERA_H
#define _CAMERA_H

// My Headers
#include "GlobalTypedefs.h"
#include "Mesh.h"

class Camera : public Mesh
{
	XMMATRIX projectionMatrix;
	XMMATRIX viewMatrix;

public:
	// Initialization
	Camera(const ushort* clientDimensions);

	// Accessors
	XMMATRIX* GetProjectionMatrix() { return &projectionMatrix; }
	XMMATRIX* GetViewMatrix() { return &viewMatrix; }
};

#endif