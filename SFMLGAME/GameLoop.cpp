#include "GameLoop.h"

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


const int* GameLoop::getLevel(int num)
{
    // Init Levels

    static int level1[] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,1,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0
    };
    static int level2[] =
    {
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,2,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,1,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0
    };

    static int level3[] =
    {
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,2,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,2,0,1,0,2,
        0,0,0,0,0,0,0,0,0,0,0,0,0
    };


    switch (num) {
    case 1:
        return level1;
        break;
    case 2:
        return level2;
        break;
    case 3:
        return level3;
        break;
    default:
        std::cout << "THAT WAS THE LAST LEVEL" << std::endl;
        break;
    }
}

GameLoop::GameLoop()
{
    numPlaced = 0;
    cLevel = 1;
    won = false;
    beat = false;

    // Init window and events
    this->window = new sf::RenderWindow(sf::VideoMode(832, 640), "It Works!", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);

    //Load grass texture
    if (!grass.loadFromFile("Resources/Textures/grass.png"))
        std::cout << "Couldn't load texture: GRASS" << std::endl;
    grass.setRepeated(true);

    BKG.setTexture(grass);
    BKG.setScale(1.5, 1.5);
    BKG.setTextureRect(sf::IntRect(0, 0, 832, 640));

    map = new TileMap();

    chooseLevel(cLevel);

    // Load font
    if (!font.loadFromFile("Resources/Fonts/BigBlueTerm.ttf"))
        std::cout << "FAILED TO LOAD FONT: BIGBLUETERM" << std::endl;

    if (!s_font.loadFromFile("Resources/Fonts/GohuFont.ttf"))
        std::cout << "FAILED TO LOAD FONT: GOHU" << std::endl;

    // Init text
    gameOver_t.setFont(font);
    gameOver_t.setCharacterSize(64);
    gameOver_t.setFillColor(sf::Color::Red);
    gameOver_t.setOutlineColor(sf::Color(128, 0, 0, 255));
    gameOver_t.setOutlineThickness(4);
    gameOver_t.setPosition(sf::Vector2f(230, 220));
    gameOver_t.setString("GAME OVER");

    youWin_t.setFont(font);
    youWin_t.setCharacterSize(64);
    youWin_t.setFillColor(sf::Color(0, 255, 1, 255));
    youWin_t.setOutlineColor(sf::Color(0, 128, 0, 255));
    youWin_t.setOutlineThickness(4);
    youWin_t.setPosition(sf::Vector2f(230, 220));
    youWin_t.setString("YOU WIN!");
    
    completed_t.setFont(font);
    completed_t.setCharacterSize(32);
    completed_t.setFillColor(sf::Color(255, 255, 0, 255));
    completed_t.setOutlineColor(sf::Color(255, 180, 0, 255));
    completed_t.setOutlineThickness(4);
    completed_t.setPosition(sf::Vector2f(230, 220));
    completed_t.setString("YOU BEAT THE GAME!");

    numPlaced_t.setFont(font);
    numPlaced_t.setCharacterSize(16);
    numPlaced_t.setFillColor(sf::Color(0, 255, 255, 255));
    numPlaced_t.setOutlineColor(sf::Color(0, 0, 0, 255));
    numPlaced_t.setOutlineThickness(1.5);
    numPlaced_t.setPosition(sf::Vector2f(10, 50));

    cLevel_t.setFont(font);
    cLevel_t.setCharacterSize(16);
    cLevel_t.setFillColor(sf::Color(255, 0, 200, 255));
    cLevel_t.setOutlineColor(sf::Color(0, 0, 139, 255));
    cLevel_t.setOutlineThickness(1.5);
    cLevel_t.setPosition(sf::Vector2f(10, 10));
}

void GameLoop::pollEvents()
{
    // Poll events
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && dog.returnDeath() == false && numPlaced != 0) {
            sf::RectangleShape rect{ { 20, 20 } };
            rect.setPosition(sf::Vector2f(sf::Mouse::getPosition(*window)));
            rect.setFillColor(sf::Color::Yellow);
            placed.push_back(rect);
            numPlaced -= 1;
        }
    }
}

void GameLoop::update()
{

    //Update
    dog.update();
    if (placed.size() != 0)
        dog.moveTowards(placed);
    
    std::string numPlaced_s = " PLACES LEFT";
    std::string cLevel_s = "LEVEL: ";

    numPlaced_t.setString(std::to_string(numPlaced).append(numPlaced_s));
    cLevel_t.setString(cLevel_s.append(std::to_string(cLevel)));
    
    int tileUnderPlayer;

    switch (cLevel) {
    case 1:
        tileUnderPlayer = level1[dog.tileX + dog.tileY * 13];
        break;
    case 2:
        tileUnderPlayer = level2[dog.tileX + dog.tileY * 13];
        break;
    case 3:
        tileUnderPlayer = level3[dog.tileX + dog.tileY * 13];
        break;
    default:
        tileUnderPlayer = 0;
        break;
    }
    
    if (tileUnderPlayer == 1) {
        won = true;
        while (won == true) {
            render();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                break;
            }
            else {
                continue;
            }
        }
        end();
    }
    else if (tileUnderPlayer == 2) {
        dog.setDeath(true);
    }
    if (dog.returnDeath() == true) {
        while (dog.returnDeath() == true) {
            render();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                break;
            }
            else {
                continue;
            }
        }
        dog.setDeath(false);
        dog.reset();
        placed.clear();
        if (cLevel == 1)
            numPlaced = 1;
        else if (cLevel == 2)
            numPlaced = 2;
        else if (cLevel == 3)
            numPlaced = 3;
    }

}

void GameLoop::render()
{
    // Render
    window->clear();

    // Draw Background
    window->draw(BKG);

    // Draw blocks
    window->draw(*map);


    //Draw Sprites
    for (auto& e : placed) {
        window->draw(e);
    }

    dog.render(*window);

    window->draw(numPlaced_t);
    window->draw(cLevel_t);

    if (won == true)
        window->draw(youWin_t);

    if (dog.returnDeath() == true)
        window->draw(gameOver_t);

    if (beat == true) {
        window->clear(sf::Color::Black);
        window->draw(completed_t);
    }

    window->display();
}

bool GameLoop::running()
{
    return window->isOpen();
}

void GameLoop::chooseLevel(int cLevel)
{
    switch (cLevel) {
    case 1:
        // Load tileset
        if (!map->load("Resources/Textures/tileset.png", sf::Vector2u(64, 64), level1, 13, 10))
            std::cout << "FAILED TO LOAD TILESET" << std::endl;
        numPlaced = 1;
        break;
    case 2:
        // Load tileset
        if (!map->load("Resources/Textures/tileset.png", sf::Vector2u(64, 64), level2, 13, 10))
            std::cout << "FAILED TO LOAD TILESET" << std::endl;
        numPlaced = 2;
        break;
    case 3:
        // Load tileset
        if (!map->load("Resources/Textures/tileset.png", sf::Vector2u(64, 64), level3, 13, 10))
            std::cout << "FAILED TO LOAD TILESET" << std::endl;
        numPlaced = 3;
        break;

    default:
        beat = true;
        break;
    }
}

void GameLoop::end()
{
    dog.reset();
    cLevel += 1;
    chooseLevel(cLevel);

    placed.clear();

    won = false;
}
