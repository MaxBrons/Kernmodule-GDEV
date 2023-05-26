#pragma once
#include "KMCore/Entity/Object.h"

namespace KMCore::Entity
{
	class Player : public Object, public sf::RectangleShape
	{
	public:
		Player() = default;
		virtual ~Player() = default;

		// Inherited via Object
		virtual void OnStart() override {

		};

		virtual void OnUpdate() override {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_Velocity > -4.0f)
			{
				AccelerateX(-m_Acceleration);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && m_Velocity < 4.0f)
			{
				AccelerateX(m_Acceleration);
			}
			move({ m_Velocity, 0.0f });
		};

		virtual void AccelerateX(float acceleration) {
			if (m_Velocity < m_MaxVelocity) {
				m_Velocity += acceleration;
			}
		}

	private:
		float m_Velocity = 0.0f;
		float m_MaxVelocity = 5.0f;
		float m_Acceleration = 0.1f;
	};
}