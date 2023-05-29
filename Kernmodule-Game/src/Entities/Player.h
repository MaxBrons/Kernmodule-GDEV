#pragma once
#include "KMCore.h"
#include "KMCore/Entity/GameObject.h"

namespace KMCore::Entity
{
	class Player : public GameObject
	{
	public:
		Player() = default;
		Player(const std::string texturePath, const std::string& name = "Player");
		virtual ~Player();

		virtual void OnStart() override;
		virtual void OnUpdate() override;

		virtual void AccelerateX(float acceleration);

	private:
		sf::Vector2f m_Velocity = { 0.0f, 0.0f };
		float m_MaxVelocity = 5.0f;
		float m_Acceleration = 0.1f;

		sf::RenderWindow* m_Window = nullptr;
	};
}