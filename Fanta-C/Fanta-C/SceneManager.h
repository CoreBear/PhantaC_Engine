#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

// My Headers
#include "Audio.h"
#include "GlobalTypedefs.h"
#include "PhysicsMain.h"
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
	PhysicsMain						physicsMain;			
	class Player*					playerPtr;
	Scene							scene;					// The actual running of the scene (game update. i.e. scene autonomousAgents)
	std::vector<Agent*>				autonomousAgents;		// Objects that can move. Contents of this container are not visible, but their physical bodies may be in the "visibleSceneObjects" container
	std::vector<Agent*>				staticAgents;			// Objects that can move. Contents of this container are not visible, but their physical bodies may be in the "visibleSceneObjects" container

public:
	// Initialization
	SceneManager(class InputManager* inputManager, ushort* clientDimensions);

	// Update
	void Update(float deltaTime);

	// Accessors
	Camera* GetCamera() { return cameraPtr; }
	std::vector<Agent*>* GetAutonomousAgents() { return &autonomousAgents; }
	std::vector<Agent*>* GetStaticAgents() { return &staticAgents; }
};

#endif