#pragma region Dependencies
// My Headers
#include "Renderer.h"				// Connection to declarations

#include "Camera.h"
#include "GlobalMath.h"
#include "GlobalVramStructures.h"
#include "LineRenderer.h"
#include "Mesh.h"
#include "Pooler.h"
#include "SceneGraph.h"
#include "SceneManager.h"
#include "SceneObject.h"
#include "UiManager.h"

// System Headers
#include <d3dcompiler.h>			// Required for loading and compiling HLSL shaders

// Link Library Dependencies	
// Automatically linked in linker stage
// Can specify in "Additional Dependencies" in linker options
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "winmm.lib")

// Shaders
#include "BasicPixelShader.csh"
#include "BasicVertexShader.csh"
#include "UiVertexShader.csh"
#pragma endregion

#pragma region Forward Declarations
Renderer* Renderer::rendererInstance = nullptr;
#pragma endregion

#pragma region Initialization
Renderer::Renderer(Application_Level::WindowCreator* window, SceneManager* sceneManagerPtr, uchar targetFPS) : cameraPtr(&sceneManagerPtr->GetScenePtr()->GetCamera()), lineRenderer(LineRenderer::GetInstance()), uiManagerPtr(UiManager::GetInstance(this))
{
	#pragma region Device and swap chain
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
	swapChainDesc.BufferCount = 1;										// Number of buffers in swap chain
	swapChainDesc.BufferDesc.Width = window->GetClientDimensions()[1];
	swapChainDesc.BufferDesc.Height = window->GetClientDimensions()[0];
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = targetFPS;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;		// Describes surface usage and CPU access options for back buffer
	swapChainDesc.OutputWindow = *window->GetWindowHandle();
	swapChainDesc.SampleDesc.Count = 1;									// Number of multisamples per pixel
	swapChainDesc.SampleDesc.Quality = 0;								// Image quality level
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;				// Discards the back buffer info when swapped
	swapChainDesc.Windowed = TRUE;

	UINT createDeviceFlags = 0;
	#if _DEBUG
	createDeviceFlags = D3D11_CREATE_DEVICE_DEBUG;
	#endif

	// These are the feature levels that we will accept.
	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1
	};

	// This will be the feature level that 
	// is used to create our device and swap chain.
	D3D_FEATURE_LEVEL featureLevel;

	HRESULT hr = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE,
		nullptr, createDeviceFlags, featureLevels, _ARRAYSIZE(featureLevels),
		D3D11_SDK_VERSION, &swapChainDesc, &swapChain, &device, &featureLevel,
		&deviceContext);

	if (hr == E_INVALIDARG)
	{
		D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE,
		nullptr, createDeviceFlags, &featureLevels[1], _ARRAYSIZE(featureLevels) - 1,
		D3D11_SDK_VERSION, &swapChainDesc, &swapChain, &device, &featureLevel,
		&deviceContext);
	}
	#pragma endregion

	#pragma region Buffers
	// Initialize the back buffer of the swap chain and associate it to a render target view
	ID3D11Texture2D* backBuffer;
	swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);

	// Nullptr, because the entire buffer is the view
	device->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView[RENDER_TARGET_VIEW::DEFAULT]);

	ReleaseResource(backBuffer);

	// Constant Buffers
	for (uchar i = 0; i < CONSTANT_BUFFER_TYPE::COUNT; ++i)
	{
		D3D11_BUFFER_DESC constantBufferDesc;
		ZeroMemory(&constantBufferDesc, sizeof(D3D11_BUFFER_DESC));

		constantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		constantBufferDesc.ByteWidth = sizeof(XMMATRIX);
		constantBufferDesc.CPUAccessFlags = 0;
		constantBufferDesc.Usage = D3D11_USAGE_DEFAULT;

		device->CreateBuffer(&constantBufferDesc, nullptr, &constantBuffers[i]);
	}

	// Vertex Buffer
	D3D11_BUFFER_DESC vertexBufferDesc;
	ZeroMemory(&vertexBufferDesc, sizeof(D3D11_BUFFER_DESC));
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.ByteWidth = sizeof(SIMPLE_VERTEX) * lineRenderer->GetContainerCapacity();
	vertexBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;

	device->CreateBuffer(&vertexBufferDesc, NULL, &vertexBuffers[VERTEX_BUFFER::DEFAULT]);
	#pragma endregion

	#pragma region Viewport
	// Initialize the viewport to occupy the entire client area (main camera's viewport)
	viewPort[VIEWPORT::DEFAULT].Width = static_cast<float>(window->GetClientDimensions()[1]);
	viewPort[VIEWPORT::DEFAULT].Height = static_cast<float>(window->GetClientDimensions()[0]);
	viewPort[VIEWPORT::DEFAULT].TopLeftX = 0.0f;
	viewPort[VIEWPORT::DEFAULT].TopLeftY = 0.0f;
	viewPort[VIEWPORT::DEFAULT].MinDepth = 0.0f;
	viewPort[VIEWPORT::DEFAULT].MaxDepth = 1.0f;
	#pragma endregion
	
	#pragma region Stencil
	// Create depth-stencil buffer/state/view
	D3D11_TEXTURE2D_DESC depthStencilBufferDesc;
	D3D11_DEPTH_STENCIL_DESC depthStencilStateDesc;
	ZeroMemory(&depthStencilBufferDesc, sizeof(D3D11_TEXTURE2D_DESC));
	ZeroMemory(&depthStencilStateDesc, sizeof(D3D11_DEPTH_STENCIL_DESC));

	depthStencilBufferDesc.ArraySize = 1;							// Number of textures in array
	depthStencilBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;	// How to bind to pipeline
	depthStencilBufferDesc.CPUAccessFlags = 0;						// No CPU access required.
	depthStencilBufferDesc.Format = DXGI_FORMAT_D32_FLOAT;
	depthStencilBufferDesc.Width = window->GetClientDimensions()[1];
	depthStencilBufferDesc.Height = window->GetClientDimensions()[0];
	depthStencilBufferDesc.MipLevels = 1;							// Max mip levels in the texture
	depthStencilBufferDesc.SampleDesc.Count = 1;					// Match with swapChain's value
	depthStencilBufferDesc.SampleDesc.Quality = 0;					// Match with swapChain's value
	depthStencilBufferDesc.Usage = D3D11_USAGE_DEFAULT;				// ID's how the texture is to be read from and written to

	device->CreateTexture2D(&depthStencilBufferDesc, nullptr, &depthStencilBuffer[TEXTURE2D::DEFAULT]);
	device->CreateDepthStencilView(depthStencilBuffer[TEXTURE2D::DEFAULT], nullptr, &depthStencilView[DEPTH_STENCIL_VIEW::DEFAULT]);

	depthStencilStateDesc.DepthEnable = TRUE;							// Depth testing
	depthStencilStateDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;	// Identify a portion of depth stencil buffer that can be modified by depth data
	depthStencilStateDesc.DepthFunc = D3D11_COMPARISON_LESS;			// Compares depth data against existing depth data
	depthStencilStateDesc.StencilEnable = FALSE;						// Stencil testing

	device->CreateDepthStencilState(&depthStencilStateDesc, &depthStencilState[DEPTH_STENCIL_STATE::DEFAULT]);
	#pragma endregion
	
	#pragma region Shaders
	// Create pixel shader
	device->CreatePixelShader(BasicPixelShader, sizeof(BasicPixelShader), nullptr, &pixelShader[PIXEL_SHADER::DEFAULT]);
	
	// Create vertex shaders
	device->CreateVertexShader(BasicVertexShader, sizeof(BasicVertexShader), nullptr, &vertexShader[VERTEX_SHADER::BASIC]);
	device->CreateVertexShader(UiVertexShader, sizeof(UiVertexShader), nullptr, &vertexShader[VERTEX_SHADER::UI]);
	#pragma endregion
	
	#pragma region Input Layout
	D3D11_INPUT_ELEMENT_DESC basicInputLayoutDesc[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, offsetof(SIMPLE_VERTEX,localPos), D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, offsetof(SIMPLE_VERTEX,color), D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	device->CreateInputLayout(basicInputLayoutDesc, ARRAYSIZE(basicInputLayoutDesc), BasicVertexShader, sizeof(BasicVertexShader), &inputLayout[INPUT_LAYOUT::DEFAULT]);
	#pragma endregion

	#pragma region Consistant Pipeline Pieces (Will be changed in the future)
	// Resources
	deviceContext->UpdateSubresource(constantBuffers[CONSTANT_BUFFER_TYPE::APPLICATION], 0, nullptr, cameraPtr->GetProjectionMatrix(), 0, 0);

	// Input Assembler
	deviceContext->IASetInputLayout(inputLayout[INPUT_LAYOUT::DEFAULT]);
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
	deviceContext->IASetVertexBuffers(0, 1, &vertexBuffers[VERTEX_BUFFER::DEFAULT], &simpleVertexStride, &offset);

	// Vertex Shader
	deviceContext->VSSetConstantBuffers(0, CONSTANT_BUFFER_TYPE::COUNT, constantBuffers);

	// Rasterizer Stage
	deviceContext->RSSetViewports(1, &viewPort[VIEWPORT::DEFAULT]);

	// Pixel Shader
	deviceContext->PSSetShader(pixelShader[PIXEL_SHADER::DEFAULT], nullptr, 0);

	// Output Merger
	deviceContext->OMSetRenderTargets(1, &renderTargetView[RENDER_TARGET_VIEW::DEFAULT], depthStencilView[DEPTH_STENCIL_VIEW::DEFAULT]);
	deviceContext->OMSetDepthStencilState(depthStencilState[DEPTH_STENCIL_STATE::DEFAULT], 1);
	#pragma endregion
}
Renderer* Renderer::GetInstance(Application_Level::WindowCreator* window, SceneManager* sceneManagerPtr, uchar targetFPS)
{
	// If instance is already created, return it
	if (rendererInstance) return rendererInstance;

	// If instance has not been created, create it and return it
	else
	{
		rendererInstance = new Renderer(window, sceneManagerPtr, targetFPS);
		return rendererInstance;
	}
}
#pragma endregion

