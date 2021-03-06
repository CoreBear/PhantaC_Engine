#ifndef _MESH_H
#define _MESH_H

// My Headers
#include <DirectXColors.h>
#include "GlobalDirectX.h"
#include "GlobalTypedefs.h"
#include "LineRenderer.h"

class Mesh
{
protected:
	float		depth;
	float		height;
	float		scale;
	float		width;
	ushort		reusableIterator;
	XMVECTORF32	color;

public:
	// Initialization
	Mesh(XMVECTORF32 inColor = Colors::White, float inDepth = 1, float inHeight =1 , float inWidth = 1, float inScale = 1) : depth(inDepth), height(inHeight), scale(inScale), width(inWidth), color(inColor) { return; }

	// Public Interface
	/// Summary
	/// This is how each line is uploaded into the renderer's lineRender
	///
	/// Parameters
	/// lineRenderer - The container that stores the lines that will be uploaded into vram
	virtual void AddMyLinesToRenderer(LineRenderer* lineRenderer) { return; }
	/// Summary
	/// Changes the mesh's color at runtime
	///
	/// Parameters
	/// inColor - The color that the mesh will be changed to
	void ChangeColor(XMVECTORF32 inColor) { if (inColor != color) color = inColor; }

	// Accessors
	float GetDepth() const { return depth; }
	float GetHeight() const { return height; }
	float GetScale() const { return scale; }
	float GetWidth() const { return width; }
};

#endif