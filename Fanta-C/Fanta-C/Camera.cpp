#include "Camera.h"

Camera::Camera(XMVECTOR position, XMVECTOR forward, XMVECTOR up, float inMoveSpeed, float inRotationSpeed) : TransformObject(position, forward, up, inMoveSpeed, inRotationSpeed)
{
	const float			nearFarPlaneDistances[2] = { 1.0f, 100.0f };	// 0 - NearZ. 1 - FarZ
	const float			verticalFOV = XMConvertToRadians(45.0f);

	projectionMatrix = XMMatrixPerspectiveFovLH(verticalFOV, float(clientDimensions[1]) / clientDimensions[0], nearFarPlaneDistances[0], nearFarPlaneDistances[1]);
}