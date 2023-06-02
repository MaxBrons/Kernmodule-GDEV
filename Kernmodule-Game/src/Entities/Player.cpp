#include "kmpch.h"
#include "Player.h"

namespace KMCore::Entity
{
	Player::Player(const std::string texturePath, const std::string& name)
		:Sprite(texturePath, Core::Transform(), name)
	{
		m_Collider = new Core::ColliderComponent(transform);
		collider = m_Collider;

		m_RigidBody = new Core::RigidBodyComponent(transform);
		m_RigidBody->Mass = 200.0f;
	}

	void Player::OnStart()
	{
		BASE(OnStart());
		m_Window = Application::Get().GetWindow().GetRenderWindow();
		Vector2 size = (Vector2)GetTexture()->getSize() * Application::GlobalScaleMultiplier;
		size /= 2.0f;

		transform->SetSize(size.x, size.y); 
		transform->SetPosition((m_Window->getSize().x / 2.0f) - transform->GetSize().x / 2, m_Window->getSize().y - (transform->GetSize().y * 1.1f));
		AddComponent(m_RigidBody);
		AddComponent(m_Collider);
	};

	void Player::OnUpdate()
	{
		BASE(OnUpdate());

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			m_RigidBody->AddForce(Vector2::left);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			m_RigidBody->AddForce(Vector2::right);

		if (((collider->GetBounds().x < m_MovementBounds.x) && m_RigidBody->Velocity.x < 0.0f) || ((collider->GetBounds().z > m_MovementBounds.z) && m_RigidBody->Velocity.x > 0.0f))
			m_RigidBody->Velocity = Vector2::zero;
		m_RigidBody->OnUpdate();
	}

	void Player::OnDestroy()
	{
		BASE(OnDestroy());
		delete m_Collider;
		delete m_RigidBody;
	}
}