#pragma region Public Interface
void Renderer::DrawDebug()
{
	// Reset color to black and set depth to max
	ResetScreen();

	// Set vertex shader for 3D
	deviceContext->VSSetShader(vertexShader[VERTEX_SHADER::BASIC], nullptr, 0);

	// Load view matrix (camera's world matrix) into vram
	deviceContext->UpdateSubresource(constantBuffers[CONSTANT_BUFFER_TYPE::FRAME], 0, nullptr, &XMMatrixInverse(nullptr, *cameraPtr->GetViewMatrix()), 0, 0);

	//
	//											Do not add anything above this line
	// ------------------------------------------------------------------------------------------------------------------------------- 
	//											Add anything you want to draw below this line
	//	

	// For each renderable objct, pass it to draw lines
	for (renderIterator = 0; renderIterator < Pooler::activeObjects.GetSize(); ++renderIterator)
	{
		if (Pooler::activeObjects.At(renderIterator)->GetRenderable())
			DrawLines(Pooler::activeObjects.At(renderIterator));
	}
	
	//
	//											Add anything you want to draw above this line
	// --------------------------------------------------------------------------------------------------------------------------------
	//											Do not add anything below this line
	//
}
void Renderer::DrawUI()
{
	// Set vertex shader for UI
	deviceContext->VSSetShader(vertexShader[VERTEX_SHADER::UI], nullptr, 0);

	//
	//											Do not add anything above this line
	// ------------------------------------------------------------------------------------------------------------------------------- 
	//											Add anything you want to draw below this line
	//	

	// Draw UI element
	DrawLines(uiManagerPtr->GetReticle());

	//
	//											Add anything you want to draw above this line
	// --------------------------------------------------------------------------------------------------------------------------------
	//											Do not add anything below this line
	//

	// Show frame to user
	swapChain->Present(vSync, 0);
}
#pragma endregion

