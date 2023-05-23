#include "kmpch.h"
#include "Application.h"

namespace KMCore
{
	Application* Application::s_Instance = nullptr;

	Application::Application(const WindowData& data)
	{
		s_Instance = this;
		m_Window = std::make_unique<GameWindow>(data);
	}

	void Application::Run()
	{
		sf::Clock clock;
		sf::RenderWindow* window = m_Window->GetRenderWindow();

		while (window->isOpen())
		{
			UpdateDeltaTime(clock);
			PollEvents();
			UpdateLevels();

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(sf::Event& event)
	{
		if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
		{
			m_Window->GetRenderWindow()->close();
			m_Running = false;
		}

		for (auto it = m_Levels.begin(); it != m_Levels.end(); it++)
		{
			(*it)->OnEvent(event);
		}

		if (!m_Running)
		{
			for (Level* level : m_Levels)
			{
				RemoveLevel(level);
			}
		}
	}

	void Application::UpdateLevels()
	{
		for (Level* level : m_Levels)
		{
			level->OnUpdate(m_LastFrameTime);
		}
	}

	void Application::PollEvents()
	{
		sf::Event event;
		while (m_Window->GetRenderWindow()->pollEvent(event))
		{
			OnEvent(event);
		}
	}

	void Application::UpdateDeltaTime(sf::Clock& clock)
	{
		sf::Time timeStep = clock.getElapsedTime() - m_LastFrameTime;
		m_LastFrameTime = timeStep;
		clock.restart();
	}

	void Application::AddLevel(Level* level)
	{
		m_Levels.push_back(level);
		level->OnStart();
	}

	void Application::RemoveLevel(Level* level)
	{
		auto it = std::find(m_Levels.begin(), m_Levels.end(), level);
		if (it != m_Levels.end())
		{
			level->OnDestroy();
			m_Levels.erase(it);
		}
	}
}
