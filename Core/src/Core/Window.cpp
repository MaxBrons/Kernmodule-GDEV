#include "kmpch.h"
#include "Window.h"

namespace KMCore
{
	DefaultWindow::DefaultWindow(const WindowData& data)
	{
		Init(data);
	}

	DefaultWindow::~DefaultWindow()
	{
		Close();
	}

	void DefaultWindow::Init(const WindowData& data)
	{
		m_Data->Title = data.Title;
		m_Data->VideoMode = data.VideoMode;
		m_Data->ContextSettings = data.ContextSettings;

		m_Window = new sf::RenderWindow(data.VideoMode, data.Title, data.Style, data.ContextSettings);
		SetVSync(data.VSync);
	}

	void DefaultWindow::Update()
	{
		PollEvent();

		m_Window->clear();
		m_Window->draw(sf::CircleShape(10.f));
		m_Window->display();
	}

	void DefaultWindow::PollEvent()
	{
		sf::Event event;
		while (m_Window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				Close();
		}
	}

	void DefaultWindow::Close()
	{
		m_Window->close();
		delete m_Window;
	}
}

