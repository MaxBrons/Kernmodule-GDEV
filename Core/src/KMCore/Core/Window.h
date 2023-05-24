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

	class Window
	{
	public:
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSyncEnabled() const = 0;

		virtual sf::RenderWindow* GetRenderWindow() const = 0;

		static Window* Create(const WindowData& settings = WindowData());
	};
}

