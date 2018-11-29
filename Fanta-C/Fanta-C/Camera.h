#ifndef _CAMERA_H
#define _CAMERA_H

// My Headers
#include "GlobalTypedefs.h"
#include "Mesh.h"

class Camera : public Mesh
{
	XMMATRIX projectionMatrix;
	
public:
	// Initialization
	Camera(const ushort* clientDimensions);

	// Accessors
	const XMMATRIX& GetProjectionMatrix() const { return projectionMatrix; }
};

#endif