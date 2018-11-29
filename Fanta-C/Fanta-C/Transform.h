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
	XMMATRIX myWorldMatrix;

public:
	// Initialization
	Transform(const XMVECTOR& position) : myWorldMatrix(XMMatrixIdentity()) { myWorldMatrix.r[3] = position; }		
	Transform(const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up){ myWorldMatrix = XMMatrixLookAtLH(position, forward, up); }
	
	// Accessors
	virtual bool GetFlatness() const { return false; }
	virtual float GetScale() const { return false; }
	XMMATRIX* GetWorldMatrix() { return &myWorldMatrix; }
	XMVECTOR* GetPosition() { return &myWorldMatrix.r[3]; }
};

#endif&