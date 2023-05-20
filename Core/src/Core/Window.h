#pragma once
#include "Core.h"

namespace KMCore
{
	struct WindowData
	{
		std::string Title;
		bool VSync = false;

		sf::VideoMode VideoMode;
		sf::Uint32 Style;
		sf::ContextSettings ContextSettings;

		WindowData(const std::string title = "New Window", sf::VideoMode mode = sf::VideoMode(720, 360), sf::Uint32 style = 7U, const sf::ContextSettings context = sf::ContextSettings())
			: Title(title), VideoMode(mode), Style(style), ContextSettings(context)
		{
		}
	};

	class DefaultWindow
	{
	public:
		DefaultWindow(const WindowData& data = WindowData());
		virtual ~DefaultWindow();

		virtual void Init(const WindowData& data);
		virtual void Update();
		virtual void PollEvent();
		virtual void Close();

		inline virtual uint32_t GetWidth() const { return m_Data->VideoMode.width; };
		inline virtual uint32_t GetHeight() const { return m_Data->VideoMode.height; }

		inline virtual bool GetVSync() const { return m_Data->VSync; }
		inline virtual void SetVSync(bool enabled) {
			m_Data->VSync = enabled;
			m_Window->setVerticalSyncEnabled(enabled);
		}

		inline void* GetWindow() const { return m_Window.get(); }
		inline bool IsOpen() const { return m_IsOpen; }

		static DefaultWindow* Create(const WindowData& settings = WindowData()) { return new DefaultWindow(settings); }
	private:
		std::unique_ptr<sf::RenderWindow> m_Window;
		std::vector<sf::Drawable*> m_SceneObjects;
		std::unique_ptr<WindowData> m_Data;
		bool m_IsOpen = true;
	};
}

