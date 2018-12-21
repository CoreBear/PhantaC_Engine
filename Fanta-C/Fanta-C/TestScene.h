#ifndef _TEST_SCENE_H
#define _TEST_SCENE_H

// My Header
#include "SceneGraph.h"

class TestScene : public SceneGraph
{

public:
	// Initialization
	TestScene(bool useGrid, ushort* clientDimensions);
};

#endif