#ifndef _CAMERA_H
#define _CAMERA_H

#include "TransformObject.h"
#include "ProgramGlobals.h"

class Camera : public TransformObject
{
	const float		moveSpeed = 1;
	float			nearFarPlaneDistances[2] = { 1.0f, 100.0f };																// 0 - NearZ. 1 - FarZ
	float			verticalFOV = XMConvertToRadians(45.0f);																	
	XMVECTOR		cameraVectors[3] = { XMVectorSet(0, 0, 0, 1), XMVectorSet(0, 10, -15, 1), XMVectorSet(0, 1, 0, 0) };		// look direction, position, updirection
	XMMATRIX		projectionMatrix;
	XMMATRIX		viewMatrix;

public:
	// Initialization
	Camera()
	{
		projectionMatrix = XMMatrixPerspectiveFovLH(verticalFOV, float(clientDimensions[1]) / clientDimensions[0], nearFarPlaneDistances[0], nearFarPlaneDistances[1]);
		viewMatrix = XMMatrixLookAtLH(cameraVectors[1], cameraVectors[0], cameraVectors[2]);
	}

	// Accessors
	const XMMATRIX& GetProjectionMatrix() const { return projectionMatrix; }
	const XMMATRIX& GetViewMatrix() const { return viewMatrix; }

	// Mutators
	void Move(uchar direction, float deltaTime) 
	{
		// Remember that movement is backwards
		switch (direction)
		{
		case 0:
			viewMatrix.r[3].m128_f32[0] += moveSpeed * deltaTime;
			break;
		case 1:
			viewMatrix.r[3].m128_f32[2] -= moveSpeed * deltaTime;
			break;
		case 2:
			viewMatrix.r[3].m128_f32[0] -= moveSpeed * deltaTime;
			break;
		case 3:
			viewMatrix.r[3].m128_f32[2] += moveSpeed * deltaTime;
			break;
		}
	}
};

#endif