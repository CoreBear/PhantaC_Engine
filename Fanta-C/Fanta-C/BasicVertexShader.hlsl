cbuffer PerApplication : register(b0)
{
	matrix projectionMatrix;
}

cbuffer PerFrame : register(b1)
{
	matrix viewMatrix;
}

cbuffer PerObject : register(b2)
{
	matrix worldMatrix;
}

struct Input
{
	float3 localPos : POSITION;
	float4 color : COLOR;
};
struct Output
{
	float4 color : COLOR;
	float4 localPosHomo : SV_POSITION;
};
Output main(Input input)
{
	Output output;

	matrix viewProjMat = mul(projectionMatrix, mul(viewMatrix, worldMatrix));
	output.localPosHomo = mul(viewProjMat, float4(input.localPos, 1.0f));
	output.color = input.color;

	return output;
}