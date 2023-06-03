#include "kmpch.h"
#include "GameObject.h"

namespace KMCore::Entity
{
	GameObject::GameObject(const Core::Transform& transform, const std::string& name)
		: Object(name)
	{
		m_Shape = new sf::RectangleShape({ transform.size.x, transform.size.y });
		this->transform = new Core::TransformComponent(m_Shape, transform);

		m_Components.push_back(this->transform);
	}

	GameObject::~GameObject()
	{
		delete m_Shape;
	}

	void GameObject::OnStart()
	{
		COMPFUNC(OnStart());
	}

	void GameObject::OnUpdate()
	{
		COMPFUNC(OnUpdate());
	}

	void GameObject::OnDestroy()
	{
		COMPFUNC(OnDestroy());
		for (auto* comp : m_Components)
		{
			delete comp;
		}
	}

	void GameObject::Draw(sf::RenderWindow* window)
	{
		window->draw(*m_Shape);
		OnDraw();
	}

	void GameObject::AddComponent(Core::Component* component)
	{
		if (std::find(m_Components.begin(), m_Components.end(), component) != m_Components.end())
			m_Components.push_back(component);
	}

	template<typename T>
	T* GameObject::GetComponent() const
	{
		for (auto* comp : m_Components)
		{
			T* returnComp = static_cast<T*>(comp);
			if (returnComp != nullptr)
			{
				return returnComp;
			};
		}
		return nullptr;
	}

	std::vector<Core::Component*>& GameObject::GetComponents()
	{
		return m_Components;
	}
}