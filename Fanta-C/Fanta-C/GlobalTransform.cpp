#pragma region Dependencies
// My Headers
#include "GlobalTransform.h"		// Connection to declarations

#include "ColliderManager.h"
#pragma endregion

#pragma region Global Variables
XMMATRIX GlobalTransform::transformMatrix;
XMVECTOR GlobalTransform::translationVector;
#pragma endregion

#pragma region Public Interface
void GlobalTransform::RotateOnWorldXAxis(float angle, XMMATRIX& inWorldMatrix)
{
	// Set the transform matrix to whatever's space we are trying to step into
	transformMatrix = XMMatrixIdentity();
	transformMatrix.r[1].m128_f32[1] = float(cos(XMConvertToRadians(angle)));
	transformMatrix.r[1].m128_f32[2] = float(sin(XMConvertToRadians(angle)));
	transformMatrix.r[2].m128_f32[1] = -transformMatrix.r[1].m128_f32[2];
	transformMatrix.r[2].m128_f32[2] = transformMatrix.r[1].m128_f32[1];
	inWorldMatrix = XMMatrixMultiply(transformMatrix, inWorldMatrix);
}
void GlobalTransform::RotateOnWorldYAxis(float angle, XMMATRIX& inWorldMatrix)
{
	// Set the transform matrix to whatever's space we are trying to step into
	transformMatrix = XMMatrixIdentity();
	transformMatrix.r[0].m128_f32[0] = float(cos(XMConvertToRadians(angle)));
	transformMatrix.r[0].m128_f32[2] = float(sin(XMConvertToRadians(angle)));
	transformMatrix.r[2].m128_f32[0] = -transformMatrix.r[0].m128_f32[2];
	transformMatrix.r[2].m128_f32[2] = transformMatrix.r[0].m128_f32[0];
	inWorldMatrix = XMMatrixMultiply(transformMatrix, inWorldMatrix);
}
void GlobalTransform::RotateOnWorldZAxis(float angle, XMMATRIX& inWorldMatrix)
{
	// Set the transform matrix to whatever's space we are trying to step into
	transformMatrix = XMMatrixIdentity();
	transformMatrix.r[0].m128_f32[0] = float(cos(XMConvertToRadians(angle)));
	transformMatrix.r[0].m128_f32[1] = float(sin(XMConvertToRadians(angle)));
	transformMatrix.r[1].m128_f32[0] = -transformMatrix.r[0].m128_f32[1];
	transformMatrix.r[1].m128_f32[1] = transformMatrix.r[0].m128_f32[0];
	inWorldMatrix = XMMatrixMultiply(transformMatrix, inWorldMatrix);
}
void GlobalTransform::RotateOnXAxis(float angle, XMMATRIX& inWorldMatrix)
{
	transformMatrix = XMMatrixIdentity();
	transformMatrix.r[1].m128_f32[1] = float(cos(XMConvertToRadians(angle)));
	transformMatrix.r[1].m128_f32[2] = float(sin(XMConvertToRadians(angle)));
	transformMatrix.r[2].m128_f32[1] = -transformMatrix.r[1].m128_f32[2];
	transformMatrix.r[2].m128_f32[2] = transformMatrix.r[1].m128_f32[1];
	inWorldMatrix = XMMatrixMultiply(inWorldMatrix, transformMatrix);
}
void GlobalTransform::RotateOnYAxis(float angle, XMMATRIX& inWorldMatrix)
{
	transformMatrix = XMMatrixIdentity();
	transformMatrix.r[0].m128_f32[0] = float(cos(XMConvertToRadians(angle)));
	transformMatrix.r[0].m128_f32[2] = float(sin(XMConvertToRadians(angle)));
	transformMatrix.r[2].m128_f32[0] = -transformMatrix.r[0].m128_f32[2];
	transformMatrix.r[2].m128_f32[2] = transformMatrix.r[0].m128_f32[0];
	inWorldMatrix = XMMatrixMultiply(inWorldMatrix, transformMatrix);
}
void GlobalTransform::RotateOnZAxis(float angle, XMMATRIX& inWorldMatrix)
{
	transformMatrix = XMMatrixIdentity();
	transformMatrix.r[0].m128_f32[0] = float(cos(XMConvertToRadians(angle)));
	transformMatrix.r[0].m128_f32[1] = float(sin(XMConvertToRadians(angle)));
	transformMatrix.r[1].m128_f32[0] = -transformMatrix.r[0].m128_f32[1];
	transformMatrix.r[1].m128_f32[1] = transformMatrix.r[0].m128_f32[0];
	inWorldMatrix = XMMatrixMultiply(inWorldMatrix, transformMatrix);
}
void GlobalTransform::Scale(float x, float y, float z, ColliderManager* colliderManager, XMMATRIX& inWorldMatrix)
{
	// Update colliderManager extents
	//colliderManager->SetExtents(x, y, z);

	// Update mesh vertices
	transformMatrix = XMMatrixIdentity();
	transformMatrix.r[0] *= x;
	transformMatrix.r[1] *= y;
	transformMatrix.r[2] *= z;
	inWorldMatrix = XMMatrixMultiply(transformMatrix, inWorldMatrix);
}
void GlobalTransform::Translate(float x, float y, float z, XMMATRIX& inWorldMatrix)
{
	inWorldMatrix.r[3].m128_f32[0] += x;
	inWorldMatrix.r[3].m128_f32[1] += y;
	inWorldMatrix.r[3].m128_f32[2] += z;
}
void GlobalTransform::UniformScale(float value, ColliderManager* colliderManager, XMMATRIX& inWorldMatrix)
{
	// Update colliderManager extents
	//colliderManager->SetExtents(value, value, value);

	// Update mesh vertices
	transformMatrix = XMMatrixIdentity();
	transformMatrix.r[0] *= value;
	transformMatrix.r[1] *= value;
	transformMatrix.r[2] *= value;
	inWorldMatrix = XMMatrixMultiply(transformMatrix, inWorldMatrix);
}
#pragma endregion