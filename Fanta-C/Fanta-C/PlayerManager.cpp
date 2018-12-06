#pragma region Dependencies
// My Header
#include "PlayerManager.h"			// Connection to declarations

#include "BulletTrail.h"
#include "GlobalInputVariables.h"
#include "SceneGraph.h"
#pragma endregion

#pragma region Public Interface
void PlayerManager::Shoot()
{
	// Poorly hacked together
	bulletTrail = new ObjectManager(new BulletTrail, false, true);
	static_cast<BulletTrail*>(bulletTrail->GetMesh())->SetLineColor(&Colors::White);
	static_cast<BulletTrail*>(bulletTrail->GetMesh())->SetPositions(&camera->GetViewMatrix()->r[3], &XMVectorSet(camera->GetViewMatrix()->r[3].m128_f32[0] + camera->GetViewMatrix()->r[2].m128_f32[0] * 25,
																												camera->GetViewMatrix()->r[3].m128_f32[1] + camera->GetViewMatrix()->r[2].m128_f32[1] * 25,
																												camera->GetViewMatrix()->r[3].m128_f32[2] + camera->GetViewMatrix()->r[2].m128_f32[2] * 25, 
																												camera->GetViewMatrix()->r[3].m128_f32[3]));
	// Add bullet trail to the scene for rendering and collision
	sceneGraphPtr->AddObjectToScene(bulletTrail);
}
#pragma endregion
