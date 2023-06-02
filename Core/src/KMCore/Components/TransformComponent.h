#pragma once
#include "KMCore/Core/Core.h"
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
			SetScale(size.x, size.y);
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

		const inline void Move(float x, float y) { m_Shape->move({ x,y }); }

		const inline void SetPosition(float x, float y) { m_Shape->setPosition({ x, y }); }
		const inline Vector2 GetPosition() const { return { m_Shape->getPosition().x, m_Shape->getPosition().y }; }

		const inline void SetRotation(float rotation) { m_Shape->setRotation(rotation); }
		const inline float GetRotation() const { return m_Shape->getRotation(); }

		const inline void SetSize(float x, float y) { m_Shape->setSize({ x, y }); }
		const inline Vector2 GetSize() const
		{
			return { m_Shape->getSize().x, m_Shape->getSize().y };
		}

		const inline void SetScale(float x, float y) { m_Shape->setScale({ x, y }); }
		const inline Vector2 GetScale() const
		{
			return { m_Shape->getScale().x, m_Shape->getScale().y };
		}

		bool enabled = true;

	private:
		sf::RectangleShape* m_Shape = nullptr;
	};
}
