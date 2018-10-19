#pragma region Dependencies
#include "TransformObject.h"
#pragma endregion

#pragma region Initialization
TransformObject::TransformObject()
{
	moveSpeed = 0;
	rotationSpeed = 0;	
	myWorldMatrix = XMMatrixIdentity();
}
TransformObject::TransformObject(XMVECTOR* position, float inMoveSpeed, float inRotationSpeed) : moveSpeed(inMoveSpeed), rotationSpeed(inRotationSpeed)
{
	myWorldMatrix = XMMatrixIdentity();
	myWorldMatrix.r[3] = *position;					
}
TransformObject::TransformObject(bool camera, XMVECTOR position, XMVECTOR forward, XMVECTOR up, float inMoveSpeed, float inRotationSpeed) : moveSpeed(inMoveSpeed), rotationSpeed(inRotationSpeed)
{
	if (camera)
		myWorldMatrix = XMMatrixLookAtLH(position, forward, up);
	else
	{
		// Position
		myWorldMatrix.r[3] = position;

		// Forward
		myWorldMatrix.r[2] = (forward + position) - position;
		myWorldMatrix.r[2] = XMVector3Normalize(myWorldMatrix.r[2]);

		// Right
		myWorldMatrix.r[0] = XMVector3Cross(up, myWorldMatrix.r[2]);
		myWorldMatrix.r[0] = XMVector3Normalize(myWorldMatrix.r[0]);

		// Up
		myWorldMatrix.r[1] = XMVector3Cross(myWorldMatrix.r[2], myWorldMatrix.r[0]);
		myWorldMatrix.r[1] = XMVector3Normalize(myWorldMatrix.r[1]);
	}
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