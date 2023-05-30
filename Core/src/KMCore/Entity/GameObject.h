#pragma once
#include "KMCore/Entity/Object.h"
#include "KMCore/Components/TransformComponent.h"
#include <iostream>

namespace KMCore::Entity
{
	class GameObject : public Object
	{
	public:
		GameObject(const std::string& texturePath, const Core::Transform& transform = Core::Transform(), const std::string& name = "New GameObject");
		virtual ~GameObject();

		virtual void OnStart() override {}
		virtual void OnUpdate() override {}
		virtual void OnDestroy() override {}

		virtual void Draw(sf::RenderWindow* window);

		inline sf::RectangleShape* GetShape() const { return m_Shape; }
		const inline sf::Texture* GetTexture() const { return m_Shape->getTexture(); }

		Core::TransformComponent* transform = nullptr;
	private:
		sf::RectangleShape* m_Shape = nullptr;
		Core::TransformComponent* m_TransformComponent = nullptr;
	};
}
