#include "kmpch.h"
#include "Application.h"

namespace KMCore
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		s_Instance = this;
		m_Window = std::make_unique<DefaultWindow>();
	}

	Application::Application(const WindowData& data)
	{
		s_Instance = this;
		m_Window = std::make_unique<DefaultWindow>(WindowData(data));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Window->IsOpen())
		{
			m_Window->Update();
		}
		m_Window = nullptr;
	}
}
