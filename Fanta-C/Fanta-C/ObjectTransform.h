#ifndef __OBJECT_TRANSFORM_H
#define __OBJECT_TRANSFORM_H

// My Headers
#include "GlobalTypedefs.h"
#include "LineRenderer.h"
#include "Mesh.h"
#include "WorldObject.h"

class ObjectTransform : public WorldObject, public Mesh
{
protected:
	float			moveSpeed;
	float			rotationSpeed;
	XMMATRIX		myTransformMatrix;
	XMVECTOR		myTranslationVector;

public:
	// Initialization
	ObjectTransform(const XMVECTOR& position) : WorldObject(position) { return; }
	ObjectTransform(bool camera, const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up) : WorldObject(camera, position, forward, up) { return; }

	// Public Interface
	virtual void DrawMe(LineRenderer& lineRenderer) { return; }
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
	virtual bool GetFlatness() const { return false; }
	float GetMoveSpeed() const { return moveSpeed; }
	float GetRotationSpeed() const { return rotationSpeed; }
	virtual float GetScale() const { return false; }

	// Mutators
	void SetMoveSpeed(float inMoveSpeed) { moveSpeed = inMoveSpeed; }
	void SetRotationSpeed(float inRotationSpeed) { rotationSpeed = inRotationSpeed; }
};

#endif