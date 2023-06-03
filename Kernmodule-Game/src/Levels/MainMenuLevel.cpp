#include "MainMenuLevel.h"

namespace KMGame
{
	MainMenuLevel::MainMenuLevel()
	{
		m_Window = &(GameWindow&)Application::Get().GetWindow();
	}

	void MainMenuLevel::OnStart()
	{
		m_Title = new UI::UIText("assets/Fonts/Roboto-Black.ttf", "SPEED RACER", 100 * Application::GlobalScaleMultiplier);
		m_Title->setOrigin(m_Title->getLocalBounds().width / 2, m_Title->getLocalBounds().height / 2);
		m_Title->setFillColor(sf::Color(234, 182, 118));
		m_Title->transform->SetPosition(WINDOW_WIDTH_REF / 2.0f, WINDOW_HEIGHT_REF / 2.0f - (WINDOW_HEIGHT_REF / 5 * Application::GlobalScaleMultiplier));

		m_Text = new UI::UIText("assets/Fonts/Roboto-Black.ttf", "Press 'ENTER' to start playing...\nPress 'ESCAPE' at any time to quit the game\nUse the 'A' and 'D' keys to move around\n", 50 * Application::GlobalScaleMultiplier);
		m_Text->setOrigin(m_Text->getLocalBounds().width / 2, m_Text->getLocalBounds().height / 2);
		m_Text->setFillColor(sf::Color::White);
		m_Text->transform->SetPosition(WINDOW_WIDTH_REF / 2.0f, WINDOW_HEIGHT_REF / 2.0f);

		m_Background = new KMCore::Entity::GameObject(Core::Transform({}, 0.0f, Vector2(WINDOW_WIDTH_REF, WINDOW_HEIGHT_REF)));
		m_Background->GetShape()->setFillColor(sf::Color(150, 150, 150, 100));

		m_Background->OnStart();
		m_Text->OnStart();
		m_Title->OnStart();
	}

	void MainMenuLevel::OnDestroy()
	{
		m_Background->OnDestroy();
		m_Text->OnDestroy();
		m_Title->OnDestroy();

		delete m_Background;
		delete m_Text;
		delete m_Title;
	}

	void MainMenuLevel::OnEvent(sf::Event& event)
	{
		if (event.key.code == sf::Keyboard::Enter)
		{
			Application::Get().AddLevel(new SpeedRacerLevel());
			Application::Get().RemoveLevel(this);
		}
	}

	void MainMenuLevel::OnUpdate(sf::Time timeStep)
	{
		m_Background->OnUpdate();
		m_Text->OnUpdate();
		m_Title->OnUpdate();

		m_Background->Draw(m_Window);
		m_Text->Draw(m_Window);
		m_Title->Draw(m_Window);
	}
}
