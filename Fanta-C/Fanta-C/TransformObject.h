#ifndef _TRANSFORM_OBJECT_H
#define _TRANSFORM_OBJECT_H

#include "Typedefs.h"
#include <DirectXMath.h>
using namespace DirectX;

class TransformObject
{
protected:
	DirectX::XMMATRIX		myWorldMatrix;

public:
	// Initialization
	TransformObject() { myWorldMatrix = XMMatrixIdentity(); }
	TransformObject(char xPos, char yPos, char zPos)
	{
		myWorldMatrix = XMMatrixIdentity();
		myWorldMatrix.r[3].m128_f32[0] = xPos;
		myWorldMatrix.r[3].m128_f32[1] = yPos;
		myWorldMatrix.r[3].m128_f32[2] = zPos;
	}

	// Accessors
	DirectX::XMMATRIX& GetWorldMatrix() { return myWorldMatrix; }
};

#endif