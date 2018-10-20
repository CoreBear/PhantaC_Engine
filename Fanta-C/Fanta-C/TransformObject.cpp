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