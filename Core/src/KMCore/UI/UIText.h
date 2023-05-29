#pragma once
#include "../Core/Core.h"

namespace KMCore::UI
{
	class UIText : public sf::Text
	{
	public:
		UIText() = default;
		UIText(const std::string& fontFilePath, const std::string& content = std::string(), int characterSize = 12)
			:m_Font(new sf::Font()), m_Content(content), m_CharacterSize(characterSize)
		{
			m_Font->loadFromFile(fontFilePath);

			setFont(*m_Font);
			setString(m_Content);
			setCharacterSize(m_CharacterSize);
		}
		virtual ~UIText() = default;

	private:
		sf::Font* m_Font = nullptr;
		std::string m_Content;
		int m_CharacterSize;
	};
}
