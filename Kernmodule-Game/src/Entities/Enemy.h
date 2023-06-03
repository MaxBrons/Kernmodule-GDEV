#pragma once
#include "KMCore/Core/Application.h"
#include "KMCore/Entity/Sprite.h"
#include "KMCoreUtilities.h"
#include "KMCore/Components/ColliderComponent.h"
#include "KMCore/Components/RigidBodyComponent.h"

#include <iostream>

using namespace KMCore;
using namespace KMCore::Entity;

namespace KMGame::Entity
{
	class Enemy : public ::Sprite
	{
	public:
		Enemy(const std::string texturePath, const std::string& name = "New Enemy");
		virtual ~Enemy() = default;

		virtual void OnStart() override;
		virtual void OnUpdate() override;
		virtual void OnDestroy() override;

		inline void SetMovementBounds(Vector4 bounds) { m_MovementBounds = bounds; }

		Core::ColliderComponent* collider = nullptr;

	private:
		float m_RandomXDir = 0.0f;
		Vector4 m_MovementBounds;

		Core::ColliderComponent* m_Collider = nullptr;
		Core::RigidBodyComponent* m_RigidBody = nullptr;
	};
}