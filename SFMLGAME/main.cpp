#include <SFML/Graphics.hpp>
#include <iostream>

sf::Vector2f Interpolate(const sf::Vector2<float>& pointA, const sf::Vector2<float>& pointB, float factor) {
    if (factor > 1.f)
        factor = 1.f;

    else if (factor < 0.f)
        factor = 0.f;

    return pointA + (pointB - pointA) * factor;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);

    sf::RectangleShape shape(sf::Vector2f(50, 50));
    shape.setFillColor(sf::Color::Green);
    sf::Vector2f pointA = sf::Vector2f(10, 10), pointB = sf::Vector2f(500, 500);
    float factor = 0.f, speed = .01f;

    shape.setPosition(pointA);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();

        factor += (clock.getElapsedTime().asSeconds() * speed);
        shape.setPosition(Interpolate(pointA, pointB, factor));
    }

    return 0;
}