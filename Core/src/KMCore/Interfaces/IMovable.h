#pragma once
#include "KMCore/Components/TransformComponent.h"

namespace KMCore
{
	class IMovable
	{
	public:
		Core::TransformComponent* transform = nullptr;

		inline virtual const void SetSpeed(const Vector2& value) { m_Speed = value * Application::GlobalScaleMultiplier; };
		inline virtual const Vector2& GetSpeed() const { return m_Speed; }

	protected:
		Vector2 m_Speed = Vector2(1.0, 1.0f);
	};
}
