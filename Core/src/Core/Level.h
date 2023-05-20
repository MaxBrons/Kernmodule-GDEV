#pragma once
#include "Core.h"

namespace KMCore {
	class Level {

	public:
		Level() {
			shape.setFillColor(sf::Color::Green);
		}
		virtual ~Level() {}

		sf::Shape& GetCircleShape() {
			return shape;
		}

		void Draw(sf::RenderWindow* window) const {
			window->clear();
			window->draw(shape);
			window->display();
		}
	private:
		sf::CircleShape shape{ 100.f };
	};
}