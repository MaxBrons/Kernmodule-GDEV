#include "kmpch.h"
#include "Sprite.h"
namespace KMCore::Entity
{
	Sprite::Sprite(const std::string& texturePath, const Core::Transform& transform, const std::string& name)
		:GameObject(transform, name)
	{
		sf::Texture* texture = new sf::Texture();
		if (texture->loadFromFile(texturePath))
			m_Shape->setTexture(texture);
	}

	Sprite::~Sprite()
	{
		if (m_Shape != nullptr)
			delete m_Shape->getTexture();
	}
}


