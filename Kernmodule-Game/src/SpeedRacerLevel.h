#pragma once
#include "KMCore.h"
#include "KMCore/Core/Level.h"
#include "KMCore/Core/Time.h"
#include "KMCoreUtilities.h"
#include "KMCore/UI/UIText.h"
#include "Entities/Enemy.h"
#include "Entities/Player.h"

#include <sstream>
#include <ctime>

using namespace KMCore;
class SpeedRacerLevel : public Level
{
public:
	SpeedRacerLevel();
	virtual ~SpeedRacerLevel() = default;

	virtual void OnStart() override;
	virtual void OnDestroy() override;
	virtual void OnEvent(sf::Event& event) override;
	virtual void OnUpdate(sf::Time deltaTime) override;

	void UpdateUI();
	void UpdateEnemies();
	void SpawnEnemy();
	void CheckCollision();
	void DrawScene();

private:
	GameWindow* m_Window = nullptr;

	Entity::GameObject* m_Background = nullptr;
	Entity::Player* m_Player = nullptr;
	std::vector<Entity::Enemy*> m_Enemies;
	
	UI::UIText* m_ScoreText = nullptr;
	UI::UIText* m_EndScreenText = nullptr;
	Entity::GameObject* m_EndScreenBG = nullptr;
	bool m_Collided = false;

	int m_Score = 0;

	float m_SpawnTimer = 0.0f;
	float m_SpawnDelay = 2.0f;
};

