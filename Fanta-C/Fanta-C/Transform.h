#ifndef _TRANSFORM_H
#define _TRANSFORM_H

// My Headers
#include "GlobalTypedefs.h"
#include "LineRenderer.h"

// Forward Declarations
class colliderManager;

class Transform
{
protected:
	XMMATRIX myLocalMatrix;

public:
	// Initialization
	Transform(XMMATRIX* inMatrix) : myLocalMatrix(*inMatrix) { return; }
	Transform(const XMVECTOR& position) 
	{
		myLocalMatrix = XMMatrixIdentity();
		myLocalMatrix.r[3] = position;
	}
	
	// Accessors
	virtual float GetScale() const { return false; }
	XMMATRIX* GetLocalMatrix() { return &myLocalMatrix; }
	XMVECTOR* GetPosition() { return &myLocalMatrix.r[3]; }

	// Mutators
	void SetLocalMatrix(XMMATRIX* inMatrix) { myLocalMatrix = *inMatrix; }
};

#endif&