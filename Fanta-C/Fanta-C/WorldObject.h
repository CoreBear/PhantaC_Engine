#ifndef _WORLD_OBJECT_H
#define _WORLD_OBJECT_H

// System Headers
#include "GlobalDirectX.h"

// My Headers
#include "Typedefs.h"
using namespace DirectX;

class WorldObject
{
	const XMVECTOR		worldVectors[3] = { XMVectorSet(1, 0, 0, 1), XMVectorSet(0, 1, 0, 1), XMVectorSet(0, 0, 1, 1) };	// X-Axis, Y-Axis, Z-Axis

protected:
	XMMATRIX			myWorldMatrix;
		
public:
	// Initialization
	WorldObject() { myWorldMatrix = XMMatrixIdentity(); }														// Generic instantiation at origin
	WorldObject(XMVECTOR* position) : myWorldMatrix(XMMatrixIdentity()) { myWorldMatrix.r[3] = *position; }		// Instatiation at specific position
	WorldObject(bool camera, XMVECTOR position, XMVECTOR forward, XMVECTOR up);		
	
	// Accessors
	XMMATRIX& GetWorldMatrix() { return myWorldMatrix; }
};

#endif