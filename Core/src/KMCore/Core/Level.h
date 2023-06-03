#pragma once

namespace KMCore
{
	class Level
	{
	public:
		virtual ~Level() = default;

		virtual void OnStart() = 0;
		virtual void OnUpdate(sf::Time timeStep) = 0;
		virtual void OnDestroy() = 0;
		virtual void OnEvent(sf::Event& event) = 0;
	};
}