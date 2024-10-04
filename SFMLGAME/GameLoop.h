#pragma once
#include <iostream>
#include <fstream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Dog.h"
#include "tilemap.h"

class GameLoop
{
private:
	sf::RenderWindow* window;

	//Init Tilemap Loader
	TileMap* map;

	// Init dog
	Dog dog;

	// Create a Vector of placed
	std::vector<sf::RectangleShape> placed;

	// Create a Vector of balls
	std::vector<sf::Sprite> balls;

	// Init Background sprite
	sf::Sprite BKG;

	// Init ball texture
	sf::Texture ball_t;

	// Init grass texture
	sf::Texture grass;

	// Load font & text
	sf::Font font;
	sf::Font s_font;
	sf::Text gameOver_t;
	sf::Text youWin_t;
	sf::Text numPlaced_t;
	sf::Text completed_t;
	sf::Text cLevel_t;
	sf::Text deathCounter_t;
	sf::Text title_t;
	sf::Text name_t;

	// Number of placed
	int numPlaced;

	int cLevel;
	int deathCounter;

	bool won;
	bool beat;

	const int* getLevel(int num);

	const int* level0 = getLevel(0);
	const int* level1 = getLevel(1);
	const int* level2 = getLevel(2);
	const int* level3 = getLevel(3);
	const int* level4 = getLevel(4);
	const int* level5 = getLevel(5);

public:

	GameLoop();

	void pollEvents();

	void update();

	void render();

	bool running();

	void chooseLevel(int cLevel);

	void end();
};
