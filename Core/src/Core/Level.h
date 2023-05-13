#pragma once

#ifndef KM_LEVEL_H
#define KM_LEVEL_H

#include <SFML/Graphics.hpp>

namespace KMCore {
	class Level {

	public:
		Level() {
			shape.setFillColor(sf::Color::Green);
			shape2.setFillColor(sf::Color::Red);
			shape3.setFillColor(sf::Color::Yellow);
		}
		~Level() {}

		void Draw(sf::RenderWindow& window) const {
			window.clear();
			window.draw(shape);
			window.draw(shape2);
			window.draw(shape3);
			window.display();
		}
	private:
		sf::CircleShape shape{ 100.f };
		sf::CircleShape shape2{ 50.f };
		sf::CircleShape shape3{ 25.f };
	};
}
#endif // !KM_LEVEL_H