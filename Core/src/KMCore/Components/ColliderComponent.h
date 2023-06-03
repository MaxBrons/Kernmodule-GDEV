#pragma once
#include "../Core/Core.h"
#include "Component.h"
#include "TransformComponent.h"

namespace KMCore::Core
{
	class ColliderComponent : public Component
	{
	public:
		ColliderComponent() = default;
		ColliderComponent(TransformComponent* transform)
		{
			m_Transform = transform;
		}
		virtual ~ColliderComponent() = default;

		void OnStart() override {};
		void OnUpdate() override {};
		void OnDestroy() override {};

		bool IsColliding(const ColliderComponent& other)
		{
			bool left = GetBounds().x < other.GetBounds().z;
			bool right = GetBounds().z > other.GetBounds().x;
			bool bottom = GetBounds().w > other.GetBounds().y;
			bool top = GetBounds().y < other.GetBounds().w;

			if (left && right && top && bottom)
			{
				return true;
			}
			return false;
		}

		const inline Vector4 GetBounds() const
		{
			return Vector4(
				m_Transform->GetPosition().x + (m_Transform->GetSize().x * 0.1f),
				m_Transform->GetPosition().y + (m_Transform->GetSize().x * 0.1f),
				m_Transform->GetPosition().x + m_Transform->GetSize().x - (m_Transform->GetSize().x * 0.1f),
				m_Transform->GetPosition().y + m_Transform->GetSize().y - (m_Transform->GetSize().x * 0.1f)
			);
		}

	private:
		TransformComponent* m_Transform = nullptr;
	};
}