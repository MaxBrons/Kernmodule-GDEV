#pragma once
#include "KMCore/Entity/Object.h"
#include "KMCore/Components/TransformComponent.h"
#include <iostream>

namespace KMCore::Entity
{
	class GameObject : public Object
	{
#define COMPFUNC(x) for(auto& c : m_Components) c->x
	public:
		GameObject(const Core::Transform& transform = Core::Transform(), const std::string& name = "New GameObject");
		virtual ~GameObject();

		virtual void OnStart() override
		{
			COMPFUNC(OnStart());
		}
		virtual void OnUpdate() override
		{
			COMPFUNC(OnUpdate());
		}
		virtual void OnDestroy() override
		{
			COMPFUNC(OnDestroy());
			for (auto* comp : m_Components)
			{
				delete comp;
			}
		}

		virtual void Draw(sf::RenderWindow* window);

		inline sf::RectangleShape* GetShape() const { return m_Shape; }

		template<typename T>
		inline T* GetComponent() const;

		Core::TransformComponent* transform = nullptr;

	protected:
		inline void AddComponent(Core::Component* comp);

	protected:
		sf::RectangleShape* m_Shape = nullptr;
		Core::TransformComponent* m_TransformComponent = nullptr;

		std::vector<Core::Component*> m_Components;
	};
}
