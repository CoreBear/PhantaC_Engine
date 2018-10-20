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
	XMMATRIX		globalMatrix;
	XMMATRIX		myTransformMatrix;

public:
	// Initialization
	ObjectTransform(float inMoveSpeed, float inRotationSpeed) : moveSpeed(inMoveSpeed), rotationSpeed(inRotationSpeed) { return; }
	ObjectTransform(XMVECTOR* position, float inMoveSpeed, float inRotationSpeed) : moveSpeed(inMoveSpeed), rotationSpeed(inRotationSpeed), WorldObject(position) { return; }
	ObjectTransform(bool camera, XMVECTOR* position, XMVECTOR* forward, XMVECTOR* up, float inMoveSpeed, float inRotationSpeed) : moveSpeed(inMoveSpeed), rotationSpeed(inRotationSpeed), WorldObject(camera, *position, *forward, *up) { return; }

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