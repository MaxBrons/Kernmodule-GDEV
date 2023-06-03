#include "kmpch.h"
#include "Enemy.h"

namespace KMGame::Entity
{
	Enemy::Enemy(const std::string texturePath, const std::string& name)
		:Sprite(texturePath, Core::Transform(), name)
	{
		m_Collider = new Core::ColliderComponent(transform);
		collider = m_Collider;

		m_RigidBody = new Core::RigidBodyComponent();

		m_RandomXDir = GetRandomValue(1) >= 0.5f ? 1 : -1;

		AddComponent(m_RigidBody);
		AddComponent(m_Collider);
	}

	void Enemy::OnStart()
	{
		BASE(OnStart());

		Vector2 size = (Vector2)GetTexture()->getSize();
		size /= 2.0f;

		transform->SetSize(size.x, size.y);
	}

	void Enemy::OnUpdate()
	{
		BASE(OnUpdate());
		m_RigidBody->AddForce(Vector2(m_RandomXDir * m_Speed.x, m_Speed.y));

		if (((collider->GetBounds().x < m_MovementBounds.x) && m_RigidBody->GetVelocity().x < 0.0f) ||
			((collider->GetBounds().z > m_MovementBounds.z) && m_RigidBody->GetVelocity().x > 0.0f))
		{
			m_RigidBody->GetVelocity().x *= -0.1f;
			m_RandomXDir *= -1;
		}

		if (transform->GetPosition().y > m_MovementBounds.w)
			enabled = false;

		m_RigidBody->OnUpdate();
		transform->Move(m_RigidBody->GetVelocity().x, m_RigidBody->GetVelocity().y);
	}

	void Enemy::OnDestroy()
	{
		BASE(OnDestroy());
		delete m_Collider;
	}
}
