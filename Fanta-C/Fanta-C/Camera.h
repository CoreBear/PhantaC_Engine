#ifndef _CAMERA_H
#define _CAMERA_H

// My Headers
#include "GlobalTypedefs.h"
#include "Mesh.h"

class Camera : public Mesh
{
	XMMATRIX projectionMatrix;
	XMMATRIX viewMatrix;
	static Camera* cameraInstance;

	// Initialization
	Camera(const ushort* clientDimensions);
	Camera(Camera const&) = delete;
	Camera operator=(Camera const&) = delete;

public:
	// Accessors
	static Camera* GetInstance(const ushort* clientDimensions);
	XMMATRIX* GetProjectionMatrix() { return &projectionMatrix; }
	XMMATRIX* GetViewMatrix() { return &viewMatrix; }
};

#endif