#ifndef __OBJECT_TRANSFORM_H
#define __OBJECT_TRANSFORM_H

// My Headers
#include "GlobalDirectX.h"
#include "LineRenderer.h"
#include "WorldObject.h"
#include "Typedefs.h"

class ObjectTransform : public WorldObject
{
protected:
	float			moveSpeed;
	float			rotationSpeed;
	XMMATRIX		myTransformMatrix;
	XMVECTOR		myTranslationVector;

public:
	// Initialization
	ObjectTransform(XMVECTOR* position, float inMoveSpeed, float inRotationSpeed) : moveSpeed(inMoveSpeed), rotationSpeed(inRotationSpeed), WorldObject(position) { return; }
	ObjectTransform(bool camera, XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float inMoveSpeed, float inRotationSpeed) : moveSpeed(inMoveSpeed), rotationSpeed(inRotationSpeed), WorldObject(camera, *position, *forward, *up) { return; }

	// Public Interface
	void RotateOnWorldXAxis(float angle);
	void RotateOnWorldYAxis(float angle);
	void RotateOnWorldZAxis(float angle);
	void RotateOnZAxis(float angle);
	void RotateOnXAxis(float angle);
	void RotateOnYAxis(float angle);
	void Scale(float x, float y, float z);
	void Translate(float x, float y, float z);
	void WorldTranslate(uchar index, float speed);

	// Accessors
	float GetMoveSpeed() const { return moveSpeed; }
	float GetRotationSpeed() const { return rotationSpeed; }
};

#endif