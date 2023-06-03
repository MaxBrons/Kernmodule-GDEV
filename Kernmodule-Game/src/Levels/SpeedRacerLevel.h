#pragma once
#include "KMCore.h"
#include "KMCoreUtilities.h"
#include "KMCore/Core/Level.h"
#include "KMCore/Core/Time.h"
#include "KMCore/UI/UIText.h"
#include "KMCore/Entity/Sprite.h"

#include "../Entities/Enemy.h"
#include "../Entities/Player.h"
#include "../Entities/Road.h"
#include "KMCore/Components/RigidBodyComponent.h"

#include <sstream>
#include <ctime>

using namespace KMCore;
namespace KMGame
{
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
		void DrawScene();
		void CheckCollision();
		void UpdateEnemies();
		void SpawnEnemy();

	private:
		GameWindow* m_Window = nullptr;

		Entity::Road* m_Background = nullptr;
		Entity::Player* m_Player = nullptr;
		std::vector<Entity::Enemy*> m_Enemies;

		UI::UIText* m_ScoreText = nullptr;
		UI::UIText* m_EndScreenText = nullptr;
		KMCore::Entity::GameObject* m_EndScreenBG = nullptr;

		std::string m_CarFileLocations[3]{
			"assets/Sprites/cars_racer_red.png",
			"assets/Sprites/cars_racer_green.png",
			"assets/Sprites/cars_racer_yellow.png"
		};

		bool m_Collided = false;
		int m_Score = 0;
		float m_SpawnTimer = 999.0f;
		float m_SpawnDelay = 1.0f;

		Vector2 m_EnemyMovementSpeed = Vector2(25.0f, 70.0f);
		Vector2 m_PlayerMovementSpeed = Vector2(45.0f, 0.0f);
		Vector2 m_RoadMovementSpeed = Vector2(0.0f, 30.0f);
	};
}

