#pragma once

#ifndef KM_APPLICATION_H
#define KM_APPLICATION_H

#include "Level.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

namespace KMCore {

	class Application
	{
	public:
		Application();
		Application(sf::WindowHandle handle, const sf::ContextSettings& settings = sf::ContextSettings());
		Application(sf::VideoMode mode, const sf::String& title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());
		~Application() {}

		void Run(const Level& level);
		void Quit();

		inline sf::RenderWindow& GetWindow(){
			return m_Window;
		}

	private:
		sf::RenderWindow m_Window;
		KMCore::Level m_CurrentLevel;
		bool m_Running = false;
	};

}
#endif // !KM_APPLICATION_H
