#include "kmpch.h"
#include "GameObject.h"

namespace KMCore::Entity
{
	GameObject::GameObject(const Core::Transform& transform, const std::string& name)
		: Object(name)
	{
		m_Shape = new sf::RectangleShape({ transform.size.x, transform.size.y });
		m_TransformComponent = new Core::TransformComponent(m_Shape, transform);
		this->transform = m_TransformComponent;

		m_Components.push_back(m_TransformComponent);
	}

	GameObject::~GameObject()
	{
		transform = nullptr;
		delete m_Shape;
		delete m_TransformComponent;
	}

	void GameObject::Draw(sf::RenderWindow* window)
	{
		window->draw(*m_Shape);
	}

	template<typename T>
	T* GameObject::GetComponent() const
	{
		for (auto& it = m_Components.begin(); it != m_Components.end();)
		{
			if (typeid(*(*it++)) == typeid(T))
				return static_cast<T*>(*it);
		}
		return nullptr;
	};

	void GameObject::AddComponent(Core::Component* component)
	{
		if (std::find(m_Components.begin(), m_Components.end(), component) != m_Components.end())
			m_Components.push_back(component);
	}
}