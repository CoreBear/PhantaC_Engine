#pragma region Dependencies
// My Headers
#include "Camera.h"		// Connection to declarations
#pragma endregion

#pragma region Initialization
Camera::Camera(const ushort* clientDimensions) : Mesh(true)
{
	const float	nearFarPlaneDistances[2] = { 1.0f, 100.0f };	// 0 - NearZ. 1 - FarZ
	const float	verticalFOV = XMConvertToRadians(45.0f);

	projectionMatrix = XMMatrixPerspectiveFovLH(verticalFOV, float(clientDimensions[1]) / clientDimensions[0], nearFarPlaneDistances[0], nearFarPlaneDistances[1]);
}
#pragma endregion