#include "kmpch.h"
#include "SpeedRacerLevel.h"
namespace KMGame
{
	SpeedRacerLevel::SpeedRacerLevel()
	{
		m_Window = &(GameWindow&)Application::Get().GetWindow();
	}

	void SpeedRacerLevel::OnStart()
	{
		m_EndScreenBG = new KMCore::Entity::GameObject(Core::Transform({}, 0.0f, Vector2(WINDOW_WIDTH_REF, WINDOW_HEIGHT_REF)));
		m_EndScreenBG->GetShape()->setFillColor(sf::Color(0, 0, 0, 150));

		m_EndScreenText = new UI::UIText("assets/Fonts/Roboto-Black.ttf", "Oh no.. you crashed!\nYou're total score is: ", 100 * Application::GlobalScaleMultiplier);
		m_EndScreenText->setOrigin(m_EndScreenText->getLocalBounds().width / 2, m_EndScreenText->getLocalBounds().height / 2);
		m_EndScreenText->setFillColor(sf::Color(27, 180, 246));
		m_EndScreenText->transform->SetPosition(WINDOW_WIDTH_REF / 2.0f, WINDOW_HEIGHT_REF / 2.0f);

		m_ScoreText = new UI::UIText("assets/Fonts/Roboto-Black.ttf", std::string(), 100 * Application::GlobalScaleMultiplier);
		m_ScoreText->setFillColor(sf::Color(199, 0, 57));

		m_Player = new Entity::Player("assets/Sprites/cars_racer_blue.png"); \
		m_Player->SetMovementBounds(Vector4(WINDOW_WIDTH_REF / 5, 0.0f, WINDOW_WIDTH_REF - (WINDOW_WIDTH_REF / 5), WINDOW_HEIGHT_REF));
		m_Player->SetSpeed(m_PlayerMovementSpeed);

		m_Background = new Entity::Road();
		m_Background->SetSpeed(m_RoadMovementSpeed);

		//Call onstart methods on the gameobjects
		m_Background->OnStart();
		m_Player->OnStart();
		m_EndScreenBG->OnStart();
		m_EndScreenText->OnStart();
		m_ScoreText->OnStart();
	}

	void SpeedRacerLevel::OnDestroy()
	{
		for (auto& e : m_Enemies)
		{
			e->OnDestroy();
			delete e;
		}
		m_Enemies.clear();

		m_Background->OnDestroy();
		m_Player->OnDestroy();
		m_ScoreText->OnDestroy();
		m_EndScreenText->OnDestroy();
		m_EndScreenBG->OnDestroy();

		delete m_Background;
		delete m_Player;
		delete m_ScoreText;
		delete m_EndScreenText;
		delete m_EndScreenBG;
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
			UpdateEnemies();

			m_Background->OnUpdate();
			m_Player->OnUpdate();
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
			m_EndScreenText->Draw(m_Window);
		}
		else
			m_ScoreText->Draw(m_Window);
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
		for (auto& enemy : m_Enemies)
		{
			if (enemy->enabled)
			{
				enemy->OnUpdate();
				continue;
			}

			enemy->OnDestroy();
			m_Enemies.erase(std::find(m_Enemies.begin(), m_Enemies.end(), enemy));
			m_Score++;
		}
	}

	void SpeedRacerLevel::SpawnEnemy()
	{
		if (m_SpawnTimer >= m_SpawnDelay)
		{
			int randIndex = (int)GetRandomValue(2);
			Entity::Enemy* enemy = new Entity::Enemy(m_CarFileLocations[randIndex]);
			enemy->OnStart();

			Vector2 windowSize = Vector2(WINDOW_WIDTH_REF, WINDOW_HEIGHT_REF);
			float offset = windowSize.x / 5;
			float enemyWidth = enemy->transform->GetSize().x;
			float newPosX = offset + ((windowSize.x - (offset * 2) - enemyWidth) * GetRandomValue(1.0f));

			enemy->SetMovementBounds(Vector4(offset, -windowSize.y, windowSize.x - offset, windowSize.y));
			enemy->transform->SetPosition(newPosX, -enemy->transform->GetSize().y * 2);
			enemy->SetSpeed(m_EnemyMovementSpeed * (float)(randIndex == 2 ? 2 : 1));
			sf::RectangleShape s;

			m_Enemies.push_back(enemy);
			m_SpawnTimer = 0.0f;
		}
		else
		{
			m_SpawnTimer += 1.0f / 60.0f;
		}
	}
}