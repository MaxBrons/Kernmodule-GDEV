#pragma once
#include "KMCore/Core/Core.h"
#include "KMCore/Core/Application.h"
#include "KMCoreUtilities.h"
#include "Component.h"
#include "TransformComponent.h"

namespace KMCore::Core
{
	class RigidBodyComponent : public Component
	{
	public:
		RigidBodyComponent() = default;
		virtual ~RigidBodyComponent() = default;

		void OnStart() override {};
		void OnDestroy() override {};

		inline void AddForce(const Vector2 force)
		{
			m_Force = force;
		}

		void OnUpdate() override
		{
			float dt = (1.0f / 60.0f);
			m_Acceleration.x = (m_Force.x * m_Friction.x) / m_Mass;
			m_Acceleration.y = (m_Force.y  * m_Friction.y) / m_Mass;
			m_Velocity += m_Acceleration * dt;
			m_Velocity *= m_Drag;

			if (KMMathf::abs(m_Velocity.x) < 0.01f && KMMathf::abs(m_Velocity.y) < 0.01f)
				m_Velocity = Vector2::zero;

			m_Force = Vector2::zero;
		}

		inline float& GetMass() { return m_Mass; }
		inline float& GetDrag() { return m_Drag; }
		inline Vector2& GetVelocity() { return m_Velocity; }

		inline const void SetMass(float value) { m_Mass = value; }
		inline const void SetDrag(float value) { m_Drag = value; }
		inline const void SetVelocity(const Vector2& value) { m_Velocity = value; }

	private:
		float m_Mass =			 1.0f;
		float m_Drag =			 0.93f;
		Vector2 m_Force =		 Vector2(0.0f, 0.0f);
		Vector2 m_Friction =	 Vector2(1.0f, 1.0f);
		Vector2 m_Velocity =	 Vector2::zero;
		Vector2 m_Acceleration = Vector2::zero;
	};
}
