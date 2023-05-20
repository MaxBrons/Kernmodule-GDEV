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

		virtual ~Application() = default;

		void Run();
		void Quit();

		DefaultWindow& GetWindow() { return *m_Window; }
		inline bool IsRunning() { return m_Running; }

	private:
		DefaultWindow* m_Window;
		ApplicationSettings m_ApplicationSettings;
		bool m_Running = true;

	private:
		static Application* s_Instance;
	};
}
