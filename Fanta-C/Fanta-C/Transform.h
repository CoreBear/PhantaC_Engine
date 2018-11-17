#ifndef _TRANSFORM_H
#define _TRANSFORM_H

// My Headers
#include "GlobalTypedefs.h"
#include "LineRenderer.h"

class Transform
{
protected:
	float		moveSpeed;
	float		rotationSpeed;
	XMMATRIX	myTransformMatrix;
	XMMATRIX	myWorldMatrix;
	XMVECTOR	myTranslationVector;

public:
	// Initialization
	Transform(const XMVECTOR& position) : myWorldMatrix(XMMatrixIdentity()) { myWorldMatrix.r[3] = position; }		
	Transform(bool camera, const XMVECTOR& position, const XMVECTOR& forward, const XMVECTOR& up);

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
	virtual bool GetFlatness() const { return false; }
	float GetMoveSpeed() const { return moveSpeed; }
	float GetRotationSpeed() const { return rotationSpeed; }
	virtual float GetScale() const { return false; }
	XMMATRIX& GetTransformMatrix() { return myTransformMatrix; }
	XMMATRIX& GetWorldMatrix() { return myWorldMatrix; }
	XMVECTOR& GetPosition() { return myWorldMatrix.r[3]; }

	// Mutators
	void SetMoveSpeed(float inMoveSpeed) { moveSpeed = inMoveSpeed; }
	void SetRotationSpeed(float inRotationSpeed) { rotationSpeed = inRotationSpeed; }
};

#endif