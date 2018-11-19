#ifndef _OBJECT_MANAGER_H
#define _OBJECT_MANAGER_H

// My Headers
#include "Collider.h"
#include "GlobalTypedefs.h"
#include "Mesh.h"
#include "Transform.h"

class ObjectManager
{
	bool		renderable;
	Collider*	colliderPtr = nullptr;			
	Mesh*		meshPtr = nullptr;				// Renderable shape
	Transform*	transformPtr = nullptr;

public:
	// Initialization
	ObjectManager(Mesh* inMesh, bool camera, bool collidable, bool renderable, const XMVECTOR& position = { 0, 0, 0, 1 }, const XMVECTOR& forward = { 0, 0, 1, 1 }, const XMVECTOR& up = { 0, 1, 0, 1 });

	// Clean Up
	~ObjectManager();

	// Accessors
	bool GetRenderable() { return renderable; }
	Collider* GetCollider() { return colliderPtr; }
	Mesh* GetMesh() { return meshPtr; }
	Transform* GetTransform() { return transformPtr; }
};

#endif