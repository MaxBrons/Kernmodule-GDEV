#pragma once
#include "KMCore/Entity/Object.h"

namespace KMCore::Entity
{
	class Enemy : public Object, public sf::RectangleShape
	{
	public:
		Enemy() = default;
		virtual ~Enemy() = default;

		// Inherited via Object
		virtual void OnStart() override {
			m_Window = Application::Get().GetWindow().GetRenderWindow();
		};

		virtual void OnUpdate() override {
			AccelerateX(
				//static_cast<float>(rand() & static_cast<int>(2) - 1));
				0.1f
			);
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

		sf::RenderWindow* m_Window;
	};
}