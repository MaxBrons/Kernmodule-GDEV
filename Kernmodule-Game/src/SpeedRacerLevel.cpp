#include "kmpch.h"
#include "SpeedRacerLevel.h"

SpeedRacerLevel::SpeedRacerLevel()
{
	m_Window = &(GameWindow&)Application::Get().GetWindow();
}

void SpeedRacerLevel::OnStart()
{
	m_EndScreenBG = new Entity::GameObject(Core::Transform({}, 0.0f, (Vector2)m_Window->getSize()));
	m_EndScreenBG->GetShape()->setFillColor(sf::Color(0, 0, 0, 150));

	m_EndScreenText = new UI::UIText("assets/Fonts/Roboto-Black.ttf", "Oh no.. you crashed!\nYou're total score is: ", 100 * Application::GlobalScaleMultiplier);
	m_EndScreenText->setOrigin(m_EndScreenText->getLocalBounds().width / 2, m_EndScreenText->getLocalBounds().height / 2);
	m_EndScreenText->setFillColor(sf::Color(27, 180, 246));
	m_EndScreenText->transform->SetPosition(Application::Get().GetWindow().GetWidth() / 2.0f, Application::Get().GetWindow().GetHeight() / 2.0f);

	m_ScoreText = new UI::UIText("assets/Fonts/Roboto-Black.ttf", std::string(), 100 * Application::GlobalScaleMultiplier);
	m_ScoreText->setFillColor(sf::Color(199, 0, 57));
	m_ScoreText->transform->SetPosition(0.0f, 0.0f);

	m_Background = new Entity::Sprite("assets/Sprites/background-1.png");
	m_Background->transform->SetSize(m_Window->getSize().x, m_Window->getSize().y);
	m_Background1 = new Entity::Sprite("assets/Sprites/background-1.png");
	m_Background1->transform->SetSize(m_Window->getSize().x, m_Window->getSize().y);
	m_Background1->transform->SetPosition(0.0f, -m_Background1->transform->GetSize().y);

	m_Player = new Entity::Player("assets/Sprites/cars_racer_blue.png"); \
		Vector2 bgSize = m_Background->transform->GetSize();
	m_Player->SetMovementBounds(Vector4(bgSize.x / 5, 0.0f, bgSize.x - (bgSize.x / 5), bgSize.y));
	m_PlayerRigidBody =  m_Player->GetComponent<KMCore::Core::RigidBodyComponent>();

	m_EndScreenText->OnStart();
	m_ScoreText->OnStart();
	m_Background->OnStart();
	m_Background1->OnStart();
	m_Player->OnStart();

	m_SpawnTimer = 1000.0f;
	SpawnEnemy();
}

void SpeedRacerLevel::OnDestroy()
{
	m_EndScreenText->OnDestroy();
	m_ScoreText->OnDestroy();
	m_Background->OnDestroy();
	m_Background1->OnDestroy();
	m_Player->OnDestroy();

	delete m_Player;
	delete m_Background;

	for (auto& e : m_Enemies)
		delete e;
	m_Enemies.clear();

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

		m_Player->OnUpdate();
		UpdateEnemies();

		CheckCollision();
		UpdateBackground();
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
		LOG("DESTROYED");
	}
}

void SpeedRacerLevel::UpdateBackground()
{
	if (m_PlayerRigidBody != nullptr)
	{
		m_Background->transform->Move(0.0f, m_PlayerRigidBody->Velocity.y);
	}
}

void SpeedRacerLevel::SpawnEnemy()
{
	if (m_SpawnTimer >= m_SpawnDelay)
	{
		Entity::Enemy* enemy = new Entity::Enemy("assets/Sprites/cars_racer_red.png");
		enemy->OnStart();

		Vector2 windowSize = m_Window->GetRenderWindow()->getSize();
		float width = windowSize.x;
		float offset = windowSize.x / 5;
		float enemyOffset = enemy->transform->GetSize().x / 2;

		enemy->SetMovementBounds(Vector4(offset, -windowSize.y, width - offset, windowSize.y));
		enemy->transform->SetPosition(offset + enemyOffset + GetRandomValue(width - (offset * 2) - enemyOffset), -enemy->transform->GetSize().y);
		LOG(enemy->transform->GetPosition().x);
		m_Enemies.push_back(enemy);

		m_SpawnTimer = 0.0f;
	}
	else
	{
		m_SpawnTimer += 1.0f / 60.0f;
	}
}