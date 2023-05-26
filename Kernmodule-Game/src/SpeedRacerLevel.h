#pragma once
#include "KMCore.h"
#include "KMCore/Core/Level.h"
#include "KMCore/Core/Time.h"
#include "Entities/Player.h"
#include "Entities/Enemy.h"
#include <ctime>

using namespace KMCore;
class SpeedRacerLevel : public Level
{
public:
	SpeedRacerLevel(const std::string& name = "New Level");
	virtual ~SpeedRacerLevel() = default;

	virtual void OnStart() override;
	virtual void OnDestroy() override;
	virtual void OnEvent(sf::Event& event) override;
	virtual void OnUpdate(sf::Time deltaTime) override;

	void UpdateEnemies();

	void MovePlayer();
	void SpawnEnemy();

	virtual void Draw(sf::Shape& shape);

private:
	void DrawEnemies();

private:
	GameWindow* m_Window;
	std::string m_Name;

	Entity::Player m_Player;
	std::vector<Entity::Enemy> m_Enemies = std::vector<Entity::Enemy>();

	float m_SpawnTimer = 0.0f;
	float m_SpawnDelay = 1.0f;
};

