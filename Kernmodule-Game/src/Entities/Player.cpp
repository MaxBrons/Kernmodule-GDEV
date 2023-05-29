#include "kmpch.h"
#include "Player.h"

namespace KMCore::Entity
{
	Player::Player(const std::string texturePath, const std::string& name)
		:GameObject(texturePath, Core::Transform(), name)
	{
	}

	Player::~Player()
	{
		m_Window = nullptr;
	}

	void Player::OnStart()
	{
		BASE(OnStart);
		m_Window = Application::Get().GetWindow().GetRenderWindow();
		sf::Vector2f size = (sf::Vector2f)GetTexture()->getSize();
		transform->SetSize(size.x / 4, size.y / 4);
		transform->SetPosition((m_Window->getSize().x / 2.0f) - transform->GetSize().x/2, m_Window->getSize().y - (transform->GetSize().y * 1.1f));
	};

	void Player::OnUpdate()
	{
		BASE(OnUpdate);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_Velocity.x > -4.0f)
		{
			AccelerateX(-m_Acceleration);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && m_Velocity.x < 4.0f)
		{
			AccelerateX(m_Acceleration);
		}
		transform->Move(m_Velocity.x, 0.0f);
	};

	void Player::AccelerateX(float acceleration)
	{
		if (m_Velocity.x < m_MaxVelocity)
		{
			m_Velocity.x += acceleration;
		}
	}
}
