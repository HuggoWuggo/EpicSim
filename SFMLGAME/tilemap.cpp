#include "tilemap.h"

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{

    // load the tileset texture
    if (!m_tileset.loadFromFile(tileset))
        return false;

    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number
            int tileNumber = tiles[i + j * width];

            // find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
    return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_tileset;

    // draw the vertex array
    target.draw(m_vertices, states);
}

// create the window
//sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");

// define the level with an array of tile indices
//const int level[] =
//{
//    0, 1, 2, 3, 1, 2, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1,
//    0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
//    1, 1, 0, 0, 2, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
//    0, 1, 0, 0, 3, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0,
//    0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0,
//    0, 0, 1, 0, 3, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0,
//    1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
//    0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
//};

// create the tilemap from the level definition
//TileMap map;
//if (!map.load("Fonts/tileset_s.png", sf::Vector2u(32, 32), level, 16, 8))
//    return -1;

//Code

//window.draw(map);