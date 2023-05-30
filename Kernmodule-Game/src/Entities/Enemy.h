#pragma once
#include "KMCore/Core/Application.h"
#include "KMCore/Entity/GameObject.h"
#include "KMCoreUtilities.h"
#include "KMCore/Components/ColliderComponent.h"

#include <iostream>

namespace KMCore::Entity
{
	class Enemy : public GameObject
	{
	public:
		Enemy(const std::string texturePath, const std::string& name = "New Enemy");
		virtual ~Enemy();

		virtual void OnStart() override;
		virtual void OnUpdate() override;

		virtual void Accelerate(float accelerationX, float accelerationY);

		inline float GetRandomValue(float maxValue)
		{
			return (rand() & static_cast<int>(maxValue * 100)) / 100.0f;
		}

		float MaxMovementSpeed = 5.0f;

		Core::ColliderComponent* collider = nullptr;

	private:
		Vector2 m_Velocity = { 0.0f, 0.0f };
		float m_Acceleration = 0.1f;

		Core::ColliderComponent* m_Collider = nullptr;
	};
}