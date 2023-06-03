#pragma once
#include "Core.h"
#include "Game/GameWindow.h"
#include "Level.h"
#include "Time.h"
#include "KMCoreUtilities.h"

namespace KMCore
{
	class Application
	{
	public:
		Application(const WindowData& data = WindowData());
		virtual ~Application() = default;

		virtual void Run();

		void AddLevel(Level* level);
		void RemoveLevel(Level* level);

		inline virtual Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

		static float GlobalScaleMultiplier;

	private:
		virtual void PollEvents();
		virtual void OnEvent(sf::Event& event);

		//void UpdateDeltaTime(sf::Clock& clock);
		void UpdateLevels();

	private:
		std::unique_ptr<GameWindow> m_Window;
		std::vector<Level*> m_Levels;
		sf::Time m_LastFrameTime = sf::Time();
		bool m_Running = true;

	private:
		static Application* s_Instance;
	};
}
