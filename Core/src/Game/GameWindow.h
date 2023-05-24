#pragma once
#include "KMCore/Core/Window.h"
#include "KMCore/Core/Level.h"

namespace KMCore
{

	class GameWindow : public Window
	{
	public:
		GameWindow(const WindowData& data);
		virtual ~GameWindow();

		void OnUpdate() override;

		inline uint32_t GetWidth() const override { return m_Data.VideoMode.width; }
		inline uint32_t GetHeight() const override { return m_Data.VideoMode.height; }

		void SetVSync(bool enabled) override;
		bool IsVSyncEnabled() const override;

		inline virtual sf::RenderWindow* GetRenderWindow() const { return m_Window; }
	private:
		virtual void Init(const WindowData& props);
		virtual void Shutdown();
	private:
		sf::RenderWindow* m_Window;
		WindowData m_Data;
	};
}

