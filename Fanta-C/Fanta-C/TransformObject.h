#ifndef _TRANSFORM_OBJECT_H
#define _TRANSFORM_OBJECT_H

// System Headers
#include "GlobalDirectX.h"

// My Headers
#include "Typedefs.h"
using namespace DirectX;

class TransformObject
{
	XMMATRIX			myWorldMatrix;
	const XMVECTOR		worldVectors[3] = { XMVectorSet(1, 0, 0, 1), XMVectorSet(0, 1, 0, 1), XMVectorSet(0, 0, 1, 1) };	// X-Axis, Y-Axis, Z-Axis
		
public:
	// Initialization
	TransformObject() { myWorldMatrix = XMMatrixIdentity(); }														// Generic instantiation at origin
	TransformObject(XMVECTOR* position) : myWorldMatrix(XMMatrixIdentity()) { myWorldMatrix.r[3] = *position; }		// Instatiation at specific position
	TransformObject(bool camera, XMVECTOR position, XMVECTOR forward, XMVECTOR up);		
	
	// Accessors
	XMMATRIX& GetWorldMatrix() { return myWorldMatrix; }
};

#endif