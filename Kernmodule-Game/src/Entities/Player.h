#pragma once
#include "KMCore/Core/Application.h"
#include "KMCore/Entity/Sprite.h"
#include "KMCore/Components/ColliderComponent.h"
#include "KMCore/Components/RigidBodyComponent.h"

using namespace KMCore;
using namespace KMCore::Entity;

namespace KMGame::Entity
{
	class Player : public Sprite
	{
	public:
		Player() = default;
		Player(const std::string texturePath, const std::string& name = "Player");
		~Player() = default;

		void OnStart() override;
		void OnUpdate() override;
		void OnDestroy() override;

		inline void SetMovementBounds(Vector4 bounds) { m_MovementBounds = bounds; }

		Core::ColliderComponent* collider = nullptr;

	private:
		sf::RenderWindow* m_Window = nullptr;
		Vector4 m_MovementBounds;

		Core::ColliderComponent* m_Collider = nullptr;
		Core::RigidBodyComponent* m_RigidBody = nullptr;
	};
}