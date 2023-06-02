#pragma once
#include "KMCore/Entity/GameObject.h"

namespace KMCore::Entity
{
	class Sprite : public GameObject
	{
	public:
		Sprite(const std::string& texturePath, const Core::Transform& transform = Core::Transform(), const std::string& name = "New Sprite");
		virtual ~Sprite();

		const inline sf::Texture* GetTexture() const { return m_Shape->getTexture(); }
	};
}
