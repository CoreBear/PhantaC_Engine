#pragma region Dependencies
// My Headers
#include "TransformObject.h"		// Connection to declarations
#pragma endregion

#pragma region Initialization
TransformObject::TransformObject(bool camera, XMVECTOR position, XMVECTOR forward, XMVECTOR up)
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

//#pragma region Public Interface
//void TransformObject::OnXAxis(float speed)
//{
//	ResetTransformMatrix();
//	myTransformMatrix.r[1].m128_f32[1] =  cos(XMConvertToRadians(speed));
//	myTransformMatrix.r[1].m128_f32[2] =  sin(XMConvertToRadians(speed));
//	myTransformMatrix.r[2].m128_f32[1] = -myTransformMatrix.r[1].m128_f32[2];
//	myTransformMatrix.r[2].m128_f32[2] =  myTransformMatrix.r[1].m128_f32[1];
//	UpdateWorldMatrix();
//}
//void TransformObject::OnYAxis(float speed)
//{
//	ResetTransformMatrix();
//	myTransformMatrix.r[0].m128_f32[0] =  cos(XMConvertToRadians(speed));
//	myTransformMatrix.r[0].m128_f32[2] =  sin(XMConvertToRadians(speed));
//	myTransformMatrix.r[2].m128_f32[0] = -myTransformMatrix.r[0].m128_f32[2];
//	myTransformMatrix.r[2].m128_f32[2] =  myTransformMatrix.r[0].m128_f32[0];
//	UpdateWorldMatrix();
//}
//void TransformObject::OnZAxis(float speed)
//{
//	ResetTransformMatrix();
//	myTransformMatrix.r[0].m128_f32[0] =  cos(XMConvertToRadians(speed));
//	myTransformMatrix.r[0].m128_f32[1] =  sin(XMConvertToRadians(speed));
//	myTransformMatrix.r[1].m128_f32[0] = -myTransformMatrix.r[0].m128_f32[1];
//	myTransformMatrix.r[1].m128_f32[1] =  myTransformMatrix.r[0].m128_f32[0];
//	UpdateWorldMatrix();
//}
//void TransformObject::Translate(float x, float y, float z)
//{
//	ResetTransformMatrix();
//	myTransformMatrix.r[3].m128_f32[0] = x;
//	myTransformMatrix.r[3].m128_f32[1] = y;
//	myTransformMatrix.r[3].m128_f32[2] = z;
//	UpdateWorldMatrix();
//}
//#pragma endregion