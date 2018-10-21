#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

// My Headers
#include "Agent.h"
#include "Audio.h"
#include "GlobalTypedefs.h"
#include "Physics.h"
#include "Scene.h"

// System Headers
#include <vector>

// Forward Declaration
class Camera;
class ObjectTransform;
class RenderableObject;

class SceneManager
{
	Audio							audio;					
	Camera*							cameraPtr;
	Physics							physics;				// Collisions and movement
	class Player*					playerPtr;
	Scene							scene;					// The actual running of the scene (game update. i.e. scene agents)
	std::vector<Agent*>				autonomousAgents;		// Objects that can move by themselves. Contents of this container are not visible, but their physical bodies may be in the "visibleSceneObjects" container
	std::vector<RenderableObject*>	visibleSceneObjects;	// Objects that can be seen

	// Private
	template<typename Generic> void AddObjectToContainer(std::vector<Generic>* container, Generic object) { container->push_back(object); }
	//void AddObjectToContainer(Agent* object) { autonomousAgents.push_back(object); }
	//void AddObjectToContainer2(RenderableObject* object) { visibleSceneObjects.push_back(object); }
	//template<typename Generic> void RemoveObjectFromContainer(std::vector<Generic>* container, Generic* object) { container->erase(std::remove(sceneObjects->begin(), container->end(), object), container->end()); }

public:
	// Initialization
	SceneManager(class InputController* inputController, ushort* clientDimensions);

	// Update
	void Update(float deltaTime);

	// Accessors
	Camera* GetCamera() { return (Camera*)autonomousAgents[0]->GetPhysicalBodyPtr(); }
	std::vector<RenderableObject*>* GetvisibleSceneObjects() { return &visibleSceneObjects; }
};

#endif