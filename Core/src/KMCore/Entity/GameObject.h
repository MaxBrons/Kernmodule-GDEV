#pragma once
#include "KMCore/Entity/Object.h"
#include "KMCore/Components/TransformComponent.h"
#include <iostream>

namespace KMCore::Entity
{
	class GameObject : public Object
	{
	public:
		GameObject(const std::string& texturePath, const Core::Transform& transform = Core::Transform(), const std::string& name = "New GameObject")
			: Object(name)
		{
			m_Shape = new sf::RectangleShape(transform.size);
			m_TransformComponent = new Core::TransformComponent(m_Shape, transform);
			this->transform = m_TransformComponent;

			sf::Texture* texture = new sf::Texture();
			if (texture->loadFromFile(texturePath))
			{
				m_Shape->setTexture(texture);
				return;
			}
			delete texture;
		}
		virtual ~GameObject()
		{
			transform = nullptr;
			delete m_Shape;
			delete m_TransformComponent;
		}

		virtual void OnStart() override {}
		virtual void OnUpdate() override {}
		virtual void OnDestroy() override {}

		virtual void Draw(sf::RenderWindow* window)
		{
			window->draw(*m_Shape);
		}

		inline sf::RectangleShape* GetShape() const { return m_Shape; }
		const inline sf::Texture* GetTexture() const { return m_Shape->getTexture(); }

		Core::TransformComponent* transform = nullptr;
	private:
		sf::RectangleShape* m_Shape = nullptr;
		Core::TransformComponent* m_TransformComponent = nullptr;
	};
}
#pragma once
