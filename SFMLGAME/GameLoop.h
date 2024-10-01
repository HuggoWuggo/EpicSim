#pragma once
#include <iostream>
#include <fstream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Dog.h"

// Load Tilemap
class TileMap : public sf::Drawable, public sf::Transformable
{
public:

	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

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

	// Number of placed
	int numPlaced;

	int cLevel;

	bool won;
	bool beat;

	const int* getLevel(int num);

	const int* level1 = getLevel(1);
	const int* level2 = getLevel(2);
	const int* level3 = getLevel(3);

public:

	GameLoop();

	void pollEvents();

	void update();

	void render();

	bool running();

	void chooseLevel(int cLevel);

	void end();
};