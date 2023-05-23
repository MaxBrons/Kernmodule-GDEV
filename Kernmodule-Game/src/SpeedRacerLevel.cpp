#include "kmpch.h"
#include "SpeedRacerLevel.h"

using namespace sf;
SpeedRacerLevel::SpeedRacerLevel(const std::string& name)
	:m_Name(name)
{
	m_Window = Application::Get().GetWindow().GetRenderWindow();
}

void SpeedRacerLevel::OnStart()
{
	m_Player = RectangleShape({ 100.0f,100.0f });
	m_Player.setOutlineThickness(10.0f);
	m_Player.setFillColor(sf::Color(255, 255, 255, 200));
	m_Player.move(sf::Vector2f(100.0f, 0.0f));
	m_Player.rotate(45);
}

void SpeedRacerLevel::OnDestroy()
{

}

void SpeedRacerLevel::OnEvent(sf::Event& event)
{
	Vector2f playerPos = m_Player.getPosition();
	if (event.key.code == Keyboard::A)
	{
		m_Player.setPosition(playerPos + Vector2f(1.0f, 0.0f));
	}
	if (event.key.code == Keyboard::D)
	{
		m_Player.setPosition(playerPos + Vector2f(-1.0f, 0.0f));
	}
}

void SpeedRacerLevel::OnUpdate(sf::Time deltaTime)
{
	m_Window->clear();
	Draw(m_Player);
	m_Window->display();
}

void SpeedRacerLevel::Draw(sf::Shape& shape)
{
	m_Window->draw(shape, sf::RenderStates::Default);
}
