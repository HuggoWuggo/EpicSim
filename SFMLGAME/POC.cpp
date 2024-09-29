#include <iostream>

#include <SFML/Graphics.hpp>

sf::Vector2f Interpolate(const sf::Vector2<float>& pointA, const sf::Vector2<float>& pointB, float factor) {
    if (factor > 1.f)
        factor = 1.f;

    else if (factor < 0.f)
        factor = 0.f;

    return pointA + (pointB - pointA) * factor;
}

int main() {
    // Init window and events
	sf::RenderWindow window(sf::VideoMode(800, 600), "It Works", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    
    // Init grass texture
    sf::Texture grass;
    if (!grass.loadFromFile("Resources/Textures/grass.png"))
        std::cout << "Couldn't load texture: GRASS" << std::endl;
    grass.setRepeated(true);

    // Init Background sprite
    sf::Sprite BKG;
    BKG.setTexture(grass);
    BKG.setScale(1.5, 1.5);
    BKG.setTextureRect(sf::IntRect(0, 0, 800, 600));

    // Define moveTowards variables
    sf::Vector2f pointA = sf::Vector2f(10, 10), pointB = sf::Vector2f(500, 500);
    float factor = 0.f, speed = .005f;

    // Define moveTowards shape 1
    sf::RectangleShape shape(sf::Vector2f(50, 50));
    shape.setFillColor(sf::Color(0, 0, 0, 100));
    shape.setPosition(pointA);

    // Define moveTowards shape 2
    sf::RectangleShape end(sf::Vector2f(20, 20));
    end.setFillColor(sf::Color::Yellow);
    end.setPosition(sf::Vector2f(pointB.x + 15.5f, pointB.y + 15.5f));
    
    // Define moveTowards clock
    sf::Clock clock;

	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Move towards factor
        factor += (clock.getElapsedTime().asSeconds() * speed /*Questionable function*/ / 2);
        shape.setPosition(Interpolate(pointA, pointB, factor));

        // Render
        window.clear();

        // Draw Background
        window.draw(BKG);

        //Draw Sprites
        window.draw(shape);
        window.draw(end);

        window.display();
    }

}