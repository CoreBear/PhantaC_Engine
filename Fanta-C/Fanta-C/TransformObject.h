#ifndef _TRANSFORM_OBJECT_H
#define _TRANSFORM_OBJECT_H

#include "Typedefs.h"
#include <DirectXMath.h>
using namespace DirectX;

class TransformObject
{
	float				moveSpeed;
	float				rotationSpeed;
	float				moveInput[2] = { 0, 0 };																			// Stores which direction to move in x and z axis
	XMMATRIX			myTransformMatrix;
	XMMATRIX			myWorldMatrix;
	const XMVECTOR		worldVectors[3] = { XMVectorSet(1, 0, 0, 1), XMVectorSet(0, 1, 0, 1), XMVectorSet(0, 0, 1, 1) };	// X-Axis, Y-Axis, Z-Axis
		
public:
	// Initialization
	TransformObject();																										// Generic instantiation at origin
	TransformObject(float inMoveSpeed);																										// Generic instantiation at origin
	TransformObject(XMVECTOR* position, float inMoveSpeed = 0, float inRotationSpeed = 0);
	TransformObject(bool camera, XMVECTOR position, XMVECTOR forward, XMVECTOR up, float inMoveSpeed = 0, float inRotationSpeed = 0);

	// Accessors
	float GetMoveSpeed() { return moveSpeed; }
	float GetRotationsSpeed() { return rotationSpeed; }
	XMMATRIX& GetWorldMatrix() { return myWorldMatrix; }

	// Mutators
	void OnXAxis(float speed);
	void OnYAxis(float speed);
	void OnZAxis(float speed);
	void ResetTransformMatrix() { myTransformMatrix = XMMatrixIdentity(); }
	void Translate(float x, float y);
	void UpdateWorldMatrix() { myWorldMatrix = XMMatrixMultiply(myWorldMatrix, myTransformMatrix); }
};

#endif