#ifndef _SCENE_OBJECT_H
#define _SCENE_OBJECT_H

// System Headers
#include <vector>

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class ObjectManager;
class ScriptManager;

class SceneObject
{
	// Variables
	ObjectManager*				object = nullptr;
	std::vector<SceneObject*>	myChildren;
	std::vector<ScriptManager*>	myScripts;
	uchar						objectIterator[2];

public:
	// Initialization
	SceneObject(ObjectManager* inObject) { object = inObject; }

	// Update
	void Update();

	// Accessors
	ObjectManager* GetMyObject() { return object; }
	std::vector<SceneObject*>* GetMyChildren() { return &myChildren; }
	std::vector<ScriptManager*>* GetMyScripts() { return &myScripts; }

	// Clean Up
	~SceneObject();
};

#endif