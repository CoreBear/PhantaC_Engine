#ifndef __MOVEABLE_OBJECT_H
#define __MOVEABLE_OBJECT_H

// My Headers
#include "GlobalDirectX.h"
#include "LineRenderer.h"
#include "TransformObject.h"
#include "Typedefs.h"

class MoveableObject : public TransformObject
{
protected:
	float			moveSpeed;
	float			rotationSpeed;
	XMMATRIX		globalMatrix;
	XMMATRIX		myTransformMatrix;

public:
	// Initialization
	MoveableObject(float inMoveSpeed, float inRotationSpeed) : moveSpeed(inMoveSpeed), rotationSpeed(inRotationSpeed) { return; }
	MoveableObject(XMVECTOR* position, float inMoveSpeed, float inRotationSpeed) : moveSpeed(inMoveSpeed), rotationSpeed(inRotationSpeed), TransformObject(position) { return; }
	MoveableObject(bool camera, XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float inMoveSpeed, float inRotationSpeed) : moveSpeed(inMoveSpeed), rotationSpeed(inRotationSpeed), TransformObject(camera, *position, *forward, *up) { return; }

	// Public Interface
	void OnXAxis(float angle);
	void OnYAxis(float angle);
	void OnZAxis(float angle);
	void OnWorldXAxis(float angle);
	void OnWorldYAxis(float angle);
	void OnWorldZAxis(float angle);
	void Translate(float x, float y, float z);
	void WorldTranslate(float x, float y, float z);

	// Accessors
	float GetMoveSpeed() const { return moveSpeed; }
	float GetRotationSpeed() const { return rotationSpeed; }
};

#endif