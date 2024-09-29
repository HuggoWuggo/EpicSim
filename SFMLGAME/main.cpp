#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Dog.h"

int main() {
    // Init window and events
	sf::RenderWindow window(sf::VideoMode(800, 600), "It Works!", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    
    // Create a Vector of Rectangles
    std::vector<sf::RectangleShape> placed;

    // Init grass texture
    sf::Texture grass;
    if (!grass.loadFromFile("Resources/Textures/grass.png"))
        std::cout << "Couldn't load texture: GRASS" << std::endl;
    grass.setRepeated(true);

    // Init dog
    Dog dog;
    // Init Background sprite
    sf::Sprite BKG;
    BKG.setTexture(grass);
    BKG.setScale(1.5, 1.5);
    BKG.setTextureRect(sf::IntRect(0, 0, 800, 600));
    

	while (window.isOpen())
    {

        // Poll events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::RectangleShape rect{ { 20, 20 } };
                rect.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
                rect.setFillColor(sf::Color::Yellow);
                placed.push_back(rect);
            }
        }

        //Update
        dog.update();
        if (placed.size() != 0)
            dog.moveTowards(placed);

        // Render
        window.clear();

        // Draw Background
        window.draw(BKG);

        //Draw Sprites
        dog.render(window);
        for (auto& e : placed) {
            window.draw(e);
        }

        window.display();
    }

}