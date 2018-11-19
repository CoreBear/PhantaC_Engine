#pragma region Dependencies
#include "Transform.h"
#pragma endregion

#pragma region Public Interface
void Transform::RotateOnWorldXAxis(float angle)
{
	// Doesn't work properly
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[1].m128_f32[1] =  float(cos(XMConvertToRadians(angle)));
	myTransformMatrix.r[1].m128_f32[2] =  float(sin(XMConvertToRadians(angle)));
	myTransformMatrix.r[2].m128_f32[1] = -myTransformMatrix.r[1].m128_f32[2];
	myTransformMatrix.r[2].m128_f32[2] =  myTransformMatrix.r[1].m128_f32[1];
	myWorldMatrix = XMMatrixMultiply(myWorldMatrix, myTransformMatrix);
}
void Transform::RotateOnWorldYAxis(float angle)
{
	// Doesn't work properly
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[0].m128_f32[0] =  float(cos(XMConvertToRadians(angle)));
	myTransformMatrix.r[0].m128_f32[2] =  float(sin(XMConvertToRadians(angle)));
	myTransformMatrix.r[2].m128_f32[0] = -myTransformMatrix.r[0].m128_f32[2];
	myTransformMatrix.r[2].m128_f32[2] =  myTransformMatrix.r[0].m128_f32[0];
	myWorldMatrix = XMMatrixMultiply(myTransformMatrix, myWorldMatrix);
}
void Transform::RotateOnWorldZAxis(float angle)
{
	// Doesn't work properly
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[0].m128_f32[0] =  float(cos(XMConvertToRadians(angle)));
	myTransformMatrix.r[0].m128_f32[1] =  float(sin(XMConvertToRadians(angle)));
	myTransformMatrix.r[1].m128_f32[0] = -myTransformMatrix.r[0].m128_f32[1];
	myTransformMatrix.r[1].m128_f32[1] =  myTransformMatrix.r[0].m128_f32[0];
	myWorldMatrix = XMMatrixMultiply(myWorldMatrix, myTransformMatrix);
}
void Transform::RotateOnXAxis(float angle)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[1].m128_f32[1] = float(cos(XMConvertToRadians(angle)));
	myTransformMatrix.r[1].m128_f32[2] = float(sin(XMConvertToRadians(angle)));
	myTransformMatrix.r[2].m128_f32[1] = -myTransformMatrix.r[1].m128_f32[2];
	myTransformMatrix.r[2].m128_f32[2] = myTransformMatrix.r[1].m128_f32[1];
	myWorldMatrix = XMMatrixMultiply(myWorldMatrix, myTransformMatrix);
}
void Transform::RotateOnYAxis(float angle)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[0].m128_f32[0] = float(cos(XMConvertToRadians(angle)));
	myTransformMatrix.r[0].m128_f32[2] = float(sin(XMConvertToRadians(angle)));
	myTransformMatrix.r[2].m128_f32[0] = -myTransformMatrix.r[0].m128_f32[2];
	myTransformMatrix.r[2].m128_f32[2] = myTransformMatrix.r[0].m128_f32[0];
	myWorldMatrix = XMMatrixMultiply(myWorldMatrix, myTransformMatrix);
}
void Transform::RotateOnZAxis(float angle)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[0].m128_f32[0] = float(cos(XMConvertToRadians(angle)));
	myTransformMatrix.r[0].m128_f32[1] = float(sin(XMConvertToRadians(angle)));
	myTransformMatrix.r[1].m128_f32[0] = -myTransformMatrix.r[0].m128_f32[1];
	myTransformMatrix.r[1].m128_f32[1] = myTransformMatrix.r[0].m128_f32[0];
	myWorldMatrix = XMMatrixMultiply(myWorldMatrix, myTransformMatrix);
}
void Transform::Scale(float x, float y, float z)
{
	// Doesn't work properly
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[0] *= x;
	myTransformMatrix.r[1] *= y;
	myTransformMatrix.r[2] *= z;
	myWorldMatrix = XMMatrixMultiply(myTransformMatrix, myWorldMatrix);
}
void Transform::Translate(float x, float y, float z)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[3].m128_f32[0] = x;
	myTransformMatrix.r[3].m128_f32[1] = y;
	myTransformMatrix.r[3].m128_f32[2] = z;
	myWorldMatrix = XMMatrixMultiply(myWorldMatrix, myTransformMatrix);
}
void Transform::WorldTranslate(uchar index, float speed)
{
	// Doesn't work properly
	// index 0 - horizontal, 1 - vertical, 2 - for/back
	// Store object direction
	myTranslationVector = (myWorldMatrix.r[index] + myWorldMatrix.r[3]) - myWorldMatrix.r[3];
	myTranslationVector = XMVector3Normalize(myTranslationVector);
	
	myWorldMatrix.r[3].m128_f32[0] += myTranslationVector.m128_f32[0] * speed;
	myWorldMatrix.r[3].m128_f32[1] += myTranslationVector.m128_f32[1] * speed;
	myWorldMatrix.r[3].m128_f32[2] += myTranslationVector.m128_f32[2] * speed;
}
#pragma endregion