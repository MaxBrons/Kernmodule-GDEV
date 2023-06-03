#include "kmpch.h"
#include "Player.h"

namespace KMGame::Entity
{
	Player::Player(const std::string texturePath, const std::string& name)
		:Sprite(texturePath, Core::Transform(), name)
	{
		m_Collider = new Core::ColliderComponent(transform);
		collider = m_Collider;

		m_RigidBody = new Core::RigidBodyComponent();
	}

	void Player::OnStart()
	{
		BASE(OnStart());
		m_Window = Application::Get().GetWindow().GetRenderWindow();
		Vector2 size = (Vector2)GetTexture()->getSize();
		size /= 2.0f;

		transform->SetSize(size.x, size.y);
		transform->SetPosition((WINDOW_WIDTH_REF / 2.0f) - transform->GetSize().x / 2, WINDOW_HEIGHT_REF - (transform->GetSize().y * 1.1f));

		AddComponent(m_RigidBody);
		AddComponent(m_Collider);
	};

	void Player::OnUpdate()
	{
		BASE(OnUpdate());

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			m_RigidBody->AddForce(Vector2::left * m_Speed.x);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			m_RigidBody->AddForce(Vector2::right * m_Speed.x);

		m_RigidBody->OnUpdate();

		if (collider->GetBounds().x < m_MovementBounds.x && m_RigidBody->GetVelocity().x < 0.0f || 
			collider->GetBounds().z > m_MovementBounds.z && m_RigidBody->GetVelocity().x > 0.0f)
		{
			m_RigidBody->SetVelocity(Vector2::zero);
		}

		transform->Move(m_RigidBody->GetVelocity().x, m_RigidBody->GetVelocity().y);
	}

	void Player::OnDestroy()
	{
		BASE(OnDestroy());
		delete m_Collider;
		delete m_RigidBody;
	}
}
