#ifndef _RENDERABLE_OBJECT_H
#define _RENDERABLE_OBJECT_H

// My Headers
#include "GlobalTypedefs.h"
#include "LineRenderer.h"
#include "Shape.h"

class RenderableObject
{
	Shape*		meshPtr;

public:	
	// Initialization
	RenderableObject(Shape* inShapePtr) : meshPtr(inShapePtr) { return; }

	// Public Interface
	void AddMeToLineRenderer(LineRenderer& lineRenderer) { meshPtr->AddMyLinesToRenderer(lineRenderer); }
};

#endif
