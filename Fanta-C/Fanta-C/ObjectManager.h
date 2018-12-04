#ifndef _OBJECT_MANAGER_H
#define _OBJECT_MANAGER_H

// My Headers
#include "GlobalTypedefs.h"
#include "Camera.h"
#include "ColliderManager.h"
#include "Mesh.h"
#include "Transform.h"

class ObjectManager
{
	bool				renderable;
	ColliderManager*	colliderManagerPtr = nullptr;			
	Mesh*				meshPtr = nullptr;				// Renderable shape
	Transform*			transformPtr = nullptr;
	uint				uniqueObjectID;
	static uint			idCounter;

public:
	// Initialization
	ObjectManager(Camera* camera);
	ObjectManager(Mesh* inMesh, bool collidable, bool renderable, const XMVECTOR& position = { 0, 0, 0, 1 }, const XMVECTOR& forward = { 0, 0, 1, 1 }, const XMVECTOR& up = { 0, 1, 0, 1 });

	// Clean Up
	~ObjectManager();

	// Accessors
	bool GetRenderable() { return renderable; }
	ColliderManager* GetColliderManager() { return colliderManagerPtr; }
	Mesh* GetMesh() { return meshPtr; }
	Transform* GetTransform() { return transformPtr; }
	uint GetUniqueID() { return uniqueObjectID; }
};

#endif