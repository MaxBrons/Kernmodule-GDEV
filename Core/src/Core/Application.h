#pragma once
#include "Core.h"
#include "Window.h"

namespace KMCore 
{
	struct ApplicationSettings 
	{
		std::string Title;
		uint32_t Width, Height;
		bool VSync;

		sf::Uint32 Style;
		sf::ContextSettings ContextSettings;
	};

	class Application
	{
	public:
		Application();
		Application(const WindowData& data);

		virtual ~Application();

		virtual void Run();

		inline virtual DefaultWindow& GetWindow() { return *m_Window; }
		inline virtual bool IsRunning() { return m_Running; }

	public:
		static Application* s_Instance;
	private:
		std::unique_ptr<DefaultWindow> m_Window;
		std::unique_ptr<ApplicationSettings> m_ApplicationSettings;
		bool m_Running = true;

	};
}
