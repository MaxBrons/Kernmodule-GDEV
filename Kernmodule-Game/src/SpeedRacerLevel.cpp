#include "kmpch.h"
#include "SpeedRacerLevel.h"
#include "Time.h"

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
	if (event.type == Event::MouseButtonPressed || 
		event.type == Event::MouseButtonReleased)
		return;

	if (event.key.code == Keyboard::A)
	{
		m_Player.move(Vector2f(-100.0f, 0.0f));
	}
	if (event.key.code == Keyboard::D)
	{
		m_Player.move(Vector2f(100.0f, 0.0f));
	}
}

void SpeedRacerLevel::OnUpdate(sf::Time deltaTime)
{
	if (m_SpawnTimer >= m_SpawnDelay)
	{
		if (m_Enemies.size() < m_MaxEnemies)
		{
			Entity::Enemy* enemy = new Entity::Enemy();
			sf::RectangleShape& shape = enemy->GetShape();
			shape.setPosition(m_Window->getSize().x / 2.0f, m_Window->getSize().y / 2.0f);
			shape.setFillColor(sf::Color::Green);
			shape.setSize(sf::Vector2f(100.0f,100.0f));
			m_Enemies.push_back(enemy);
			m_SpawnTimer = 0.0f;
		}
	}
	else
	{
		m_SpawnTimer += KMCore::Time::deltaTime;
	}

	m_Window->clear();
	Draw(m_Player);
	for (auto& enemy : m_Enemies)
	{
		enemy->GetShape().move(sf::Vector2f(0, 50.0f * KMCore::Time::deltaTime));
		if (enemy->GetShape().getPosition().y > m_Window->getView().getSize().y)
		{
			auto& it = std::find(m_Enemies.begin(), m_Enemies.end(), enemy);
			if (*it != nullptr)
			{
				m_Enemies.erase(it);
			}
		}

		Draw(*enemy);
	}
	m_Window->display();
}

void SpeedRacerLevel::Draw(sf::Shape& shape)
{
	m_Window->draw(shape, sf::RenderStates::Default);
}
