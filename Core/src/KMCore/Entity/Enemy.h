#pragma once
#include "Object.h"

namespace KMCore::Entity
{
	class Enemy : public Object
	{
	public:
		Enemy()
		{
			m_EnemyShape = sf::RectangleShape();
		}
		virtual ~Enemy() = default;

		sf::RectangleShape& GetShape() { return m_EnemyShape; }

		operator sf::RectangleShape& () { return m_EnemyShape; }
	private:
		sf::RectangleShape m_EnemyShape;
	};
}