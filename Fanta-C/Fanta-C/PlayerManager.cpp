#pragma region Dependencies
// My Header
#include "PlayerManager.h"			// Connection to declarations

#include "BulletTrail.h"
#include "Camera.h"
#include "GlobalInputVariables.h"
#include "GlobalTransform.h"
#include "SceneGraph.h"
#include "SceneObject.h"
#pragma endregion

#pragma region Forward Declarations
PlayerManager* PlayerManager::playerManagerInstance = nullptr;
#pragma endregion

#pragma region Public Interface
void PlayerManager::Move(char x, char y, char z) { GlobalTransform::Translate(x * GlobalTime::deltaTime * velocity, y * GlobalTime::deltaTime * velocity, z * GlobalTime::deltaTime * velocity, *camera->GetViewMatrix()); }
void PlayerManager::Pitch(char angle) { GlobalTransform::RotateOnXAxis(angle * GlobalTime::deltaTime * angularVelocity, *camera->GetViewMatrix()); }
void PlayerManager::Roll(char angle) { GlobalTransform::RotateOnZAxis(angle * GlobalTime::deltaTime * angularVelocity, *camera->GetViewMatrix()); }
void PlayerManager::Shoot()
{
	// Hacked together shoot mechanic. Will remove
	// Create new trail
	bulletTrail = new SceneObject(new BulletTrail, false, true);

	// Color it and position it
	static_cast<BulletTrail*>(bulletTrail->GetMesh())->SetLineColor(&Colors::White);
	static_cast<BulletTrail*>(bulletTrail->GetMesh())->SetPositions(&XMVectorSet(camera->GetViewMatrix()->r[3].m128_f32[0], camera->GetViewMatrix()->r[3].m128_f32[1] - 1, camera->GetViewMatrix()->r[3].m128_f32[2], 
	camera->GetViewMatrix()->r[3].m128_f32[3]),	&XMVectorSet(camera->GetViewMatrix()->r[3].m128_f32[0] + camera->GetViewMatrix()->r[2].m128_f32[0] * trailDistance, camera->GetViewMatrix()->r[3].m128_f32[1] + camera->GetViewMatrix()->r[2].m128_f32[1] * trailDistance,
	camera->GetViewMatrix()->r[3].m128_f32[2] + camera->GetViewMatrix()->r[2].m128_f32[2] * trailDistance, camera->GetViewMatrix()->r[3].m128_f32[3]));

	// Add bullet trail to the scene for rendering and collision
	sceneGraphPtr->AddObjectToScene(bulletTrail);
}
void PlayerManager::Yaw(char angle) { GlobalTransform::RotateOnWorldYAxis(angle * GlobalTime::deltaTime * angularVelocity, *camera->GetViewMatrix()); }
#pragma endregion

#pragma region Accessors
PlayerManager * PlayerManager::GetInstance(Camera* inCamera, SceneGraph* sceneGraph, float inVelocity, float inAngularVelocity)
{
	// If instance is already created, return it
	if (playerManagerInstance) return playerManagerInstance;

	// If instance has not been created, create it and return it
	else
	{
		playerManagerInstance = new PlayerManager(inCamera, sceneGraph, inVelocity, inAngularVelocity);
		return playerManagerInstance;
	}
}
#pragma endregion