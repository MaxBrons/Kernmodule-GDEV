#include "kmpch.h"
#include "Enemy.h"

namespace KMCore::Entity
{
	Enemy::Enemy(const std::string texturePath, const std::string& name)
		:GameObject(texturePath, Core::Transform(), name)
	{
		OnStart();
	}

	void Enemy::OnStart()
	{
		BASE(OnStart);
		sf::Vector2f size = (sf::Vector2f)GetTexture()->getSize();
		transform->SetSize(size.x / 4, size.y / 4);
	}

	void Enemy::OnUpdate()
	{
		BASE(OnUpdate);
		transform->Move(m_Velocity.x, m_Velocity.y);
	}

	void Enemy::Accelerate(float accelerationX, float accelerationY)
	{
		if (m_Velocity.x < MaxMovementSpeed)
		{
			m_Velocity.x += accelerationX;
			m_Velocity.x = KMMathf::clamp(m_Velocity.x, 0.0f, MaxMovementSpeed);
		}

		if (m_Velocity.y < MaxMovementSpeed)
		{
			m_Velocity.y += accelerationY;
			m_Velocity.y = KMMathf::clamp(m_Velocity.y, 0.0f, MaxMovementSpeed);
		}
	}
}
