#ifndef _GLOBAL_TRANSFORM_H
#define _GLOBAL_TRANSFORM_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalTypedefs.h"

// Forward Declarations
class ColliderManager;

class GlobalTransform
{
	static XMMATRIX transformMatrix;
	static XMVECTOR translationVector;

public:
	static void RotateOnWorldXAxis(float angle, XMMATRIX& inWorldMatrix);
	static void RotateOnWorldYAxis(float angle, XMMATRIX& inWorldMatrix);
	static void RotateOnWorldZAxis(float angle, XMMATRIX& inWorldMatrix);
	static void RotateOnZAxis(float angle, XMMATRIX& inWorldMatrix);
	static void RotateOnXAxis(float angle, XMMATRIX& inWorldMatrix);
	static void RotateOnYAxis(float angle, XMMATRIX& inWorldMatrix);
	static void Scale(float x, float y, float z, ColliderManager* colliderManager, XMMATRIX& inWorldMatrix);
	static void Translate(float x, float y, float z, XMMATRIX& inWorldMatrix);
	static void UniformScale(float value, ColliderManager* colliderManager, XMMATRIX& inWorldMatrix);
	//static void WorldTranslate(uchar index, float speed, XMMATRIX& inWorldMatrix);
};

#endif