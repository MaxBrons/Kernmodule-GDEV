#include "kmpch.h"
#include "SpeedRacerLevel.h"

SpeedRacerLevel::SpeedRacerLevel(const std::string& name)
	:m_Name(name)
{
	m_Window = &(GameWindow&)Application::Get().GetWindow();
}

void SpeedRacerLevel::OnStart()
{
	m_Player = Entity::Player();
	m_Player.OnStart();

	Entity::Enemy enemy = Entity::Enemy();
	enemy.OnStart();
	enemy.setFillColor(sf::Color::Green);
	enemy.setSize(sf::Vector2f(50.0f, 50.0f));
	for (size_t i = 0; i < 5; i++)
	{
		m_Enemies.push_back(enemy);
	}
}

void SpeedRacerLevel::OnDestroy()
{

}

void SpeedRacerLevel::OnEvent(sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed ||
		event.type == sf::Event::MouseButtonReleased)
		return;
}

void SpeedRacerLevel::OnUpdate(sf::Time deltaTime)
{
	if (m_Window->GetRenderWindow() == nullptr) {
		return;
	}

	SpawnEnemy();
	UpdateEnemies();
	m_Player.OnUpdate();

	m_Window->clear();
	Draw(m_Player);
	DrawEnemies();
	m_Window->display();
}

void SpeedRacerLevel::UpdateEnemies()
{
	for (auto& e : m_Enemies) {
		if (e.enabled)
			e.OnUpdate();
	}
}

void SpeedRacerLevel::SpawnEnemy()
{
	if (m_SpawnTimer >= m_SpawnDelay)
	{
		Entity::Enemy* enemy = nullptr;
		for (auto& e : m_Enemies) {
			if (!e.enabled)
			{
				enemy = &e;
				break;
			}
		}

		if (enemy != nullptr) {
			enemy->setPosition(
				static_cast<float>(rand() & static_cast<int>(m_Window->getSize().x - enemy->getSize().x)),
				-enemy->getSize().y);
			enemy->enabled = true;
		}
		m_SpawnTimer = 0.0f;
	}
	else
	{
		m_SpawnTimer += 1.0f / 60.0f;
	}
}

void SpeedRacerLevel::DrawEnemies()
{
	for (int i = 0; i < m_Enemies.size(); i++)
	{
		m_Enemies[i].move({ 0, 5.0f });
		Draw(m_Enemies[i]);
		if (m_Enemies[i].getPosition().y > m_Window->GetRenderWindow()->getView().getSize().y)
		{
			m_Enemies[i].enabled = false;
		}
	}
}

void SpeedRacerLevel::Draw(sf::Shape& shape)
{
	m_Window->GetRenderWindow()->draw(shape, sf::RenderStates::Default);
}
