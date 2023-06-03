#pragma once
#include "KMCore/Core/Window.h"
#include "KMCore/Core/Level.h"

namespace KMCore
{
	class GameWindow : public Window, public sf::RenderWindow
	{
	public:
		GameWindow(const WindowData& data);
		virtual ~GameWindow();

		virtual void Init(const WindowData& props);
		void OnUpdate() override;
		virtual void Shutdown();

		inline uint32_t GetWidth() const override { return m_Data.VideoMode.width; }
		inline uint32_t GetHeight() const override { return m_Data.VideoMode.height; }

		inline WindowData GetWindowData() const { return m_Data; }

		void SetVSync(bool enabled) override;
		bool IsVSyncEnabled() const override;

		inline virtual sf::RenderWindow* GetRenderWindow() { return this; }

	private:
		WindowData m_Data;
	};
}

