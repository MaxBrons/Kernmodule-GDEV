#pragma once
#include "../Core/Core.h"
#include "../Entity/GameObject.h"

namespace KMCore::UI
{
	class UIText : public Entity::GameObject, public sf::Text
	{
	public:
		UIText() = default;
		UIText(const std::string& fontFilePath, const std::string& content = std::string(), int characterSize = 12)
			:m_Content(content), m_CharacterSize(characterSize)
		{
			m_Font.loadFromFile(fontFilePath);

			setFont(m_Font);
			setString(m_Content);
			setCharacterSize(m_CharacterSize);
		}
		virtual ~UIText() = default;

		void OnStart() override
		{
			setPosition((sf::Vector2f)transform->GetPosition());
			setRotation(transform->GetRotation());
			setScale((sf::Vector2f)transform->GetScale());
		}

		void Draw(sf::RenderWindow* window) override
		{
			BASE(Draw(window));
			window->draw(*this);
		}

	private:
		sf::Font m_Font;
		std::string m_Content;
		int m_CharacterSize;
	};
}
