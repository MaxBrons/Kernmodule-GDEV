#pragma once
#include "KMCore/Core/Core.h"

namespace KMCore::Core
{
	struct Transform
	{
	public:
		sf::Vector2f position;
		float		 rotation;
		sf::Vector2f size;
		sf::Vector2f scale;

		Transform(sf::Vector2f position = sf::Vector2f(), float rotation = 0.0f, sf::Vector2f size = sf::Vector2f(), sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f))
			: position(position), rotation(rotation), size(size), scale(scale)
		{
		}
	};

	class TransformComponent
	{
	public:
		TransformComponent(sf::RectangleShape* shape)
		{
			m_Shape = shape;
		}
		TransformComponent(sf::RectangleShape* shape, sf::Vector2f position, float rotation, sf::Vector2f size, sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f))
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

		const inline void Move(float x, float y) { m_Shape->move({ x, y }); }

		const inline void SetPosition(float x, float y) { m_Shape->setPosition({ x, y }); }
		const inline sf::Vector2f GetPosition() const { return m_Shape->getPosition(); }

		const inline void SetRotation(float rotation) { m_Shape->setRotation(rotation); }
		const inline float GetRotation() const { return m_Shape->getRotation(); }

		const inline void SetSize(float x, float y) { m_Shape->setSize({ x, y }); }
		const inline sf::Vector2f GetSize() const { return m_Shape->getSize(); }

		const inline void SetScale(float x, float y) { m_Shape->setScale({ x, y }); }
		const inline sf::Vector2f GetScale() const { return m_Shape->getScale(); }

		bool enabled = true;

	private:
		sf::RectangleShape* m_Shape = nullptr;
	};
}