#pragma region Private
void Renderer::ResetScreen()
{
	deviceContext->ClearRenderTargetView(renderTargetView[RENDER_TARGET_VIEW::DEFAULT], DirectX::Colors::Black);
	deviceContext->ClearDepthStencilView(depthStencilView[DEPTH_STENCIL_VIEW::DEFAULT], D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, maxZBufferDepth, 0);
}
void Renderer::DrawLines(Mesh* mesh)
{
	// Load mesh into line renderer
	meshLoader.AddLinesToLineRenderer(lineRenderer, mesh);

	// Load lines into VRAM
	ZeroMemory(&resourceForVertBuffer, sizeof(resourceForVertBuffer));
	deviceContext->Map(vertexBuffers[VERTEX_BUFFER::DEFAULT], 0, D3D11_MAP_WRITE_DISCARD, NULL, &resourceForVertBuffer);
	memcpy(resourceForVertBuffer.pData, lineRenderer->GetAllVertices(), sizeof(SIMPLE_VERTEX) * lineRenderer->GetCurrentVertexCount());
	deviceContext->Unmap(vertexBuffers[VERTEX_BUFFER::DEFAULT], 0);

	// Render
	deviceContext->Draw(lineRenderer->GetCurrentVertexCount(), 0);

	// Remove all lines made by line rendererPtr
	lineRenderer->ClearLines();
}
void Renderer::DrawLines(SceneObject* object)
{
	// Load mesh into line renderer
	meshLoader.AddLinesToLineRenderer(lineRenderer, object->GetMesh());

	// Upload object's world matrix into vram
	deviceContext->UpdateSubresource(constantBuffers[CONSTANT_BUFFER_TYPE::OBJECT], 0, nullptr, object->GetTransform()->GetLocalMatrix(), 0, 0);

	// Load lines into VRAM
	ZeroMemory(&resourceForVertBuffer, sizeof(resourceForVertBuffer));
	deviceContext->Map(vertexBuffers[VERTEX_BUFFER::DEFAULT], 0, D3D11_MAP_WRITE_DISCARD, NULL, &resourceForVertBuffer);
	memcpy(resourceForVertBuffer.pData, lineRenderer->GetAllVertices(), sizeof(SIMPLE_VERTEX) * lineRenderer->GetCurrentVertexCount());
	deviceContext->Unmap(vertexBuffers[VERTEX_BUFFER::DEFAULT], 0);
	
	// Render
	deviceContext->Draw(lineRenderer->GetCurrentVertexCount(), 0);

	// Remove all lines made by line rendererPtr
	lineRenderer->ClearLines();
}
#pragma endregion

