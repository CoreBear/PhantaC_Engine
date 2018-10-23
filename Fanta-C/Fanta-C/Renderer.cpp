#pragma region Dependencies
// My Headers
#include "Renderer.h"				// Connection to declarations
#include "Agent.h"
#include "Camera.h"
#include "GlobalGeometry.h"
#include "GlobalApplication.h"
#include "SceneManager.h"

// System Headers
// DirectX Includes
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
#pragma endregion

#pragma region Initialization
Renderer::Renderer(HWND windowHandle, SceneManager* sceneManager, const ushort* clientDimensions, ushort targetFPS)
{
	#pragma region Device and swap chain
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
	swapChainDesc.BufferCount = 1;										// Number of buffers in swap chain
	swapChainDesc.BufferDesc.Width = clientDimensions[1];
	swapChainDesc.BufferDesc.Height = clientDimensions[0];
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = targetFPS;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;		// Describes surface usage and CPU access options for back buffer
	swapChainDesc.OutputWindow = windowHandle;
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
	for (iterators[0] = 0; iterators[0]  < CONSTANT_BUFFER_TYPE::COUNT; ++iterators[0])
	{
		D3D11_BUFFER_DESC constantBufferDesc;
		ZeroMemory(&constantBufferDesc, sizeof(D3D11_BUFFER_DESC));

		constantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		constantBufferDesc.ByteWidth = sizeof(XMMATRIX);
		constantBufferDesc.CPUAccessFlags = 0;
		constantBufferDesc.Usage = D3D11_USAGE_DEFAULT;

		device->CreateBuffer(&constantBufferDesc, nullptr, &constantBuffers[iterators[0]]);
	}

	// Vertex Buffer
	D3D11_BUFFER_DESC vertexBufferDesc;
	ZeroMemory(&vertexBufferDesc, sizeof(D3D11_BUFFER_DESC));
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.ByteWidth = sizeof(SIMPLE_VERTEX) * lineRenderer.GetContainerCapacity();
	vertexBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;

	device->CreateBuffer(&vertexBufferDesc, NULL, &vertexBuffers[VERTEX_BUFFER::DEFAULT]);
	#pragma endregion

	#pragma region Viewport
	// Initialize the viewport to occupy the entire client area (main camera's viewport)
	viewPort[VIEWPORT::DEFAULT].Width = static_cast<float>(clientDimensions[1]);
	viewPort[VIEWPORT::DEFAULT].Height = static_cast<float>(clientDimensions[0]);
	viewPort[VIEWPORT::DEFAULT].TopLeftX = 0.0f;
	viewPort[VIEWPORT::DEFAULT].TopLeftY = 0.0f;
	viewPort[VIEWPORT::DEFAULT].MinDepth = 0.0f;
	viewPort[VIEWPORT::DEFAULT].MaxDepth = 1.0f;
	#pragma endregion
	
	#pragma region Stencil
	// create depth-stencil buffer/state/view
	D3D11_TEXTURE2D_DESC depthStencilBufferDesc;
	D3D11_DEPTH_STENCIL_DESC depthStencilStateDesc;
	ZeroMemory(&depthStencilBufferDesc, sizeof(D3D11_TEXTURE2D_DESC));
	ZeroMemory(&depthStencilStateDesc, sizeof(D3D11_DEPTH_STENCIL_DESC));

	depthStencilBufferDesc.ArraySize = 1;							// Number of textures in array
	depthStencilBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;	// How to bind to pipeline
	depthStencilBufferDesc.CPUAccessFlags = 0;						// No CPU access required.
	depthStencilBufferDesc.Format = DXGI_FORMAT_D32_FLOAT;
	depthStencilBufferDesc.Width = clientDimensions[1];
	depthStencilBufferDesc.Height = clientDimensions[0];
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
	
	// Create vertex shader
	device->CreateVertexShader(BasicVertexShader, sizeof(BasicVertexShader), nullptr, &vertexShader[VERTEX_SHADER::DEFAULT]);
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
	deviceContext->UpdateSubresource(constantBuffers[CONSTANT_BUFFER_TYPE::APPLICATION], 0, nullptr, &sceneManager->GetCamera()->GetProjectionMatrix(), 0, 0);

	// Input Assembler
	deviceContext->IASetInputLayout(inputLayout[INPUT_LAYOUT::DEFAULT]);
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
	deviceContext->IASetVertexBuffers(0, 1, &vertexBuffers[VERTEX_BUFFER::DEFAULT], &vertexStride, &offset);

	// Vertex Shader
	deviceContext->VSSetShader(vertexShader[VERTEX_SHADER::DEFAULT], nullptr, 0);
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
#pragma endregion

#pragma region Public Interface
void Renderer::Update(std::vector<Agent*>* staticAgents, std::vector<Agent*>* autonomousAgents)
{
	// Reset color to black and set depth to max
	ResetScreen();

	// Load view matrix (camera's world matrix) into vram
	// If camera is not moving, we can set this during initialization
	deviceContext->UpdateSubresource(constantBuffers[CONSTANT_BUFFER_TYPE::FRAME], 0, nullptr, &autonomousAgents->at(0)->GetTransformPtr()->GetWorldMatrix(), 0, 0);

	//											Add anything you want to draw here
	// ------------------------------------------------------------------------------------------------------------------------------- 
	//
	// Look into multi-threading this
	// Skip over index 0, because of camera (it doesn't get "rendered")
	// Load objects into line renderer, then draw them

	#pragma region Draw Autonomous Agents
	for (renderIterator = 0; renderIterator < staticAgents->size(); ++renderIterator)
	{
		staticAgents->at(renderIterator)->GetRendererPtr()->AddMeToLineRenderer(lineRenderer);
		DrawLineRenders(staticAgents->at(renderIterator)->GetTransformPtr()->GetWorldMatrix());
	}
	#pragma endregion	

	#pragma region Draw Autonomous Agents
	// Camera's index is 0, so skip
	for (renderIterator = 1; renderIterator < autonomousAgents->size(); ++renderIterator)
	{
		autonomousAgents->at(renderIterator)->GetRendererPtr()->AddMeToLineRenderer(lineRenderer);
		DrawLineRenders(autonomousAgents->at(renderIterator)->GetTransformPtr()->GetWorldMatrix());
	}	
	#pragma endregion

	//											Don't add anything under here
	// --------------------------------------------------------------------------------------------------------------------------------
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
void Renderer::DrawLineRenders(const XMMATRIX& objectTransform)
{
	// Upload object's world matrix into vram
	deviceContext->UpdateSubresource(constantBuffers[CONSTANT_BUFFER_TYPE::OBJECT], 0, nullptr, &objectTransform, 0, 0);

	// Load lines into VRAM
	ZeroMemory(&resourceForVertBuffer, sizeof(resourceForVertBuffer));
	deviceContext->Map(vertexBuffers[VERTEX_BUFFER::DEFAULT], 0, D3D11_MAP_WRITE_DISCARD, NULL, &resourceForVertBuffer);
	memcpy(resourceForVertBuffer.pData, lineRenderer.GetAllVertices(), sizeof(SIMPLE_VERTEX) * lineRenderer.GetCurrentVertexCount());
	deviceContext->Unmap(vertexBuffers[VERTEX_BUFFER::DEFAULT], 0);
	
	// Render
	deviceContext->Draw(lineRenderer.GetCurrentVertexCount(), 0);

	// Remove all lines made by line renderer
	lineRenderer.ClearLines();
}
#pragma endregion

#pragma region Clean Up
Renderer::~Renderer()
{
	#pragma region Buffers
	ReleaseResource(constantBuffers[CONSTANT_BUFFER_TYPE::COUNT]);
	ReleaseResource(vertexBuffers[VERTEX_BUFFER::COUNT]);
	#pragma endregion

	#pragma region Layouts
	ReleaseResource(inputLayout[INPUT_LAYOUT::COUNT]);
	#pragma endregion

	#pragma region Shaders
	ReleaseResource(pixelShader[PIXEL_SHADER::COUNT]);
	ReleaseResource(vertexShader[VERTEX_SHADER::COUNT]);
	#pragma endregion

	#pragma region Misc
	ReleaseResource(depthStencilState[DEPTH_STENCIL_STATE::COUNT]);
	ReleaseResource(depthStencilView[DEPTH_STENCIL_VIEW::COUNT]);
	ReleaseResource(device);
	ReleaseResource(deviceContext);
	ReleaseResource(renderTargetView[RENDER_TARGET_VIEW::COUNT]);
	ReleaseResource(depthStencilBuffer[TEXTURE2D::COUNT]);
	ReleaseResource(swapChain);

	// How do vectors delete? Becase objectsTo... may need to be deleted
	#pragma endregion
}
template<typename Generic>
inline void Renderer::ReleaseResource(Generic& ptr)
{
	if (ptr != NULL)
	{
		ptr->Release();
		ptr = NULL;
	}
}
#pragma endregion