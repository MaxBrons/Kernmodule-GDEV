#include "kmpch.h"
#include "Application.h"

namespace KMCore
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		s_Instance = this;
		m_Window = new DefaultWindow(WindowData());
	}

	Application::Application(const WindowData& data)
	{
		s_Instance = this;
		m_Window = new DefaultWindow(WindowData(data));
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->Update();
		}
	}

	void Application::Quit()
	{
		//_Window->Close();
		//m_Window.reset();
	}
}
