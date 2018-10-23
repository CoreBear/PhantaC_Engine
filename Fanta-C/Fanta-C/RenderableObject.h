#ifndef _RENDERABLE_OBJECT_H
#define _RENDERABLE_OBJECT_H

// My Headers
#include "GlobalTypedefs.h"
#include "LineRenderer.h"
#include "Mesh.h"

class RenderableObject
{
	Mesh*		meshPtr;

public:	
	// Initialization
	RenderableObject(Mesh* inMeshPtr) : meshPtr(inMeshPtr) { return; }

	// Public Interface
	void AddMeToLineRenderer(LineRenderer& lineRenderer) { meshPtr->DrawMe(lineRenderer); }
};

#endif
