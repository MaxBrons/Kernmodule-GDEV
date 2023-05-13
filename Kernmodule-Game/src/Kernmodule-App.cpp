#include "KMCore.h"
#include <SFML/Graphics.hpp>

int main()
{
    KMCore::Application app(sf::VideoMode(720, 360), "New window"); 
    KMCore::Level level;
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    app.Run(level);

    return 0;
}