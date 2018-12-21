#ifndef _MESH_LOADER_H
#define _MESH_LOADER_H

// My Headers
#include "LineRenderer.h"
#include "Mesh.h"

class MeshLoader
{
public:
	void AddLinesToLineRenderer(LineRenderer* lineRenderer, Mesh* inMesh) { inMesh->AddMyLinesToRenderer(lineRenderer); }
};

#endif