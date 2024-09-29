#pragma once
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Dog.h"

class GameLoop
{
private:
	sf::RenderWindow* window;

	// Init dog
	Dog dog;

	// Create a Vector of Rectangles
	std::vector<sf::RectangleShape> placed;

	// Init Background sprite
	sf::Sprite BKG;

	// Init grass texture
	sf::Texture grass;

public:
	GameLoop();

	void pollEvents();

	void update();

	void render();

	bool running();
};

