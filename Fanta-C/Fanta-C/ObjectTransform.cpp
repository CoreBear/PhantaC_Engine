#pragma region Dependencies
#include "ObjectTransform.h"
#pragma endregion

#pragma region Initialization
ObjectTransform::ObjectTransform(bool camera, const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up)
{
	if (!camera)
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
	else
		myWorldMatrix = XMMatrixLookAtLH(position, forward, up);
}
#pragma endregion

#pragma region Public Interface
void ObjectTransform::RotateOnWorldXAxis(float angle)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[1].m128_f32[1] =  float(cos(XMConvertToRadians(angle)));
	myTransformMatrix.r[1].m128_f32[2] =  float(sin(XMConvertToRadians(angle)));
	myTransformMatrix.r[2].m128_f32[1] = -myTransformMatrix.r[1].m128_f32[2];
	myTransformMatrix.r[2].m128_f32[2] =  myTransformMatrix.r[1].m128_f32[1];
	myWorldMatrix = XMMatrixMultiply(myWorldMatrix, myTransformMatrix);
}
void ObjectTransform::RotateOnWorldYAxis(float angle)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[0].m128_f32[0] =  float(cos(XMConvertToRadians(angle)));
	myTransformMatrix.r[0].m128_f32[2] =  float(sin(XMConvertToRadians(angle)));
	myTransformMatrix.r[2].m128_f32[0] = -myTransformMatrix.r[0].m128_f32[2];
	myTransformMatrix.r[2].m128_f32[2] =  myTransformMatrix.r[0].m128_f32[0];
	myWorldMatrix = XMMatrixMultiply(myWorldMatrix, myTransformMatrix);
}
void ObjectTransform::RotateOnWorldZAxis(float angle)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[0].m128_f32[0] =  float(cos(XMConvertToRadians(angle)));
	myTransformMatrix.r[0].m128_f32[1] =  float(sin(XMConvertToRadians(angle)));
	myTransformMatrix.r[1].m128_f32[0] = -myTransformMatrix.r[0].m128_f32[1];
	myTransformMatrix.r[1].m128_f32[1] =  myTransformMatrix.r[0].m128_f32[0];
	myWorldMatrix = XMMatrixMultiply(myWorldMatrix, myTransformMatrix);
}
void ObjectTransform::RotateOnXAxis(float angle)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[1].m128_f32[1] = float(cos(XMConvertToRadians(angle)));
	myTransformMatrix.r[1].m128_f32[2] = float(sin(XMConvertToRadians(angle)));
	myTransformMatrix.r[2].m128_f32[1] = -myTransformMatrix.r[1].m128_f32[2];
	myTransformMatrix.r[2].m128_f32[2] = myTransformMatrix.r[1].m128_f32[1];
	myWorldMatrix = XMMatrixMultiply(myTransformMatrix, myWorldMatrix);
}
void ObjectTransform::RotateOnYAxis(float angle)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[0].m128_f32[0] = float(cos(XMConvertToRadians(angle)));
	myTransformMatrix.r[0].m128_f32[2] = float(sin(XMConvertToRadians(angle)));
	myTransformMatrix.r[2].m128_f32[0] = -myTransformMatrix.r[0].m128_f32[2];
	myTransformMatrix.r[2].m128_f32[2] = myTransformMatrix.r[0].m128_f32[0];
	myWorldMatrix = XMMatrixMultiply(myTransformMatrix, myWorldMatrix);
}
void ObjectTransform::RotateOnZAxis(float angle)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[0].m128_f32[0] = float(cos(XMConvertToRadians(angle)));
	myTransformMatrix.r[0].m128_f32[1] = float(sin(XMConvertToRadians(angle)));
	myTransformMatrix.r[1].m128_f32[0] = -myTransformMatrix.r[0].m128_f32[1];
	myTransformMatrix.r[1].m128_f32[1] = myTransformMatrix.r[0].m128_f32[0];
	myWorldMatrix = XMMatrixMultiply(myTransformMatrix, myWorldMatrix);
}
void ObjectTransform::Scale(float x, float y, float z)
{
	// This isn't fully correct
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[0] *= x;
	myTransformMatrix.r[1] *= y;
	myTransformMatrix.r[2] *= z;
	myWorldMatrix = XMMatrixMultiply(myTransformMatrix, myWorldMatrix);
}
void ObjectTransform::Translate(float x, float y, float z)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[3].m128_f32[0] = x;
	myTransformMatrix.r[3].m128_f32[1] = y;
	myTransformMatrix.r[3].m128_f32[2] = z;
	myWorldMatrix = XMMatrixMultiply(myWorldMatrix, myTransformMatrix);
}
void ObjectTransform::WorldTranslate(uchar index, float speed)
{
	// index 0 - horizontal, 1 - vertical, 2 - for/back
	// Store object direction
	myTranslationVector = (myWorldMatrix.r[index] + myWorldMatrix.r[3]) - myWorldMatrix.r[3];
	myTranslationVector = XMVector3Normalize(myTranslationVector);
	
	myWorldMatrix.r[3].m128_f32[0] += myTranslationVector.m128_f32[0] * speed;
	myWorldMatrix.r[3].m128_f32[1] += myTranslationVector.m128_f32[1] * speed;
	myWorldMatrix.r[3].m128_f32[2] += myTranslationVector.m128_f32[2] * speed;
}
#pragma endregion