#pragma once
#include "KMCore/Core/Application.h"
#include "KMCore/Entity/GameObject.h"
#include "KMCore/Components/ColliderComponent.h"

namespace KMCore::Entity
{
	class Player : public GameObject
	{
	public:
		Player() = default;
		Player(const std::string texturePath, const std::string& name = "Player");
		~Player();

		void OnStart() override;
		void OnUpdate() override;

		void AccelerateX(float acceleration);

		Core::ColliderComponent* collider = nullptr;

	private:
		Vector2 m_Velocity = { 0.0f, 0.0f };
		float m_MaxVelocity = 5.0f;
		float m_Acceleration = 0.1f;

		sf::RenderWindow* m_Window = nullptr;

		Core::ColliderComponent* m_Collider = nullptr;
	};
}