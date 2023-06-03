#include "kmpch.h"
#include "Application.h" 

namespace KMCore
{

	Application* Application::s_Instance = nullptr;
	float Application::GlobalScaleMultiplier = 1.0f;

	Application::Application(const WindowData& data)
	{
		s_Instance = this;
		m_Window = std::make_unique<GameWindow>(data);
		GlobalScaleMultiplier = 1.0f / WINDOW_WIDTH_REF * (float)m_Window->GetWidth();
	}

	void Application::Run()
	{
		while (m_Window->isOpen())
		{
			//UpdateDeltaTime(clock);
			PollEvents();

			m_Window->clear();
			UpdateLevels();
			m_Window->display();

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(sf::Event& event)
	{
		if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
		{
			m_Window->close();
			m_Running = false;
		}

		if (event.type == sf::Event::Resized)
		{
			WindowData data = m_Window->GetWindowData();
			data.VideoMode = sf::VideoMode(event.size.width, event.size.height);
			m_Window->Init(data);
			std::cout << "Window width: " << event.size.width << " " << "Window height: " << event.size.height << std::endl;
		}

		for (int i = 0; i < m_Levels.size(); i++)
		{
			m_Levels[i]->OnEvent(event);
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
		while (m_Window->pollEvent(event))
		{
			OnEvent(event);
		}
	}

	/*void Application::UpdateDeltaTime(sf::Clock& clock)
	{
		sf::Time timeStep = clock.getElapsedTime() - m_LastFrameTime;
		std::cout << timeStep.asMilliseconds() << std::endl;

		m_LastFrameTime = timeStep;

		KMCore::Time::time = clock.getElapsedTime().asMilliseconds();
		KMCore::Time::deltaTime = m_LastFrameTime.asMilliseconds();
		clock.restart();
	}*/

	void Application::AddLevel(Level* level)
	{
		m_Levels.emplace_back(level);
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
