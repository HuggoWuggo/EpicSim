#include "GameLoop.h"

const int* GameLoop::getLevel(int num)
{
    // Init Levels

    static int level0[] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0
    };

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

    static int level4[] =
    {
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,2,0,2,0,2,0,2,0,2,0,2,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,2,0,2,0,2,0,2,0,2,0,2,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,1,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0
    };

    static int level5[] =
    {
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        2,2,2,2,2,0,0,0,0,0,0,0,0,
        2,0,0,1,2,0,0,0,0,0,0,0,0,
        2,0,0,0,2,0,0,0,0,0,0,3,0,
        2,0,4,0,2,0,0,0,0,0,0,0,0,
        2,2,2,2,2,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0
    };


    switch (num) {
    case 0:
        return level0;
        break;
    case 1:
        return level1;
        break;
    case 2:
        return level2;
        break;
    case 3:
        return level3;
        break;
    case 4:
        return level4;
    case 5:
        return level5;
        break;
    }
}

GameLoop::GameLoop()
{
    numPlaced = 0;
    cLevel = 0;
    won = false;
    beat = false;
    deathCounter = 0;

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

    // Load ball Texture
    ball_t.loadFromFile("Resources/Sprites/ball.png");
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

    deathCounter_t.setFont(font);
    deathCounter_t.setCharacterSize(16);
    deathCounter_t.setFillColor(sf::Color(255, 0, 0, 255));
    deathCounter_t.setOutlineColor(sf::Color(128, 0, 0, 255));
    deathCounter_t.setOutlineThickness(1.5);
    deathCounter_t.setPosition(sf::Vector2f(10, 90));

    cLevel_t.setFont(font);
    cLevel_t.setCharacterSize(16);
    cLevel_t.setFillColor(sf::Color(255, 0, 200, 255));
    cLevel_t.setOutlineColor(sf::Color(0, 0, 139, 255));
    cLevel_t.setOutlineThickness(1.5);
    cLevel_t.setPosition(sf::Vector2f(10, 10));

    title_t.setFont(font);
    title_t.setCharacterSize(32);
    title_t.setFillColor(sf::Color(180, 0, 0, 255));
    title_t.setOutlineColor(sf::Color(255, 255, 0, 255));
    title_t.setOutlineThickness(1.5);
    title_t.setPosition(sf::Vector2f(230, 220));
    title_t.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
    title_t.setString("CHINESE SIMULATOR");

    name_t.setFont(font);
    name_t.setCharacterSize(16);
    name_t.setFillColor(sf::Color(0, 0, 0, 255));
    name_t.setOutlineColor(sf::Color(255, 255, 255, 255));
    name_t.setOutlineThickness(1);
    name_t.setPosition(sf::Vector2f(280, 280));
    name_t.setStyle(sf::Text::Style::Italic | sf::Text::Style::Underlined);
    name_t.setString("By The Oguhs Cookies Team");
}

void GameLoop::pollEvents()
{
    // Poll events
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && dog.returnDeath() == false && numPlaced != 0 && cLevel != 0) {
            sf::RectangleShape rect{ { 20, 20 } };
            rect.setPosition(sf::Vector2f(sf::Mouse::getPosition(*window)));
            rect.setFillColor(sf::Color(0, 0, 0, 0));
            placed.push_back(rect);

            sf::Sprite ball;
            ball.setTexture(ball_t);
            ball.setPosition(rect.getPosition());
            ball.setScale(0.5, 0.5);

            balls.push_back(ball);

            numPlaced -= 1;
        }
    }
}

void GameLoop::update()
{
    if (cLevel == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            won = true;
            end();
        }
    }
    int xp, yp;

    //Update
    dog.update();
    if (placed.size() != 0)
        dog.moveTowards(placed);
    
    std::string numPlaced_s = " PLACES LEFT";
    std::string cLevel_s = "LEVEL: ";
    std::string deathCounter_s = "DEATHS: ";

    numPlaced_t.setString(std::to_string(numPlaced).append(numPlaced_s));
    cLevel_t.setString(cLevel_s.append(std::to_string(cLevel)));
    deathCounter_t.setString(deathCounter_s.append(std::to_string(deathCounter)));
    
    int tileUnderPlayer;

    switch (cLevel) {
    case 0:
        tileUnderPlayer = level0[dog.tileX + dog.tileY * 13];
        break;
    case 1:
        tileUnderPlayer = level1[dog.tileX + dog.tileY * 13];
        break;
    case 2:
        tileUnderPlayer = level2[dog.tileX + dog.tileY * 13];
        break;
    case 3:
        tileUnderPlayer = level3[dog.tileX + dog.tileY * 13];
        break;
    case 4:
        tileUnderPlayer = level4[dog.tileX + dog.tileY * 13];
        break;
    case 5:
        tileUnderPlayer = level5[dog.tileX + dog.tileY * 13];
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
        dog.dead_anim();  // Call death animation
    }
    else if (tileUnderPlayer == 3) {
        for (int i = 0; i < 13 * 11; ++i) { // Loop through all tiles (13 columns by 11 rows)
            if (level5[i] == 4) {
                int x = (i % 13) * 64; // Column index (x)
                int y = (i / 13) * 64; // Row index (y)

                xp = x;
                yp = y - 60;
            }
        }
        dog.dogSpr.setPosition(xp, yp);
        placed.clear();
        dog.Moving = false;
    }


    if (dog.returnDeath() == true) {
        while (dog.returnDeath() == true) {
            if (tileUnderPlayer == 2)
                dog.dead_anim();  // Continue calling death animation in the death loop
            render();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                break;
            }
        }
        deathCounter += 1;
        dog.setDeath(false);
        dog.reset();
        placed.clear();
        balls.clear();
        if (cLevel == 0)
            numPlaced = 1;
        else if (cLevel == 1)
            numPlaced = 1;
        else if (cLevel == 2)
            numPlaced = 2;
        else if (cLevel == 3)
            numPlaced = 3;
        else if (cLevel == 4)
            numPlaced = 3;
        else if (cLevel == 5)
            numPlaced = 2;
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
        if (cLevel != 0)
            window->draw(e);
    }

    if (balls.size() > 0 && cLevel != 0) {
        for (auto& e : balls) {
            window->draw(e);
        }
    }

    if (cLevel != 0)
        dog.render(*window);

    if (cLevel != 0){
        window->draw(numPlaced_t);
        window->draw(cLevel_t);
        window->draw(deathCounter_t);
    }
    else {
        window->draw(title_t);
        window->draw(name_t);
    }

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
    case 0:
        // Load tileset
        if (!map->load("Resources/Textures/tileset.png", sf::Vector2u(64, 64), level0, 13, 10))
            std::cout << "FAILED TO LOAD TILESET" << std::endl;
        numPlaced = 1;
        break;
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
    case 4:
        // Load tileset
        if (!map->load("Resources/Textures/tileset.png", sf::Vector2u(64, 64), level4, 13, 10))
            std::cout << "FAILED TO LOAD TILESET" << std::endl;
        numPlaced = 3;
        break;
    case 5:
        // Load tileset
        if (!map->load("Resources/Textures/tileset.png", sf::Vector2u(64, 64), level5, 13, 10))
            std::cout << "FAILED TO LOAD TILESET" << std::endl;
        numPlaced = 2;
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
    balls.clear();

    won = false;
}
