#include "kmpch.h"
#include "SpeedRacerLevel.h"

SpeedRacerLevel::SpeedRacerLevel()
{
	m_Window = &(GameWindow&)Application::Get().GetWindow();
}

void SpeedRacerLevel::OnStart()
{
	m_EndScreenBG = new Entity::GameObject(std::string(), Core::Transform({}, 0.0f, (Vector2)m_Window->getSize()));
	m_EndScreenBG->GetShape()->setFillColor(sf::Color(0,0,0, 150));

	m_EndScreenText = new UI::UIText("assets/Fonts/Roboto-Black.ttf", "Oh no.. you crashed!\nYou're total score is: ");
	m_EndScreenText->setFillColor(sf::Color::White);
	m_EndScreenText->setOrigin(150.0f, 50.0f);
	m_EndScreenText->setPosition(m_Window->getSize().x / 2.0f, m_Window->getSize().y / 2.0f);
	m_EndScreenText->setCharacterSize(m_Window->GetWidth() / (m_EndScreenText->getString().getSize() / 2));

	m_ScoreText = new UI::UIText("assets/Fonts/Roboto-Black.ttf", std::string(), 25);
	m_ScoreText->setFillColor(sf::Color::White);
	m_ScoreText->setPosition({ 0.0f, 0.0f });

	m_Background = new Entity::GameObject("assets/Sprites/background-1.png");
	m_Background->transform->SetSize(m_Window->getSize().x, m_Window->getSize().y);

	m_Player = new Entity::Player("assets/Sprites/cars_racer_blue.png");
	m_Player->OnStart();

	m_SpawnTimer = 1000.0f;
	SpawnEnemy();
}

void SpeedRacerLevel::OnDestroy()
{
	delete m_Player;
	delete m_Background;

	for (auto& e : m_Enemies)
		delete e;
	m_Enemies.clear();

	delete m_ScoreText;
	delete m_EndScreenText;
}

void SpeedRacerLevel::OnEvent(sf::Event& event)
{
	if (m_Collided)
	{
		if (event.key.code == sf::Keyboard::Enter)
		{
			Application::Get().AddLevel(new SpeedRacerLevel());
			Application::Get().RemoveLevel(this);
		}
	}
}

void SpeedRacerLevel::OnUpdate(sf::Time deltaTime)
{
	if (m_Window == nullptr)
		return;

	if (!m_Collided)
	{
		SpawnEnemy();

		m_Player->OnUpdate();
		UpdateEnemies();

		CheckCollision();
	}

	UpdateUI();
	DrawScene();
}

void SpeedRacerLevel::UpdateUI()
{
	std::stringstream stringStream;

	if (!m_Collided)
	{
		stringStream << "Score: " << m_Score;
		m_ScoreText->setString(stringStream.str());
	}

	stringStream.clear();
	stringStream << "Oh no.. you crashed!\nYou're total score is: " << m_Score << "\nPress Enter to continue..";
	m_EndScreenText->setString(stringStream.str());
}

void SpeedRacerLevel::DrawScene()
{
	m_Background->Draw(m_Window);
	m_Player->Draw(m_Window);

	for (auto& e : m_Enemies)
		e->Draw(m_Window);

	if (m_Collided)
	{
		m_EndScreenBG->Draw(m_Window);
		m_Window->draw(*m_EndScreenText);
	}
	else
		m_Window->draw(*m_ScoreText);
}

void SpeedRacerLevel::CheckCollision()
{
	for (auto& e : m_Enemies)
	{
		if (m_Player->collider->IsColliding(*e->collider))
		{
			m_Collided = true;
		}
	}
}

void SpeedRacerLevel::UpdateEnemies()
{
	for (auto& e : m_Enemies)
	{
		if (e->enabled)
		{
			e->Accelerate(0.0f, 0.1f);
			e->OnUpdate();
		}

		if (e->transform->GetPosition().y > m_Window->getSize().y)
		{
			e->OnDestroy();
			auto& enemy = std::find(m_Enemies.begin(), m_Enemies.end(), e);
			m_Enemies.erase(enemy);
			m_Score++;
		}
	}
}

void SpeedRacerLevel::SpawnEnemy()
{
	if (m_SpawnTimer >= m_SpawnDelay)
	{
		Entity::Enemy* enemy = new Entity::Enemy("assets/Sprites/cars_racer_red.png");
		float bgSize = m_Background->transform->GetSize().x;
		enemy->transform->SetPosition(bgSize / 4 + GetRandomValue(bgSize / 2), -enemy->transform->GetSize().y);
		enemy->MaxMovementSpeed = 2.5f;
		enemy->enabled = true;
		enemy->OnStart();

		m_Enemies.push_back(enemy);

		m_SpawnTimer = 0.0f;
	}
	else
	{
		m_SpawnTimer += 1.0f / 60.0f;
	}
}