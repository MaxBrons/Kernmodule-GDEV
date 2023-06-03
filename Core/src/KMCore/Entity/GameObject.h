#pragma once
#include "KMCore/Entity/Object.h"
#include "KMCore/Interfaces/IMovable.h"
#include "KMCore/Components/TransformComponent.h"
#include "KMCoreUtilities.h"
#include <iostream>

namespace KMCore::Entity
{
	class GameObject : public Object, public IMovable
	{
#define COMPFUNC(x) for(auto& c : m_Components) c->x
	public:
		GameObject(const Core::Transform& transform = Core::Transform(), const std::string& name = "New GameObject");
		virtual ~GameObject();

		virtual void OnStart() override;
		virtual void OnUpdate() override;
		virtual void OnDestroy() override;

		virtual void Draw(sf::RenderWindow* window);

		inline sf::RectangleShape* GetShape() const { return m_Shape; }

		void AddComponent(Core::Component* comp);
		inline std::vector<Core::Component*>& GetComponents();

		template<typename T>
		inline T* GetComponent() const;

	protected:
		virtual void OnDraw() {}

	protected:
		sf::RectangleShape* m_Shape = nullptr;

		std::vector<Core::Component*> m_Components = std::vector<Core::Component*>();
	};
}
