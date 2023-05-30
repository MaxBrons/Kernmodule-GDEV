#pragma once
#include "KMCore/Core/Core.h"
#include "TransformComponent.h"

namespace KMCore::Core
{
	class RigidBodyComponent
	{
	public:
		RigidBodyComponent() = default;
		RigidBodyComponent(TransformComponent* transform)
		{
			m_Transform = transform;
		}
		virtual ~RigidBodyComponent() = default;

		void AddForce(Vector2 foce);

	private:
		TransformComponent* m_Transform = nullptr;
		Vector2 m_Velocity;
		float m_Mass;
		float m_Drag;
		float m_GravityScale;

	};
}
