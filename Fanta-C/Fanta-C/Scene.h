#ifndef _SCENE_H
#define _SCENE_H

// System Headers
#include <vector>

class Scene
{
public:
	// Update
	void Update(std::vector<class AutonomousAgent*>* agents);
};

#endif