cbuffer PerApplication : register(b0)
{
	matrix projectionMatrix;
}

cbuffer PerFrame : register(b1)
{
	matrix viewMatrix;
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

	matrix viewProjMat = mul(projectionMatrix, viewMatrix);
	output.localPosHomo = float4(input.localPos, 1.0f);
	output.color = input.color;

	return output;
}