#pragma region Clean Up
Renderer::~Renderer()
{
	// Reusable for iteration
	uchar i;

	#pragma region Buffers
	for (i = 0; i < CONSTANT_BUFFER_TYPE::COUNT; ++i)
		ReleaseResource(constantBuffers[i]);

	for (i = 0; i < VERTEX_BUFFER::COUNT; ++i)
		ReleaseResource(vertexBuffers[i]);
	#pragma endregion

	#pragma region Layouts
	for (i = 0; i < INPUT_LAYOUT::COUNT; ++i)
		ReleaseResource(inputLayout[i]);
	#pragma endregion

	#pragma region Shaders
	for (i = 0; i < PIXEL_SHADER::COUNT; ++i)
		ReleaseResource(pixelShader[i]);

	for (i = 0; i < VERTEX_SHADER::COUNT; ++i)
		ReleaseResource(vertexShader[i]);
	#pragma endregion

	#pragma region Misc
	for (i = 0; i < DEPTH_STENCIL_STATE::COUNT; ++i)
		ReleaseResource(depthStencilState[i]);

	for (i = 0; i < DEPTH_STENCIL_VIEW::COUNT; ++i)
		ReleaseResource(depthStencilView[i]);

	for (i = 0; i < RENDER_TARGET_VIEW::COUNT; ++i)
		ReleaseResource(renderTargetView[i]);

	for (i = 0; i < TEXTURE2D::COUNT; ++i)
		ReleaseResource(depthStencilBuffer[i]);
	
	ReleaseResource(device);
	ReleaseResource(deviceContext);
	ReleaseResource(swapChain);

	delete lineRenderer;
	#pragma endregion
}
template<typename Generic> 
void Renderer::ReleaseResource(Generic& ptr)
{
	if (ptr != NULL)
	{
		ptr->Release();
		ptr = NULL;
	}
}
#pragma endregion