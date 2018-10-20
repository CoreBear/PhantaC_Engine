#pragma region Dependencies
#include "ObjectTransform.h"
#pragma endregion

#pragma region Public Interface
void ObjectTransform::OnWorldXAxis(float angle)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[1].m128_f32[1] =  cos(XMConvertToRadians(angle));
	myTransformMatrix.r[1].m128_f32[2] =  sin(XMConvertToRadians(angle));
	myTransformMatrix.r[2].m128_f32[1] = -myTransformMatrix.r[1].m128_f32[2];
	myTransformMatrix.r[2].m128_f32[2] =  myTransformMatrix.r[1].m128_f32[1];
	myWorldMatrix = XMMatrixMultiply(myWorldMatrix, myTransformMatrix);
}
void ObjectTransform::OnWorldYAxis(float angle)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[0].m128_f32[0] =  cos(XMConvertToRadians(angle));
	myTransformMatrix.r[0].m128_f32[2] =  sin(XMConvertToRadians(angle));
	myTransformMatrix.r[2].m128_f32[0] = -myTransformMatrix.r[0].m128_f32[2];
	myTransformMatrix.r[2].m128_f32[2] =  myTransformMatrix.r[0].m128_f32[0];
	myWorldMatrix = XMMatrixMultiply(myWorldMatrix, myTransformMatrix);
}
void ObjectTransform::OnWorldZAxis(float angle)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[0].m128_f32[0] =  cos(XMConvertToRadians(angle));
	myTransformMatrix.r[0].m128_f32[1] =  sin(XMConvertToRadians(angle));
	myTransformMatrix.r[1].m128_f32[0] = -myTransformMatrix.r[0].m128_f32[1];
	myTransformMatrix.r[1].m128_f32[1] =  myTransformMatrix.r[0].m128_f32[0];
	myWorldMatrix = XMMatrixMultiply(myWorldMatrix, myTransformMatrix);
}
void ObjectTransform::OnXAxis(float angle)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[1].m128_f32[1] = cos(XMConvertToRadians(angle));
	myTransformMatrix.r[1].m128_f32[2] = sin(XMConvertToRadians(angle));
	myTransformMatrix.r[2].m128_f32[1] = -myTransformMatrix.r[1].m128_f32[2];
	myTransformMatrix.r[2].m128_f32[2] = myTransformMatrix.r[1].m128_f32[1];
	myWorldMatrix = XMMatrixMultiply(myTransformMatrix, myWorldMatrix);
}
void ObjectTransform::OnYAxis(float angle)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[0].m128_f32[0] = cos(XMConvertToRadians(angle));
	myTransformMatrix.r[0].m128_f32[2] = sin(XMConvertToRadians(angle));
	myTransformMatrix.r[2].m128_f32[0] = -myTransformMatrix.r[0].m128_f32[2];
	myTransformMatrix.r[2].m128_f32[2] = myTransformMatrix.r[0].m128_f32[0];
	myWorldMatrix = XMMatrixMultiply(myTransformMatrix, myWorldMatrix);
}
void ObjectTransform::OnZAxis(float angle)
{
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[0].m128_f32[0] = cos(XMConvertToRadians(angle));
	myTransformMatrix.r[0].m128_f32[1] = sin(XMConvertToRadians(angle));
	myTransformMatrix.r[1].m128_f32[0] = -myTransformMatrix.r[0].m128_f32[1];
	myTransformMatrix.r[1].m128_f32[1] = myTransformMatrix.r[0].m128_f32[0];
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
void ObjectTransform::WorldTranslate(float x, float y, float z)
{
	// Use global matrix to implement this
	myTransformMatrix = XMMatrixIdentity();
	myTransformMatrix.r[3].m128_f32[0] = x;
	myTransformMatrix.r[3].m128_f32[1] = y;
	myTransformMatrix.r[3].m128_f32[2] = z;
	myWorldMatrix = XMMatrixMultiply(myWorldMatrix, myTransformMatrix);
}
#pragma endregion