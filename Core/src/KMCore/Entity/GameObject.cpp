#include "kmpch.h"
#include "GameObject.h"

namespace KMCore::Entity
{
	GameObject::GameObject(const std::string& texturePath, const Core::Transform& transform, const std::string& name)
		: Object(name)
	{
		m_Shape = new sf::RectangleShape({ transform.size.x, transform.size.y });
		m_TransformComponent = new Core::TransformComponent(m_Shape, transform);
		this->transform = m_TransformComponent;

		sf::Texture* texture = new sf::Texture();
		if (texture->loadFromFile(texturePath))
		{
			m_Shape->setTexture(texture);
			return;
		}
	}

	GameObject::~GameObject()
	{
		transform = nullptr;
		delete m_Shape->getTexture();
		delete m_Shape;
		delete m_TransformComponent;
	}

	void GameObject::Draw(sf::RenderWindow* window)
	{
		window->draw(*m_Shape);
	}
}