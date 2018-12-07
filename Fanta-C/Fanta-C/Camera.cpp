#pragma region Dependencies
// My Headers
#include "Camera.h"		// Connection to declarations
#pragma endregion

#pragma region Forward Declarations
Camera* Camera::cameraInstance = nullptr;
#pragma endregion

#pragma region Initialization
Camera::Camera(const ushort* clientDimensions)
{
	const float	nearFarPlaneDistances[2] = { 1.0f, 100.0f };	// 0 - NearZ. 1 - FarZ
	const float	verticalFOV = XMConvertToRadians(45.0f);
	const XMVECTOR cameraVectors[3] = { XMVectorSet(0, 3, -20, 1), XMVectorSet(0, 0, 1, 0), XMVectorSet(0, 1, 0, 0) };
	
	projectionMatrix = XMMatrixPerspectiveFovLH(verticalFOV, float(clientDimensions[1]) / clientDimensions[0], nearFarPlaneDistances[0], nearFarPlaneDistances[1]);
	viewMatrix = XMMatrixInverse(nullptr, XMMatrixLookAtLH(cameraVectors[0], cameraVectors[1], cameraVectors[2]));
}
#pragma endregion

#pragma region Accessors
Camera* Camera::GetInstance(const ushort * clientDimensions)
{
	// If instance has been created, return it
	if (cameraInstance) return cameraInstance;

	// If instance has not been created, create it and return it
	else
	{
		cameraInstance = new Camera(clientDimensions);
		return cameraInstance;
	}
}
#pragma endregion
