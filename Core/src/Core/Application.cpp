#include "kmpch.h"
#include "Application.h"

namespace KMCore {

	Application::Application()
	{
	}

	Application::Application(sf::WindowHandle handle, const sf::ContextSettings& settings)
		:m_Window(handle, settings)
	{
	}

	Application::Application(sf::VideoMode mode, const sf::String& title, sf::Uint32 style, const sf::ContextSettings& settings)
		:m_Window(mode, title, style, settings)
	{
	}

	void Application::Run(const Level& level)
	{
		if (m_Running)
			return;
		m_Running = true;
		m_CurrentLevel = level;

		while (m_Window.isOpen())
		{
			sf::Event event;
			while (m_Window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					Quit();
			}
			
			m_CurrentLevel.Draw(m_Window);
		}
	}

	void Application::Quit()
	{
		m_Running = false;
		m_Window.close();
	}
}
