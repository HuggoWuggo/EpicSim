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

	// Init Background sprite
	sf::Sprite BKG;

	// Init grass texture
	sf::Texture grass;

	// Load font & text
	sf::Font font;
	sf::Text gameOver_t;
	sf::Text youWin_t;
	sf::Text numPlaced_t;
	sf::Text completed_t;

	// Number of placed
	int numPlaced;

	int cLevel;

	bool won;
	bool beat;

	int level2[130];

	const int* getLevel(int num);

public:

	GameLoop();

	void pollEvents();

	void update();

	void render();

	bool running();

	void chooseLevel(int cLevel);

	void end();
};
