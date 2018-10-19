#pragma region Dependencies
#include "TransformObject.h"
#pragma endregion

#pragma region Initialization
TransformObject::TransformObject()
{
	moveSpeed = 0;
	rotationSpeed = 0;
	
	stabilizationVectors[0] = XMVectorSet(0, 0, 0, 1);		// Position
	stabilizationVectors[1] = XMVectorSet(0, 0, 1, 1);		// Forward direction
	stabilizationVectors[2] = XMVectorSet(0, 1, 0, 1);		// Up direction

	myWorldMatrix = XMMatrixLookAtRH(stabilizationVectors[0], stabilizationVectors[1], stabilizationVectors[2]);
}
TransformObject::TransformObject(float xPos, float yPos, float zPos, float inMoveSpeed, float inRotationSpeed) : moveSpeed(inMoveSpeed), rotationSpeed(inRotationSpeed)
{
	stabilizationVectors[0] = XMVectorSet(xPos, yPos,     zPos, 1);		// Position
	stabilizationVectors[1] = XMVectorSet(xPos, yPos, zPos + 1, 1);		// Forward direction
	stabilizationVectors[2] = XMVectorSet(	 0,	   1,		 0, 1);		// Up direction

	myWorldMatrix = XMMatrixLookAtRH(stabilizationVectors[0], stabilizationVectors[1], stabilizationVectors[2]);
}
TransformObject::TransformObject(XMVECTOR position, XMVECTOR forward, XMVECTOR up, float inMoveSpeed, float inRotationSpeed) : moveSpeed(inMoveSpeed), rotationSpeed(inRotationSpeed)
{
	stabilizationVectors[0] = position;
	stabilizationVectors[1] = forward;
	stabilizationVectors[2] = up;

	myWorldMatrix = XMMatrixLookAtLH(stabilizationVectors[0], stabilizationVectors[1], stabilizationVectors[2]);
}
#pragma endregion

#pragma region Public Interface
void TransformObject::Transform(bool* keysCurrentlyPressed)
{
	// Reset transformation matrix
	myTransformMatrix = XMMatrixIdentity();

	// A - Yaw Left
	if (keysCurrentlyPressed[0])
		OnYAxis(-rotationSpeed);

	// D - Yaw Right
	if (keysCurrentlyPressed[1])
		OnYAxis(rotationSpeed);

	// I - Nose Down
	if (keysCurrentlyPressed[2])
		OnXAxis(-rotationSpeed);

	// J - Roll Left
	if (keysCurrentlyPressed[3])
		OnZAxis(-rotationSpeed);

	// K - Nose Up
	if (keysCurrentlyPressed[4])
		OnXAxis(rotationSpeed);

	// L - Roll Right
	if (keysCurrentlyPressed[5])
		OnZAxis(rotationSpeed);

	// S - Move Back
	if (keysCurrentlyPressed[6])
		Translate(0, moveSpeed);

	// W - Move Forward
	if (keysCurrentlyPressed[7])
		Translate(0, -moveSpeed);

	// Apply the the transform to object's world matrix
	myWorldMatrix = XMMatrixMultiply(myWorldMatrix, myTransformMatrix);
}
#pragma endregion

#pragma region Black
void TransformObject::OnXAxis(float speed)
{
	myTransformMatrix.r[1].m128_f32[1] =  cos(XMConvertToRadians(speed));
	myTransformMatrix.r[1].m128_f32[2] =  sin(XMConvertToRadians(speed));
	myTransformMatrix.r[2].m128_f32[1] = -myTransformMatrix.r[1].m128_f32[2];
	myTransformMatrix.r[2].m128_f32[2] =  myTransformMatrix.r[1].m128_f32[1];
}
void TransformObject::OnYAxis(float speed)
{
	myTransformMatrix.r[0].m128_f32[0] =  cos(XMConvertToRadians(speed));
	myTransformMatrix.r[0].m128_f32[2] =  sin(XMConvertToRadians(speed));
	myTransformMatrix.r[2].m128_f32[0] = -myTransformMatrix.r[0].m128_f32[2];
	myTransformMatrix.r[2].m128_f32[2] =  myTransformMatrix.r[0].m128_f32[0];
}
void TransformObject::OnZAxis(float speed)
{
	myTransformMatrix.r[0].m128_f32[0] =  cos(XMConvertToRadians(speed));
	myTransformMatrix.r[0].m128_f32[1] =  sin(XMConvertToRadians(speed));
	myTransformMatrix.r[1].m128_f32[0] = -myTransformMatrix.r[0].m128_f32[1];
	myTransformMatrix.r[1].m128_f32[1] =  myTransformMatrix.r[0].m128_f32[0];
}
void TransformObject::Translate(float x, float z)
{
	myTransformMatrix.r[3].m128_f32[0] = x;
	myTransformMatrix.r[3].m128_f32[1] = 0;
	myTransformMatrix.r[3].m128_f32[2] = z;
}
#pragma endregion