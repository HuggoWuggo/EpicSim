#include <SFML/Graphics.hpp>
#include <iostream>

sf::Vector2f Interpolate(const sf::Vector2<float>& pointA, const sf::Vector2<float>& pointB, float factor) {
    if (factor > 1.f)
        factor = 1.f;

    else if (factor < 0.f)
        factor = 0.f;

    return pointA + (pointB - pointA) * factor;
}

void moveTowards(sf::RenderWindow& window)
{

    sf::RectangleShape shape(sf::Vector2f(50, 50));
    sf::RectangleShape end(sf::Vector2f(20, 20));

    shape.setFillColor(sf::Color(0, 255, 0, 100));
    end.setFillColor(sf::Color::Yellow);

    sf::Vector2f pointA = sf::Vector2f(10, 10), pointB = sf::Vector2f(500, 500);
    float factor = 0.f, speed = .01f;

    shape.setPosition(pointA);
    end.setPosition(sf::Vector2f(pointB.x + 15.5, pointB.y + 15.5));

    sf::Clock clock;

    while (window.isOpen())
    {

        factor += (clock.getElapsedTime().asSeconds() * speed);
        shape.setPosition(Interpolate(pointA, pointB, factor));
        window.draw(shape);
        window.draw(end);
    }
}