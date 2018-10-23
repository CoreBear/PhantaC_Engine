#ifndef _MESH_H
#define _MESH_H

class Mesh
{
public: 
	// Public Interface
	virtual void DrawMe(LineRenderer& lineRenderer) { return; }
};

#endif