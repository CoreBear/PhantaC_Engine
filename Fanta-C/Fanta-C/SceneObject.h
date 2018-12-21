#ifndef _SCENE_OBJECT_H
#define _SCENE_OBJECT_H

// System Headers
#include <vector>

// My Headers
#include "GlobalTypedefs.h"
#include "ColliderManager.h"
#include "Mesh.h"
#include "MyVector.h"
#include "Transform.h"

// Forward Declarations
class SceneGraph;
class ScriptManager;
class Transform;

class SceneObject
{
	bool						active;
	bool						collidable;
	bool						logical;
	bool						renderable;
	ColliderManager*			colliderManagerPtr;
	Mesh*						meshPtr;			// Renderable shape
	//MyVector<SceneObject*>	myChildren;
	//MyVector<ScriptManager*>	myScripts;
	std::vector<SceneObject*>	myChildren;
	std::vector<ScriptManager*> myScripts;
	Transform*					transformPtr;
	uchar						objectIterator;
	uint						uniqueObjectID;
	static uint					idCounter;

public:
	// Initialization
	SceneObject(SceneObject* camera);
	SceneObject(Mesh* inMesh, bool inActive, bool inCollidable, bool inLogical, bool inRenderable, const XMVECTOR& position = { 0, 0, 0, 1 });

	// Update
	void Update();

	// Public Interface
	void AddScript(ScriptManager* script) { myScripts.push_back(script); }

	// Clean Up
	~SceneObject();

	// Accessors
	bool GetActive() { return active; }
	bool GetCollidable() { return collidable; }
	bool GetLogical() { return logical; }
	bool GetRenderable() { return renderable; }
	ColliderManager* GetColliderManager() { return colliderManagerPtr; }
	Mesh* GetMesh() { return meshPtr; }
	//MyVector<SceneObject*>* GetMyChildren() { return &myChildren; }
	//MyVector<ScriptManager*>* GetMyScripts() { return &myScripts; }
	std::vector<SceneObject*>* GetMyChildren() { return &myChildren; }
	std::vector<ScriptManager*>* GetMyScripts() { return &myScripts; }
	Transform* GetTransform() { return transformPtr; }
	uint GetUniqueID() { return uniqueObjectID; }

	// Mutators
	void SetActive(bool inActive) { active = inActive; }
	void SetLogical(bool inLogical) { logical = inLogical; }
	void SetCollidable(bool inCollidable) { collidable = inCollidable; }
	void SetRenderable(bool inRenderable) { renderable = inRenderable; }
};

#endif