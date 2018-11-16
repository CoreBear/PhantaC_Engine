#ifndef _OBJECT_MANAGER_H
#define _OBJECT_MANAGER_H

// My Headers
#include "Collider.h"
#include "GlobalTypedefs.h"
#include "Mesh.h"
#include "Transform.h"

class ObjectManager
{
	Collider*	colliderPtr = nullptr;			
	Mesh*		meshPtr = nullptr;				// Renderable shape
	Transform*	transformPtr = nullptr;

public:
	// Initialization
	ObjectManager(Mesh* inMesh, bool camera, bool collidable, bool transformable, const XMVECTOR& position = { 0, 0, 0, 1 }, const XMVECTOR& forward = { 0, 0, 1, 1 }, const XMVECTOR& up = { 0, 1, 0, 1 });

	// Clean Up
	~ObjectManager();

	// Accessors
	Mesh* GetMesh() { return meshPtr; }
	Transform* GetTransform() { return transformPtr; }
};

#endif