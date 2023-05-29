#pragma once
#include "KMCore.h"
#include "KMCore/Entity/GameObject.h"
#include "KMCoreUtilities.h"
#include <iostream>

namespace KMCore::Entity
{
	class Enemy : public GameObject
	{
	public:
		Enemy(const std::string texturePath, const std::string& name = "New Enemy");
		virtual ~Enemy() = default;

		virtual void OnStart() override;
		virtual void OnUpdate() override;

		virtual void Accelerate(float accelerationX, float accelerationY);

		inline float GetRandomValue(float maxValue)
		{
			return (rand() & static_cast<int>(maxValue * 100)) / 100.0f;
		}

		float MaxMovementSpeed = 5.0f;

	private:
		sf::Vector2f m_Velocity = { 0.0f, 0.0f };
		float m_Acceleration = 0.1f;
	};
}