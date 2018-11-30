#ifndef _RENDERER_H
#define _RENDERER_H

// My Headers
#include "GlobalRendererStructures.h"
#include "GlobalTypedefs.h"
#include "LineRenderer.h"
#include "MeshLoader.h"

// System Headers
#include <d3d11.h>	
#include <vector>

// Forward Declarations
class Object;
class ObjectManager;

class Renderer
{
	// Misc Variables
	LineRenderer					lineRenderer;									// Object that renders lines on screen
	MeshLoader						meshLoader;										// Adds mesh lines to the line renderer
	ushort							renderIterator;									// Iterator for object rendering

	// Pipeline Variables
	const float						maxZBufferDepth = 1.0f;							// Self-explanatory
	const uchar						vSync = 0;										// 0 - vSync off. 1 - On
	const UINT						offset = 0;										// Offset of bytes between first element of vert buffer and first element that will be used
	const UINT						simpleVertexStride = sizeof(SIMPLE_VERTEX);		// Size (in bytes) of the elements that are to be used from that vertex buffer
	
	D3D11_MAPPED_SUBRESOURCE		resourceForVertBuffer;							// Resource for transferring information into vertex buffer
	D3D11_VIEWPORT					viewPort[VIEWPORT::COUNT];						// Index 0 - Main Camera. 1 - Rear View. Tells D3D11 what portion of the screen/surface to draw to (normally all of it)
	ID3D11Buffer*					constantBuffers[CONSTANT_BUFFER_TYPE::COUNT];	// Buffers used to update ram
	ID3D11Buffer*					vertexBuffers[VERTEX_BUFFER::COUNT];			// Buffers that store vertex infromation
	ID3D11DepthStencilState*		depthStencilState[DEPTH_STENCIL_STATE::COUNT];	// Store depth and stencil states used by OM stage
	ID3D11DepthStencilView*			depthStencilView[DEPTH_STENCIL_VIEW::COUNT];	// Depth buffer
	ID3D11Device*					device = nullptr;								// Loads resources onto the graphics card (geometry, textures, shaders, ...)
	ID3D11DeviceContext*			deviceContext = nullptr;						// Sends commands directly to graphics card. Chooses buffers, topology, shaders, and draws
	ID3D11InputLayout*				inputLayout[INPUT_LAYOUT::COUNT];				// Describe the order and type of data that is expected by the vertex shader
	ID3D11PixelShader*				pixelShader[PIXEL_SHADER::COUNT];				// Stores a reference to the pixel shader
	ID3D11RenderTargetView*			renderTargetView[RENDER_TARGET_VIEW::COUNT];	// D3D connection to backbuffer or any drawable surface
	ID3D11Texture2D*				depthStencilBuffer[TEXTURE2D::COUNT];			// Texture to associate to the depth stencil view
	ID3D11VertexShader*				vertexShader[VERTEX_SHADER::COUNT];				// Stores a reference to the vertex shader
	IDXGISwapChain*					swapChain = nullptr;							// Communicates with windows and manages drawing area (2 buffers)
	
	// Private
	void ResetScreen();
	void DrawLines(ObjectManager* object);

	// Clean Up
	template<typename Generic> void ReleaseResource(Generic& ptr);

public:
	// Initialization
	Renderer(HWND windowHandle, class SceneManager* sceneManagerPtr, const ushort* clientDimensions, ushort targetFPS, ObjectManager* cameraObject);

	// Update
	void Update(std::vector<ObjectManager*>* renderableObjects, ObjectManager* cameraObject);

	// Clean-up
	~Renderer();
};

#endif