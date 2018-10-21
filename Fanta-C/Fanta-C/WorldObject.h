#ifndef _WORLD_OBJECT_H
#define _WORLD_OBJECT_H

// System Headers
#include "GlobalDirectX.h"

// My Headers
#include "GlobalTypedefs.h"

class WorldObject
{
protected:
	XMMATRIX			myWorldMatrix;
		
public:
	// Initialization
	WorldObject(const XMVECTOR& position) : myWorldMatrix(XMMatrixIdentity()) { myWorldMatrix.r[3] = position; }		// Instatiation at specific position
	WorldObject(bool camera, const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up);
	
	// Accessors
	XMMATRIX& GetWorldMatrix() { return myWorldMatrix; }
};

#endif