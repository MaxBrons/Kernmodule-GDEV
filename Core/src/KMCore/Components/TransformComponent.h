#pragma once
#include "KMCore/Core/Core.h"
#include "KMCore/Core/Application.h"
#include "Component.h"

namespace KMCore::Core
{
	struct Transform
	{
	public:
		Vector2 position;
		float	rotation;
		Vector2 size;
		Vector2 scale;

		Transform(Vector2 position = Vector2(), float rotation = 0.0f, Vector2 size = Vector2(), Vector2 scale = Vector2(1.0f, 1.0f))
			: position(position), rotation(rotation), size(size), scale(scale)
		{
		}
	};

	class TransformComponent : public Component
	{
	public:
		TransformComponent() = default;
		TransformComponent(sf::RectangleShape* shape)
		{
			m_Shape = shape;
		}
		TransformComponent(sf::RectangleShape* shape, Vector2 position, float rotation, Vector2 size, Vector2 scale = Vector2(1.0f, 1.0f))
		{
			m_Shape = shape;
			SetPosition(position.x, position.y);
			SetRotation(rotation);
			SetSize(size.x, size.y);
			SetScale(scale.x, scale.y);
		}
		TransformComponent(sf::RectangleShape* shape, const Transform& transform)
		{
			m_Shape = shape;
			SetPosition(transform.position.x, transform.position.y);
			SetRotation(transform.rotation);
			SetSize(transform.size.x, transform.size.y);
			SetScale(transform.scale.x, transform.scale.y);
		}

		virtual ~TransformComponent() = default;

		void OnStart() override {};
		void OnUpdate() override {};
		void OnDestroy() override {};

		const inline void Move(float x, float y) { m_Shape->move(sf::Vector2f(x, y)); }

		const inline void SetPosition(float x, float y) { m_Shape->setPosition(sf::Vector2f(x, y)); }
		const inline Vector2 GetPosition() const { return { m_Shape->getPosition().x, m_Shape->getPosition().y }; }

		const inline void SetRotation(float rotation) { m_Shape->setRotation(rotation); }
		const inline float GetRotation() const { return m_Shape->getRotation(); }

		const inline void SetSize(float x, float y) { m_Shape->setSize(sf::Vector2f(x, y)); }
		const inline Vector2 GetSize() const { return { m_Shape->getSize().x, m_Shape->getSize().y }; }

		const inline void SetScale(float x, float y) { m_Shape->setScale(sf::Vector2f(x, y) * Application::GlobalScaleMultiplier); }
		const inline Vector2 GetScale() const { return { m_Shape->getScale().x, m_Shape->getScale().y }; }

		bool enabled = true;

	private:
		sf::RectangleShape* m_Shape = nullptr;
	};
}
