#ifndef _SCENE_OBJECT_H
#define _SCENE_OBJECT_H

// System Headers
#include <vector>

// My Headers
#include "GlobalTypedefs.h"
#include "Camera.h"
#include "ColliderManager.h"
#include "Mesh.h"
#include "Transform.h"

// Forward Declarations
class ScriptManager;

class SceneObject
{
	bool						renderable;
	ColliderManager*			colliderManagerPtr = nullptr;			
	Mesh*						meshPtr = nullptr;				// Renderable shape
	Transform*					transformPtr = nullptr;
	uchar						objectIterator[2];
	uint						uniqueObjectID;
	static uint					idCounter;
	std::vector<SceneObject*>	myChildren;
	std::vector<ScriptManager*>	myScripts;


public:
	// Initialization
	SceneObject() { return; }
	SceneObject(Camera* camera);
	SceneObject(Mesh* inMesh, bool collidable, bool renderable, const XMVECTOR& position = { 0, 0, 0, 1 }, const XMVECTOR& forward = { 0, 0, 1, 1 }, const XMVECTOR& up = { 0, 1, 0, 1 });

	// Update
	void Update();

	// Clean Up
	~SceneObject();

	// Accessors
	bool GetRenderable() { return renderable; }
	ColliderManager* GetColliderManager() { return colliderManagerPtr; }
	Mesh* GetMesh() { return meshPtr; }
	Transform* GetTransform() { return transformPtr; }
	uint GetUniqueID() { return uniqueObjectID; }
	std::vector<SceneObject*>* GetMyChildren() { return &myChildren; }
	std::vector<ScriptManager*>* GetMyScripts() { return &myScripts; }
};

#endif