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
		RigidBodyComponent(TransformComponent* transform)
		{
			m_Transform = transform;
		}
		virtual ~RigidBodyComponent() = default;

		void AddForce(const Vector2 direction)
		{
			Vector2::Clamp(Velocity += ((direction * Acceleration) / Mass) * Application::GlobalScaleMultiplier, -MaxVelocity, MaxVelocity);
		}

		void OnUpdate() override
		{
			Velocity *= Drag;
			if (KMMathf::abs(Velocity.x) < MinVelocity)
				Velocity.x = 0.0f;
			if (KMMathf::abs(Velocity.y) < MinVelocity)
				Velocity.y = 0.0f;

			m_Transform->Move(Velocity.x, Velocity.y);
		}

		Vector2 Velocity;
		float MinVelocity = 0.1f;
		float MaxVelocity = 250.0f;
		float Acceleration = 100.0f;
		float Mass = 300.0f;
		float Drag = 0.93f;

	private:
		TransformComponent* m_Transform = nullptr;
	};
}
