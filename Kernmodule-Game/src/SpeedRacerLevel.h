#pragma once
#include "KMCore.h"
#include "KMCore/Core/Level.h"

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

	virtual void Draw(sf::Shape& shape);

private:
	sf::RenderWindow* m_Window;
	std::string m_Name;
	sf::RectangleShape m_Player;
};

