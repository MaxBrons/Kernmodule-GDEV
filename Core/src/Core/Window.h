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

		WindowData(const std::string& title = "New Window", sf::VideoMode mode = sf::VideoMode(720, 360), sf::Uint32 style = 7U, const sf::ContextSettings context = sf::ContextSettings())
			: Title(title), VideoMode(mode), Style(style), ContextSettings(context)
		{
		}
	};

	class DefaultWindow
	{
	public:
		DefaultWindow() = default;
		DefaultWindow(const WindowData& data);
		virtual ~DefaultWindow();

		virtual void Init(const WindowData& data);
		virtual void Update();
		virtual void PollEvent();
		virtual void Close();

		inline virtual uint32_t GetWidth() const { return m_Data->VideoMode.width; };
		inline virtual uint32_t GetHeight() const { return m_Data->VideoMode.height; }

		inline virtual void SetVSync(bool enabled) { 
			m_Data->VSync = enabled;
			m_Window->setVerticalSyncEnabled(enabled);
		}
		inline virtual bool GetVSync() const { return m_Data->VSync; }

		inline virtual void* GetWindow() const { return m_Window; }

		static DefaultWindow* Create(const WindowData& settings = WindowData()) { return new DefaultWindow(settings); }
	private:
		sf::RenderWindow* m_Window;
		std::vector<sf::Drawable*> m_SceneObjects;
		WindowData* m_Data;
	};
}

