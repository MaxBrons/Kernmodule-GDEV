#pragma once
#include "KMCore.h"
#include "KMCoreUtilities.h"
#include "KMCore/Core/Level.h"
#include "KMCore/UI/UIText.h"

#include "SpeedRacerLevel.h"

namespace KMGame
{
	class MainMenuLevel : public Level
	{
	public:
		MainMenuLevel();
		virtual ~MainMenuLevel() = default;

		virtual void OnStart() override;
		virtual void OnDestroy() override;
		virtual void OnEvent(sf::Event& event) override;

	private:
		GameWindow* m_Window = nullptr;
		UI::UIText* m_Title= nullptr;
		UI::UIText* m_Text = nullptr;
		KMCore::Entity::GameObject* m_Background = nullptr;

		// Inherited via Level
		virtual void OnUpdate(sf::Time timeStep) override;
	};
}

